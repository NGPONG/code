import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class APP {
  public static void main(String[] args) throws IllegalAccessException, InstantiationException {
    Person.class.newInstance();
  }
}

class Person {
  public Person() {

  }

  public void speak() {
    System.out.println("hello,world");
  }
}