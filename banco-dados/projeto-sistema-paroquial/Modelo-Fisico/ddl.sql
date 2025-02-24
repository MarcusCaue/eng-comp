DROP DATABASE IF EXISTS paroquia_sancte_ioseph;

CREATE DATABASE paroquia_sancte_ioseph;
USE paroquia_sancte_ioseph;

-- Criação das tabelas das entidades

/* 
Tabelas que faltam:
  - FielParticipaPastoral

*/

CREATE TABLE Pessoa (
  id integer NOT NULL PRIMARY KEY,
  nome varchar(60) NOT NULL,
  idade integer NOT NULL,
  sacerdote_fk integer NULL,
  fiel_fk integer NULL
);

CREATE TABLE Fiel (
  id integer NOT NULL,
  turma_catequese_fk integer NULL,
  comunidade_fk integer NOT NULL,

  CONSTRAINT fiel_pk PRIMARY KEY (id)
);

CREATE TABLE Pastoral (
  id integer NOT NULL,
  nome varchar(60) NOT NULL,
  coordenador_fk integer NOT NULL
);
ALTER TABLE Pastoral ADD CONSTRAINT pastoral_pk PRIMARY KEY (id);

CREATE TABLE TurmaCatequese (
  id integer NOT NULL PRIMARY KEY,
  padroeiro varchar(60) NULL,
  comunidade_fk integer NOT NULL,
  catequista_fk integer NOT NULL
);

CREATE TABLE Comunidade (
  id integer NOT NULL PRIMARY KEY,
  nome varchar(120) NOT NULL,
  localizacao varchar(60) NOT NULL,
  padroeiro varchar(60) NOT NULL,
  dataFundacao date NOT NULL
);

CREATE TABLE Dizimo (
  id integer NOT NULL PRIMARY KEY,
  valor real NOT NULL DEFAULT 0.00,
  data date NOT NULL,
  comunidade_fk integer NOT NULL
);

CREATE TABLE Igreja (
  id integer NOT NULL PRIMARY KEY,
  nome varchar(120) NOT NULL



);


DESCRIBE Dizimo;