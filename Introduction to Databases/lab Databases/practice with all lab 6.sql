create schema if not exists DB;
use DB;
create table if not exists discount(
chapter varchar(45) not null primary key unique,
discounts int not null
);
create table if not exists clients(
number_ac int not null primary key unique auto_increment,
name_c varchar(45) not null
);
create table if not exists goods(
id_g int not null primary key unique,
price int not null,
good varchar(45) not null,
client_g int not null,
discount_chapter varchar(45) not null,
foreign key (discount_chapter) references discount (chapter),
foreign key (client_g) references clients (number_ac)
);

insert into discount values ('перифирия', 10), ('комплектующие пк', 5), ('проф. оборудование', 2);
insert into clients values (101,'Сергей'), (202,'Дмитрий'), (303,'Александр'), (404,'Мария');
insert into goods (id_g, price, good, client_g, discount_chapter) values ('101', '20', 'клавиатура', 101, 'перифирия'), ('202', '40', 'мышь', 202, 'комплектующие пк'), ('303', '50', 'монитор', 303, 'проф. оборудование'), ('404', '100', 'видеокарта', 404, 'перифирия');
SELECT * FROM discount;
SELECT * FROM clients;
SELECT * FROM goods;
SELECT name_c FROM clients;
SELECT goods.*, clients.name_c FROM goods
JOIN clients ON goods.client_g = clients.number_ac;
SELECT goods.*, clients.name_c FROM goods
JOIN clients ON goods.client_g = clients.number_ac
WHERE goods.price > 50;
UPDATE goods SET price = 25 WHERE id_g = 101;
DELETE FROM goods WHERE id_g = 404;
SELECT * FROM discount ORDER BY chapter ASC;
SELECT goods.*, clients.name_c, discount.discounts AS Скидка FROM goods
JOIN clients ON goods.client_g = clients.number_ac
JOIN discount ON goods.discount_chapter = discount.chapter;
SELECT * FROM goods WHERE good IS NOT NULL;
SELECT * FROM goods WHERE good IS NULL;
SELECT SUM(price) AS Общая_сумма FROM goods;
SELECT AVG(price) AS Средняя_цена FROM goods;
SELECT client_g, COUNT(*) AS Количество_заказов FROM goods
GROUP BY client_g;
SELECT client_g, SUM(price) AS Общая_сумма FROM goods
GROUP BY client_g;
UPDATE goods SET discount_chapter = 'перифирия' WHERE id_g = 202;
INSERT INTO clients (name_c) VALUES ('Екатерина');
DELETE FROM clients WHERE name_c = 'Мария';
SELECT * FROM goods WHERE client_g IS NULL;





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






DELIMITER //
CREATE TRIGGER UpdateDiscount
AFTER INSERT ON goods
FOR EACH ROW
BEGIN
    UPDATE goods
    SET discount_chapter = (
        SELECT chapter
        FROM discount
        WHERE NEW.price >= discount.lower_bound
        ORDER BY discount.lower_bound DESC
        LIMIT 1
    )
    WHERE id_g = NEW.id_g;
END //
DELIMITER ;
/* 
Автоматическое обновление категории скидки на товар при добавлении нового товара или изменении его цены.
*/
DELIMITER //
CREATE TRIGGER DeleteClientGoods
AFTER DELETE ON clients
FOR EACH ROW
BEGIN
    DELETE FROM goods
    WHERE client_g = OLD.number_ac;
END //
DELIMITER ;
/* 
Удаление всех товаров клиента при удалении записи о клиенте.
*/
DELIMITER //
CREATE TRIGGER UpdateOrderCount
AFTER INSERT ON goods
FOR EACH ROW
BEGIN
    UPDATE clients
    SET order_count = (
        SELECT COUNT(*)
        FROM goods
        WHERE client_g = NEW.client_g
    )
    WHERE number_ac = NEW.client_g;
END //
DELIMITER ;
/* 
Обновление количества заказов для клиента при добавлении или удалении записи о товаре.
*/





DELIMITER //
CREATE PROCEDURE AddClient(
  clientName VARCHAR(45)
)
BEGIN
  INSERT INTO clients (name_c)
  VALUES (clientName);
END //
DELIMITER ;
/* 
Добавление нового клиента в таблицу "clients".
*/
DELIMITER //
CREATE FUNCTION GetClientOrderCount(
  clientNumber INT
)
RETURNS INT
BEGIN
  DECLARE orderCount INT;
  SELECT order_count INTO orderCount
  FROM clients
  WHERE number_ac = clientNumber;
  RETURN orderCount;
END //
DELIMITER ;
/* 
Получение количества заказов для заданного клиента.
*/

