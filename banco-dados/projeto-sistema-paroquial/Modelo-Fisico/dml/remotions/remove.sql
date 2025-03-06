-- Remoções simples
DELETE FROM Dizimo WHERE data = "2006-06-27";
DELETE FROM Igreja WHERE id = 17;

-- Removendo um fiel
DELETE FROM FielParticipaPastoral WHERE fiel_fk = 5; -- Participante de uma pastoral
DELETE FROM FielParticipaPastoral WHERE pastoral_fk = 10; -- Removendo os membros da pastoral da qual a fiel era coordenadora
DELETE FROM Pastoral WHERE coordenador_fk = 5; -- Coordenadora da pastoral
DELETE FROM Batismo WHERE pessoa_batizada_fk = 5; -- Removendo seu registro de batismo
DELETE FROM PessoaEhPadrinho WHERE pessoa_fk = 5; -- Removendo seu registro como madrinha de um batismo
DELETE FROM Pessoa WHERE fiel_fk = 5; -- Removendo da tabela genérica Pessoa
DELETE FROM TurmaCatequese WHERE catequista_fk = 5; -- Removendo a turma de catequese coordenada pela pessoa
DELETE FROM Fiel WHERE id = 5; -- Finalmente excluindo o registro da fiel
