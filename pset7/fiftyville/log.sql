-- Keep a log of any SQL queries you execute as you solve the mystery.
-- I followed the suggestion to review at first the crime_scene_reports table
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";
-- As we found in the descriion of the report, the theft took place in the court house, so at first i am going to review
-- the transcript of the witnesses
SELECT name, trascript FROM interviews WHERE year = 2020 AND day = 28 AND month = 7;
-- The theft took place 10:15 am, within 10 minutes, the thief left from the parking lot, he was seen withdrawing money from
-- an ATM on Fifer Street.
-- Around the time of the theft he made a phone call that lasted less than a minute, saied that they would take a flight
--the next day in the mrning out of Fiftyville, and the person on the other end was the one that bought it.
SELECT activity, licence_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10 AND minute >= 15 AND minute < 26;

SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate IN (SELECT license_plate
FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute < 26);

--Here i jus tryed to check who of the peolpe that left the courthouse aslo withdraw money from the atm in Fifer Street
SELECT account_number, transaction_type FROM atm_transactions WHERE year = 2020 AND day = 28 AND month = 7
AND atm_location = "Fifer Street" AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN
(SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10
AND minute >= 15 AND minute < 26)));

--Here i reviewed people's name and number
SELECT name, phone_number FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND day = 28 AND month = 7
AND atm_location = "Fifer Street" AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN
(SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10
AND minute >= 15 AND minute < 26)))));

--now i am just going to review the call that were made from the previus numbers that day.
SELECT duration, caller FROM phone_calls WHERE year = 2020 AND day = 28 AND month = 7 AND duration <= 60 AND caller IN
(SELECT phone_number FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND day = 28 AND month = 7
AND atm_location = "Fifer Street" AND account_number IN
(SELECT account_number FROM bank_accounts WHERE person_id IN
(SELECT id FROM people WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10
AND minute >= 15 AND minute < 26))))));

--Russel or Ernest are the thief Russell | (770) 555-1861 -- Ernest | (367) 555-5533


SELECT name FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id IN
(SELECT id FROM flights WHERE year = 2020 AND day = 29 AND month = 7 AND origin_airport_id IN
(SELECT id FROM airports WHERE city = "Fiftyville"))) AND name IN ("Russell", "Ernest");


SELECT license_plate FROM courthouse_security_logs WHERE
year = 2020 AND day = 28 AND month = 7 AND hour = 10 AND minute >=15 AND minute < 26 AND license_plate IN
(SELECT license_plate FROM people WHERE name IN ("Russell", "Ernest"));

SELECT name FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE year = 2020 AND day = 28 AND month = 7  AND duration < 60 AND caller IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE
year = 2020 AND day = 28 AND month = 7 AND hour = 10 AND minute >=15 AND minute < 26 AND license_plate IN
(SELECT license_plate FROM people WHERE name IN ("Russell", "Ernest")))));


SELECT city FROM airports WHERE id IN
(SELECT destination_airport_id FROM flights WHERE year = 2020 AND day = 29 AND month = 7 AND id IN
(SELECT flight_id FROM passengers WHERE passport_number IN
(SELECT passport_number FROM people WHERE name = "Ernest")));


SELECT license_plate, activity FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
and hour = 10 AND minute >= 15 AND minute < 26 AND license_plate IN
(SELECT license_plate FROM people WHERE name IN ("Ernest", "Russell"));



-- Russell went to Boston Philip
-- Ernest went to London Berthold

