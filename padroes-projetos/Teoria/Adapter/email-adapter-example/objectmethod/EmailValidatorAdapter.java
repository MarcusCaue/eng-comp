package objectmethod;

import org.apache.commons.validator.routines.EmailValidator;

public class EmailValidatorAdapter implements EmailValidatorInterface {
  private EmailValidator validator;

  public EmailValidatorAdapter() {
    this.validator = EmailValidator.getInstance();
  }

  public boolean isEmailValid(String email) {
    return validator.isValid(email);
  }
}
