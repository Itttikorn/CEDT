SELECT product_id, product_description, product_finish
FROM product
WHERE CAST(product_finish AS VARCHAR) LIKE '%white%'