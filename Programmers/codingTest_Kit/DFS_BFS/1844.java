package Programmers.codingTest_Kit.DFS_BFS;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};
    
    public int solution(int[][] maps) {
        return BFS(new int[maps.length][maps[0].length], maps);
    }

    public int BFS(int[][] visit, int[][] maps){
        int result = -1;
        int x = 0;
        int y = 0;
        visit[x][y] = 1;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {x, y});
        while(!q.isEmpty()){
            int[] current = q.remove();
            int X = current[0];
            int Y = current[1];
            if(X == maps.length - 1 && Y == maps[0].length - 1){
                result = visit[X][Y];
                break;
            }

            for(int i = 0; i < 4; i++){
                int nx = X + dx[i];
                int ny = Y + dy[i];

                if(nx >= 0 && nx < maps.length && ny > 0 && ny < maps[0].length && visit[nx][ny] == 0 && maps[nx][ny] == 1 ){
                    visit[nx][ny] = visit[X][Y] + 1;
                    q.add(new int[] {nx, ny});
                }
            }
        }
        return result;
    }
}