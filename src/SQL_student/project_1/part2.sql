DROP TABLE IF EXISTS client;
DROP TABLE IF EXISTS item;
DROP TABLE IF EXISTS buy;
CREATE TABLE client (
	id_client SERIAL PRIMARY KEY,
	name VARCHAR(20),
	birthdate DATE,
	addres VARCHAR(100)
);

CREATE TABLE item (
	id_item SERIAL PRIMARY KEY,
	name_item VARCHAR(20),
	description VARCHAR(200)
);

INSERT INTO client(name, birthdate, addres)
VALUES ('Anna', '2000-11-09', 'Moscow'), 
		('Boris', '1998-01-30', 'Saint Petersburg'), 
		('Anton B', '1998-02-23', 'Moscow'), 
		('Nadezhda', '2002-04-30', 'Samara'), 
		('Anton A', '2005-01-06', 'Ulyanovsk'), 
		('Anton S', '2006-12-14', 'Saint Petersburg'), 
		('Ivan', '1970-07-12', 'Noyabrsk'), 
		('Alexandra', '2005-04-30', 'Novosibirsk'), 
		('Anton G', '1998-02-23', 'Moscow'),
		('Angelina', '1999-11-11', 'Saint Petersburg');
		
INSERT INTO item(name_item, description)
VALUES ('hand cream', 'moisturizing hand cream with aloe and collagen'), 
		('3-in-1 shampoo', 'moisturizing, growth-promoting shampoo with mint scent. suitable for body and face'), 
		('3-in-1 shampoo', 'moisturizing, growth-promoting shampoo with mint scent. suitable for body and face'), 
		('hand cream', 'moisturizing hand cream with aloe and collagen'), 
		('laundry soap', 'ordinary soap. pH level 8.5 - 12'), 
		('laundry detergent', 'powder for white clothes, whitening'), 
		('hair spray', 'strong-hold hair spray for thick hair'), 
		('face toner', 'cleansing product with low pH. for all skin types'), 
		('laundry soap', 'ordinary soap. pH level 8.5 - 12'),
		('nail polishes', 'set of gel polishes, 3 colors');

--SELECT * FROM client WHERE id_client < 5
--UNION ALL
--SELECT * FROM client WHERE name = 'Антон'
--ORDER BY id_client;

--SELECT * FROM item WHERE id_item < 3
--INTERSECT
--SELECT * FROM item WHERE id_item < 5
--ORDER BY id_item;

--SELECT * FROM client WHERE id_client < 10
--EXCEPT
--SELECT * FROM client WHERE id_client > 3
--ORDER BY id_client;

--SELECT * FROM client CROSS JOIN item WHERE client.id_client < 3 AND item.id_item <= 2;

CREATE TABLE buy (
	id_client INT,
	id_item INT,
	name_client VARCHAR(20),
	yearr DATE,
	city VARCHAR(30),
	name_item VARCHAR(20)
);

INSERT INTO buy (id_client, id_item) VALUES (1, 1), (1, 3), 
											(1, 3), (1, 3), (4, 5), 
											(4, 6), (8, 1), 
											(8, 2), (5, 4), (5, 4), (5, 4), (5, 4),
											(6, 8), (3, 2);
						
--SELECT buy.id_client, client.name AS client_name, client.addres AS city, buy.id_item, item.name_item AS item_name FROM client
--JOIN buy ON client.id_client = buy.id_client 
--JOIN item ON item.id_item = buy.id_item;

UPDATE buy SET name_client = client.name,
			   yearr = client.birthdate,
			   city = client.addres,
			   name_item = item.name_item
FROM client, item
WHERE buy.id_client = client.id_client AND buy.id_item = item.id_item;

ALTER TABLE buy ADD column count_item INT DEFAULT 1;

SELECT SUM(id_client)/COUNT(id_client), name_client, name_item, SUM(count_item) FROM buy
GROUP BY name_item, name_client
ORDER BY name_client;

