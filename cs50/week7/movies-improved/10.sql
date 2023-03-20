SELECT DISTINCT name
FROM people
JOIN directors ON director.person_id = id
JOIN ratings ON ratings.movie_id = directors.movie_id
WHERE ratings.rating >= 9.0;