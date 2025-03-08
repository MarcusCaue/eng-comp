-- Nova Inserção após a alimentação inicial
INSERT INTO Bispo VALUES (4, "Diocese de Palmares", "2000-01-25");
INSERT INTO Sacerdote VALUES (10, NULL, 4);
INSERT INTO Pessoa VALUES (25, "Henrique Soares Costa", 64, 10, NULL);

-- Atualizações
UPDATE Fiel SET turma_catequese_fk = 4 WHERE id = 12; -- Adicionando um fiel a uma turma de catequese
UPDATE Batismo SET data = "2019-09-15", igreja_fk = 6, missa_fk = 5 WHERE id = 16; -- Alterando um batismo para ser celebrado numa missa por um bispo
-- Alterando um batismo para ser celebrado numa missa por um bispo; mas pegando os valores a partir de uma consulta
UPDATE Batismo as b
  SET b.data = (SELECT m.data FROM Missa as m WHERE m.nome = "Imaculada Conceição" AND m.celeb_princ_fk = 8),
  b.igreja_fk = (SELECT m.igreja_fk FROM Missa as m WHERE m.nome = "Imaculada Conceição" AND m.celeb_princ_fk = 8),
  b.missa_fk = (SELECT m.id FROM Missa as m WHERE m.nome = "Imaculada Conceição" AND m.celeb_princ_fk = 8)
  WHERE pessoa_batizada_fk = 14;
