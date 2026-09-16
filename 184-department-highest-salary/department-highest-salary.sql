# Write your MySQL query statement below

SELECT 
    d.name as Department,
    e.name as Employee ,
    e.salary as Salary
FROM (
    SELECT e.*, DENSE_RANK() OVER (
        PARTITION BY e.departmentId
        ORDER BY e.salary DESC
    ) AS rnk FROM Employee e
) e
JOIN
Department as d
ON e.departmentId = d.id
WHERE e.rnk = 1