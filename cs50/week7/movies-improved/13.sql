SELECT DISTINCT name
FROM people
JOIN stars ON stars.person_id = id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN (
    SELECT id
    FROM movies
    JOIN stars ON stars.person_id = id
    JOIN people ON people.id = stars.person_id
    WHERE people.name = 'Kevin Bacon' AND people.birth = '1958'
)
AND name != 'Kevin Bacon';