# person 表格
# +----+---------+
# | Id | Email   |
# +----+---------+
# | 1  | a@b.com |
# | 2  | c@d.com |
# | 3  | a@b.com |
# +----+---------+
# 从表格 person 中选出 重复的 email, 从而得到
# +---------+
# | Email   |
# +---------+
# | a@b.com |
# +---------+
#
# 同类题目 P596
# 参考链接 https://www.w3schools.com/sql/sql_count_avg_sum.asp
# 参考答案 https://leetcode.com/problems/duplicate-emails/solution/

select email from
(
	select email, count(email) as cnt
	from person
	group by email
)
as
	newtable
where
	cnt > 1
;