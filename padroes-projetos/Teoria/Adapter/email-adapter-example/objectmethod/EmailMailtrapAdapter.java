package objectmethod;

import mailtrapioemailregex.EmailValidation;

public class EmailMailtrapAdapter implements EmailValidatorInterface {
  public boolean isEmailValid(String email) {
    EmailValidation mailtrapValidator = new EmailValidation();
    return mailtrapValidator.validaEmail(email);
  }
}