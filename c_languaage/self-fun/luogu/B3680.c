//
// Created by 23125 on 2023/12/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100
typedef struct people {
    char name[25];
    char who;
    int skill;
} People;

People Survive[LEN];
People Hunter[LEN];

int comp(const void *l, const void *r) {
    People *left = (People *) l;
    People *right = (People *) r;
    return -(left->skill - right->skill) + (right->skill - left->skill);
}

int main() {
    int n, m;
    int n1 = 0;
    int m1 = 0;
    scanf("%d%d", &n, &m);//n survive
    for (int i = 0; i < n + m; ++i) {
        char na[25] = {0};
        char w;
        int s;
        scanf("%s %c%d", na, &w, &s);
        if (w == 'H') {
            memcpy(Hunter[n1].name, na, sizeof(na) / sizeof(na[0]));
            Hunter[n1].who = w;
            Hunter[n1].skill = s;
            n1++;
        } else {
            memcpy(Survive[m1].name, na, sizeof(na) / sizeof(na[0]));
            Survive[m1].who = w;
            Survive[m1].skill = s;
            m1++;
        }
    }
    qsort(Survive, n,
          sizeof(Survive[0]), comp);
    qsort(Hunter, m,
          sizeof(Hunter[0]), comp);
    printf("%s\n", Hunter[2].name);
    for (int i = 5; i < 9; ++i) {
        printf("%s\n", Survive[i].name);
    }
}