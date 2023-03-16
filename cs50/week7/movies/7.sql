SELECT movies.title, ratings.rating
FROM movies WHERE year = '2010'
JOIN ratings
ON movies.id = ratings.movie_id LIMIT 10;
--ORDER BY ratings.rating DESC;


SELECT movies.title, ratings.rating
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE movies.year = '2010'
ORDER BY ratings.rating DESC
LIMIT 10;