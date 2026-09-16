-- создание таблицы клиентов --
CREATE TABLE client (
	id_client SERIAL PRIMARY KEY,
	name VARCHAR(20),
	birthdate DATE,
	addres VARCHAR(100)
);

-- создание таблицы покупок --
CREATE TABLE item (
	id_item SERIAL PRIMARY KEY,
	name_item VARCHAR(20),
	description VARCHAR(200)
);
