# Write your MySQL query statement below
SELECT user_Id, CONCAT(UPPER(LEFT(name,1)), LOWER(SUBSTRING(name,2))) AS name
FROM Users
ORDER BY user_id