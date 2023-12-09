SELECT name FROM people LEFT JOIN stars ON people.id = person_id LEFT JOIN movies ON movie_id = movies.id WHERE movies.title = "Toy Story";
