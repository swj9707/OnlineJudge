
public class pg77484 {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int[] rank = { 6, 6, 5, 4, 3, 2, 1 };
        int count = 0;
        int countZero = 0;

        for (int i = 0; i < 6; i++) {
            if (lottos[i] == 0)
                countZero++;
            else {
                for (int j = 0; j < win_nums.length; j++) {
                    if (lottos[i] == win_nums[j]) {
                        count++;
                        break;
                    }
                }
            }
        }

        answer[0] = rank[count + countZero];
        answer[1] = rank[count];

        return answer;
    }
}
