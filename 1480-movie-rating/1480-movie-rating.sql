WITH TABLE1 AS (
    SELECT user_id, COUNT(*) AS NUMBER_OF_RATING 
    FROM MovieRating 
    GROUP BY user_id
),
TABLE2 AS (
    SELECT T1.user_id, U.name, NUMBER_OF_RATING 
    FROM TABLE1 T1
    LEFT JOIN Users U
      ON T1.user_id = U.user_id
),
TABLE4 AS (
    SELECT movie_id, AVG(rating) AS AVG_RATING  
    FROM MovieRating 
    WHERE YEAR(created_at) = 2020 
      AND MONTH(created_at) = 2
    GROUP BY movie_id
), 
TABLE5 AS (
    SELECT T4.movie_id, M.title, AVG_RATING  
    FROM TABLE4 T4
    LEFT JOIN Movies M
      ON T4.movie_id = M.movie_id
)
(
    SELECT NAME AS results 
    FROM TABLE2
    WHERE NUMBER_OF_RATING = (SELECT MAX(NUMBER_OF_RATING) FROM TABLE2)
    ORDER BY name 
    LIMIT 1
)
UNION ALL
(
    SELECT title AS results
    FROM (
        SELECT title, AVG_RATING
        FROM TABLE5
        WHERE AVG_RATING = (SELECT MAX(AVG_RATING) FROM TABLE5)
        ORDER BY title
        LIMIT 1
    ) AS sub
);
