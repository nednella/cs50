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





-----------------------------------------------------------------------------------------------------------------------------------
-- QUERIES BASED ON WITNESS INTERVIEWS

-- check security camera footage for the date and time of the theft
-- within 10 minutes of the theft (10:15am), there were 8 cars that left the bakery parking lot
SELECT *
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = 'exit';



-- check ATM records for the date of the theft
-- there are 8 total withdrawal transactions that match the information in Eugene's interview
SELECT *
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';



-- check phone calls for the date of the theft, with less than 1 minute duration
-- there are 9 total phone calls that took place on the day of the theft with less than 1 minute duration
SELECT *
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;





-----------------------------------------------------------------------------------------------------------------------------------
-- QUERIES BASED ON INFORMATION FOUND AS A RESULT OF WITNESS INTERVIEWS

-- obtain identities of those that match:
-- 1. the 8 license plates recorded leaving the parking lot within 10 minutes of the theft
-- 2. the 8 ATM records on the morning of the theft
-- 3. the 9 outgoing phone calls on the day of the theft with less than 1 minute duration
SELECT *
FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE people.license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
) AND bank_accounts.account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
) AND people.phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
);

-- there are 2 matches!
-- ID 686048, name Bruce, phone number (367) 555-5533, passport number 5773159633, license plate 94KL13X
-- ID 514354, name Diana, phone number (770) 555-1861, passport number 3592750733, license plate 322W7JE



-- check the identities of those people who received a call from these 2 individuals on the day of the theft
SELECT *
FROM people
WHERE phone_number IN (
    SELECT *
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND (caller = '(367) 555-5533' OR caller = '(770) 555-1861')
);

-- there are 2 matches!
-- ID 847116, name Philip, phone number (725) 555-3243, passport number 3391710505, license plate GW362R6
-- ID 864400, name Robin, phone number (375) 555-8161, passport number (N/A), license plate 4V16VO0





-----------------------------------------------------------------------------------------------------------------------------------
-- LIST OF SUSPECTS AND THEIR ACCOMPLICES

-- SUSPECT 1
    -- ID 686048, name Bruce, phone number (367) 555-5533, passport number 5773159633, license plate 94KL13X
-- ACCOMPLICE 1
    -- ID 864400, name Robin, phone number (375) 555-8161, passport number (N/A), license plate 4V16VO0

-- SUSPECT 2
    -- ID 514354, name Diana, phone number (770) 555-1861, passport number 3592750733, license plate 322W7JE
-- ACCOMPLICE 2
    -- ID 847116, name Philip, phone number (725) 555-3243, passport number 3391710505, license plate GW362R6





-----------------------------------------------------------------------------------------------------------------------------------
--

-- analyse list of airports in the database
SELECT *
FROM airports;

-- ID 8, abbreviation CSF, full_name Fiftyville Regional Airport, city Fiftyville


-- analyse list of outbound flights from the Fiftyville airport on the day after the theft
SELECT *
FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE airports.abbreviation = 'CSF' AND year = 2021 AND month = 7 AND day = 29;



-- check passenger lists for SUSPECT name for the outbound flights on 29th July 2021 from Fiftyville airport
SELECT *
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id IN (
        SELECT flights.id
        FROM flights
        JOIN airports ON airports.id = flights.origin_airport_id
        WHERE airports.abbreviation = 'CSF' AND year = 2021 AND month = 7 AND day = 29
    )
) AND (name = 'Bruce' OR name = 'Diana');


AND (passport_number = 5773159633 OR passport_number = );









-- analyse list of airports where those outbound flights were destined to land
SELECT *
FROM airports
WHERE id IN (
    SELECT destination_airport_id
    FROM airports
    JOIN flights ON flights.origin_airport_id = airports.id
    WHERE airports.abbreviation = 'CSF' AND year = 2021 AND month = 7 AND day = 29
);


-- analyse list of flights





-- check whether either of the accomplices booked a flight on 29th July 2021 as requested by the thief
SELECT *
FROM airports



