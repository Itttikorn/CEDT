package SelfTest;

import static org.junit.jupiter.api.Assertions.assertNull;

public class partialArray {
    public static int[] partialArray(int[] a, int i, int j){
        if(a==null) return null;
        if(i>=j) return null;
        if(j>a.length) return null;
        int size = a.length - (j - i);
        int[] b = new int[size];
        int pos=0;
        for(int n=0;n<a.length;n++){
            if(n<i || n>=j){
                b[pos] = a[n];
                System.out.println(b[pos]);
                pos++;
            }
        }
        return b;
    }

//    public static void main(String[] args) {
//        int[] a = { 1, 2, 3, 4, 5 };
//        int[] b = partialArray.partialArray(a, 3, 5);
//        for(int e : b){
//            System.out.println(e);
//        }
//    }
}
