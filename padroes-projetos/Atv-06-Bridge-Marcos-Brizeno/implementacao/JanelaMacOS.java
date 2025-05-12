package implementacao;

import abstracao.JanelaImplementada;

public class JanelaMacOS implements JanelaImplementada {

    public void desenharJanela(String titulo) {
        System.out.println(titulo + " - Janela MacOS");
    }

    public void desenharBotao(String titulo) {
        System.out.println(titulo + " - Botão MacOS");
    }

}