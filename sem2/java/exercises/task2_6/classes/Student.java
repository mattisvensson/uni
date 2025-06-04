package task2_6.classes;

public class Student extends Person {
  private String studentId;
  private String[] courses;
  private String immatriculationYear;

  public Student(String name, Integer age, String city, String studentId, String[] courses, String immatriculationYear) {
    super(name, age, city);
    this.studentId = studentId;
    this.courses = courses;
    this.immatriculationYear = immatriculationYear;
  }

  public String getStudentId() {
    return studentId;
  }
  public void setStudentId(String studentId) {
    this.studentId = studentId;
  }
  public String[] getCourses() {
    return courses;
  }
  public void setCourses(String[] courses) {
    this.courses = courses;
  }
  public String getImmatriculationYear() {
    return immatriculationYear;
  }
  public void setImmatriculationYear(String immatriculationYear) {
    this.immatriculationYear = immatriculationYear;
  }
}
