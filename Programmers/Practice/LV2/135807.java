package LV2;

import java.util.Arrays;

class Solution {
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;

        Arrays.sort(arrayA);
        Arrays.sort(arrayB);

        int firstGcd = getGcd(arrayA);
        int secondGcd = getGcd(arrayB);

        for (int i = 0; i < arrayB.length; i++) {
            if (arrayB[i] % firstGcd == 0) {
                firstGcd = -1;
                break;
            }
        }

        answer = Math.max(answer, firstGcd);

        for (int i = 0; i < arrayA.length; i++) {
            if (arrayA[i] % secondGcd == 0) {
                secondGcd = -1;
                break;
            }
        }

        answer = Math.max(answer, secondGcd);

        return answer;
    }

    public int gcd(int a, int b) {
        if (a % b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public int getGcd(int[] array) {
        int value = array[0];
        for (int i = 1; i < array.length; i++) {
            value = gcd(array[i], value);
        }
        return value;
    }
}