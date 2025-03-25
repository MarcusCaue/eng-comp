DROP DATABASE IF EXISTS formula_01;
CREATE DATABASE formula_01;
USE formula_01;

create table equipe(
  id int primary key,
  nome varchar(30),
  pais int	
);

create table piloto(
  id int primary key,
  nome varchar(40),
  equipe int ,
  pais int
);

create table pais(
  id int primary key,
  nome varchar(30)	
);

create table circuito(
  id int primary key,
  nome varchar(30),
  pais int	
);

create table prova(
  id int primary key,
  data date,
  circuito int	
);

create table piloto_pos(
  prova int,
  piloto int,
  posicao int
);

ALTER TABLE piloto ADD CONSTRAINT FK_pe FOREIGN KEY (equipe) REFERENCES equipe (id);
ALTER TABLE equipe ADD CONSTRAINT FK_ep FOREIGN KEY (pais) REFERENCES pais (id);
ALTER TABLE circuito ADD CONSTRAINT FK_cp FOREIGN KEY (pais) REFERENCES pais (id);
ALTER TABLE prova ADD CONSTRAINT FK_pc FOREIGN KEY (circuito) REFERENCES circuito (id);
ALTER TABLE piloto_pos ADD CONSTRAINT FK_pp FOREIGN KEY (prova) REFERENCES prova (id);
ALTER TABLE piloto_pos ADD CONSTRAINT FK_pp2 FOREIGN KEY (piloto) REFERENCES piloto (id);
ALTER TABLE piloto ADD CONSTRAINT FK_pe2 FOREIGN KEY (pais) REFERENCES pais (id);
ALTER TABLE piloto_pos ADD PRIMARY KEY (prova, piloto);



insert into pais values (1,'Brasil'),(2,'Argentina'),(3,'Alemanha'),(4,'Inglaterra'),(5,'Italia'),(6,'Finlandia'),(7,'Suiça')
,(8,'Canadá'),(9,'Dinamarca'),(10,'Australia'), (11,'Holanda'),(12,'Mexico'),(13,'França'),(14,'Espanha');
insert into pais values (15,'Austria');
insert into pais values (16,'Reino Unido');
insert into pais values (17,'Estados Unidos');
insert into pais values (18,'Emirados ÁArabes Unidos');
insert into pais values (19,'Arabia Saudita');
insert into pais values (20,'Catar');
insert into pais values (21,'Turquia');
insert into pais values (22,'Belgica');
select * from pais;

insert into equipe values (1,'Red Bull Racing',15),(2,'McLaren',16),(3,'Aston Martin Racing',16),(4,'Williams',16),(5,'Haas F1 Team',17),(6,'AlphaTauri',5),(7,'Alpine',13)
,(8,'Ferrari',5),(9,'Alfa Romeo',5),(10,'Mercedes',3);
select * from equipe;

insert into piloto values (1,'Max Verstappen',1,11),(2,'Daniel Ricciardo',2,10),(3,'Lando Norris',2,16),(4,'Sebastian Vettel',3,3),(5,'Nicholas Latifi',4,8),(6,'Kevin Magnussen',5,9),(7,'Pierre Gasly',6,13)
,(8,'Fernando Alonso',7,14),(9,'Sergio Perez',1,12),(10,'Lance Stroll',3,8), (11,'Carlos Sainz Jr.',8,14),(12,'Lewis Hamilton',10,16),(13,'Valtteri Bottas',9,6),(14,'Mick Schumacher',5,3);
select * from piloto;

insert into circuito values (1,'GP de Abu Dhabi',18);
insert into circuito values(2,'GP da Arabia Saudita',19);
insert into circuito values(3,'GP do Catar',20);
insert into circuito values(4,'GP do Brasil',1);
insert into circuito values (5,'GP do Mexico',12);
insert into circuito values(6,'GP dos EUA',17);
insert into circuito values(7,'GP da Turquia',21);
insert into circuito values(8,'GP da Italia',5),(9,'GP da Holanda',11),(10,'GP da Belgica',22);
select * from circuito;

insert into prova values (1,'2023-12-12',1);
insert into prova values (2,'2023-12-05',2), (3,'2023-11-21',3),(4,'2021-11-14',4),(5,'2023-11-07',5),(6,'2023-10-24',6),(7,'2023-10-10',7),(8,'2023-09-12',8),(9,'2023-09-05',9),
(10,'2023-08-29',10);
select * from prova;

insert into piloto_pos values(1,1,1);
insert into piloto_pos values(1,11,2);
insert into piloto_pos values(1,12,3);
insert into piloto_pos values(1,10,4);
insert into piloto_pos values(1,4,5);
insert into piloto_pos values(2,12,1);
insert into piloto_pos values(2,1,2);
insert into piloto_pos values(2,13,3);
insert into piloto_pos values(2,11,4);
insert into piloto_pos values(2,14,5);
insert into piloto_pos values(3,12,1);
insert into piloto_pos values(3,1,2);
insert into piloto_pos values(3,8,3);
insert into piloto_pos values(3,5,4);
insert into piloto_pos values(3,6,5);
insert into piloto_pos values(4,12,1);
insert into piloto_pos values(4,1,2);
insert into piloto_pos values(4,13,3);
insert into piloto_pos values(4,11,4);
insert into piloto_pos values(4,2,5);
insert into piloto_pos values(5,1,1);
insert into piloto_pos values(5,12,2);
insert into piloto_pos values(5,9,3);
insert into piloto_pos values(5,8,4);
insert into piloto_pos values(5,7,5);
insert into piloto_pos values(6,1,1);
insert into piloto_pos values(6,12,2);
insert into piloto_pos values(6,9,3);
insert into piloto_pos values(6,7,4);
insert into piloto_pos values(6,8,5);
insert into piloto_pos values(7,13,1);
insert into piloto_pos values(7,1,2);
insert into piloto_pos values(7,12,3);
insert into piloto_pos values(7,2,4);
insert into piloto_pos values(7,7,5);
insert into piloto_pos values(8,2,1);
insert into piloto_pos values(8,3,2);
insert into piloto_pos values(8,13,3);
insert into piloto_pos values(8,14,4);
insert into piloto_pos values(8,7,5);
insert into piloto_pos values(9,1,1);
insert into piloto_pos values(9,12,2);
insert into piloto_pos values(9,13,3);
insert into piloto_pos values(9,2,4);
insert into piloto_pos values(9,4,5);
insert into piloto_pos values(10,1,1);
insert into piloto_pos values(10,12,2);
insert into piloto_pos values(10,5,3);
insert into piloto_pos values(10,3,4);
insert into piloto_pos values(10,6,5);

select * from piloto_pos;