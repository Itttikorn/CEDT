 CREATE OR REPLACE FUNCTION get_branches_assets_greater_than(con NUMERIC)
 RETURNS TABLE (
 	branch_name VARCHAR,
	 branch_city VARCHAR,
	 assets NUMERIC
 )
 LANGUAGE plpgsql
 AS
 $$
 BEGIN
 	RETURN query
	SELECT B.branch_name, B.branch_city, B.assets
	FROM branch B
	WHERE B.assets > con;
END;
$$

 select * from get_branches_assets_greater_than(100);