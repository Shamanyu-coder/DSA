# Write your MySQL query statement below
select (
    select MAX(distinct  salary)
    from Employee 
    where salary<(select MAX(salary) from Employee)
)AS SecondHighestSalary;

    