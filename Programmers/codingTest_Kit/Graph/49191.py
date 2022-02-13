from collections import Counter


def solution(n, results):
    answer = 0
    board = [[0] * n for _ in range(n)]
    for p1, p2 in results:
        board[p1 - 1][p2 - 1] = 1
        board[p2 - 1][p1 - 1] = -1

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if board[i][j] == 0:
                    if board[i][k] == 1 and board[k][j] == 1:
                        board[i][j] = 1
                    elif board[i][k] == -1 and board[k][j] == -1:
                        board[i][j] = -1

    for i in range(n):
        if Counter(board[i])[0] == 1:
            answer += 1

    return answer