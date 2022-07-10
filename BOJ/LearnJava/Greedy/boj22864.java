import java.util.*;
import java.io.*;

public class boj22864 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int A, B, C, M;
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        M = sc.nextInt();
        int fatigue = 0;
        int work = 0;
        for(int time = 1; time <= 24; time++){
            if(fatigue + A <= M){
                fatigue += A;
                work += B;
            } else {
                fatigue -= C;
                if(fatigue < 0) fatigue = 0;
            }
        }
        System.out.println(work);
    }
    
}
