package LV2;

class Solution {
    public int solution(int storey) {
        int answer = 0;
        String temp = Integer.toString(storey);
        
        int[] numbers = new int[temp.length()];

        for (int i = 0; i < temp.length(); i++)
            numbers[i] = temp.charAt(i) - '0';

        for(int i = numbers.length - 1; i >= 0; i--){
            if(numbers[i] > 5){
                answer += 10 - numbers[i];

                if(i == 0) answer++;
                else numbers[i - 1]++;

            } else if (numbers[i] == 5 && i > 0 && numbers[i - 1] >= 5) {
                answer += 5;
                numbers[i - 1]++;
            } else {
                answer += numbers[i];
            }
        }
        return answer;
    }
}