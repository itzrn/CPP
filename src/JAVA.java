public class JAVA {
    int a; int b;
    JAVA(int a, int b){
        this.a = a;
        this.b = b;
    }
    public static void main(String[] args) {
        JAVA[] arr = new JAVA[2];
        for(int i=0;i<2;i++){
            arr[0] = new JAVA(10, 12);
        }

    }
}
