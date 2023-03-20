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
-- Eugene (Interview ID 162)   - He recognised the thief, but doesn't know their name. He saw the thief withdrawing money from the ATM on the same morning
-- Raymond (Interview ID 163)  - Saw the thief call someone and talk for less than 1 minute. Heard the thief state they would take the earliest flight out of Fiftyville tomorrow (29th July 2021), and asked them to buy a plane ticket.

-- check security camera footage for the date and time of the theft
SELECT *
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

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
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Humphrey Lane' AND transaction_type = 'withdraw';




