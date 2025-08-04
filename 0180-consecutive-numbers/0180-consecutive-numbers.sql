# Write your MySQL query statement below
SELECT DISTINCT TABLE1.num AS ConsecutiveNums 
FROM 
    Logs AS TABLE1
    INNER JOIN
    Logs AS TABLE2
    ON TABLE1.id = TABLE2.id -1
    INNER JOIN
    LOGS AS TABLE3
    ON TABLE1.id = TABLE3.id -2
    where TABLE1.num = TABLE2.num and TABLE2.num = TABLE3.num
    