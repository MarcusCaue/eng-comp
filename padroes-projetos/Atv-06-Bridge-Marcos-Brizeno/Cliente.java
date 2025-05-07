import abstracao.*;
import implementacao.*;

public class Cliente {
	public static void main(String[] args) {
		JanelaAbstrata janela;

		// Criando uma janela de diálogo em um ambiente Linux
		janela = new JanelaDialogo(new JanelaLinux());
		janela.desenhar();

		// Criando uma janela de aviso em um ambiente Linux
		janela = new JanelaAviso(new JanelaLinux());
		janela.desenhar();

		// Criando uma janela de diálogo em um ambiente Windows
		janela = new JanelaDialogo(new JanelaWindows());
		janela.desenhar();
	}
}