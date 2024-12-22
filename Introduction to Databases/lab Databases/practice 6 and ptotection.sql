CREATE VIEW DiscountsSummary AS
SELECT discount_chapter, SUM(price) AS TotalPrice
FROM goods
GROUP BY discount_chapter;
/* 
Просмотр общей суммы покупок для каждой категории скидки.
*/
CREATE VIEW HighValueGoods AS
SELECT *
FROM goods
WHERE price > 50;
/* 
Просмотр всех товаров с ценой выше 50.
*/
CREATE VIEW OrdersByClient AS
SELECT client_g, COUNT(*) AS OrderCount
FROM goods
GROUP BY client_g;
/* 
Просмотр количества заказов для каждого клиента.
*/
CREATE VIEW GoodsWithDiscount AS
SELECT goods.*, clients.name_c, discount.discounts AS Скидка
FROM goods
JOIN clients ON goods.client_g = clients.number_ac
JOIN discount ON goods.discount_chapter = discount.chapter;
/* 
Просмотр информации о товарах с примененными скидками и именами клиентов.
*/
