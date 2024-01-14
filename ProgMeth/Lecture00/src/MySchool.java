public class MySchool {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.id = 660101;
        s1.name = "Pop";
        s1.addScore(10);

        Student s2 = new Student();
        s2.id = 660102;
        s2.name = "Toe";
        s2.addScore(-100);

        s1.printInfo();
        s2.printInfo();
    }
}
