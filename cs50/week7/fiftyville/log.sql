-- Keep a log of any SQL queries you execute as you solve the mystery.

-- understand the contents and layout of the stored data
.schema

-- check what information is stored in the crime scene reports
SELECT *
FROM crime_scene_reports;

-- check the crime scene reports on the day that the theft of the CS50 duck took place
SELECT *
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28;

-- case ID 295 - CS50 duck theft.
-- 10:15am at the Humprhrey Street bakery. 3 witnesses, all were interviewed.

--
SELECT *
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;