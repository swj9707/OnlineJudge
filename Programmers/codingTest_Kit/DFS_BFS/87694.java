package Programmers.codingTest_Kit.DFS_BFS;

import java.util.*;
class Solution {

    class Player{
        int x;
        int y;
        
        public Player(int x, int y){
            this.x=x;
            this.y=y;   
        }
    }

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        
        int start_x=characterX*2;
        int start_y=characterY*2;
        int end_x=itemX*2;
        int end_y=itemY*2;
        
        boolean[][] map= new boolean[103][103];
        
        for(int[] data:rectangle){
            for(int i=data[1]*2;i<=data[3]*2;i++){
              for(int j=data[0]*2;j<=data[2]*2;j++){
                    map[i][j]=true;
                  
              }  
            }
        }
        
        for(int[] data:rectangle){
            for(int i=data[1]*2+1;i<data[3]*2;i++){
              for(int j=data[0]*2+1;j<data[2]*2;j++){
                    map[i][j]=false;
              }  
            }
        }
    
        Stack<Player> stack = new Stack<>();
        
        Player p = new Player(start_x,start_y);
        stack.add(p);
        
        List<Integer> result =new ArrayList<>();
        int cnt=0;
        
        while(true){       
            if(stack.isEmpty()){
                result.add(cnt);
                break;
            }
            Player temp=stack.pop();
            int x=temp.x;
            int y=temp.y; 
           
            if(x==end_x&&y==end_y){
                result.add(cnt);         
            }
            
            map[y][x]=false;
            
            if(map[y+1][x]==true) stack.add(new Player(x,y+1));
            if(map[y][x+1]==true) stack.add(new Player(x+1,y));
            if(map[y-1][x]==true) stack.add(new Player(x,y-1));
            if(map[y][x-1]==true) stack.add(new Player(x-1,y));
            
            cnt++;
            
        }
        
        answer=Math.min(result.get(0)/2,result.get(1)/2-result.get(0)/2);      
        return answer;
    }
    
    
}