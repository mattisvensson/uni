package task2_6.classes;

import task2_6.interfaces.Enrollable;

public class Lecture implements Enrollable {
  private String[] enrolledStudents;
  private String name;
  private String[] topics;
  private String lecturer;

  public Lecture(String name, String[] topics, String lecturer) {
    this.name = name;
    this.topics = topics;
    this.lecturer = lecturer;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String[] getTopics() {
    return topics;
  }

  public void setTopics(String[] topcis) {
    this.topics = topcis;
  }

  public String getLecturer() {
    return lecturer;
  }

  public void setLecturer(String lecturer) {
    this.lecturer = lecturer;
  }

  public String[] getEnrolledStudents() {
    return enrolledStudents;
  }

  public void enrollStudent(String student) {
    if (enrolledStudents == null) {
      enrolledStudents = new String[1];
      enrolledStudents[0] = student;
    } else {
      String[] newEnrolled = new String[enrolledStudents.length + 1];
      System.arraycopy(enrolledStudents, 0, newEnrolled, 0, enrolledStudents.length);
      newEnrolled[enrolledStudents.length] = student;
      enrolledStudents = newEnrolled;
    }
  }

  @Override
  public void unenrollStudent(String student) {
    if (enrolledStudents != null) {
      for (int i = 0; i < enrolledStudents.length; i++) {
        if (enrolledStudents[i].equals(student)) {
          String[] newEnrolled = new String[enrolledStudents.length - 1];
          System.arraycopy(enrolledStudents, 0, newEnrolled, 0, i);
          System.arraycopy(enrolledStudents, i + 1, newEnrolled, i, enrolledStudents.length - i - 1);
          enrolledStudents = newEnrolled;
          break;
        }
      }
    }
  }
}
