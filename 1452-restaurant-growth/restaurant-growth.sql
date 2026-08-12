# Write your MySQL query statement below
SELECT DISTINCT 
    visited_on , 
    SUM(amount) OVER w AS amount , 
    ROUND((SUM(amount) OVER w)/7,2) as average_amount
FROM Customer
    WINDOW w AS (
        ORDER BY visited_on
        range between interval 6 day PRECEDING and current row
    )
LIMIT 6, 999
