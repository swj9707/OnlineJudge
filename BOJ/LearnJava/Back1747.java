package BOJ.LearnJava;

import java.util.Scanner;

public class Back1747 {
    public static void main(String[] args){
        int MAX = 1004000;
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[MAX];
        for(int i = 1; i <= MAX; i++){
            arr[i] = i;
        }
        for(int i = 2; i * i <= MAX; i++){
            if(arr[i] == -1) continue;
            for(int j = i * 2; j <= MAX; j += i){
                arr[j] = -1;
            }
        }
        arr[0] = arr[1] = -1;
        int N;
        N = sc.nextInt();
        for(int i = N; i <= MAX; i++){
            if(arr[i] != -1){
                if(isPalindrom(arr[i])){
                    System.out.print(arr[i]);
                    break;
                }
            }
        }
    }
    public static boolean isPalindrom(int inputData){
        String str = Integer.toString(inputData);
        for(int i = 0 ; i < str.length(); i++){
            if(str.charAt(i) != str.charAt(str.length() - i - 1)){
                return false; 
            }
        }
        return true;
    }
}
