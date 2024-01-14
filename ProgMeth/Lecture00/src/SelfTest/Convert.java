package SelfTest;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class Convert {
    public static String[] convert(String[] s)  throws FileNotFoundException{
        ArrayList<Pair> a = new ArrayList<Pair>();
        Scanner fileScanner = new Scanner(new File("src/SelfTest/mapping.txt"));
        while (fileScanner.hasNext()) { // อ่านมาหนึ่งบรรทัด
            //แล้วให้ Scanner ตัวที่สอง รับบรรทัดนั ้นเข้ามา แต่ยังไม่แสกนของในนั ้น
            Scanner line = new Scanner(fileScanner.nextLine());
            //แล้วบอก SCanner ตัวที่สอง ว่าของแต่ละชิ ้นที่อ่าน ให้คั่นด้วยคอมม่า
            line.useDelimiter(",");
            // แล้วสามารถ next() เพื่ออ่านดาต้าทีละตัว แยกด้วยคอมม่านั่นเอง ตรงนี ้ถ้าคอมม่ามีเยอะก็คงต้องใช้ลูป
            String data1 = line.next().trim();
            String data2 = line.next().trim();
            Pair p1 = new Pair();
            p1.x = data1;
            p1.y = data2;
            a.add(p1);
            Pair p2 = new Pair();
            p2.x = data2;
            p2.y = data1;
            a.add(p2);
        }
//        for(Pair sp : a){
//            System.out.println(sp.x + " " + sp.y);
//        }
//        System.out.println("array s");
//        for(String ss : s){
//            System.out.println(ss);
//        }
        String[] ans = new String[s.length];
        for(int i=0;i<s.length;i++){
            boolean found = false;
            for(Pair sp : a){
                //System.out.println(Objects.equals(sp.x, s[i]));
                if(Objects.equals(sp.x, s[i])){
                    ans[i] = sp.y;
                    System.out.println("found");
                    found = true;
                    break;
                }
            }
            if(!found){
                ans[i] = "No match";
            }
        }
        return ans;

    }

//    public static void main(String[] args) throws FileNotFoundException {
//        String[] s1 = { "5", "1", "a", "7", "F" };
//        String[] ans = convert(s1);
//        for(String e : ans){
//            System.out.println(e);
//        }
//    }
}
