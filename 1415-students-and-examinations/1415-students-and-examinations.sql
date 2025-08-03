SELECT student_id, 
       student_name, 
       subject_name,
       CASE
           WHEN attended_exam IS NOT NULL THEN attended_exam
           ELSE 0
       END AS attended_exams
FROM (
    SELECT a.student_id, a.student_name, a.subject_name, b.count AS attended_exam
    FROM (
        SELECT student_id, student_name, subject_name
        FROM Students
        INNER JOIN Subjects
    ) AS a
    LEFT JOIN (
        SELECT student_id, subject_name, COUNT(*) AS count
        FROM Examinations 
        GROUP BY student_id, subject_name 
    ) AS b
    ON a.student_id = b.student_id 
    AND a.subject_name = b.subject_name
) AS lastable 
ORDER BY student_id ASC, subject_name ASC;
