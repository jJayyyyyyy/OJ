/*
https://leetcode.com/problems/combine-two-tables/description/
从两个表中选出PersonId相同的记录

Solution
https://leetcode.com/problems/combine-two-tables/solution/

join
https://www.w3schools.com/sql/sql_join.asp

*/
# Write your MySQL query statement below
select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId;
