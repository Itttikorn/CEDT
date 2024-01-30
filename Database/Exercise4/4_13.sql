SELECT SUM(p.standard_price * ol.ordered_quantity) AS total_payment
FROM order_line ol JOIN product p
ON ol.product_id = p.product_id
WHERE ol.order_id = 3