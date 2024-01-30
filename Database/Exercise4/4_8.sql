SELECT c.customer_id, c.customer_name, COUNT(*) AS order_count
FROM customer c JOIN ordert o
ON c.customer_id = o.customer_id
GROUP BY c.customer_id
ORDER BY COUNT(*) DESC LIMIT 3