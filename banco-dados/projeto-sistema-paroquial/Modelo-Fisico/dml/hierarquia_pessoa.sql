INSERT INTO Fiel (id, comunidade_fk) VALUES
  (1, 1), (2, 3), (3, 3),  (4, 5),  (5, 8),  (6, 5),  (7, 8),  (8, 5),  (9, 2),  (10, 2),  (11, 2),  (12, 4),  (13, 6),  (14, 4),  (15, 7);

INSERT INTO Bispo VALUES (1, "Diocese de Campina Grande", "2011-03-07"), (2, "Diocese da Administração Apostólica", "2003-05-31"), (3, "Arquidiocese de Cartago", "2020-08-10");

INSERT INTO Padre VALUES 
  (1, "2000-01-01", NULL, "Visitante", 1), 
  (2, "2010-11-21", "Ordem de São Bento", "Visitante", 1), 
  (3, "2022-10-11", "Ordem de São Francisco de Assis", "Visitante", 1), 
  (4, "2015-07-03", NULL, "Pároco", 1), 
  (5, "2016-02-04", NULL, "Vigário", 1), 
  (6, "2024-12-16", NULL, "Vigário", 1);

INSERT INTO Sacerdote VALUES 
  (1, 1, NULL), (2, 2, NULL), (3, 3, NULL), (4, 4, NULL), (5, 5, NULL), (6, 6, NULL), 
  (7, NULL, 1), (8, NULL, 2), (9, NULL, 3);

INSERT INTO Pessoa (id, nome, idade, fiel_fk, sacerdote_fk) VALUES 
  -- Fiéis 
  (1, "José Guilherme", 19, 1, NULL),
  (2, "Artur Ramalho", 20, 2, NULL),
  (3, "Ricardo Sousa", 32, 3, NULL),
  (4, "Marianna Silva", 16, 4, NULL),
  (5, "Yasmim Ferreira", 23, 5, NULL),
  (6, "Josefa Gonçalves", 58, 6, NULL),
  (7, "José Costa", 61, 7, NULL),
  (8, "Severina Ramos", 66, 8, NULL),
  (9, "Pedro Monteiro", 43, 9, NULL),
  (10, "Pedro Silva", 21, 10, NULL),
  (11, "José Sousa", 29, 11, NULL),
  (12, "José Faustino", 75, 12, NULL),
  (13, "Anástica Lopes", 55, 13, NULL),
  (14, "Adriana Ferreira", 33, 14, NULL),
  (15, "Gabriel Dias", 26, 15, NULL),
  -- Sacerdotes
  (16, "Paulo Junior", 58, NULL, 2),
  (17, "Pedro Silva", 30, NULL, 3),
  (18, "Bruno Medeiros", 41, NULL, 5),
  (19, "Tobias Diniz", 40, NULL, 6),
  (20, "Adriel David", 27, NULL, 1),
  (21, "Carlos Antônio", 60, NULL, 4),
  (22, "Dulcênio Matos", 63, NULL, 7),
  (23, "Fernando Falcão", 58, NULL, 8),
  (24, "José Romano", 68, NULL, 9);
