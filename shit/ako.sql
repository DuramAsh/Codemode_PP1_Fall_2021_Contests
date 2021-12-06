CREATE TABLE person
(
    id         SERIAL PRIMARY KEY,
    first_name VARCHAR(20) NOT NULL,
    last_name  VARCHAR(20) NOT NULL
);

INSERT INTO person
VALUES (16592, 'John', 'Smith');
INSERT INTO person
VALUES (44815, 'Akmaral', 'Tazhiyeva');
INSERT INTO person
VALUES (52082, 'Olula', 'Kanatova');
INSERT INTO person
VALUES (77780, 'Damir', 'Erzhigitov');
INSERT INTO person
VALUES (97824, 'Merei', 'Inirbay');

CREATE TABLE person_info
(
    id            SERIAL PRIMARY KEY REFERENCES person (id),
    date_of_birth DATE        NOT NULL,
    email         VARCHAR,
    country       VARCHAR(20) NOT NULL,
    city          VARCHAR(20) NOT NULL,
    street        VARCHAR(20),
    flat          INTEGER
);

INSERT INTO person_info
VALUES (16592, '1994-05-23', 'johnny.94@icloud.com', 'USA', 'California', 'Racer', 213);
INSERT INTO person_info
VALUES (44815, '2002-12-30', 'ako228@gmail.com', 'KZ', 'Talgar', 'Shelk', 37);
INSERT INTO person_info
VALUES (52082, '2002-12-19', 'akula_xXx@mail.ru', 'KZ', 'Taldyqorgan', 'RB', 55);
INSERT INTO person_info
VALUES (77780, '2003-11-23', 'd_erzhigitov@kbtu.kz', 'Thailand', 'Bangkok', 'Transov', 69);
INSERT INTO person_info
VALUES (97824, '2003-01-04', 'mereykatazik@bk.ru', 'KZ', 'Talgar', 'Shelk', 38);

CREATE TABLE account
(
    number    VARCHAR(20) PRIMARY KEY,
    person_id INTEGER REFERENCES person (id),
    cur_bal   NUMERIC NOT NULL,
    fee       NUMERIC NOT NULL
);

INSERT INTO account
VALUES ('KZ392870', 16592, 75071, 79821);
INSERT INTO account
VALUES ('US564941', 77780, 92983, 85371);

CREATE TABLE online
(
    id                    INTEGER PRIMARY KEY REFERENCES person (id),
    receive_notifications BOOLEAN NOT NULL
);

INSERT INTO online
VALUES (44815, true);
INSERT INTO online
VALUES (52082, true);
INSERT INTO online
VALUES (97824, false);

CREATE TABLE credit_card
(
    number        VARCHAR(16) PRIMARY KEY,
    onl_person_id INTEGER REFERENCES online (id),
    expires       DATE    NOT NULL,
    cvv           INTEGER NOT NULL
);

INSERT INTO credit_card
VALUES ('7326312191311617', 44815, '2024-09-21', 354);
INSERT INTO credit_card
VALUES ('3693464832804125', 52082, '2024-04-13', 946);
INSERT INTO credit_card
VALUES ('4731777467022708', 97824, '2024-05-26', 816);

CREATE TABLE in_store
(
    id INTEGER PRIMARY KEY REFERENCES person (id)
);

INSERT INTO in_store
VALUES (16592);
INSERT INTO in_store
VALUES (77780);

CREATE TABLE product
(
    id           SERIAL PRIMARY KEY,
    title        VARCHAR NOT NULL,
    type         VARCHAR NOT NULL,
    manufacturer VARCHAR NOT NULL,
    cost         NUMERIC NOT NULL
);

INSERT INTO product
VALUES (77824, 'iPhone 13', 'Smartphone', 'Apple', 450000);
INSERT INTO product
VALUES (49337, 'GFX 2000', 'Freezer', 'LG', 700000);
INSERT INTO product
VALUES (23959, 'AirBuds3', 'Accessories', 'Xiaomi', 15000);
INSERT INTO product
VALUES (47592, 'Mibro Air', 'Watches', 'Xiaomi', 21000);
INSERT INTO product
VALUES (44345, 'Zenbook X', 'Laptop', 'Asus', 320000);
INSERT INTO product
VALUES (46324, 'Bloody V7', 'Mouse', 'A4Tech', 8000);
INSERT INTO product
VALUES (34410, 'Nord 9R', 'Smartphone', 'OnePlus', 250000);
INSERT INTO product
VALUES (12934, 'Galaxy S21', 'Smartphone', 'Samsung', 390000);
INSERT INTO product
VALUES (42354, '100851', 'Watches', 'ARRIS', 80000);
INSERT INTO product
VALUES (65165, 'Nitro V', 'Laptop', 'Acer', 410000);

CREATE TABLE package
(
    id              SERIAL PRIMARY KEY,
    recipient_id    INTEGER NOT NULL REFERENCES online (id),
    tracking_number NUMERIC NOT NULL,
    total_cost      NUMERIC NOT NULL,
    delivered       BOOLEAN NOT NULL,
    send_date       DATE    NOT NULL,
    est_deliv_date  DATE    NOT NULL,
    deliv_date      DATE    NOT NULL
);

INSERT INTO package
VALUES (354415, 44815, 72996723, 700000, false, '2020-12-30', '2021-01-10', '2022-01-10');
INSERT INTO package
VALUES (310966, 52082, 67443609, 328000, true, '2020-02-19', '2020-03-01', '2020-02-28');
INSERT INTO package
VALUES (324686, 97824, 16806985, 450000, true, '2021-09-26', '2021-10-06', '2021-10-02');
INSERT INTO package
VALUES (562284, 44815, 76939480, 15000, true, '2020-07-14', '2020-07-24', '2020-07-24');
INSERT INTO package
VALUES (582014, 44815, 87736393, 7000000, true, '2021-04-12', '2021-04-22', '2021-04-25');

CREATE TABLE package_product
(
    prod_id    INTEGER NOT NULL REFERENCES product (id),
    package_id INTEGER NOT NULL REFERENCES package (id),
    amount     INTEGER NOT NULL,
    PRIMARY KEY (prod_id, package_id)
);

INSERT INTO package_product
VALUES (77824, 354415, 1);
INSERT INTO package_product
VALUES (34410, 354415, 1);
INSERT INTO package_product
VALUES (44345, 310966, 1);
INSERT INTO package_product
VALUES (46324, 310966, 1);
INSERT INTO package_product
VALUES (77824, 324686, 1);
INSERT INTO package_product
VALUES (23959, 562284, 1);
INSERT INTO package_product
VALUES (49337, 582014, 10);

CREATE TABLE warehouse
(
    id      SERIAL PRIMARY KEY,
    country VARCHAR NOT NULL,
    city    VARCHAR NOT NULL,
    street  VARCHAR NOT NULL,
    num     INTEGER NOT NULL
);

INSERT INTO warehouse
VALUES (2022, 'USA', 'California', 'Gangbang', 12);
INSERT INTO warehouse
VALUES (6820, 'KZ', 'Almaty', 'Koktem-1', 41);

CREATE TABLE store_product_warehouse
(
    prod_id      INTEGER NOT NULL REFERENCES product (id),
    store_id     INTEGER NOT NULL REFERENCES store (id),
    warehouse_id INTEGER NOT NULL REFERENCES warehouse (id),
    amount       INTEGER NOT NULL,
    PRIMARY KEY (prod_id, store_id, warehouse_id)
);

INSERT INTO store_product_warehouse
VALUES (77824, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (49337, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (23959, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (47592, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (44345, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (46324, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (34410, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (12934, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (42354, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (65165, 7624, 6820, 1000);
INSERT INTO store_product_warehouse
VALUES (34410, 5515, 6820, 100);
INSERT INTO store_product_warehouse
VALUES (12934, 5515, 6820, 100);
INSERT INTO store_product_warehouse
VALUES (42354, 5515, 6820, 100);
INSERT INTO store_product_warehouse
VALUES (65165, 5515, 6820, 100);
INSERT INTO store_product_warehouse
VALUES (77824, 7624, 2022, 0);
INSERT INTO store_product_warehouse
VALUES (49337, 7624, 2022, 1);
INSERT INTO store_product_warehouse
VALUES (23959, 7624, 2022, 0);
INSERT INTO store_product_warehouse
VALUES (47592, 7624, 2022, 1);
INSERT INTO store_product_warehouse
VALUES (44345, 7624, 2022, 213);
INSERT INTO store_product_warehouse
VALUES (46324, 7624, 2022, 321);
INSERT INTO store_product_warehouse
VALUES (34410, 7624, 2022, 542);
INSERT INTO store_product_warehouse
VALUES (12934, 7624, 2022, 413);
INSERT INTO store_product_warehouse
VALUES (42354, 7624, 2022, 12);
INSERT INTO store_product_warehouse
VALUES (65165, 7624, 2022, 0);

CREATE TABLE store
(
    id      SERIAL PRIMARY KEY,
    title   VARCHAR NOT NULL,
    country VARCHAR NOT NULL,
    city    VARCHAR NOT NULL,
    street  VARCHAR NOT NULL,
    num     INTEGER NOT NULL,
    owner   VARCHAR NOT NULL
);

INSERT INTO store
VALUES (8974, 'Amazon', 'USA', 'California', 'Justice', 213, 'Brad Pitt');
INSERT INTO store
VALUES (7624, 'Sulpak', 'KZ', 'Almaty', 'Auezova', 99, 'Nazeek');
INSERT INTO store
VALUES (5515, 'Kuanyshbek', 'KZ', 'Almaty', 'Tole Bi', 59, 'Kuanyshbek Abdurazak');

CREATE TABLE sale
(
    store_id           INTEGER   NOT NULL REFERENCES store (id),
    in_store_client_id INTEGER   NOT NULL REFERENCES in_store (id),
    time_of_deal       TIMESTAMP NOT NULL,
    bought_product     INTEGER   NOT NULL REFERENCES product (id),
    amount             INTEGER   NOT NULL,
    cost               NUMERIC   NOT NULL,
    PRIMARY KEY (store_id, in_store_client_id, time_of_deal, bought_product)
);

INSERT INTO sale
VALUES (8974, 16592, '2021-12-02', 77824, 1, 450000);
INSERT INTO sale
VALUES (8974, 16592, '2021-12-03', 77824, 2, 900000);
INSERT INTO sale
VALUES (7624, 77780, '2021-08-31', 65165, 1, 410000);
INSERT INTO sale
VALUES (5515, 77780, '2021-09-01', 46324, 1, 8000);

SELECT first_name, last_name, package.tracking_number, product.title, package_product.amount
FROM person
         INNER JOIN online ON person.id = online.id
         INNER JOIN package ON online.id = package.recipient_id
         INNER JOIN package_product ON package.id = package_product.package_id
         INNER JOIN product ON package_product.prod_id = product.id;

SELECT first_name, last_name, sum(package.total_cost) sum
FROM person
         INNER JOIN online ON person.id = online.id
         INNER JOIN package ON online.id = package.recipient_id
GROUP BY person.id
ORDER BY sum DESC
LIMIT 1;

SELECT first_name, last_name, sum(sale.cost) sum
FROM person
         INNER JOIN in_store ON person.id = in_store.id
         INNER JOIN sale ON in_store.id = sale.in_store_client_id
GROUP BY person.id
ORDER BY sum DESC
LIMIT 1;

SELECT product.title, product.type, product.manufacturer, sum(product.cost * package_product.amount) c
FROM product
         INNER JOIN package_product ON product.id = package_product.prod_id
         INNER JOIN package ON package_product.package_id = package.id
GROUP BY product.id
ORDER BY c DESC
LIMIT 2;

SELECT product.title, product.type, product.manufacturer, sum(product.cost * sale.amount) c
FROM product
         INNER JOIN sale ON product.id = sale.bought_product
         INNER JOIN in_store ON sale.in_store_client_id = in_store.id
GROUP BY product.id
ORDER BY c DESC
LIMIT 2;

SELECT product.title, product.type, product.manufacturer, (count(product.id) * package_product.amount) c
FROM product
         INNER JOIN package_product ON product.id = package_product.prod_id
         INNER JOIN package ON package_product.package_id = package.id
GROUP BY product.id, package_product.amount
ORDER BY c DESC
LIMIT 2;
CREATE VIEW a AS
SELECT product.title, product.type, product.manufacturer, sum(sale.amount) c
FROM product
         INNER JOIN sale ON product.id = sale.bought_product
         INNER JOIN in_store ON sale.in_store_client_id = in_store.id
GROUP BY product.id, sale.amount
ORDER BY c DESC;

SELECT title, type, manufacturer, sum(c) s
FROM a
GROUP BY title, type, manufacturer
ORDER BY s DESC
LIMIT 2;

SELECT product.title, product.type, product.manufacturer, warehouse.city
FROM product
         INNER JOIN store_product_warehouse ON product.id = store_product_warehouse.prod_id
         INNER JOIN warehouse ON store_product_warehouse.warehouse_id = warehouse.id
WHERE warehouse.city = 'California'
  AND store_product_warehouse.amount = 0;

SELECT id, recipient_id, tracking_number, total_cost
FROM package
WHERE est_deliv_date < deliv_date;

SELECT first_name,
       last_name,
       product.title,
       product.cost,
       sale.amount,
       sale.time_of_deal,
       sum(product.cost * sale.amount) sum
FROM person
         INNER JOIN in_store ON person.id = in_store.id
         INNER JOIN sale ON in_store.id = sale.in_store_client_id
         INNER JOIN product ON sale.bought_product = product.id
WHERE date_part('month', sale.time_of_deal) = 12
GROUP BY person.id, product.id, sale.amount, sale.time_of_deal;

SELECT first_name,
       last_name,
       product.title,
       product.cost,
       package_product.amount,
       send_date,
       sum(product.cost * package_product.amount) sum
FROM person
         INNER JOIN online ON person.id = online.id
         INNER JOIN package ON online.id = package.recipient_id
         INNER JOIN package_product ON package.id = package_product.package_id
         INNER JOIN product ON package_product.prod_id = product.id
WHERE date_part('month', send_date) = 12
GROUP BY person.id, product.id, package_product.amount, package.send_date;