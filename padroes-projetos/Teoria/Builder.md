#construcao 

Quando um objeto é construído através do padrão *Builder*, o cliente o obtém através de um **"fornecedor de objetos"**, o qual está relacionado com um **"construtor de objetos"** genérico que pode se especializar a depender do tipo de produto especializado que o cliente requisita.

Para fazer a construção do objeto, o "construtor" define métodos para a instanciação de **cada um dos atributos** do objeto, de modo que as **regras de negócio para os atributos** possam estar **modularizadas** e possam ser definidas pelos "construtores especializados". 

Ou seja, a construção do objeto ocorre em etapas e um objeto especializado é obtido pelo cliente quando ele informa para o fornecedor qual tipo de "construtor especializado" **"fabrica"** o objeto que ele quer.

![[builder.png]]

Consulte o [Marcos Brizeno](https://brizeno.wordpress.com/2011/09/25/mao-na-massa-builder/) para ver os exemplos em código.