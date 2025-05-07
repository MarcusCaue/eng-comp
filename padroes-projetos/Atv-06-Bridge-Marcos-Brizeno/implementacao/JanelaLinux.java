package implementacao;

import abstracao.JanelaImplementada;

public class JanelaLinux implements JanelaImplementada {

	public void desenharJanela(String titulo) {
		System.out.println(titulo + " - Janela Linux");
	}
	
	public void desenharBotao(String titulo) {
		System.out.println(titulo + " - Botão Linux");
	}

}
