//
// Created by 23125 on 2023/12/30.
//
#include <stdlib.h>
#include <stdio.h>

#define LEN 100
typedef struct node
{
    char sen[100];
    int nextone;
    struct node *up;
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
} LinkedList;


void Append(LinkedList *list) {
    Node *node = malloc(sizeof *node);

    if (node == NULL) {
        return;
    }
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->up = node;
    }
    list->tail = node;

}

LinkedList LIST;
Node all[LEN];

int main() {
    LIST.head = NULL;
    LIST.tail = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", all[i].sen);
        scanf("%d", &all[i].nextone);
    }
    for (int i = 1; i <= n; ++i) {
        int t = all[i].nextone;
        if (t >= n) {
            continue;
        }
        all[i].up = &all[t];
    }

    Node *p1 = &all[1];
    Node *p2 = all[1].up;

    while (p1 != p2 && p2 != NULL) {
        p1 = p1->up;
        p2 = p2->up;
        if (p2 == NULL) {
            break;
        }
        p2 = p2->up;
    }
    if (p2 == NULL) {
        printf("-1");
        return 0;
    } else {
        p2 = p2->up;
        p1 = &all[1];
        while (p1 != p2) {
            p1 = p1->up;
            p2 = p2->up;
        }
        printf("%s", p1->sen);
    }

    return 0;
}