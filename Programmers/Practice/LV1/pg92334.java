
import java.util.*;

public class pg92334 {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, HashSet<String>> reportedMap = new HashMap<>();
        Map<String, Integer> answerMap = new HashMap<>();

        for (int i = 0; i < id_list.length; i++) {
            reportedMap.put(id_list[i], new HashSet<String>());
            answerMap.put(id_list[i], 0);
        }

        for (String data : report) {
            String[] users = data.split(" ");
            String reportingUser = users[0];
            String reportedUser = users[1];
            reportedMap.get(reportedUser).add(reportingUser);
        }

        for (String reportedUser : reportedMap.keySet()) {
            HashSet<String> userForSend = reportedMap.get(reportedUser);
            if (userForSend.size() >= k) {
                for (String userId : userForSend) {
                    answerMap.put(userId, answerMap.get(userId) + 1);
                }
            }
        }

        for (int i = 0; i < id_list.length; i++) {
            answer[i] = answerMap.get(id_list[i]);
        }

        return answer;
    }
}
