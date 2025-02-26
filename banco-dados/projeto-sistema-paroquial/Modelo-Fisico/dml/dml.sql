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
  (3, "Capela São Paulo, apóstolo dos gentios", "São Paulo", "Rua dos Trabalhadores, Bairro Vila, nº 44", "2024-01-25", 0, NULL),
  (4, "Capela São José", "São José", "Rua do Cemitério, Bairro Cruzeiro, nº 19", "2000-03-19", 0, 5), -- SJ, C.
  (5, "Capela São Pedro", "São Pedro", "Sítio Capim de Planta", "2000-06-29", 0, NULL),
  (6, "Capela Nossa Senhora das Dores", "Bem-aventurada Virgem Maria", "Bairro Nova Cidade", "2005-09-15", 0, 7), -- Imaculado
  (7, "Capela Nossa Senhora da Imaculada Conceição", "Bem-aventurada Virgem Maria", "Bairro Nova Cidade", "2014-12-08", 0, 7), -- Imaculado
  (8, "Capela São João Batista", "São João Batista", "Sítio Malhadinha", "1999-06-24", 0, 2), -- SJB
  (9, "Capela Santa Clara de Assis", "Santa Clara de Assis", "Sítio Olho d'Água", "2011-08-24", 0, 4); -- SCA

INSERT INTO Missa VALUES 
  -- Missa com Dom Dulcênio na Igreja Matriz
  (1, "Solenidade de Corpus Christi", "Solenidade", 500, "2023-06-21", 7, 2),
  -- Missa com Pe. Adriel na Capela São José
  (2, "Solenidade de São José, Esposo da Bem-aventurada Virgem Maria", "Solenidade", 200, "2025-03-19", 1, 4),
  -- Missa com Pe. Carlinhos, Tobias e Bruno na Igreja Matriz
  (3, "Festa de Conversão de São Paulo, apóstolo", "Festa", 322, "2025-01-24", 4, 2),
  -- Missa com Dom Fernando, Pe. Adriel e Pe. Paulo na Capela de São Paulo
  (4, "Memória de Santa Escolástica, virgem e religiosa", "Memória", 100, "2025-02-10", 8, 3),
  -- Missa com Dom Dulcênio na capela de Nossa Senhora das Dores
  (5, "Memória de Nossa Senhora das Dores", "Memória", 200, "2019-09-15", 7, 6),
  -- Missa com Dom Dulcênio na Igreja Matriz
  (6, "Solenidade de São Pedro e São Paulo", "Solenidade", 800, "2018-06-29", 7, 2),
  -- Missa com Pe. Paulo no SCJ
  (7, "Missa Votiva ao Sagrado Coração de Jesus", "Memória", 100, "2019-02-07", 2, 1),



SELECT * FROM Dizimo;