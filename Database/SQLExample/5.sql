SELECT F.NAME,
	SUM(REWARD) AS TOTALREWARD
FROM FRIEND F
JOIN TASKS T ON T.FRIENDID = F.ID
GROUP BY F.ID
ORDER BY TOTALREWARD DESC
LIMIT 5