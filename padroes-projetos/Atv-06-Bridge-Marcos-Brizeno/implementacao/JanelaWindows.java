package implementacao;

import abstracao.JanelaImplementada;

public class JanelaWindows implements JanelaImplementada {

	public void desenharJanela(String titulo) {
		System.out.println(titulo + " - Janela Windows");
	}

	public void desenharBotao(String titulo) {
		System.out.println(titulo + " - Botão Windows");
	}

}
