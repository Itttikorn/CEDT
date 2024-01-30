SELECT pr.product_id, pr.product_description
FROM product pr JOIN order_line ol
ON pr.product_id = ol.product_id
GROUP BY pr.product_id
HAVING COUNT(*) = (
	SELECT MAX(C) FROM (
		SELECT COUNT(ol.order_id) AS C
        FROM product pr
        JOIN order_line ol ON pr.product_id = ol.product_id
        GROUP BY pr.product_id
	)
)