##### Find all makers that do not make laptops or printers.



SELECT DISTINCT maker FROM Product EXCEPT SELECT DISTINCT maker FROM Product WHERE type='printer' or type='laptop'





##### Find the manufacturers who sell two or more models of PC.



SELECT DISTINCT P1.maker FROM Product as P1, Product as P2 

WHERE P1.maker=P2.maker

AND P1.type='pc' AND P1.type='pc'

AND p1.model!=P2.model



##### Find all makers that sell PC’s or Laptop’s with at least 2 Gb of ram.



SELECT DISTINCT maker FROM Product as P, (SELECT model FROM Laptop WHERE ram >= 2048 UNION SELECT model FROM PC WHERE ram >= 2048) as D WHERE P.model=D.model ORDER BY maker



##### Find the model with the highest price.



SELECT DISTINCT p1.price FROM PC AS p1, PC AS p2 WHERE p1.price > p2.price ORDER BY p1.price DESC

