SELECT c.customer_id, c.customer_name
FROM customer c
WHERE NOT EXISTS (
	SELECT *
    FROM ordert o
    WHERE o.CUSTOMER_ID = c.CUSTOMER_ID
)
ORDER BY c.customer_id ASC