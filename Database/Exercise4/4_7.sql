SELECT P.product_id, P.product_description
FROM product P JOIN order_line O
ON O.product_id = P.product_id
GROUP BY P.product_id HAVING SUM(o.ordered_quantity) >= ALL(
	SELECT SUM(o.ordered_quantity)
	FROM product P JOIN order_line O
	ON O.product_id = P.product_id
	GROUP BY P.product_id
)