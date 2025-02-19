/* Funções para retornar uma informação de uma data:
  - month(data: DATE) -> int
  - day(data: DATE) -> int
  - year(data: DATE) -> int
*/


/* -- Criação da estrutura do Banco /*
/* CREATE TABLE
    CD (
        codigo INT PRIMARY KEY,
        nome VARCHAR(100) NOT NULL,
        gravadora VARCHAR(30),
        data DATE
    );

CREATE TABLE
    CANTOR (
        codigo INT PRIMARY KEY,
        nome VARCHAR(60) NOT NULL,
        biografia TEXT
    );

CREATE TABLE
    MUSICA (
        CD INT,
        numero INT,
        titulo VARCHAR(40) NOT NULL,
        cantor INT NOT NULL,
        tempo INT,
        genero VARCHAR(20),
        PRIMARY KEY (CD, numero),
        FOREIGN KEY (CD) REFERENCES CD(codigo),
        FOREIGN KEY (cantor) REFERENCES Cantor(codigo)
    );
*/

/* -- Populando o Banco */
/* INSERT INTO CD (codigo, nome, gravadora, data) VALUES 
  (1, "Fantasia", "Som Preso", '2010-09-02'),
  (2, "Fantasia de Verao", "Som Preso", '2020-10-20'),
  (3, "Romantico Total", "RGB", '2022-09-21'),
  (4, "Popular 2024", "RGB", '2024-07-09');

INSERT INTO Cantor (codigo, nome, biografia) VALUES 
  (1, "Marisa aos Montes", "Nasceu em João Pessoa em 1980. Gravou varios CDs. Formou recentemente os Carnabalistas."),
  (2, "Zeca Sertanejo", "Nasceu em Patos-PB. Não bebe. Nao fuma. Tem 3 filhos."),
  (3, "Alexandre Xicara", "Toca pagode desde os 12 anos. Comportamento calmo. Gravou tambem MPB."),
  (4, "Emerson Seringueira", "Canta MPB e sucessos internacionais desde 2000. Vendeu mais de 3 milhoes de discos."),
  (5, "Martinho do Bairoo", "Alem de pagode, canta sertanejo desde crianca. Tem familia em Campina Grande.");

INSERT INTO Musica (cd, numero, titulo, cantor, tempo, genero) VALUES
  (1, 1, "Coracao apaixonado", 1, 120, "MPB"), 
  (1, 2, "Coracao dilacerado", 2, 180, "MPB"),
  (1, 3, "Mulher", 1, 120, "PAGODE"), 
  (1, 4, "Mulheres apaixonadas", 4, 178, NULL), 
  (1, 5, "Vou embora", 5, 300, "SAMBA"),

  (2, 1, "Adeus para sempre", 2, 180, "SAMBA"), 
  (2, 2, "Nova infancia", 4, 198, "MPB"), 
  (2, 3, "Eu voltei", 5, 345, "MPB"), 
  (2, 4, "Volta para mim", 5, 532, "SAMBA"), 

  (3, 1, "Amor de irmao", 4, 123, "SAMBA"),
  (3, 2, "Amigo", 3, 452, "SERTANEJO"),
  (3, 3, "Amigo para sempre", 2, 89, "SERTANEJO"),
  (3, 4, "Cancao para o amigo", 1, 365, "MPB"),

  (4, 1, "Andancas", 2, 320, "MPB"),
  (4, 2, "Irmao do coracao", 4, 180, NULL),
  (4, 3, "Amor de mae", 3, 124, "PAGODE");
*/

-- 5. Altere o nome do cantor Matinho do Bairro para Martinho do Zepa.
UPDATE Cantor SET nome = "Martinho do Zepa" WHERE codigo = 5;
-- 6. Altere o cantor da música Nova Infancia para a cantora Marisa aos Montes.
UPDATE Musica SET cantor = 1 WHERE titulo = "Nova infancia"; 
-- 7. Altere a data do lançamento do CD Popular 2024 para 10/6/2024.
UPDATE CD Set data = "2024-06-10" WHERE nome = "Popular 2024";
-- 8. Exiba todos os dados das músicas em ordem crescente de duração.
SELECT * FROM Musica ORDER BY tempo ASC;
-- 9. Exiba o título e o gênero de todas as músicas cadastradas, apresentado o genero em ordem alfabética, seguido dos títulos das músicas em ordem alfabética.
SELECT titulo as "Título", genero as "Gênero" FROM Musica ORDER BY genero ASC, titulo ASC;
-- 10. Selecione todos os CDs da gravadora Som Preso.
SELECT * FROM CD WHERE gravadora = "Som Preso";
-- 11. Exiba todas as músicas do CD Fantasia de Verao.
SELECT * FROM Musica WHERE cd = 2;
-- 12. Exiba as músicas que não tem genero cadastrado.
SELECT * FROM Musica WHERE genero IS NULL;
-- 13. Altere o gênero da música Irmao do coracao e Mulheres apaixonadas para MPB.
UPDATE Musica SET genero = "MPB" WHERE titulo IN ("Mulheres apaixonadas", "Irmao do coracao");
-- 14. Exiba todas as músicas que contém a palavra irmao.
SELECT * FROM Musica WHERE titulo LIKE "%irmao%";
-- 15. Consulte todas as músicas do gênero MPB.
SELECT * FROM Musica WHERE genero = "MPB";
-- 16. Exiba todas as músicas com duração entre 2 e 4 minutos.
SELECT * FROM Musica WHERE tempo BETWEEN 120 AND 240;
-- 17. Selecione os CDs lançados no mês de setembro.
SELECT * FROM Cd WHERE MONTH(data) = 9;
-- 18. Exiba todos cantores cujo nome iniciam com a letra M.
SELECT * FROM Cantor WHERE nome LIKE "M%";
-- 19. Exiba todos os dados dos CDs do mais recente para o mais antigo.
SELECT * FROM CD ORDER BY data DESC;
-- 20. Exiba o título, o gênero e o tempo de duração de todas as músicas do gênero SAMBA, PAGODE e SERTANEJO.
SELECT titulo as "Título", genero as 'Genero', tempo as 'Tempo (s)' FROM Musica WHERE genero = "SAMBA" OR genero = "PAGODE" or genero = "SERTANEJO";
-- 21. Selecione todas as músicas que os títulos tenham somente uma palavra.
SELECT titulo FROM Musica WHERE titulo NOT LIKE "% %";
-- 22. Exiba o nome do CD, o nome da gravadora e há quanto tempo (em anos) os CDs foram lançados em ordem descrescente de tempo.
SELECT nome as "Nome", gravadora as "Gravadora", YEAR(data) as "Ano de lançamento" FROM CD ORDER BY data DESC;
-- 23. Exclua a música Vou embora. O que aconteceu? Explique.
DELETE FROM Musica WHERE titulo = "Vou embora";