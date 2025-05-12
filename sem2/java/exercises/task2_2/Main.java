public class Main {
  public static void main(String[] args) {
    Course courseA = new Course(args[0], args[1]);
    Course courseB = new Course(args[2], args[3]);
    Course courseC = new Course(args[4], args[5]);

    String[] studentACourses = {args[8], args[9]};
    Student studentA = new Student(args[6], args[7], studentACourses);
    
    String[] studentBCourses = {args[12], args[13]};
    Student studentB = new Student(args[10], args[11], studentBCourses);
    
    String[] studentCCourses = {args[16], args[17]};
    Student studentC = new Student(args[14], args[15], studentCCourses);
  
    printStudentDetails(studentA);
    printStudentDetails(studentB);
    printStudentDetails(studentC);
    printCourseDetails(courseA);
    printCourseDetails(courseB);
    printCourseDetails(courseC);
  }

  // Helper method to print student details
  public static void printStudentDetails(Student student) {
    System.out.println("Student Name: " + student.getName());
    System.out.println("Student ID: " + student.getStudentId());
    System.out.println("Courses:");
    for (String course : student.getCourses()) {
      System.out.println("  - " + course);
    }
    System.out.println();
  }

  // Helper method to print course details
  public static void printCourseDetails(Course course) {
    System.out.println("Course ID: " + course.getCourseId());
    System.out.println("Course Title: " + course.getTitle());
    System.out.println();
  }
}