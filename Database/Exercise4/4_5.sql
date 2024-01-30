SELECT c.customer_id, c.customer_name, COUNT(*) AS number_of_orders 
FROM customer c JOIN ordert o
ON c.customer_id = o.customer_id
GROUP BY c.customer_id
ORDER BY COUNT(*) DESC