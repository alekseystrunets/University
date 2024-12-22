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
insert into goods values (101, 20, 'клавиатура', 'перифирия'), (202, 40, 'мышь', 'перифирия'), (303, 50, 'монитор', 'комплектующие пк'), (404, 100, 'видеокарта', 'комплектующие пк'); 
insert into clients (name_c, goods_id) values ('Сергей', 101), ('Дмитрий', 202), ('Александр', 303), ('Мария', 404);