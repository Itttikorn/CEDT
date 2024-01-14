package SelfTest;

public class RowToColumn {
    public static int[][] rowToColumn(int[][] a){
        int[][] b = new int[a.length][a.length];
        int row=0,column=0;
        for(int i=0;i<a.length;i++){
            row=0;
            for(int j=0;j<a[i].length;j++){
                System.out.println(i+""+j+""+row+""+column);
                System.out.println( b[row][column] +""+ a[i][j]);
                b[row][column] = a[i][j];
                row++;
            }
            column++;
        }
        return b;
    }

    public static void main(String[] args) {
        int[][] a = {{1,2,3},{4,5,6},{7,8,9}};
        int[][] b = RowToColumn.rowToColumn(a);
        for(int[] c : b){
            for(int d:c){
                System.out.print(d);
            }
            System.out.print("\n");
        }
    }
}
