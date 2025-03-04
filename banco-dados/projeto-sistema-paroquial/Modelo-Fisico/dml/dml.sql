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
  -- Sagrado Coração de Jesus - Aníbal Teixeira
  (1, 150.00, "1996-03-10", 1), 
  (2, 165.30, "2005-07-22", 1), 
  (3, 180.75, "2018-11-15", 1), 
  -- São João Batista - Malhadinha
  (4, 200.50, "2000-09-05", 2), 
  (5, 250.00, "2012-06-18", 2), 
  -- Matriz São Pedro e São Paulo
  (6, 180.75, "2023-07-25", 3), 
  (7, 190.80, "2023-09-12", 3), 
  (8, 205.00, "2024-02-28", 3), 
  (9, 215.50, "2025-03-02", 3), 
  -- Santa Clara de Assis - Olho d'Água
  (10, 220.00, "2011-05-14", 4), 
  (11, 230.50, "2017-10-30", 4), 
  -- São José - Cruzeiro
  (12, 175.25, "2002-12-05", 5), 
  (13, 185.75, "2010-08-22", 5), 
  (14, 195.60, "2016-04-09", 5), 
  (15, 210.20, "2020-11-18", 5), 
  (16, 225.40, "2023-06-25", 5), 
  -- São José - Verdes
  (17, 190.00, "2015-09-14", 6), 
  -- Imaculado Coração de Maria - Nova Cidade
  (18, 205.75, "1998-02-11", 7), 
  (19, 210.40, "2006-06-27", 7), 
  (20, 220.30, "2015-01-22", 7), 
  -- Nossa Senhora de Guadalupe - Capim de Planta
  (21, 215.00, "2021-12-01", 8), 
  (22, 225.00, "2023-07-03", 8); 

INSERT INTO Igreja VALUES
  -- Comunidade "Matriz São Pedro e São Paulo"
  (1, "Igreja São Pedro e São Paulo", "São Pedro", "Rua das Palmeiras, 120, Bairro Vila", "1980-05-15", 1, 3),
  (2, "Igreja São Francisco de Assis", "São Francisco de Assis", "Rua dos Pássaros, 22, Bairro Vila", "1970-10-04", 0, 3),
  (3, "Capela São Paulo Apóstolo", "São Paulo", "Rua das Acácias, 55, Bairro Vila", "1995-06-29", 0, 3),
  -- Comunidade "Nossa Senhora de Guadalupe - Capim de Planta" (Padroeira: Bem-aventurada Virgem Maria)
  (4, "Igreja Nossa Senhora Aparecida", "Bem-aventurada Virgem Maria", "Avenida Central, 300, Sítio Capim de Planta", "1975-09-22", 0, 8),
  (5, "Capela Nossa Senhora de Guadalupe", "Bem-aventurada Virgem Maria", "Rua das Flores, 77, Sítio Capim de Planta", "2020-12-12", 0, 8),
  -- Comunidade "São José - Cruzeiro"
  (6, "Capela Santo Antônio", "Santo Antônio", "Praça da Matriz, 50, Bairro Cruzeiro", "1990-11-30", 0, 5),
  (7, "Igreja Santa Rita de Cássia", "Santa Rita de Cássia", "Praça do Rosário, 12, Bairro Cruzeiro", "2005-08-22", 0, 5),
  (8, "Capela São José", "São José", "Rua Esperança, 98, Bairro Cruzeiro", "2000-03-19", 0, 5),
  -- Comunidade "Santa Clara de Assis - Olho d'Água" (Padroeira: Santa Clara)
  (9, "Capela Santa Clara", "Santa Clara", "Rua do Sol, 75, Sítio Olho d'Água", "2000-07-10", 0, 4),
  -- Comunidade "São José - Verdes"
  (10, "Igreja São José", "São José", "Travessa Esperança, 200, Sítio Verdes", "2010-03-25", 0, 6),
  (11, "Capela Nossa Senhora das Graças", "Bem-aventurada Virgem Maria", "Rua da Fé, 88, Sítio Verdes", "1998-05-13", 0, 6),
  -- Comunidade "Imaculado Coração de Maria - Nova Cidade" (Padroeira: Bem-aventurada Virgem Maria)
  (12, "Capela Imaculada Conceição", "Bem-aventurada Virgem Maria", "Alameda das Palmeiras, 18, Bairro Nova Cidade", "1995-12-08", 0, 7),
  (13, "Capela São Sebastião", "São Sebastião", "Travessa do Carmo, 45, Bairro Nova Cidade", "2018-01-20", 0, 7),
  (14, "Capela Imaculado Coração de Maria", "Bem-aventurada Virgem Maria", "Rua dos Lírios, 101, Bairro Nova Cidade", "1996-07-02", 0, 7),
  -- Comunidade "Sagrado Coração de Jesus - Aníbal Teixeira"
  (15, "Igreja Sagrado Coração de Jesus", "Sagrado Coração de Jesus", "Rua dos Anjos, 99, Bairro Aníbal Teixeira", "1988-06-05", 0, 1),
  -- Comunidade "São João Batista - Malhadinha"
  (16, "Capela São João Batista", "São João Batista", "Estrada Nova, 654, Sítio Malhadinha", "2015-04-20", 0, 2),
  -- Igrejas sem comunidade
  (17, "Igreja Nossa Senhora do Rosário", "Bem-aventurada Virgem Maria", "Avenida dos Anjos, 500, Centro", "1965-10-07", 0, NULL),
  (18, "Capela São Miguel Arcanjo", "São Miguel Arcanjo", "Rua das Missões, 120, Bairro Santo Anjo", "1982-09-29", 0, NULL),
  (19, "Igreja Cristo Redentor", "Nosso Senhor Jesus Cristo", "Avenida da Paz, 1000, Cidade Nova", "1992-12-25", 0, NULL),
  (20, "Capela Santa Teresinha", "Santa Teresinha do Menino Jesus", "Rua da Esperança, 77, Bairro Primavera", "2010-10-01", 0, NULL);

INSERT INTO Pastoral VALUES
  (1, "Pastoral da Liturgia", 3), 
  (2, "Pastoral do Dízimo", 6), 
  (3, "Pastoral da Catequese", 10), 
  (4, "Pastoral da Juventude", 2), 
  (5, "Pastoral do Batismo", 9), 
  (6, "Pastoral Familiar", 12), 
  (7, "Pastoral da Música", 15), 
  (8, "Pastoral Carcerária", 8), 
  (9, "Pastoral Vocacional", 11), 
  (10, "Pastoral da Acolhida", 5), 
  (11, "Pastoral do Crisma", 7);

INSERT INTO TurmaCatequese VALUES
  (1, "Santo Antônio", 1, 3), 
  (2, "São Francisco de Assis", 2, 10), 
  (3, "Nossa Senhora das Graças", 3, 2), 
  (4, "Santa Rita de Cássia", 4, 12), 
  (5, "São João Bosco", 5, 6), 
  (6, "Santa Teresinha", 6, 9), 
  (7, "São Miguel Arcanjo", 7, 15), 
  (8, "Nossa Senhora do Carmo", 8, 5),
  (9, "São Sebastião", 1, 7), 
  (10, "Santo Expedito", 2, 11), 
  (11, "São Bento", 3, 4), 
  (12, "Nossa Senhora Aparecida", 5, 8), 
  (13, "São Judas Tadeu", 6, 13);

INSERT INTO Missa VALUES 
  (1, "Corpus Christi", "Solenidade", 500, "2023-06-21", 7, 2),
  (2, "São José, Esposo da Bem-aventurada Virgem Maria", "Solenidade", 200, "2025-03-19", 1, 4),
  (3, "Festa de Conversão de São Paulo, apóstolo", "Festa", 322, "2025-01-24", 4, 2),
  (4, "Santa Escolástica, virgem e religiosa", "Memória", 100, "2025-02-10", 8, 3),
  (5, "Nossa Senhora das Dores", "Memória", 200, "2019-09-15", 7, 6),
  (6, "São Pedro e São Paulo", "Solenidade", 800, "2018-06-29", 7, 2),
  (7, "Missa Votiva ao Sagrado Coração de Jesus", "Memória", 100, "2019-02-07", 2, 1),
  (8, 'Quarta-feira de Cinzas', 'memória', 250.00, '2023-02-22', 4, 3),
  (9, '1º Domingo da Quaresma', 'solenidade', 180.00, '2022-03-06', 5, 5),
  (10, '2º Domingo da Quaresma', 'solenidade', 200.50, '2021-02-28', 1, 2),
  (11, '3º Domingo da Quaresma', 'solenidade', 175.30, '2024-03-03', 6, 6),
  (12, '4º Domingo da Quaresma', 'solenidade', 210.75, '2020-03-22', 4, 7),
  (13, '5º Domingo da Quaresma', 'solenidade', 195.20, '2023-03-26', 5, 1),
  (14, 'Domingo de Ramos', 'solenidade', 300.00, '2024-03-24', 2, 3),
  (15, 'Ceia do Senhor', 'solenidade', 450.50, '2021-04-01', 1, 8),
  (16, 'Segunda-feira da Semana Santa', 'memória', 120.00, '2022-04-11', 3, 6),
  (17, 'Vigília Pascal', 'solenidade', 500.00, '2020-04-11', 7, 3),
  (18, 'Domingo de Páscoa', 'solenidade', 400.25, '2023-04-09', 5, 4),
  (19, 'Pentecostes', 'solenidade', 275.00, '2022-06-05', 2, 7),
  (20, 'Sagrado Coração de Jesus', 'solenidade', 320.75, '2020-06-19', 4, 3),
  (21, 'Assunção de Nossa Senhora', 'solenidade', 310.50, '2021-08-15', 5, 8),
  (22, 'São Francisco de Assis', 'memória', 180.00, '2023-10-04', 3, 2),
  (23, 'Nossa Senhora Aparecida', 'solenidade', 290.00, '2024-10-12', 1, 5),
  (24, 'Natal do Senhor', 'solenidade', 600.00, '2022-12-25', 6, 3),
  (25, 'Santos Anjos da Guarda', 'memória', 350.00, '2020-10-02', 8, 5),
  (26, 'Domingo da Misericórdia', 'solenidade', 280.00, '2023-04-16', 9, 6),
  (27, 'Santo Antônio', 'memória', 230.00, '2021-06-13', 7, 1),
  (28, 'Imaculada Conceição', 'solenidade', 400.00, '2022-12-08', 8, 2);

INSERT INTO Batismo (id, data, pessoa_batizada_fk, igreja_fk, sacerdote_fk, missa_fk) VALUES
  (1, '2023-04-09', 1, 1, 4, 8),
  (2, '2023-06-15', 2, 2, 5, 9),
  (3, '2024-02-14', 3, 3, 6, 10),
  (4, '2024-03-31', 4, 4, 4, 11),
  (5, '2024-05-20', 5, 5, 5, 12),
  (6, '2023-09-08', 6, 6, 6, 13),
  (7, '2024-12-25', 7, 1, 4, 14),
  (8, '2025-01-06', 8, 2, 5, 15),
  (9, '2023-11-01', 9, 3, 6, 16),
  (10, '2024-07-16', 10, 4, 4, 17),
  (11, '2023-12-08', 11, 5, 5, 18),
  (12, '2024-06-29', 12, 6, 6, 19),
  -- Batismos celebrados por bispos (fora da missa)
  (13, '2023-05-10', 13, 1, 7, NULL),
  (14, '2024-09-14', 14, 2, 8, NULL),
  (15, '2025-02-02', 15, 3, 9, NULL),
  (16, '2023-08-20', 16, 4, 7, NULL),
  (17, '2024-10-05', 17, 5, 8, NULL);

INSERT INTO FielParticipaPastoral (pastoral_fk, fiel_fk) VALUES
  -- Pastoral da Criança
  (1, 2), (1, 3), (1, 5),
  -- Pastoral da Juventude
  (2, 4), (2, 6), (2, 7), (2, 8),
  -- Pastoral do Dízimo
  (3, 1), (3, 9), (3, 10),
  -- Pastoral da Catequese
  (4, 11), (4, 12),
  -- Pastoral Litúrgica
  (5, 13), (5, 14),
  -- Pastoral Familiar
  (6, 3), (6, 7), (6, 8), (6, 15),
  -- Pastoral Vocacional
  (7, 2), (7, 4), (7, 6),
  -- Pastoral da Acolhida
  (8, 9), (8, 10),
  -- Pastoral Carcerária
  (9, 5), (9, 12), (9, 14),
  -- Pastoral do Crisma
  (10, 1), (10, 13), (10, 15);

