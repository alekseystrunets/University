create schema if not exists DB;
use DB;
create table if not exists teacher(
kod_teacher int not null primary key unique,
kod_kafedru int not null,
name_teacher varchar(45),
indef_kod varchar(45) not null,
dolgnost varchar(255) not null default 'ассистент',
salary decimal(10,2) not null default 1000,
rise decimal(10,2) not null default 0,
birthday  date not null,
tel_teacher varchar(20) not null,
constraint chk_salary check (salary > 0),
constraint chl_dolgnost check (dolgnost in ('профессор','доцент','старший преподаватель','ассистент')),
constraint chk_rise check (rise >= 0),
constraint chk_tel_teacher check (tel_teacher regexp '[1-9][0-9][0-9][0-9][0-9][0-9]')
);
insert into teacher (kod_teacher,kod_kafedru,name_teacher,indef_kod,dolgnost,salary,rise,birthday,tel_teacher)
values (1,1,'Струнец','1g5k4d','профессор',5000,1000,'1980-07-05','1234567');