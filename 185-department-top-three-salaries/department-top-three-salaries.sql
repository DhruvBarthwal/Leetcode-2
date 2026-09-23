# Write your MySQL query statement below
SELECT 
d.name AS Department,
e.name AS Employee,
e.salary AS Salary
FROM (
    SELECT e.*, DENSE_RANK() OVER (
        PARTITION BY e.departmentID
        ORDER BY e.salary DESC
    )
    AS rnk FROM Employee e 
) e
JOIN 
department AS d
ON d.id = e.departmentId
WHERE e.rnk <= 3