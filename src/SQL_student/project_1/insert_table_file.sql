-- заполнение таблицы клиентов --
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

-- заполнение таблицы товаров --
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

-- вставка айди клиентов и айди товаров в таблицу покупок --
INSERT INTO buy (id_client, id_item) VALUES (1, 1), (1, 3), 
											(1, 3), (1, 3), (4, 5), 
											(4, 6), (8, 1), 
											(8, 2), (5, 4), (5, 4), (5, 4), (5, 4),
											(6, 8), (3, 2);
