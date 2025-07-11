#construcao 

De sua parte, o padrão *Factory Method* possui algumas similaridades ao padrão de interface *Bridge*, ao desacoplar a hierarquia de classes do **objeto produto** da hierarquia de **classes construtoras**, de modo que ambas possam se desenvolver independentemente.

Para o cliente obter o objeto, ele precisa solicitá-lo ao construtor específico que o “fabrica”.

Nesse padrão, sempre que um novo produto for adicionado à hierarquia, será necessário também adicionar uma classe construtora para ele.

![[factory-method.png]]

Para exemplos em código, consulte o [Marcos Brizeno](https://brizeno.wordpress.com/2011/09/17/mao-na-massa-factory-method/). 