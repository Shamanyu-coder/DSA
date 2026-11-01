# Write your MySQL query statement below
select 
d.name as department,
e.name as employee,
e.salary as salary 
from employee e
join department d
on e.departmentid =d.id
where(select COUNT(distinct e2.salary)
from employee e2
where e2. departmentid = e.departmentid
and e2.salary>e.salary)<3;