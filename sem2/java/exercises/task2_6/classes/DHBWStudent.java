package task2_6.classes;

public class DHBWStudent extends Student {
  private String DHBWlocation;

  public DHBWStudent(String name, Integer age, String city, String studentId, String[] courses, String immatriculationYear, String DHBWlocation) {
    super(name, age, city, studentId, courses, immatriculationYear);
    this.DHBWlocation = DHBWlocation;
  }
  public String getDHBWlocation() {
    return DHBWlocation;
  }
  public void setDHBWlocation(String DHBWlocation) {
    this.DHBWlocation = DHBWlocation;
  }
}
