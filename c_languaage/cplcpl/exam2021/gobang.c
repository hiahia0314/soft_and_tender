

#include <stdio.h>

void heng(int x, int y, char c);

void lie(int x, int y, char c);

void xie1(int x, int y, char c);

void xie2(int x, int y, char c);

char board[30][30] = {0};
int win = 0, lose = 0;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 5; i < 25; ++i) {
            scanf("%s", board[i] + 5);
        }
        for (int i = 5; i < 25; ++i) {
            for (int j = 5; j < 25; ++j) {
                if (board[i][j] == '_') {
                    heng(i, j, '#');
                    lie(i, j, '#');
                    xie1(i, j, '#');
                    xie2(i, j, '#');
                    heng(i, j, '*');
                    lie(i, j, '*');
                    xie1(i, j, '*');
                    xie2(i, j, '*');
                }
            }
        }

        if (lose >= 1) {
            printf("Lose\n");
        } else if (win >= 2) {
            printf("Win\n");
        } else {
            printf("Not Sure\n");
        }
        win = 0;
        lose = 0;
    }

    return 0;
}

void heng(int x, int y, char c) {
    int count = 1;
    for (int i = 1; i <= 5; ++i) {
        if (board[x][y + i] != c) {
            break;
        }
        count++;
    }
    for (int i = 1; i <= 5; ++i) {
        if (board[x][y - i] != c) {
            break;
        }
        count++;
    }
    if (count >= 5) {
        if (c == '#') {
            win++;
        } else {
            lose++;
        }
    }

}

void lie(int x, int y, char c) {
    int count = 1;
    for (int i = 1; i <= 5; ++i) {
        if (board[x + i][y] != c) {
            break;
        }
        count++;
    }
    for (int i = 1; i <= 5; ++i) {
        if (board[x - i][y] != c) {
            break;
        }
        count++;
    }
    if (count >= 5) {
        if (c == '#') {
            win++;
        } else {
            lose++;
        }
    }

}

void xie1(int x, int y, char c) {
    int count = 1;
    for (int i = 1; i <= 5; ++i) {
        if (board[x + i][y + i] != c) {
            break;
        }
        count++;
    }
    for (int i = 1; i <= 5; ++i) {
        if (board[x - i][y - i] != c) {
            break;
        }
        count++;
    }
    if (count >= 5) {
        if (c == '#') {
            win++;
        } else {
            lose++;
        }
    }

}

void xie2(int x, int y, char c) {
    int count = 1;
    for (int i = 1; i <= 5; ++i) {
        if (board[x - i][y + i] != c) {
            break;
        }
        count++;
    }
    for (int i = 1; i <= 5; ++i) {
        if (board[x + i][y - i] != c) {
            break;
        }
        count++;
    }
    if (count >= 5) {
        if (c == '#') {
            win++;
        } else {
            lose++;
        }
    }

}