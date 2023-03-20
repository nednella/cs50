SELECT title
FROM movies
JOIN ratings ON ratings.movie_id = id
JOIN stars ON stars.movie_id = id
JOIN people ON stars.person_id = id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC;