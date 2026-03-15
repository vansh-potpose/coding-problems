# Write your MySQL query statement below
-- select score, Rank() Over (order by score desc) as rank  from Scores;

-- SELECT score, RANK() OVER (ORDER BY score DESC) rank
-- FROM Scores;

SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) as `rank`
FROM Scores;