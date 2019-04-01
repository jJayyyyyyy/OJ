# Table: Customers
# +----+-------+
# | Id | Name  |
# +----+-------+
# | 1  | Joe   |
# | 2  | Henry |
# | 3  | Sam   |
# | 4  | Max   |
# +----+-------+
# 
# Table: Orders
# +----+------------+
# | Id | CustomerId |
# +----+------------+
# | 1  | 3          |
# | 2  | 1          |
# +----+------------+
#
# Table: Answer
# +-----------+
# | Customers |
# +-----------+
# | Henry     |
# | Max       |
# +-----------+
#
# 从 Customers 找出没有出现在 Orders 中的 Customers.Name
# 参考答案
# https://leetcode.com/problems/customers-who-never-order/solution/
# 参考链接 
# Every derived table must have its own alias
# https://stackoverflow.com/questions/1888779/what-is-the-error-every-derived-table-must-have-its-own-alias-in-mysql
# 连续的select, 要给选出来的 table 起个别名, 比如 newtable
# select xxx from (select yyy from mytable) as newtable


# Solution1
select customers.name as 'Customers'
from customers
where customers.id not in
(
	select customerid from orders
)

# where ... in ... 后接 select 的时候 不需要别名


# Solution2
select name as 'Customers'
from
(
	select id, name
	from customers
	where id not in
	(
		select customerid from orders
	)
)
as new_table