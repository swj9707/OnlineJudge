class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] data = new int[101];

        data[0] = data[1] = 1;

        for (int i = 2; i * i <= 100; i++) {
            if (data[i] == 0) {
                for (int j = i * i; j <= 100; j += i) {
                    data[j] = 1;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (data[i] == 1 && i != 1)
                answer++;
        }

        return answer;
    }
}