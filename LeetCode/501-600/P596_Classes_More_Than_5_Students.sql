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

select class from (select class, count(distinct student) as cnt_stu from courses group by class) as temp_table where cnt_stu >= 5;