package task2_6;

import task2_6.classes.Lecture;

public class Main {
  public static void main(String[] args) {
    System.out.println("Hello World");

    String[] topics = {"Analysis", "Integrals", "Differential Equations"};
    Lecture lecture = new Lecture("Math", topics, "John Doe");
    
    lecture.enrollStudent("Alice");
    lecture.enrollStudent("Bob");
    
    System.out.println("Lecture Name: " + lecture.getName());
    System.out.println("Lecturer: " + lecture.getLecturer());
    System.out.println("Enrolled Students: ");
    for (String student : lecture.getEnrolledStudents()) {
      System.out.println(student);
    }
  }
}