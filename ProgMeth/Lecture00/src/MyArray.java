import java.util.Scanner;

public class MyArray {
    public static void main(String[] args) {
        int[] scores = new int[3];
        Scanner s = new Scanner(System.in);
        for(int i=0;i<3;i++) {
            scores[i] = s.nextInt();
        }
        for(int i : scores){
            System.out.println(i);
        }
    }
}
