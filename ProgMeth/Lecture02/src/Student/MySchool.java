package Student;

public class MySchool {
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new CEDTStudent();
        Student s3 = new UndergraduateStudent("Pop");
        Student s4 = new GraduateStudent("Toe");

        CEDTStudent d1 = (CEDTStudent) s2;
        d1.setInternCompany("Google");

        //CEDTStudent d2 = (CEDTStudent) s1;
        //d2.setInternCompany("Facebook");

    }
}
