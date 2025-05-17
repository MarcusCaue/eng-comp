package abstracao;

public class JanelaEntradaDados extends JanelaAbstrata {

    public JanelaEntradaDados(JanelaImplementada janela) {
        super(janela);
    }

    public void desenhar() {
        this.janela.desenharJanela("Janela de Entrada de Dados");
        this.janela.desenharBotao("Botão Fechar");
        this.janela.desenharBotao("Botão Limpar");
        this.janela.desenharBotao("Botão Enviar");
        System.out.print("Entre com os dados: ");
    }
    
}
