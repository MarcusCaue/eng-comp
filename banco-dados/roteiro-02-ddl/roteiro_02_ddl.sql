DROP DATABASE roteiro_02_ddl;

CREATE DATABASE roteiro_02_ddl;
USE roteiro_02_ddl;

CREATE TABLE Venda (
  numero_id integer,
  data DATE,
  total real,
  codigo_cli_fk integer NOT NULL
);

CREATE TABLE Cliente (
  codigo_cli_pk integer NOT NULL PRIMARY KEY,
  nome varchar(30) NOT NULL,
  uf varchar(2)
);

ALTER TABLE Venda MODIFY COLUMN total real NOT NULL DEFAULT 0.00;
ALTER TABLE Venda ADD CONSTRAINT Pk_venda PRIMARY KEY (numero_id);
ALTER TABLE Venda ADD CONSTRAINT Fk_venda_cliente 
FOREIGN KEY (codigo_cli_fk) REFERENCES Cliente (codigo_cli_pk);

CREATE TABLE Item_venda (
  qtd real NOT NULL, 
  preco_unitario real DEFAULT 0.00,
  codigo_prod_fk integer NOT NULL,
  numero_venda_fk integer NOT NULL,

  CONSTRAINT Pk_item_venda PRIMARY KEY (codigo_prod_fk, numero_venda_fk)
);

CREATE TABLE Produto (
  codigo_pk integer NOT NULL,
  descricao varchar(50) NOT NULL,
  preco_compra real DEFAULT 0.00,
  lucro real DEFAULT 0.00,
  quantidade real DEFAULT 0,
  categoria varchar(30),

  CONSTRAINT Pk_produto PRIMARY KEY (codigo_pk)
);

ALTER TABLE Item_venda ADD CONSTRAINT Fk_item_venda_prod
FOREIGN KEY (codigo_prod_fk) REFERENCES Produto (codigo_pk);
ALTER TABLE Item_venda ADD CONSTRAINT Fk_item_venda_venda
FOREIGN KEY (numero_venda_fk) REFERENCES Venda (numero_id);
ALTER TABLE Item_venda MODIFY COLUMN qtd real DEFAULT 0.00;

DESC Venda;
DESC Item_venda;
DESC Cliente;
DESC Produto;