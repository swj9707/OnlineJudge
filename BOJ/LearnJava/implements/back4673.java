package BOJ.LearnJava.implements;

import java.util.*;
import java.io.*;

public class back4673 {
    public static void main(String[] args) {
 
        boolean [] a = new boolean[10001];
 
        for (int i = 1; i<10001; i++) {
            int n = d(i);
 
            if (n < 10001) {
                a[n] = true;
            }
        }
            for (int i = 1; i < 10001; i++) {
                if (a[i]==false) {
                    System.out.println(i);
                }
            }
 
    }
    public static int d(int number){
        int sum = number;
        while (number != 0){
            sum += number%10;                   
            number = number/10;              
        }
        return sum;                       
    }
}
