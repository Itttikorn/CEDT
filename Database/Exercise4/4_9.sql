SELECT c.customer_id, c.customer_name
FROM customer c JOIN ordert o
ON c.customer_id = o.customer_id
WHERE DATE(o.order_date) >= '2020-01-10' and DATE(o.order_date) <= '2020-01-15'
GROUP BY c.customer_id