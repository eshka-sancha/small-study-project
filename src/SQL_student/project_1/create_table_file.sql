-- создание таблицы клиентов --
CREATE TABLE client (
	id_client SERIAL PRIMARY KEY,
	name VARCHAR(20),
	birthdate DATE,
	addres VARCHAR(100)
);

-- создание таблицы товаров --
CREATE TABLE item (
	id_item SERIAL PRIMARY KEY,
	name_item VARCHAR(20),
	description VARCHAR(200)
);

-- создание таблицы покупок товаров клиентами --
CREATE TABLE buy (
	id_client INT,
	id_item INT,
	name_client VARCHAR(20),
	yearr DATE,
	city VARCHAR(30),
	name_item VARCHAR(20)
);
