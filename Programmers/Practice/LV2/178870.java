package Programmers.Practice.LV2;

import java.util.*;

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.solution(new int[] { 1, 2, 3, 4, 5 }, 7));

    }
}

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {};

        int left = 0;
        int right = 0;
        int[] dataArr = sequence;
        int N = sequence.length;
        int sum = sequence[0];

        for (int i = 1; i < N; i++) {
            dataArr[i] += dataArr[i - 1];
        }

        PriorityQueue<Element> pq = new PriorityQueue<>();

        while (left < N && right < N) {
            System.out.println(left + " " + right);
            if (sum == k) {
                Element result = new Element(left, right);
                pq.add(result);
            }

            if (sum <= k && right < N) {
                right++;
                sum += sequence[right];
            } else {
                if (left < N) {
                    sum -= sequence[left];
                    left++;
                }
            }

        }

        for (Element data : pq) {
            System.out.println(data.startIdx + " " + data.endIdx + " " + data.length);
        }
        return answer;
    }
}

class Element implements Comparable<Element> {
    int startIdx;
    int endIdx;
    int length;

    public Element(int start, int end) {
        this.startIdx = start;
        this.endIdx = end;
        this.length = end - start;
    }

    @Override
    public int compareTo(Element o) {
        if (o.length == this.length) {
            return this.startIdx - o.startIdx;
        } else {
            return this.length - o.length;
        }
    }
}