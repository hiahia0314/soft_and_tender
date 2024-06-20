//
// Created by 23125 on 2023/12/11.
//
#include <string.h>
#include <stdio.h>

#define LEN 105
char board[LEN][LEN] = {0};
int check[LEN][LEN] = {0};
int n, m, ans;

void seach(int x, int y) {
    if (x == n && y == m) {
        ans = 1;
        return;
    }
    check[x][y] = 1;//标记这个点已经被搜过
    int vert[4][2] = {1, 0,
                      -1, 0,
                      0, 1,
                      0, -1};
    for (int i = 0; i < 4; ++i) {
        int newx = x + vert[i][0];
        int newy = y + vert[i][1];
        if (newx >= 1 && newy >= 1 && newx <= n && newy <= m && check[newx][newy] != 1 && board[newx][newy] == '.') {
            seach(newx, newy);
            if (ans == 1) {
                return;
            }
        }
    }
}


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", board[i] + 1);
    }
    seach(1, 1);
    if (ans == 0) {
        printf("No");
    } else {
        printf("Yes");
    }
    return 0;
}