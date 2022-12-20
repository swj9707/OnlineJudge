package Programmers.Practice.LV2;

class Solution {
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        char[][] MATRIX = new char[m][n];

        for(int i = 0; i < m; i++){
            MATRIX[i] = board[m - i - 1].toCharArray();
        }

        while(true){
            boolean flag = true;
            boolean[][] check = new boolean[m][n];

            for(int i = 0; i < m - 1; i++){
                for(int j = 0; j < n - 1; j++){
                    if(MATRIX[i][j] == '-'){
                        continue;
                    }
                    char tmp = MATRIX[i][j];
                    if(MATRIX[i][j + 1] == tmp && MATRIX[i + 1][j] == tmp && MATRIX[i + 1][j + 1] == tmp){
                        check[i][j] = check[i][j + 1] = check[i + 1][j] = check[i + 1][j + 1] = true;
                        flag = false;
                    }
                }
            }

            if(flag){
                break;
            }

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(check[i][j]){
                        MATRIX[i][j] = '-';
                        answer++;
                    }
                }
            }

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(MATRIX[i][j] == '-'){
                        for(int k = i; k < m; k++){
                            if(MATRIX[k][j] == '-'){
                                continue;
                            }
                            MATRIX[i][j] = MATRIX[k][j];
                            MATRIX[k][j] = '-';
                            break;
                        }
                    }
                }
            }
        }

        return answer;
    }
}