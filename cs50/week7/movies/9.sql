SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM stars
    WHERE movie_id = (
        SELECT id
        FROM movies
        WHERE title = 'Toy Story'
    )
);


SELECT name, birth
FROM people
WHERE id IN (
    SELECT person_id
    FROM stars
    WHERE movie_id IN (
        SELECT id
        FROM movies
        WHERE year = '2004'
    )
)
ORDER BY birth ASC;




