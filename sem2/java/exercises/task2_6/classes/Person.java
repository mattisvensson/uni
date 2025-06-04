package task2_6.classes;

public class Person {
  private String name;
  private Integer age;
  private String city;

  Person(String name, Integer age, String city) {
    this.name = name;
    this.age = age;
    this.city = city;
  }

  public String setName(String name) {
    return this.name = name;
  }
  public String getName() {
    return this.name;
  }
  public Integer setAge(Integer age) {
    return this.age = age;
  }
  public Integer getAge() {
    return this.age;
  }
  public String setCity(String city) {
    return this.city = city;
  }
  public String getCity() {
    return this.city;
  }
}
