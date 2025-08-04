# Write your MySQL query statement below
SELECT patient_id , patient_name , conditions FROM (
    SELECT patient_id , patient_name , INSTR(conditions,"DIAB1") AS ISTHERE ,conditions FROM Patients 
) AS DUMMY1 WHERE ISTHERE > 0 AND (DUMMY1.ISTHERE = 1 OR SUBSTR(conditions,ISTHERE-1,1) = " ")
