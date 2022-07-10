import java.util.*;

public class boj16206 {
    public static int N, M;
    class cut{
        public void cut(int e){
            if(M <= 0) return;
            else{
                e -= 10;
                
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        N = sc.nextInt();
        M = sc.nextInt();
        for(int i = 0; i < N; i++){
            int next = sc.nextInt();
            list.add(next);
        }


    }
}
