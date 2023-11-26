SELECT prices.product_id,CASE WHEN ROUND(SUM(units*price)/SUM(units),2) IS NULL THEN 0 ELSE ROUND(SUM(units*price)/SUM(units),2) END as average_price
FROM Prices LEFT JOIN UnitsSold on UnitsSold.purchase_date>=Prices.start_date and UnitsSold.purchase_date<=Prices.end_date and UnitsSold.product_id=Prices.product_id
GROUP BY(prices.product_id);
