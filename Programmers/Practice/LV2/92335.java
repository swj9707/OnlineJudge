package Programmers.Practice.LV2;

class Solution {

    public String toKNum(int n, int k){
        String res = "";
        while(n > 0){
            res = n % k + res;
            n /= k;
        }
        return res;
    }

    public boolean isPrime(long n){
        if(n <=1) return false;
        else if (n == 2) return true;
        for(int i = 2; i <= Math.sqrt(n); i++){
            if ( n % i == 0){
                return false;
            }
        }
        return true;
    }

    public int solution(int n, int k) {
        int answer = 0, i, j;
        String tmp = toKNum(n, k);
        for(i = 0; i < tmp.length(); i = j){
            for(j = i + 1; j < tmp.length() && tmp.charAt(j) != '0'; j++);
                if(isPrime(Long.parseLong(tmp.substring(i, j)))){
                    answer++;
                }
        }
        return answer;
    }
}