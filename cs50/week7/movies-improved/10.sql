SELECT DISTINCT name
FROM people
JOIN directors ON person_id = id
JOIN ratings ON movie_id = directors.movie_id
WHERE ratings.rating >= 9.0;




SELECT
DISTINCT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM directors
    WHERE movie_id IN (
        SELECT movie_id
        FROM ratings
        WHERE rating >= 9.0
    )
);