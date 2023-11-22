# Write your MySQL query statement below
SELECT a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM Activity a1, Activity a2
WHERE a1.activity_type = 'start' AND a2.activity_type = 'end'
AND a1.process_id = a2.process_id
AND a1.machine_id = a2.machine_id
GROUP BY machine_id
ORDER BY machine_id ASC
