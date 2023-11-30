SELECT t1.stock_name,-t1.capital_gain_loss+t2.capital_gain_loss as capital_gain_loss

FROM(
SELECT stock_name,SUM(price) as capital_gain_loss
FROM Stocks WHERE operation='Buy'
GROUP BY stock_name) as t1
LEFT JOIN (
SELECT stock_name,SUM(price) as capital_gain_loss
FROM Stocks WHERE operation='Sell'
GROUP BY stock_name) as t2 on t1.stock_name=t2.stock_name
