package task2_6.classes;

public class Company {
  private String name;
  private String[] employees;
  private String[] dualStudents;

  public Company(String name, String[] employees, String[] dualStudents) {
    this.name = name;
    this.employees = employees;
    this.dualStudents = dualStudents;
  }
  public String getName() {
    return name;
  }
  public void setName(String name) {
    this.name = name;
  }
  public String[] getEmployees() {
    return employees;
  }
  public void setEmployees(String[] employees) {
    this.employees = employees;
  }
  public String[] getDualStudents() {
    return dualStudents;
  }
  public void setDualStudents(String[] dualStudents) {
    this.dualStudents = dualStudents;
  }
}
