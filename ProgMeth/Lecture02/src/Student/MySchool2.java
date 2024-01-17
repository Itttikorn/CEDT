package Student;

import java.util.ArrayList;

public class MySchool2 {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<Student>();
        students.add(new Student());
        students.add(new UndergraduateStudent("Pop"));
        students.add(new GraduateStudent("Toe"));
        students.add(new GraduateStudent("Lisa"));

        for(Student s : students){
            s.printName();
        }
    }
}
