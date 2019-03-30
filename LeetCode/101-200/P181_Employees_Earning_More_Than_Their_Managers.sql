# https://leetcode.com/problems/employees-earning-more-than-their-managers/description/
# 找出 employee 中比自己的 leader 的 salary 要高的人的名字
# 参考思路 https://leetcode.com/problems/employees-earning-more-than-their-managers/solution

select a.name as 'Employee' from employee as a, employee as b
where a.managerid = b.id and a.salary > b.salary
