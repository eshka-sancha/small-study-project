-- использование UNIUON с условием --
SELECT * FROM client WHERE id_client < 5
UNION
SELECT * FROM client WHERE name = 'Антон'
ORDER BY id_client;

-- использование UNIUON ALL с условием --
SELECT * FROM client WHERE id_client < 5
UNION ALL
SELECT * FROM client WHERE name = 'Антон'
ORDER BY id_client;

-- использование INTERSECT с условием --
SELECT * FROM item WHERE id_item < 3
INTERSECT
SELECT * FROM item WHERE id_item < 5
ORDER BY id_item;

-- использование EXCEPT с условием --
SELECT * FROM client WHERE id_client < 10
EXCEPT
SELECT * FROM client WHERE id_client > 3
ORDER BY id_client;

-- использование CROSS JOIN с условием --
SELECT * FROM client CROSS JOIN item WHERE client.id_client < 3 AND item.id_item <= 2;

-- использование JOIN ON с условием --
SELECT buy.id_client, client.name AS client_name, client.addres AS city, buy.id_item, item.name_item AS item_name FROM client
JOIN buy ON client.id_client = buy.id_client 
JOIN item ON item.id_item = buy.id_item;

-- обновление таблицы покупок данными из таблиц "клиенты" и "товары" с условием --
UPDATE buy SET name_client = client.name,
			   yearr = client.birthdate,
			   city = client.addres,
			   name_item = item.name_item
FROM client, item
WHERE buy.id_client = client.id_client AND buy.id_item = item.id_item;

-- добавление к таблице покупок нового столбца --
ALTER TABLE buy ADD column count_item INT DEFAULT 1;

-- запрос для вывода таблицы покупок с группировкой по купленным товарам --
SELECT SUM(id_client)/COUNT(id_client), name_client, name_item, SUM(count_item) FROM buy
GROUP BY name_item, name_client
ORDER BY name_client;

