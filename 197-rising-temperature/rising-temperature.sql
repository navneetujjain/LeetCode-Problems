SELECT
        w2.id

FROM
        weather w2, 
        weather w1

WHERE
        datediff(w2.recordDate, w1.recordDate) = 1
AND
        w2.temperature > w1.temperature