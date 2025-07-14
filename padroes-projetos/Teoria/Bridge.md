#interface 

"Desacoplar uma **abstração** de sua **implementação** para que os dois possam variar independentemente."

**Problema:** 
- Tem-se um **produto** (livro, janela, copo, caneta, caderno) e uma **via de acesso** a ele (compra virtual, compra física, troca, empréstimo).
- Para cada novo produto adicionado, deve-se implementar cada uma das vias de acesso para chegar nele.
- E para cada nova via de acesso, deve-se fazer com que seja possível chegar a cada um dos produtos através dela.
- Pense isso num sistema complexo (que é o ordinário)...  --> **Crescimento exponencial**

Uma **abstração** é uma hierarquia de classes que define ações que devem ser feitas, enquanto que a **implementação** é uma hierarquia que põe em prática essas ações definidas.

É um padrão que torna o código apto a receber alterações e ficar maior (aumentar em escala).

Muito usado em classes que possuem variantes:
- Caneta -> CanetaVermelha, CanetaAzul, CanetaPreta
- Publicação -> Livro, Artigo, Jornal, DVD, CD, Revista
- Janela -> JanelaDialogo - Janela -> JanelaWindows, JanelaLinux, JanelaMac

![[bridge.png]]

