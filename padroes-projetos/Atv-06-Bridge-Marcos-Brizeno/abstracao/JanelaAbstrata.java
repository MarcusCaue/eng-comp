package abstracao;

public abstract class JanelaAbstrata {

	protected JanelaImplementada janela;

	public JanelaAbstrata(JanelaImplementada j) {
		this.janela = j;
	}

	public void desenharJanela(String titulo) {
		this.janela.desenharJanela(titulo);
	}

	public void desenharBotao(String titulo) {
		this.janela.desenharBotao(titulo);
	}

	public abstract void desenhar();

}
