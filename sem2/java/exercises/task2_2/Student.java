public class Student {
  private String student_id;
  private String name;
  private String[] courses;

  public String setStudentId(String id) {
    return this.student_id = id;
  }

  public String getStudentId() {
    return this.student_id;
  }

  public String setName(String name) {
    return this.name = name;
  }

  public String getName() {
    return this.name;
  }

  public void setCourses(String[] courses) {
    this.courses = courses;
  }

  public String[] getCourses() {
    return this.courses;
  }

  Student(String id, String name, String[] courses) {
    this.student_id = id;
    this.name = name;
    this.courses = courses;
  }

}
