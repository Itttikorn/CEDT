SELECT COUNT(*) as total_orders
FROM ordert o
WHERE DATE(o.order_date) >= '2020-01-10' and DATE(o.order_date) <= '2020-01-15'