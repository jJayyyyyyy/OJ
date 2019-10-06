/*
https://leetcode.com/problems/rising-temperature/？goto=old
考察数据库的函数掌握情况
同类题目 P197

参考解法来自 AC Submission

DATEDIFF(d1, d2) 可以自动转换时间， 然后计算 d1 - d2 的值
*/

SELECT
    w1.id
FROM
    Weather w1, Weather w2
WHERE
    w1.Temperature > w2.Temperature
AND
    DATEDIFF(w1.RecordDate, w2.RecordDate) = 1
