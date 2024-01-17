package Student;

public class MySchool3 {
    public static void main(String[] args) {
        Student s1 = new GraduateStudent("Name");
        giveSpecialGrade(s1);
        System.out.println(s1.getCourseGrade());
    }

    public static void giveSpecialGrade(Student s) {
        if (s instanceof GraduateStudent) {
            s.setCourseGrade("A++");
        } else s.setCourseGrade("F");
    }
}
