/**
 * Para este exemplo foi utilizado a biblioteca EmailValidator do Apache Commons
 * Disponível em: https://commons.apache.org/proper/commons-validator/download_validator.cgi
 * Acesso em: 06/05/2025
 
*/

import org.apache.commons.validator.routines.EmailValidator;
import java.util.Scanner;
import objectmethod.*;

public class Main {
  public static void formaAcoplada() {
    System.out.println("\n=============== FORMA ACOPLADA, SEM ADAPTER ===============\n");
    Scanner sc = new Scanner(System.in);

    System.out.print("Digite seu email: ");
    String email =  sc.next();

    EmailValidator validator = EmailValidator.getInstance();

    if (validator.isValid(email)) {
      System.out.println("Email válido");
    } else {
      System.out.println("Email inválido");
    }
  }
  
  public static void comAdapter(EmailValidatorInterface emailValidator) {
    System.out.println("\n=============== COM O ADAPTER ===============\n");
    Scanner sc = new Scanner(System.in);

    System.out.print("Digite seu email: ");
    String email =  sc.next();

    if (emailValidator.isEmailValid(email)) {
      System.out.println("Email válido usando o adapter");
    } else {
      System.out.println("Email inválido usando o adapter");
    }
  }
  public static void main(String[] args) {
    formaAcoplada();
    comAdapter(new EmailValidatorAdapter());
    comAdapter(new EmailMailtrapAdapter());
  }
}