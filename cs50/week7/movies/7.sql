SELECT movies.title, ratings.rating
FROM movies WHERE year = '2010'
JOIN ratings
ON movies.id = ratings.movie_id LIMIT 10;
--ORDER BY ratings.rating DESC;