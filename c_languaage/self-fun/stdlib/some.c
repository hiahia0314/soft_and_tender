//
// Created by 23125 on 2023/12/17.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*Compere)(const void *, const void *);

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // 可行的简写
    // return arg1 - arg2; // 错误的简写（若给出 INT_MIN 则会失败）
}

int abs(int i) {//绝对值
    return i < 0 ? -i : i;
}

void Myqsort(void *base, size_t n,//n个元素
             size_t size, int (*cmp)(const void *, const void *)) {
    while (1 < n) {
        size_t i = 0;
        size_t j = n - 1;
        char *qi = (char *) base;//起始地址
        char *qj = qi + size * j;//最右侧开始
        char *qp = qj;//qp作为参照量
        while (i < j) {
            while (i < j && (*cmp)(qi, qp) <= 0) {
                ++i;//标记比较到哪一位了
                qi += size;//👉一个
            }//找到大于等于qp的那一个
            while (i < j && (*cmp)(qp, qj) <= 0) {
                --j;//qp右边的
                qj -= size;//👈一个
            }//找到小于等于qp的那个
            if (i < j) {
                char buf[256];//buf作为过度
                char *q1 = qi;
                char *q2 = qj;//交换qi,qj
                size_t m, ma;
                for (ma = size; ma > 0; ma -= m, q1 += m, q2 -= m) {
                    m = ma < sizeof(buf) ? ma : sizeof(buf);
                    memcpy(buf, q1, m);
                    memcpy(q1, q2, m);
                    memcpy(q2, buf, m);
                }
                ++i;
                qi += size;
            }
        }
        if (qi != qp) {
            char buf[256];
            char *q1 = qi;
            char *q2 = qp;
            size_t m, ma;
            for (ma = size; ma > 0; ma -= m, q1 += m, q2 -= m) {
                m = ma < sizeof(buf) ? ma : sizeof(buf);
                memcpy(buf, q1, m);
                memcpy(q1, q2, m);
                memcpy(q2, buf, m);
            }
        }
        j = n - i - 1;
        qi += size;
        if (j < i) {
            if (1 < j) {
                Myqsort(qi, j, size, cmp);
            }
            n = i;
        } else {
            if (1 < i) {
                Myqsort(base, i, size, cmp);
            }
            base = qi;
            n = j;

        }
    }
}

void *Mybsearch(const void *key, const void *base, size_t nelem, size_t size, Compere cmp) {
    const char *p;
    size_t n;
    for (p = (const char *) base, n = nelem; n > 0;) {
        const size_t pivot = n >> 1;//除以2
        const char *const q = p + size * pivot;//q为pivot的地址
        const int val = (*cmp)(key, q);
        if (val < 0) {
            n = pivot;//搜0到Pivot
        } else if (val == 0) {
            return ((void *) q);//找到了
        } else {//搜Pivot之上的
            p = q + size;
            n -= pivot + 1;//n为所剩的比较次数
        }
    }
    return (NULL);
}

int main() {
    int zu[] = {1, 2, 12, 9, 0, -1, 8};
    Myqsort(zu, sizeof zu / sizeof(zu[0]), sizeof(zu[0]), compare_ints);

    int len = sizeof zu / sizeof(zu[0]);
    int t = 1;
    int *key = &t;
    int *xx = Mybsearch(key, zu, len, sizeof(zu[0]), compare_ints);
    printf("%d", xx - zu);

//    for (int i = 0; i < sizeof zu / sizeof(zu[0]); ++i) {
//        printf("%d ", zu[i]);
//    }
//    putchar('\n');
//    qsort(zu, sizeof zu / sizeof(zu[0]), sizeof(zu[0]), compare_ints);
//    for (int i = 0; i < sizeof zu / sizeof(zu[0]); ++i) {
//        printf("%d ", zu[i]);
//    }
    return 0;
}