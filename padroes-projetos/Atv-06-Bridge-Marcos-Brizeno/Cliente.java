import java.util.Scanner;
import abstracao.*;
import implementacao.*;

public class Cliente {
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		JanelaAbstrata janela;

		janela = new JanelaDialogo(new JanelaLinux()); // janela de diálogo em um ambiente Linux
		janela.desenhar();

		janela = new JanelaAviso(new JanelaLinux()); // janela de aviso em um ambiente Linux
		janela.desenhar();

		janela = new JanelaDialogo(new JanelaWindows()); // janela de diálogo em um ambiente Windows
		janela.desenhar();

		System.out.println("\n ============ JANELAS MACOS ============\n");
		
		// Janelas em um sistema MacOS
		janela = new JanelaDialogo(new JanelaMacOS());
		janela.desenhar();

		janela = new JanelaAviso(new JanelaMacOS());
		janela.desenhar();

		// Janela com entrada de dados
		System.out.println("\n ============ JANELAS COM ENTRADA DE DADOS ============\n");

		janela = new JanelaEntradaDados(new JanelaMacOS()); // MacOS
		janela.desenhar();

		String dados = entrada.nextLine();
		System.out.println();

		janela = new JanelaEntradaDados(new JanelaWindows()); // Windows
		janela.desenhar();

		dados = entrada.nextLine();
		System.out.println();

		janela = new JanelaEntradaDados(new JanelaLinux()); // Linux
		janela.desenhar();

		dados = entrada.nextLine();
		System.out.println();

		entrada.close();
	}
}