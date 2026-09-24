# Write your MySQL query statement belo
select Score, dense_rank() over (order by score desc) As 'rank' from Scores;