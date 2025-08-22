#responsabilidade

Centraliza a responsabilidade em uma **única instância** de uma classe, sendo acessível a **todo o sistema** por um ponto de acesso **global**.

Exemplos: `out`, `cin`, `cout`, `endl` e entre outros objetos.

Evita a criação de várias instâncias desnecessárias.

Usos:
- Único objeto que acessa o banco de dados
- Único ponto de acesso ao arquivo global de log
- Única *[[Facade]]*

Estrutura do *Singleton*:
```java
public class Singleton {
	private dados : tipos
	private instancia : Singleton = null

	// Construtor privado é essencial 
	// para que nenhuma outra classe instancie o singleton
	private Singleton() {}

	// Ponto de acesso único à instância
	public static Singleton getInstancia() {
		if (this.instancia == null) {
			this.instacia = new Singleton();
		}
		return this.instancia;
	}

	public tipos operacoes() {...}
	public tipos getters() {...}
	public tipos setters() {...}
}
```