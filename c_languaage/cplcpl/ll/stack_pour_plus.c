//
// Created by 23125 on 2023/12/30.
//
#include <stdio.h>
#include <stdlib.h>

#define LEN 100

typedef struct node
{
    int rk;
    struct node *up;
    struct node *down;
} Node;

typedef struct link
{
    Node *top;
    Node *bottom;
} Stack;
Stack all[LEN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        Node *node = malloc(sizeof *node);
        node->rk = i;
        node->down = NULL;
        node->up = NULL;
        all[i].top = node;
        all[i].bottom = node;

    }
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        while (all[x].top != NULL) {
            Node *node = malloc(sizeof *node);
            node->rk = all[x].top->rk;
            node->down = all[y].top;
            node->up = NULL;
            all[y].top = node;
            all[x].top = all[x].top->down;
        }
        for (int i = 1; i <= n; ++i) {
            if (all[i].top == NULL) {
                printf("0\n");
            } else {
                while (all[i].top != NULL) {
                    printf("%d ", all[i].bottom->rk);
                    all[i].bottom = all[i].bottom->up;
                }
            }
        }

    }

    return 0;
}