# Write your MySQL query statement below
select distinct num as 'ConsecutiveNums'
from logs
where ((id+1, num) in (select id, num from logs)) and ((id+2, num) in (select id, num from logs));