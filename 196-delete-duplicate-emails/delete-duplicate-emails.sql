# Write your MySQL query statement below
delete from person where id not in(
select id from( select id, email, Row_number() over(partition by email order by id ) as rn
from Person ) as p where rn=1);
