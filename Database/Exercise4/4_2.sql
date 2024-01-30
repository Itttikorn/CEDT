SELECT postal_code, COUNT(*) AS customers_number 
From customer
GROUP BY postal_code
HAVING COUNT(*) > 1
ORDER BY customers_number DESC