# Write your MySQL query statement below
SELECT d.name AS Department, 
    e.name as Employee,
    e.salary as Salary
    FROM (
        SELECT e.*, DENSE_RANK() OVER (
            PARTITION BY e.departmentID
            ORDER BY e.salary DESC
        ) AS rnk FROM Employee e
    ) e
    JOIN Department as d
ON d.id = e.departmentId
WHERE rnk <=3