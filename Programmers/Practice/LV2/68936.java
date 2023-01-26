package Programmers.Practice.LV2;

class Solution {
    static int[] answer = new int[2];
    public int[] solution(int[][] arr) {
        quard(0, 0, arr.length, arr);
        return answer;
    }

    public boolean check(int x, int y, int size, int[][] arr){
        for(int i = x; i < x + size; i++){
            for(int j = y; j < y + size; j++){
                if(arr[x][y] != arr[i][j]) return false;
            }
        }
        return true;
    }

    public void quard(int startX, int startY, int size, int[][] arr) {
        if(check(startX, startY, size, arr)){
            answer[arr[startX][startY]]++;
            return;
        }

        quard(startX, startY, size / 2, arr);
        quard(startX + size / 2, startY, size / 2, arr);
        quard(startX, startY + size / 2, size / 2, arr);
        quard(startX + size / 2, startY + size / 2, size / 2, arr);
        
    }
}