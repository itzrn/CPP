import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
class Main {
    public static FastReader sc = new FastReader();
    public static int mod = 1000000007;

    public static void main(String[] args) {
        int t=sc.nextInt();
        while(t-->0){
            System.out.println(t);
            // solve();
        }
    }

    public static void solve() {
        long a = sc.nextLong();
        long b = sc.nextLong();

        System.out.println((a+b)%3 == 0 && Math.min(a, b)*2 >= Math.max(a, b)?"YES":"NO");
    }

    public static void swapLong(long a, long b){
        long temp = a;
        a=b;
        b=temp;
    }
    public static void swap(int a, int b){
        int temp=a;
        a=b;
        b=temp;
    }
    public static class FastReader{
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static int[] readIntArray(int n){
        int[] arr = new int[n+1];
        for(int i=1; i<=n; i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public static String readString(){
        return sc.next();
    }
    // swapping methods
    public static void swapInLongArray(long[] arr, int a, int b){
        long temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void swapInIntArray(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void swapInCharArray(char[] arr, int i, int j){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public long combinationInt(int n, int r){
        r = Math.min(r, n-r);
        long ans = n;
        for(int i=2; i<=r; i++){
            ans *= --n;
            ans /= i;
        }
        return ans;
    }
    static boolean isPrime(long n) {
        if (n < 2)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
 
        for (long i = 6; i * i <= n; i += 6) {
            if ((n % (i - 1) == 0) || (n % (i + 1) == 0)) {
                return false;
            }
        }
        return true;
    }
    public static long gcd(long a, long b) {
        return b == 0L ? a : gcd(b, a % b);
    }
    public static void swapThreeCharInLeftCircular(char[] str, int i, int j, int k){
        char x = str[k];
        str[k] = str[i];
        str[i] = str[j];
        str[j] = x;
    }
    public static void swapThreeCharInRightCircular(char[] str, int i, int j, int k){
        char x = str[i];
        str[i] = str[k];
        str[k] = str[j];
        str[j] = x;
    }
    public static int highestPowerOf2(int x) {
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x ^ (x >> 1);
    }
    public static double pow(int base, int exponent) { // this is the alternate of Math.pow in java to make compilation fast
        if(base == 0) return 0;
        if(exponent == 0) return 1;
        int absExponent = (exponent < 0)? exponent * -1 : exponent;
        double result = base;
        for(int i = 1; i < absExponent; i++) {
            result *= base;
        }
        if(exponent < 1) result = 1 / result;
        return result;
    }
}