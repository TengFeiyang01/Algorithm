import java.util.*;
public class Main{
    static int N = 200010;
    static int n, m ;
    static long[] w = new long[N];
    static long[] f = new long[N];
    static long[] q = new long[N];
    public static void main(String[] argrs){
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        for (int i = 1 ; i <= n ; i ++ ) w[i] = scan.nextInt();
        m = scan.nextInt();

        long res = -1e16;
        f[1] = w[1];
        for (int i = 2 ; i <= n ; i ++ ){
            for (int j = i - m; j < i; j++) {
                f[i] = Math.max(f[i], f[j] + w[i]);
            }
        } 

        System.out.println(f[n]);
    }
}
