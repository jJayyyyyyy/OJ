# 从 courses 表中选出 student 数量 >= 5 的 class, 注意每个 class 中重复的 student 只算一次
# +---------+------------+
# | student | class      |
# +---------+------------+
# | A       | Math       |
# | B       | English    |
# | C       | Math       |
# | D       | Biology    |
# | E       | Math       |
# | F       | Computer   |
# | G       | Math       |
# | H       | Math       |
# | I       | Math       |
# +---------+------------+
#
# 参考链接
# https://leetcode.com/problems/classes-more-than-5-students/solution/
# https://www.w3schools.com/sql/sql_count_avg_sum.asp

select class from (select class, count(distinct student) as cnt_stu from courses group by class) as temp_table where cnt_stu >= 5;