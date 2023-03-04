package LV2;

import java.util.*;

class Solution {

    static long MAXVALUE = 0;

    static List<Long> numList = new ArrayList<>();
    static List<Character> opList = new ArrayList<>();
    static List<Character> opKind = new ArrayList<>();

    static boolean[] visit;

    public long solution(String expression) {
        splitExp(expression);

        visit = new boolean[opKind.size()];
        List<Character> order = new ArrayList<>();
        priorityOrder(order);

        return MAXVALUE;
    }

    public static void splitExp(String e) {
        Set<Character> opSet = new HashSet<>();
        StringBuilder numberStr = new StringBuilder();

        char[] data = e.toCharArray();

        for (char x : data) {
            if (x == '+' || x == '-' || x == '*') {
                opSet.add(x);
                opList.add(x);
                numList.add(Long.valueOf(numberStr.toString()));
                numberStr = new StringBuilder();
            } else {
                numberStr.append(x);
            }
        }

        numList.add(Long.valueOf(numberStr.toString()));
        opKind = new ArrayList<>(opSet);
    }

    public static void priorityOrder(List<Character> order) {
        if (order.size() == opKind.size()) {
            Long now = calc(order);
            if (now > MAXVALUE)
                MAXVALUE = now;
            return;
        }

        for (int i = 0; i < opKind.size(); i++) {
            if (visit[i])
                continue;
            visit[i] = true;
            order.add(opKind.get(i));
            priorityOrder(order);
            visit[i] = false;
            order.remove(order.size() - 1);
        }
    }

    public static Long calcOpt(long a, long b, char opt) {
        long res = 0;
        if (opt == '+') {
            res = a + b;
        } else if (opt == '-') {
            res = a - b;
        } else {
            res = a * b;
        }
        return res;
    }

    public static Long calc(List<Character> order) {
        List<Long> copyNumList = new ArrayList<>(numList);
        List<Character> copyOptList = new ArrayList<>(opList);

        for (char opt : order) {
            for (int i = 0; i < copyOptList.size(); i++) {
                if (opt == copyOptList.get(i)) {
                    copyNumList.set(i, calcOpt(copyNumList.get(i), copyNumList.get(i + 1), opt));
                    copyNumList.remove(i + 1);
                    copyOptList.remove(i);
                    i--;
                }
            }
        }
        return Math.abs(copyNumList.get(0));
    }
}