SELECT postal_code, COUNT(*) AS customers_number 
From customer
GROUP BY postal_code
ORDER BY customers_number DESC