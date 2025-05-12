public class Course {
  private String course_id;
  private String title;

  public String setCourseId(String course_id) {
    return this.course_id = course_id;
  }

  public String getCourseId() {
    return this.course_id;
  }

  public String setTitle(String title) {
    return this.title = title;
  }

  public String getTitle() {
    return this.title;
  }

  Course(String course_id, String title) {
    this.course_id = course_id;
    this.title = title;
  }
}
