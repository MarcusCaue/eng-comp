package abstracao;

public class JanelaAviso extends JanelaAbstrata {

	public JanelaAviso(JanelaImplementada j) {
		super(j);
	}

	public void desenhar() {
		desenharJanela("Janela de Aviso");
		desenharBotao("Ok");
	}

}