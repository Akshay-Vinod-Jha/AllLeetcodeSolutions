# Write your MySQL query statement below
WITH TABLE1 AS (
    select * ,
        DENSE_RANK() OVER(PARTITION BY teacher_id ORDER BY subject_id ) AS DENSERANK
        FROM
        Teacher 
)
SELECT teacher_id,MAX(DENSERANK ) AS cnt FROM TABLE1 GROUP BY teacher_id 