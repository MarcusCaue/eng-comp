/* 
-> Devem ser criadas pelo menos 15 quinze, dentre as quais:
  - Pelo  menos  quatro  consultas  devem  envolver  duas  ou  mais  tabelas  (em alguns casos incluir outer joins) 
  - Pelo menos duas consultas devem envolver funções de agregação (COUNT, SUM, MIN, MAX, AVG) com agrupamento (GROUP BY). 
  - Pelo menos duas consultas devem envolver funções de agregação (COUNT, SUM, MIN, MAX, AVG) com agrupamento (GROUP BY) e HAVING. 

-> Antes  de  cada  consulta  deve  haver  uma  breve descrição textual dela
->  A prioridade deve ser dada a consultas que sumarizem os dados contidos no banco por meio de operadores de agregação.
*/

-- 1) Verifique o valor total de dízimo coletado para cada mês, independente do dia e do ano. Exiba os dados em ordem decrescente do valor total de dízimo a fim de saber qual mês é o mais movimentado
SELECT MONTH(data) mes, SUM(valor) "Valor Total (R$)" 
  FROM Dizimo 
  GROUP BY mes 
  ORDER BY SUM(valor) DESC;

-- 2) Exiba o nome da pastoral e a quantidade de fiéis participantes dela para que o pároco possa ver qual(is) pastoral(is) precisam de mais engajamento do povo.
SELECT p.nome "Pastoral", COUNT(fpp.fiel_fk) "Quant. fiéis participantes" 
  FROM FielParticipaPastoral fpp 
  INNER JOIN Pastoral p ON fpp.pastoral_fk = p.id 
  INNER JOIN Fiel f ON f.id = fpp.fiel_fk 
  GROUP BY p.nome;

-- 3) Exiba o nome do padre e a quantidade de missas que ele concelebrou na paróquia a fim de saber qual(is) dentre eles precisam de mais oportunidades de concelebração de missas na paróquia.
SELECT p.nome "Padre", COUNT(peccms.missa_fk) "Missa Concelebradas"
  FROM PadreConcelebraMissa peccms
  RIGHT OUTER JOIN Padre pe ON peccms.padre_fk = pe.id
  INNER JOIN Sacerdote s ON s.padre_fk = pe.id
  INNER JOIN Pessoa p ON p.sacerdote_fk = s.id
  GROUP BY p.nome
  ORDER BY COUNT(peccms.missa_fk);

-- 4) Exiba 
SELECT p.nome "Pessoa Batizada", b.data, m.nome "Missa", i.nome "Igreja"
  FROM Batismo b
  INNER JOIN Pessoa p ON b.pessoa_batizada_fk = p.id
  LEFT OUTER JOIN Missa m ON b.missa_fk = m.id
  LEFT OUTER JOIN Igreja i ON b.igreja_fk = i.id
  ORDER BY p.nome;


