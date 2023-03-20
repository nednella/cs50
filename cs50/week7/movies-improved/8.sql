SELECT name
FROM people
JOIN stars ON stars.person_id = people_id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.title = 'Toy Story';