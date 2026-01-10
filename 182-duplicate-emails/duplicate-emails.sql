# Write your MySQL query statement below
select DISTINCT email as Email from person p1 where
    1 < (select count(*) from person p2 where p2.email=p1.email);