# Write your MySQL query statement below

SELECT e.name , b.bonus
FROM Employee as e
LEFT JOIN Bonus as b
ON e.empId = b.empId
WHERE bonus is NULL OR bonus < 1000