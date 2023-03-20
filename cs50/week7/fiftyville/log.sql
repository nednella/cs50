-- Keep a log of any SQL queries you execute as you solve the mystery.

-- understand the contents and layout of the stored data
.schema

-- check what information is stored in the crime scene reports on the day that the theft of the CS50 duck took place
SELECT *
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28;

-- case ID 295 - CS50 duck theft.
-- 10:15am at the Humprhrey Street bakery. 3 witnesses, all were interviewed.



-- check what information is stored in the interviews database on the day of the theft
SELECT *
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

-- witnesses to the CS50 duck theft are:
-- Ruth (Interview ID 161)     - Within 10 minutes of the theft, she saw thief get into a car in the bakery parking lot.
-- Eugene (Interview ID 162)   - He recognised the thief, but doesn't know their name. He saw the thief withdrawing money from the ATM on Leggett Street on the same morning.
-- Raymond (Interview ID 163)  - Saw the thief call someone and talk for less than 1 minute. Heard the thief state they would take the earliest flight out of Fiftyville tomorrow (29th July 2021), and asked them to buy a plane ticket.





-- QUERIES BASED ON WITNESS INTERVIEWS

-- check security camera footage for the date and time of the theft
SELECT *
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;

-- within 10 minutes of the theft (10:15am), there were 8 cars that left the bakery parking lot:
-- ID 260, license plate 5P2BI95
-- ID 261, license plate 94KL13X
-- ID 262, license plate 6P58WS2
-- ID 263, license plate 4328GD8
-- ID 264, license plate G412CB7
-- ID 265, license plate L93JTIZ
-- ID 266, license plate 322W7JE
-- ID 267, license plate 0NTHK55



-- check ATM records for the date of the theft
SELECT *
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- there are 8 total withdrawal transactions that match the information in Eugene's interview
-- ID 246, account number 28500762, amount 48
-- ID 264, account number 28296815, amount 20
-- ID 266, account number 76054385, amount 60
-- ID 267, account number 49610011, amount 50
-- ID 269, account number 16153065, amount 80
-- ID 288, account number 25506511, amount 20
-- ID 313, account number 81061156, amount 30
-- ID 336, account number 26013199, amount 35




-- check phone calls for the date of the theft, with less than 1 minute duration
SELECT *
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- there are 9 total phone calls that took place on the day of the theft with less than 1 minute duration
-- ...





-- QUERIES BASED ON INFORMATION FOUND AS A RESULT OF WITNESS INTERVIEWS

-- obtain identities from bank accounts who's account number matches any of the 8 withdrawals
SELECT *
FROM people
JOIN bank_accounts ON person_id = people.id
WHERE bank_accounts.account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
);



-- check for records of people matching any of the 8 license plates and 9 outbound callers from the above queries
SELECT *
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
) AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
);





-- there are 4 matches for people who's cars left the bakery within 10 minutes of the theft, and who's phone numbers had an outbound call with less than 1 minute duration on the day of the theft:
-- ID 398010, name Sofia, phone number (130) 555-0289, passport number 1695452385, license plate G412CB7
-- ID 514354, name Diana, phone number (770) 555-1861, passport number 3592750733, license plate 322W7JE
-- ID 560886, name Kelsey, phone number (499) 555-9472, passport number 8294398571, license plate 0NTHK55
-- ID 686048, name Bruce, phone number (367) 555-5533, passport number 5773159633, license plate 94KL13X

-- check for records of people receiving calls from any of these 4 individuals
SELECT *
FROM phone_calls
WHERE caller IN (
    SELECT phone_number
    FROM people
    WHERE license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
    ) AND phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
    )
) AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- there are 5 matches for people who received a call from any of the 4 individuals in the query above
-- ...

-- check the identities of the 5 people in the previous query
SELECT *
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE caller IN (
        SELECT phone_number
        FROM people
        WHERE license_plate IN (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
        ) AND phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
        )
    ) AND year = 2021 AND month = 7 AND day = 28 AND duration < 60
);

-- the identities of possible people who received a call from the culprit asking to buy a flight ticket for 29th July 2021 are:
-- ID 251693, name Larry, phone number (892) 555-8872, passport number 2312901747, license plate O268ZZ0
-- ID 567218, name jack, phone number (996) 555-8899, passport number 9029462229, license plate 52R0Y8U
-- ID 626361, name Melissa, phone number (717) 555-1342, passport number 7834357192, license plate N/A
-- ID 847116, name Philip, phone number (725) 555-3243, passport number 3391710505, license plate GW362R6,
-- ID 864400, name Robin, phone number (375) 555-8161, passport number N/A, license plate 4V16VO0
















