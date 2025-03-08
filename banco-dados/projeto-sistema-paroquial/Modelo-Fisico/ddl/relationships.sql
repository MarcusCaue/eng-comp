-- Relacionamentos N:N
CREATE TABLE FielParticipaPastoral (
  pastoral_fk integer NOT NULL,
  fiel_fk integer NOT NULL,

  CONSTRAINT PRIMARY KEY (pastoral_fk, fiel_fk),
  CONSTRAINT Pastoral_fk FOREIGN KEY (pastoral_fk) REFERENCES Pastoral (id),
  CONSTRAINT Fiel_fk FOREIGN KEY (fiel_fk) REFERENCES Fiel (id)
);

CREATE TABLE PadreConcelebraMissa (
  padre_fk integer NOT NULL,
  missa_fk integer NOT NULL,

  CONSTRAINT PRIMARY KEY (padre_fk, missa_fk),
  CONSTRAINT Padre_fk FOREIGN KEY (padre_fk) REFERENCES Padre (id),
  CONSTRAINT Missa_fk FOREIGN KEY (missa_fk) REFERENCES Missa (id)
);

CREATE TABLE PessoaEhPadrinho (
  pessoa_fk integer NOT NULL,
  batismo_fk integer NOT NULL,

  CONSTRAINT PRIMARY KEY (pessoa_fk, batismo_fk),
  CONSTRAINT Pessoa_fk FOREIGN KEY (pessoa_fk) REFERENCES Pessoa (id),
  CONSTRAINT Batismo_fk FOREIGN KEY (batismo_fk) REFERENCES Batismo (id)
);

/* Outros relacionamentos */
-- Tabela Pessoa
ALTER TABLE Pessoa ADD CONSTRAINT FOREIGN KEY (sacerdote_fk) REFERENCES Sacerdote (id);
ALTER TABLE Pessoa ADD CONSTRAINT FOREIGN KEY (fiel_fk) REFERENCES Fiel (id);

-- Tabela Fiel
ALTER TABLE Fiel ADD CONSTRAINT FOREIGN KEY (turma_catequese_fk) REFERENCES TurmaCatequese (id);
ALTER TABLE Fiel ADD CONSTRAINT FOREIGN KEY (comunidade_fk) REFERENCES Comunidade (id);

-- Tabela Pastoral
ALTER TABLE Pastoral ADD CONSTRAINT FOREIGN KEY (coordenador_fk) REFERENCES Fiel (id);

-- Tabela TurmaCatequese
ALTER TABLE TurmaCatequese ADD CONSTRAINT FOREIGN KEY (comunidade_fk) REFERENCES Comunidade (id);
ALTER TABLE TurmaCatequese ADD CONSTRAINT FOREIGN KEY (catequista_fk) REFERENCES Fiel (id);

-- Tabela Dizimo
ALTER TABLE Dizimo ADD CONSTRAINT FOREIGN KEY (comunidade_fk) REFERENCES Comunidade (id);

-- Tabela Igreja
ALTER TABLE Igreja ADD CONSTRAINT FOREIGN KEY (comunidade_fk) REFERENCES Comunidade (id);

-- Tabela Sacerdote
ALTER TABLE Sacerdote ADD CONSTRAINT FOREIGN KEY (padre_fk) REFERENCES Padre (id);
ALTER TABLE Sacerdote ADD CONSTRAINT FOREIGN KEY (bispo_fk) REFERENCES Bispo (id);

-- Tabela Padre
ALTER TABLE Padre ADD CONSTRAINT FOREIGN KEY (bispo_fk) REFERENCES Bispo (id);

-- Tabela Missa
ALTER TABLE Missa ADD CONSTRAINT FOREIGN KEY (celeb_princ_fk) REFERENCES Sacerdote (id);
ALTER TABLE Missa ADD CONSTRAINT FOREIGN KEY (igreja_fk) REFERENCES Igreja (id);

-- Tabela Batismo
ALTER TABLE Batismo ADD CONSTRAINT FOREIGN KEY (pessoa_batizada_fk) REFERENCES Pessoa (id);
ALTER TABLE Batismo ADD CONSTRAINT FOREIGN KEY (igreja_fk) REFERENCES Igreja (id);
ALTER TABLE Batismo ADD CONSTRAINT FOREIGN KEY (sacerdote_fk) REFERENCES Sacerdote (id);
ALTER TABLE Batismo ADD CONSTRAINT FOREIGN KEY (missa_fk) REFERENCES Missa (id);
