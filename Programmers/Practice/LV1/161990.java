package Programmers.Practice.LV1;

class Solution {
    public int[] solution(String[] wallpaper) {
        int minX = 99, maxX = -1, minY = 99, maxY = -1;

        for(int i = 0; i < wallpaper.length; i++){
            for(int j = 0; j < wallpaper[i].length(); j++){
                if(wallpaper[i].charAt(j) == '#') {
                    minX = Math.min(minX, i);
                    maxX = Math.max(maxX, i);
                    minY = Math.min(minY, j);
                    maxY = Math.max(maxY, j);
                }
            }
        }

        return new int[] {minX, minY, maxX + 1, maxY + 1};
    }
}