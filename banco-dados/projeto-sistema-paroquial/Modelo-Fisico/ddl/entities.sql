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
  nome varchar(120) NOT NULL,
  padroeiro varchar(60) NOT NULL,
  endereco varchar(500) NOT NULL,
  dataErecaoCanonica date NOT NULL,
  ehMatriz integer NOT NULL DEFAULT 0,
  comunidade_fk integer NULL,

  CHECK (ehMatriz in (0, 1))
);

CREATE TABLE Sacerdote (
  id integer NOT NULL PRIMARY KEY,
  padre_fk integer NULL,
  bispo_fk integer NULL
);

CREATE TABLE Padre (
  id integer NOT NULL PRIMARY KEY,
  dataOrdenacao date NOT NULL,
  ordemRelg varchar(60) NULL,
  cargo varchar(60) NOT NULL,
  bispo_fk integer NOT NULL,

  CHECK (cargo IN ('pároco', 'vigário', 'visitante'))  
);

CREATE TABLE Bispo (
  id integer NOT NULL PRIMARY KEY,
  diocese varchar(300) NOT NULL UNIQUE,
  dataOrEpisc date NOT NULL
);

CREATE TABLE Missa (
  id integer NOT NULL PRIMARY KEY,
  nome varchar(500) NOT NULL,
  categLit varchar(10) NOT NULL,
  ofertas real NOT NULL DEFAULT 0.00,
  data date NOT NULL,
  celeb_princ_fk integer NOT NULL,
  igreja_fk integer NOT NULL,

  CHECK (categLit IN ('memória', 'festa', 'solenidade'))
);

CREATE TABLE Batismo (
  id integer NOT NULL PRIMARY KEY,
  data date NOT NULL,
  pessoa_batizada_fk integer NOT NULL,
  igreja_fk integer NOT NULL,
  sacerdote_fk integer NOT NULL,
  missa_fk integer NULL
);