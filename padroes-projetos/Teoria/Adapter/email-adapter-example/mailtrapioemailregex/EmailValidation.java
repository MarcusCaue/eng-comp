package mailtrapioemailregex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class EmailValidation {
  private final String regex = "^[\\w!#$%&'*+/=?`{|}~^-]+(?:\\.[\\w!#$%&'*+/=?`{|}~^-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,6}$";

  public boolean validaEmail(String email) {
    Pattern pattern = Pattern.compile(regex);
    Matcher matcher = pattern.matcher(email);
    return matcher.matches();
  }
}