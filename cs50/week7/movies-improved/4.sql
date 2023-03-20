SELECT COUNT(*)
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE id IN (
    SELECT movie_id
    FROM ratings
    WHERE rating = 10.0);