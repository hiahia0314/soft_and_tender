//
// Created by 23125 on 2023/12/18.
//
#include <stdio.h>

void *mymemchr(const void *s, int c, size_t n) {
    const unsigned char uc = c;//find c in s[0...n]
    const unsigned char *su;
    for (su = s; n > 0; ++su, --n) {
        if (*su == uc) {
            return ((void *) su);
        }
    }
    return (NULL);
}

char *(mystrchr)(const char *s, int c) {
    const char ch = c;
    for (; *s != ch; s++) {
        if (*s == '\0') {
            return NULL;
        }
    }
    return (char *) s;
}


char *mystrstr(const char *s1, const char *s2) {
    if (*s2 == '\0') {//find first occurrence of s2 in s1
        return (char *) s1;
    }
    for (; (s1 = mystrchr(s1, *s2)) != NULL//找到第一次出现s2[0]  s1会循环赋值...
            ; ++s1) {//s1 每次都是以s2[0]开头，且往后往后迭代
        const char *sc1, *sc2;
        for (sc1 = s1, sc2 = s2;;) {//在判断中++！！
            if (*++sc2 == '\0') {//找到头了  先加sc2
                return (char *) s1;
            } else if (*++sc1 != *sc2) {  //再加sc1
                break;
            }
        }
    }
    return NULL;
}


int main() {
    char zu[] = "string?Hello,9";
    int len = sizeof(zu) / sizeof(zu[0]);
    char *p = NULL;
    p = mymemchr(zu, '9', len);
    p = mystrchr(zu, '?');
    p = mystrstr(zu, "Hello");
//    printf("%d", p - zu);
//    printf("%s", p);

//    if (p == NULL) {
//        printf("nope");
//        return 0;
//    }
//    printf("%d", (int) (p - zu));

    return 0;
}