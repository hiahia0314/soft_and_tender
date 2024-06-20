//
// Created by 23125 on 2024/1/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100
typedef struct node
{
    struct node *next;
    char name[11];
    char in[11];
} Node;

typedef struct link
{
    Node *head;
    Node *tail;
} Link;

Link link;

int main() {
    link.head = NULL;
    link.tail = NULL;
    char *remove = "remove";
    char *query = "query";
    int n, q;
    scanf("%d%d", &n, &q);
    while (q--) {
        char s1[11] = {0};
        char s2[11] = {0};
        scanf("%s%s", s1, s2);
        if (s2[0] == '~') {
            Node *node = malloc(sizeof *node);
            strcpy(node->name, s1);
            link.head = node;
            link.tail = node;
            node->next = NULL;
        } else {
            Node *p = link.head;
            
        }

    }

    return 0;
}