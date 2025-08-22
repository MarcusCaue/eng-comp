#responsabilidade 

Define uma dependência **um-para-muitos** entre objetos para que quando um objeto **mudar de estado**, todos os seus dependentes sejam **notificados** e **atualizados** automaticamente.

![[images/observer.png]]

`Sujeito`: Abstração de toda entidade que pode ser observada; define o comportamento que as entidades vão ter com os observadores; possui a função `notificar()` a fim de atualizar todos os observadores sobre as mudanças de propriedades (**mudança de estado)**.

`SujeitoConcreto`: Especialização de uma entidade que realmente vai ser observada com dados concretos.

`ObservadorConcreto`: Entidade que observa um `SujeitoConcreto`, implementando a função `atualizar()` de modo a ter o estado atual do objeto observado.

> [!Observação]
> O padrão *Observer* supõe que essas notificações aconteçam em **tempo de execução**, com os observadores e os observados **em memória**, sem que a aplicação precise ser reiniciada.

Possíveis aplicações: 
- Um repositório **global** no Github que é observado por todos os repositórios **locais** que o clonaram.
- Um mesmo servidor web, relacionado a um banco de dados, que é observado por várias páginas web *front-end* que fazem requisições periódicas a ele afim de exibirem as informações do banco de dados de um modo mais elegante.
- Notificações (seja via email, telefone, etc.) sobre a disponibilidade de um produto ou sobre promoções aplicadas a ele.