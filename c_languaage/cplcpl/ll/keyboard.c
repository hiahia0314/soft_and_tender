//
// Created by 23125 on 2024/1/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 1000

typedef struct node
{
    char c;
    int rk;
    struct node *down;
    struct node *up;
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
} LinkedList;

void append(LinkedList *list, char c, int rk) {
    Node *node = malloc(sizeof *node);
    node->rk = rk;
    node->c = c;
    node->down = list->tail;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->up = node;
    }
    list->tail = node;
}

int main() {
    LinkedList small, big;
    small.tail = NULL;
    small.head = NULL;
    big.head = NULL;
    big.tail = NULL;
    int q;
    scanf("%d", &q);
    int count_small = 0;
    int count_big = 0;
    int count = 0;
    while (q--) {
        char str[LEN] = {0};
        scanf("%s", str);
        if (str[0] == '?') {
            int x;
            scanf("%d", &x);
            char *ans = malloc((2 + x) * sizeof *ans);
            Node *p1 = big.tail;
            Node *p2 = small.tail;
            int xx = x;
            for (int i = count; i > count - x; --i) {
                if (p1 != NULL && p1->rk == i) {
                    ans[xx - 1] = p1->c;
                    xx--;
                    p1 = p1->down;
                } else {
                    ans[xx - 1] = p2->c;
                    xx--;
                    p2 = p2->down;
                }
            }
            printf("%s\n", ans);
        } else {
            size_t len = strlen(str);
            for (int i = 0; i < len; ++i) {
                if (str[i] == 'm') {
                    if (count_small == 0) {
                        continue;
                    } else {
                        count--;
                        count_small--;
                        small.tail = small.tail->down;
                        small.tail->up = NULL;
                    }

                } else if (str[i] == 'M') {
                    if (count_big == 0) {
                        continue;
                    } else {
                        count--;
                        count_big--;
                        big.tail = big.tail->down;
                        big.tail->up = NULL;
                    }
                } else if (isupper(str[i])) {
                    count_big++;
                    count++;
                    append(&big, str[i], count);

                } else {
                    count_small++;
                    count++;
                    append(&small, str[i], count);

                }
            }

        }

    }

    return 0;
}