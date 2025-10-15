#interface #estrutural

"Converter a interface de uma classe em **outra interface esperada** pelos clientes. Adapter permite a comunicação entre classes que não poderiam trabalhar juntas devido à incompatibilidade de suas interfaces."

Tem grandes chances de ser utilizado para não criar *acoplamento* entre o **sistema desenvolvido** com **bibliotecas de terceiros**.

Analogias do mundo real: T de energia, adaptador para interfaces de áudio (P2, P10), adaptador de USB-C para USB-B, etc.

Também pode ser utilizado para permitir a comunicação entre um **código legado** (muito comum) com um código mais moderno.

Adapter pode ser implementado tanto com *composição* (mais comum), como com *herança múltipla*.

O uso de *interfaces* permite que vários adaptadores sejam criados se um determinado serviço apresentar problemas.
- O código cliente se relaciona apenas com a *interface* e não com os adaptadores concretos.
- Essa técnica respeita o *Open-Closed Principle*

Todavia, uma das **desvantagens** é de que a a complexidade geral do código aumenta porque você precisa introduzir um **conjunto de novas interfaces e classes**. Algumas vezes é mais simples mudar a classe serviço para que ela se adeque com o resto do seu código.

Não é responsabilidade do Adapter ter **regras de negócio**, apenas as regras de **conversão** para fazer o cliente se comunicar com o serviço.

## Composição

![[adapter-composicao.png]]

## Herança

![[adapter-heranca.png]]
