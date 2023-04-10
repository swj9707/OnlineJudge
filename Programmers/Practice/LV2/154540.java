package Programmers.Practice.LV2;

import java.util.*;

class Solution {

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static boolean[][] visit = new boolean[100][100];

    public int[] solution(String[] maps) {
        List<Integer> answer = new ArrayList<>();
        int N = maps.length;
        int M = maps[0].length();

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) {
                if(maps[i].charAt(j) != 'X' && !visit[i][j]){
                    answer.add(BFS(i, j, N, M, maps));
                }
            }
        }

        if(answer.size() == 0) {
            answer.add(-1);
        }

        return answer.stream().sorted(Comparator.naturalOrder()).mapToInt(Integer::intValue).toArray();
    }

    public static int BFS(int x, int y, int N, int M, String[] maps) {
        int result = 0;

        visit[x][y] = true;
        Deque<int[]> que = new ArrayDeque<>();
        result += maps[x].charAt(y) - '0';
        que.add(new int[] {x, y});

        while(!que.isEmpty()) {
            int X = que.peek()[0];
            int Y = que.peek()[1];
            que.pop();

            for(int i = 0; i < 4; i++){
                int nx = X + dx[i];
                int ny = Y + dy[i];

                if(nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[nx][ny] && maps[nx].charAt(ny) != 'X'){
                    visit[nx][ny] = true;
                    que.add(new int[] {nx, ny});
                    result += maps[nx].charAt(ny) - '0';
                }
            }
        }


        return result;
    }
}