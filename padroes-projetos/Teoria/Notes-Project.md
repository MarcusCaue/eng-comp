
## 1 - Login Facade

Abrir o terminal -> Login/Cadastro de Usuário (Comum ou Administrador)

1 - Para que haja um login/cadastro, é preciso acessar o **Banco de Dados**
2 - O que vai diferenciar um usuário comum de um administrador será o **padrão do email** .
	Emails de adms terminarão em **@admin.ifpb.edu.br**
3 - A depender de qual tipo de usuário logou, cada um vai ter acesso a partes diferentes do sistema (outras fachadas)

## 2 - Entidades

Empréstimo {
	- id: String (uuid)
	- situacao: boolean
	- dataEmprestimo: String
	- dataDevolucao: String
	- livro: String
	- usuarioPossuidor: String
}

Livro {
	- id: String
	- titulo: String
	- autor: String
	- anoPublicacao: int
	- editora: String
	- isbn: String
	- usuarioDoador: String
	- quantVezesEmprestado: int
}

