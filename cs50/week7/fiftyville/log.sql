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

-- check security camera footage

