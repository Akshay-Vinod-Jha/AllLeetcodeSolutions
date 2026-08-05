select
lt.student_id,
lt.student_name,
lt.subject_name,
IFNULL(rt.count_is,0) as attended_exams
from (select 
lt.student_id,
lt.student_name,
rt.subject_name
from Students as lt
cross join Subjects as rt) as lt
left join
(
    select 
student_id,
subject_name,
count(*) as count_is
from Examinations
group by student_id , subject_name

) as rt 
on lt.student_id = rt.student_id and lt.subject_name = rt.subject_name

order by student_id , subject_name