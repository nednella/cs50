SELECT title
FROM movies
WHERE id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Johnny Depp'
    )
) AND id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Helena Bonham Carter'
    )
);





SELECT name
FROM people
WHERE id IN (



) AND name != 'Kevin Bacon'






SELECT person_id
FROM stars
WHERE movie_id IN (

)


SELECT title
FROM movies
WHERE


