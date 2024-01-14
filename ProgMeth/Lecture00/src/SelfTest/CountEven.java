package SelfTest;

public class CountEven {
    public static int countEven(int[] a){
        int count = 0;
        for(int e : a){
            if(e%2==0){
                count++;
            }
        }
        return count;
    }
}
