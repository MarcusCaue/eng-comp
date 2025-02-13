create table empregado (
 idemp integer PRIMARY KEY, 
 nome varchar(20) NOT NULL, 
 secao integer NOT NULL, 
 cargo varchar(15) NOT NULL, 
 chefe integer, 
 salario decimal(7,2) NOT NULL,
 comissao decimal(7,2) NOT NULL
);

create table secao (
 idsec integer PRIMARY KEY, 
 nome varchar(20) NOT NULL, 
 cidade varchar(20) NOT NULL
);

alter table empregado add constraint foreign key (secao) references secao(idsec);

alter table empregado add constraint foreign key (chefe) references empregado (idemp);

insert secao values (10, 'Fabrica', 'Recife'),(20, 'Comercial', 'Recife'), (30, 'Marketing', 'Campina Grande'), (40, 'Planejamento', 'João Pessoa'), (50, 'Administração', 'Recife'), (60, 'Informática', 'Campina Grande'), (70, 'Recursos Humanos', 'João Pessoa')

insert empregado values (3, 'Álvaro Dias', 50, 'Administrador', NULL, 2500, 0);
insert empregado values (1, 'Ana Paula', 10, 'Programador', 3, 3000, 10); 
insert empregado values (2, 'Gustavo Henrique', 70, 'Engenheiro', 1, 2500, 50); 
insert empregado values (4, 'Antônio Carlos', 10, 'Engenheiro', 3, 2400, 20);  
insert empregado values (5, 'Susana Silva', 20, 'Administrador', NULL, 2750, 30);
insert empregado values (6, 'Cláudio José', 60, 'Vendedor', 4, 1000, 50);  




