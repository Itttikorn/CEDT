public class Student {
    // 1) properties
    int id;
    String name;
    int score;

    // 2) actions (methods)
    void addScore(int s){
        this.score += s;
    }

    void printInfo(){
        System.out.println("Student ID:\t\t" + this.id);
        System.out.println("Student Name:\t" + this.name);
        System.out.println("Score:\t\t\t" + this.score);
    }
}
