# Criação e seleção da base de dados
CREATE DATABASE bdselecao202421250026;
USE bdselecao202421250026;

# Exibição das bases de dados do servidor
SHOW DATABASES;

# Criação das tabelas 
CREATE TABLE Candidato_funcionario (
	funcionario integer,
    candidato integer,
    dt_indicacao date
);

CREATE TABLE Candidato (
	id_candidato integer,
    nome varchar(60),
    cpf varchar(14)
);

CREATE TABLE Inscricao (
	id_inscricao integer,
    candidato integer,
    cargo integer,
    dt_inscricao date
);

CREATE TABLE Teste (
	id_teste integer,
    processo integer,
    cargo integer,
    inscricao integer,
    dt_teste date
);

CREATE TABLE Cargo (
	id_cargo integer,
    descricao varchar(30)
);

CREATE TABLE Departamento (
	id_depto integer,
    descricao varchar(30)
);

CREATE TABLE Funcionario (
	id_func integer,
    depto integer,
    cargo integer,
    nome varchar(60),
    cpf varchar(14)
);

CREATE TABLE Processo_seletivo (
	id_processo integer,
    descricao varchar(60)
);

# Informações estruturais da tabela
DESCRIBE Candidato_funcionario;
DESC Candidato;
DESC Inscricao;

# Exibição das tabelas presentes na base de dados

SHOW TABLES;




