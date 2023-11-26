SELECT gf.product_id,product_name 
FROM  (
    SELECT MAX(sale_date) as mx ,MIN(sale_date) as mn ,Product.product_id,Product.product_name
FROM Product join Sales on Product.product_id=Sales.product_id
GROUP BY Product.product_id
) as gf
WHERE gf.mx<="2019-03-31" and mn>="2019-01-01";
