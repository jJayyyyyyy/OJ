# https://leetcode.com/problems/second-highest-salary/description
# 找出第二高的工资
# 参考答案: https://leetcode.com/problems/second-highest-salary/solution/

select
	ifnull
	(
		(select distinct Salary from Employee order by Salary desc limit 1 offset 1),
		null
	)
as
	SecondHighestSalary