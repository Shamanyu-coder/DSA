# Write your MySQL query statement below
select
department.name as department,
employee.name as employee,
employee.salary as salary
 from employee
 join department
  on employee.departmentid= department.id
where (employee.departmentid, employee.salary) in (select departmentid,max(salary)
 from employee group by departmentid);