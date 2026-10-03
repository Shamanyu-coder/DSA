-- # Write your MySQL query statement below
-- select *from employee  where  =max(salary)\
select 
e.name As employee
from employee e
join employee m on e.managerId =m.id
where e.salary>m.salary