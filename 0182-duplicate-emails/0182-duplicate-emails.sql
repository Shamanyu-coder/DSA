-- # Write your MySQL query statement below
-- select 
-- email as email
-- from person
-- group by email
-- having count(email)>1;


select distinct 
p1.email as email
from person p1
join person p2
on p1.email =p2 .email
and p1.id<>p2.id;