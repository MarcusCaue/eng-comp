-- Reset do Banco

-- Alimentação do Banco de Dados
INSERT INTO Comunidade VALUES 
  (1, "Sagrado Coração de Jesus - Aníbal Teixeira", "Bairro Aníbal Teixeira", "Nosso Senhor Jesus Cristo", "1995-01-19"),
  (2, "São João Batista - Malhadinha", "Sítio Malhadinha", "São João Batista", "1999-06-24"),
  (3, "Matriz São Pedro e São Paulo", "Bairro Vila", "São Pedro", "2023-06-29"),
  (4, "Santa Clara de Assis - Olho d'Água", "Sítio Olho d'Água", "Santa Clara", "2010-08-14"),
  (5, "São José - Cruzeiro", "Bairro Cruzeiro", "São José", "2000-03-19"),
  (6, "São José - Verdes", "Sítio Verdes", "São José", "2014-03-19"),
  (7, "Imaculado Coração de Maria - Nova Cidade", "Bairro Nova Cidade", "Bem-aventurada Virgem Maria", "1996-07-02"),
  (8, "Nossa Senhora de Guadalupe - Capim de Planta", "Sítio Capim de Planta", "Bem-aventurada Virgem Maria", "2020-12-12");

INSERT INTO Dizimo VALUES 
  (1, 1500, "2024-06-09", 1), (2, 478, "2024-01-07", 1), -- SCJ
  (3, 7200, "2023-06-29", 3), (4, 4500, "2023-07-02", 3), (5, 3675, "2023-10-03", 3), (6, 7000, "2023-12-25", 3), (7, 3000, "2025-01-01", 3), -- Matriz
  (8, 435, "2025-01-29", 5), (9, 1200, "2024-03-19", 5), (10, 250, "2024-11-15", 5),-- SJ, C.
  (11, 300, "2024-05-30", 8), (12, 292, "2024-04-20", 8), -- Guadalupe
  (13, 100, "2023-08-29", 7), (14, 290, "2023-11-22", 7);  -- Imaculado

INSERT INTO Igreja VALUES 
  (1, "Capela Sagrado Coração de Jesus", "Nosso Senhor Jesus Cristo", "Rua Padre João Bosco, Bairro Aníbal Teixeira, nº 90", "1995-01-19", 0, 1), -- SCJ
  (2, "Igreja Matriz São Pedro e São Paulo", "São Pedro", "Rua Presidente Médici, Bairro Vila, nº 34", "2023-06-29", 1, 3), -- Matriz
  (3, "Capela São Paulo, apóstolo dos gentios", "Rua dos Trabalhadores, Bairro Vila, nº 44", "2024-01-25"),
  (4, "Capela São José", "São José", "Rua do Cemitério, Bairro Cruzeiro, nº 19", "2000-03-19", 0, 5), -- SJ, C.
  (5, "Capela São Pedro", "São Pedro", "Sítio Capim de Planta", "2000-06-29"),
  (6, "Capela Nossa Senhora das Dores", "Bem-aventurada Virgem Maria", "Bairro Nova Cidade", "2005-09-15", 0, 7), -- Imaculado
  (7, "Capela Nossa Senhora da Imaculada Conceição", "Bem-aventurada Virgem Maria", "Bairro Nova Cidade", "2014-12-08", 0, 7), -- Imaculado
  (8, "Capela São João Batista", "São João Batista", "Sítio Malhadinha", "1999-06-24", 0, 2), -- SJB
  (8, "Capela São João Batista", "São João Batista", "Sítio Malhadinha", "1999-06-24", 0, 2), -- SJB
;

INSERT INTO Pessoa VALUES 
  -- Fiéis 
  (1, "José Guilherme", 19),
  (2, "Artur Ramalho", 20),
  (3, "Ricardo Sousa", 32),
  (4, "Marianna Silva", 16),
  (5, "Yasmim Ferreira", 23),
  (6, "Josefa Gonçalves", 58),
  (7, "José Costa", 61),
  (8, "Severina Ramos", 66),
  (9, "Pedro Monteiro", 43),
  (10, "Pedro Silva", 21),
  (11, "José Sousa", 29),
  (12, "José Faustino", 75),
  (13, "Anástica Lopes", 55),
  (14, "Adriana Ferreira", 33),
  (15, "Gabriel Dias", 26),
  -- Sacerdotes
  (16, "Paulo Junior", 58),
  (17, "Pedro Silva", 30),
  (18, "Bruno Medeiros", 41),
  (19, "Tobias Diniz", 40),
  (20, "Adriel David", 27),
  (21, "Carlos Antônio", 60),
  (22, "Dulcênio Matos", 63),
  (23, "Fernando Falcão", 58),
  (24, "José Romano", 68)
;



SELECT * FROM Dizimo;