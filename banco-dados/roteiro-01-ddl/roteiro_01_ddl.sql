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

# Alteração de tabelas existentes 

# 1 - Adição de chave primária
# ALTER TABLE <nome_tabela> ADD CONSTRAINT <nome_pk> PRIMARY KEY (<colunas...>)
ALTER TABLE Funcionario ADD CONSTRAINT Pk_func PRIMARY KEY (id_func);
ALTER TABLE Candidato ADD CONSTRAINT Pk_candidato PRIMARY KEY (id_candidato);
ALTER TABLE Candidato_funcionario ADD CONSTRAINT Pk_cand_func PRIMARY KEY (candidato, funcionario); # Tabela de um relacionamento N:N
ALTER TABLE Inscricao ADD CONSTRAINT Pk_inscricao PRIMARY KEY (id_inscricao);
ALTER TABLE Cargo ADD CONSTRAINT Pk_cargo PRIMARY KEY (id_cargo);
ALTER TABLE Teste ADD CONSTRAINT Pk_Teste PRIMARY KEY (id_teste);
ALTER TABLE Processo_seletivo ADD CONSTRAINT Pk_processo PRIMARY KEY (id_processo);
ALTER TABLE Departamento ADD CONSTRAINT Pk_depto PRIMARY KEY (id_depto);

# 2 - Adição de novas colunas a uma tabela
# ALTER TABLE <nome_tabela> ADD COLUMN <nome_coluna> <tipo>;
ALTER TABLE Teste ADD COLUMN cargo integer;

# 3 - Adição de chave estrangeira
# Obs.: É preciso que as chaves primárias já estejam criadas
# ALTER TABLE <nome_tabela> ADD CONSTRAINT <nome_fk> FOREIGN KEY (<nome_coluna>) REFERENCES <nome_tabela> (<nome_coluna>)
ALTER TABLE Candidato_funcionario ADD CONSTRAINT Fk_cand_func_cand
	FOREIGN KEY (candidato) REFERENCES Candidato (id_candidato);
ALTER TABLE Candidato_funcionario ADD CONSTRAINT Fk_cand_func
	FOREIGN KEY (funcionario) REFERENCES Funcionario (id_func);

ALTER TABLE Inscricao ADD CONSTRAINT FK_INSC_candidato
	FOREIGN KEY (candidato) REFERENCES Candidato (id_candidato);
ALTER TABLE Inscricao ADD CONSTRAINT FK_INSC_cargo
	FOREIGN KEY (cargo) REFERENCES Cargo (id_cargo);

ALTER TABLE Teste ADD CONSTRAINT Fk_teste_processo
	FOREIGN KEY (processo) REFERENCES Processo_seletivo (id_processo);
ALTER TABLE Teste ADD CONSTRAINT Fk_teste_cargo
	FOREIGN KEY (cargo) REFERENCES Cargo (id_cargo);
ALTER TABLE Teste ADD CONSTRAINT Fk_teste_inscricao
	FOREIGN KEY (inscricao) REFERENCES Inscricao (id_inscricao);

ALTER TABLE Funcionario ADD CONSTRAINT Fk_func_depto
	FOREIGN KEY (depto) REFERENCES Departamento (id_depto);
ALTER TABLE Funcionario ADD CONSTRAINT Fk_func_cargo
	FOREIGN KEY (cargo) REFERENCES Cargo (id_cargo);

# 4 - Modificação do tipo da coluna
# ALTER TABLE <tabela> MODIFY COLUMN <coluna> <novo tipo e constraints>
# É uma reescrita da coluna, uma redefinição do seu tipo
ALTER TABLE Candidato_funcionario MODIFY COLUMN dt_indicacao DATE NOT NULL;

ALTER TABLE Candidato MODIFY COLUMN nome varchar(60) NOT NULL;
ALTER TABLE Candidato MODIFY COLUMN cpf varchar(14) NOT NULL;
ALTER TABLE Inscricao MODIFY COLUMN dt_inscricao DATE NOT NULL;

ALTER TABLE Teste ADD COLUMN nota real NOT NULL;

# 5 - Renomeando uma coluna
# ALTER TABLE <tabela> CHANGE COLUMN <old> <new> <tipo e constraints>
ALTER TABLE Teste CHANGE COLUMN nota nota_teste real NOT NULL;

# 6 - Restrições semânticas
ALTER TABLE Teste ADD CONSTRAINT Ck_nota CHECK (nota_teste > 0);
ALTER TABLE Teste ADD CONSTRAINT Ck_nota_2 CHECK (nota_teste BETWEEN 0 AND 100);

# 7 - Setando um valor padrão
ALTER TABLE Teste ALTER nota_teste SET DEFAULT 7;

DESCRIBE Candidato;
DESCRIBE Candidato_funcionario;
DESCRIBE Inscricao;
DESCRIBE Teste;
DESCRIBE Cargo;
DESCRIBE Funcionario;
DESCRIBE Processo_seletivo;
DESCRIBE Departamento;

# 8 - Renomeando uma tabela
RENAME TABLE Processo_seletivo TO Processo;

# 9 - Removendo uma coluna
ALTER TABLE Candidato ADD COLUMN email varchar(60) NOT NULL;
DESCRIBE Candidato;
ALTER TABLE Candidato DROP COLUMN email;

# 10 - Excluindo uma tabela
CREATE TABLE Instituicao (
    id_inst integer NOT NULL,
    nome varchar(60),
    endereco varchar(60),
    ano_fundacao integer
);

ALTER TABLE Instituicao ADD CONSTRAINT Pk_inst PRIMARY KEY (id_inst);
DESCRIBE Instituicao;
DROP TABLE Instituicao;
SHOW TABLES;
