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