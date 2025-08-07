Não é um dos padrões definidos pelo *GOF* em seu livro, mas também é um padrão de projeto utilizado para resolver problemas no desenvolvimento de software.

Dentro do padrão arquitetural *MVC*, ele está na camada de Modelo.

Ele não é a **entidade[^1]**, mas se relaciona com ela.

Existe também, na programação, uma camada de **persistência**, responsável por pegar os dados da aplicação e registrá-los no banco de dados.

O *repository* é um padrão que fornece uma interface entre a entidade e o banco de dados
- Possui regras de negócio que conseguem moldar a entidade numa representação que o banco de dados entende.
- O movimento contrário também acontece: pega os dados da entidade salvos no banco de dados e os transforma na representação da entidade que a aplicação entende.

Se fôssemos classificá-lo, ele provavelmente seria um padrão de #construcao.

[^1]: As coisas do mundo real, com seus atributos e métodos, representadas no sistema.