-- 1. Exiba, para cada seção, o número da seção, a quantidade de empregados e total dos salários sem comissão.
SELECT idsec, COUNT(emp.nome) as "Número Empregados", SUM(emp.salario) as "Total Salários"
FROM Secao LEFT OUTER JOIN Empregado as emp ON Secao.idsec = emp.secao
GROUP BY idsec;

-- 2. Exiba, para cada cargo, o nome do cargo, o número de empregados e salário médio.
SELECT cargo, COUNT(*) as "Quantidade de Empregados", AVG(salario) as "Salário Médio" FROM Empregado 
GROUP BY cargo;

-- 3. Mostre o cargo, número de empregados e o salário médio para cada cargo, desde que o cargo tenha pelo menos 2 empregados.
SELECT cargo, COUNT(*) as quantEmp, AVG(salario) as "Salário Médio" FROM Empregado 
GROUP BY cargo HAVING (quantEmp >= 2);

-- 4. Exiba o valor do salário (incluindo a comissão) mais alto da empresa. A comissao na tabela Empregado está em valor percentual.
SELECT MAX(salario + (salario * comissao / 100)) as "Salário mais alto da empresa" FROM Empregado;

-- 5. Exiba o valor do salário (incluindo a comissão) mais alto da empresa para cada cargo.
SELECT cargo, MAX(salario + (salario * comissao / 100)) as "Salário mais alto por cargo" FROM Empregado GROUP BY cargo;

-- 6. Exiba o salário médio por cargo, exceto para o cargo o de Administrador.
SELECT cargo, AVG(salario) as "Salário médio" FROM Empregado GROUP BY cargo HAVING cargo != "Administrador";

-- 7. Exiba a quantidade de cidades que a empresa atende, isto é, as cidades que possuem seção.
SELECT COUNT(DISTINCT cidade) as "Quant. cidades atendidas" FROM Secao;

-- 8. Exiba a quantidade de empregados que não possui chefe.
SELECT (COUNT(nome) - COUNT(chefe)) as "Empregados sem chefe" FROM Empregado;

-- 9. Exiba o custo total da empresa com pagamento de salário em cada seção, mas apresente somente a seção (e o custo), onde o custo total é superior a R$2500,00.
SELECT s.nome as "Seção", SUM((emp.salario + (emp.salario * emp.comissao/100))) as custoTotal
FROM Secao as s LEFT OUTER JOIN Empregado as emp ON s.idsec = emp.secao
GROUP BY s.nome HAVING custoTotal > 2500;

-- 10. (Imagem) -> Exiba o valor total de salários brutos para cada cargo em ordem crescente
SELECT cargo, SUM(salario) as Total FROM Empregado GROUP BY cargo ORDER BY Total ASC;