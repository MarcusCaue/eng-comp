#construcao 

O padrão *Abstract Factory* busca solucionar um problema do [[Factory Method]], que é o crescimento linear da quantidade de classes produto e classes construtoras. 

Isso quer dizer que toda vez que se adiciona um novo produto, uma classe construtora também é adicionada e isso pode ser problemático se o domínio do problema tiver **muitos produtos**. 

A abordagem que o Abstract Factory segue para resolver esse desafio é tratar os produtos e as classes construtoras em **conjuntos**, em **grupos**. 

Sendo assim, quando o cliente solicita um objeto, ao invés de pedir diretamente qual produto específico ele quer, ele pede que a construtora específica forneça o objeto específico que ela constrói, o qual, de sua parte, pertence a um grupo específico. 

Assim fica mais fácil de tratar os produtos específicos, porém é necessário ter controle sobre os grupos de produtos, e sempre que um **novo grupo é criado**, cada “fabricante" precisa implementar um método para a construção de um objeto específico que pertença a esse grupo.

![[abstract-factory.png]]

Exemplos em código estão disponíveis no [Marcos Brizeno](https://brizeno.wordpress.com/2011/09/18/mao-na-massa-abstract-factory/).