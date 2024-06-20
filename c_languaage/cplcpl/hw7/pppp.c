//
// Created by 23125 on 2023/11/20.
//
#include<stdio.h>
#include <math.h>

#define LEN 1000
int chain[LEN][2];//[0]为id [1]为大小
int copy[LEN][2];
int numlian = 1;
int ans[LEN][LEN];
int time;

int ci(int m) {  //由内存m计算为2^k
    int k = 0;
    while (1) {
        if (pow(2, k) >= m) {
            break;
        }
        k++;
    }
    return k;
}

void IfA(int id, int ci) {
    int flag = 0;
    for (int i = 1; i <= numlian; i++) {
        if (ci == chain[i][1] && chain[i][0] == 0) {  //检测是否有恰好且空闲的内存组
            chain[i][0] = id;
            flag = 1;
            break;
        }
    }
    if (flag == 0) { //内存分裂
        for (int i = 1; i <= numlian; i++) {
            if (chain[i][1] > ci && chain[i][0] == 0) {

                for (int j = 1; j < i; j++) {           //左边的内存组保留
                    copy[j][0] = chain[j][0];
                    copy[j][1] = chain[j][1];
                }
                copy[i][0] = 0;


                copy[i][1] = chain[i][1] - 1;  //内存大小减1

                numlian++;
                copy[i + 1][1] = chain[i][1] - 1;

                for (int j = i + 1; j <= numlian - 1; j++) {    //后序数组向后推1位
                    copy[j + 1][0] = chain[j][0];
                    copy[j + 1][1] = chain[j][1];
                }

                break;
            }
        }
        for (int j = 1; j <= numlian; j++) {
            chain[j][0] = copy[j][0];
            chain[j][1] = copy[j][1];
        }

        IfA(id, ci);

    }
}

void IfQ() {   //用ans记录答案
    ans[time][0] = numlian;
    for (int i = 1; i <= numlian; i++) {
        ans[time][i] = chain[i][0];
    }
}


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    getchar();

    chain[1][0] = 0;  //占用标识
    chain[1][1] = n;  //节点大小

    for (int i = 1; i <= q; i++) {
        char dir;
        scanf("%c", &dir);
        getchar();
        if (dir == 'Q') {
            time++;
            IfQ();
        } else if (dir == 'A') {
            int id, m;
            scanf("%d %d", &id, &m);
            getchar();
            IfA(id, ci(m));
        }
    }

    for (int i = 1; i <= time; i++) {
        printf("%d\n", ans[i][0]);
        for (int j = 1; j <= ans[i][0]; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}