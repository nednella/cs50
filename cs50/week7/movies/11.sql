SELECT movies.title, ratings.rating
FROM movies
WHERE movies.id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
)
JOIN ratings
ON movies.id = ratings.movie_id
ORDER BY ratings.rating DESC;
