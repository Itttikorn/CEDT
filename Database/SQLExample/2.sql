SELECT NAME,
	MONEY
FROM TRAINER
GROUP BY ID
HAVING MONEY >
	(SELECT AVG(MONEY)
		FROM TRAINER)