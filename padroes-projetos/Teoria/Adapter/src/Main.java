public class Main {
  public static void main(String[] args) {
    // Interfaces não possuem instâncias mas servem como ponteiros, invocando os métodos implementados através de polimorfismo.
    AdapterInterface i;
    ServidorAdapter sa = new ServidorAdapter();
    ServerAdaptador sa2 = new ServerAdaptador();

    i = sa;
    i.exibirMensagem();
    i = sa2;
    i.exibirMensagem();
  }
}