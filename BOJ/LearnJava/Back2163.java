package BOJ.LearnJava;
import java.util.Scanner;

public class Back2163 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int count = M * N - 1;
        System.out.println(count);
    }
}