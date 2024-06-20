//
// Created by 23125 on 2023/12/3.
//
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define LEN 1000

int isreserve(char *s) {
    if (strcmp(s, "char") == 0 || strcmp(s, "const") == 0 || strcmp(s, "float") == 0 ||
        strcmp(s, "int") == 0 || strcmp(s, "static") == 0 || strcmp(s, "double") == 0 ||
        strcmp(s, "long") == 0 || strcmp(s, "void") == 0 || strcmp(s, "extern") == 0 ||
        strcmp(s, "enum") == 0 || strcmp(s, "break") == 0 || strcmp(s, "return") == 0 ||
        strcmp(s, "struct") == 0 || strcmp(s, "typedef") == 0 || strcmp(s, "union") == 0 || strcmp(s, "goto") == 0) {
        return 1;//yes
    }
    return 0;//no
}

int isinteger(char *s, int len) {
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; ++i) {
        if (!isdigit(*(s + i))) {
            return 0;//no
        }
    }
    return 1;//yes
}

int isfloat(char *s, int len) {

    if (isdigit(s[0])) {
        int countf = 0;
        for (int i = 1; i < len; ++i) {
            if (isalpha(s[i])) {//有字母
                return 0;
            }
            if (s[i] == '.') {
                countf++;
            }
            if (countf > 1) {//多个浮点
                return 0;
            }
        }
    }
    if (s[0] == '.') {
        if (!isinteger(s + 1, len - 1)) {
            return 0;
        }
    }
    return 1;//yes
}

int issign1(char s) {
    if (s == '+' || s == '-' || s == '*' || s == '/' || s == '=' || s == '>' || s == '<') {
        return 1;//yes
    }
    return 0;//no
}

int issign2(char *s) {
    if (strcmp(s, ">=") == 0 || strcmp(s, "==") == 0 || strcmp(s, "!=") == 0 || strcmp(s, "<=") == 0) {
        return 1;//yes
    }
    return 0;//no
}

int main() {
    char s[LEN] = {0};
    char ans[LEN] = {0};
    int count = 0;
    int flag = 0;
    //int n = 15;
    //while (n--) {
    //    scanf("%s", s);
    while (scanf("%s", s) != EOF) {
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '|') {
                flag = -1;
            }
        }
        int pp = 0;
        for (pp = 0; pp < strlen(s); ++pp) {
            if (s[pp] == ';') {
                ans[count] = 'n';
                count++;
            } else {
                break;
            }
        }
        if (pp == strlen(s)) {
            continue;
        } else {
            int som = 0;
            for (som = 0; pp + som < strlen(s); ++som) {
                s[som] = s[pp + som];
            }
            for (int i = som; i < strlen(s); ++i) {
                s[i] = 0;
            }
        }

        if (strlen(s) == 1 && s[0] == ';') {
            ans[count] = 'n';
            count++;
            continue;
        }
        char *position = strchr(s, ';');
        char *p1 = NULL;
        char *p2 = NULL;
        p1 = position;
        p2 = s;
        while (p1 != NULL) {
            if (p2 == p1) {
                ans[count] = 'n';
                count++;
                p2 = p1 + 1;
                p1 = strchr(p1 + 1, ';');
                continue;
            }
            char s1[LEN] = {0};
            for (int i = 0; p2 + i < p1; ++i) {
                s1[i] = *(p2 + i);
            }
            int len = strlen(s1);
            if (isreserve(s1) == 1) {//保留
                ans[count] = 'r';
                count++;
            } else if (isalpha(s1[0]) || s1[0] == '_') {//zimu
                for (int i = 0; i < len; ++i) {
                    if (!isalnum(s1[i]) && s1[i] != '_') {
                        flag = -1;//CE
                        break;
                    }
                }
                if (flag == 0) {
                    ans[count] = 'v';//变量
                    count++;
                }
            } else if (s1[0] == '.') {//浮点
                if (isfloat(s1, len) == 0) {
                    flag = -1;
                } else {
                    ans[count] = 'f';
                    count++;
                }
            } else if (isdigit(s1[0])) {
                if (isinteger(s1, len)) {
                    ans[count] = 'i';
                    count++;
                } else if (isfloat(s1, len)) {
                    ans[count] = 'f';
                    count++;
                } else {
                    flag = -1;
                }
            } else if (s1[0] == '-') {//负号打头
                ans[count] = 'o';
                count++;
                if (len < 2) {
                } else {
                    flag = -1;
                }
            } else if (len == 1 && issign1(s1[0])) {
                ans[count] = 'o';
                count++;
            } else if (len == 2 && issign2(s1)) {
                ans[count] = 'o';
                count++;
            } else {
                flag = -1;
            }
            ans[count] = 'n';
            count++;
            p2 = p1 + 1;
            p1 = strchr(p1 + 1, ';');

        }
        if (p1 == NULL && s[strlen(s) - 1] != ';') {
            int strlens = strlen(s);
            int q = 0;
            for (q = 0; p2 + q < s + strlens; ++q) {
                s[q] = *(p2 + q);
            }
            for (int i = q; i < strlens; ++i) {
                s[i] = 0;
            }
            int len = strlen(s);
            if (isreserve(s) == 1) {//保留
                ans[count] = 'r';
                count++;
                continue;
            } else if (isalpha(s[0]) || s[0] == '_') {//zimu
                for (int i = 1; i < len; ++i) {
                    if (!isalnum(s[i]) && s[i] != '_') {
                        flag = -1;//CE
                        break;
                    }
                }
                if (flag == 0) {
                    ans[count] = 'v';//变量
                    count++;
                }
            } else if (s[0] == '.') {
                if (len < 2) {
                    ans[count] = 'f';
                    count++;
                    continue;
                }//浮点
                if (isfloat(s, len) == 0) {
                    flag = -1;
                } else {
                    ans[count] = 'f';
                    count++;
                }
            } else if (isdigit(s[0])) {
                if (isinteger(s, len)) {
                    ans[count] = 'i';
                    count++;
                } else if (isfloat(s, len)) {
                    ans[count] = 'f';
                    count++;
                } else {
                    flag = -1;
                }
            } else if (s[0] == '-') {//负号打头
                ans[count] = 'o';
                count++;
                if (len < 2) {
                    continue;
                } else {
                    flag = -1;
                    continue;
                }
            } else if (len == 1 && issign1(s[0])) {
                ans[count] = 'o';
                count++;
            } else if (len == 2 && issign2(s)) {
                ans[count] = 'o';
                count++;
            } else {
                flag = -1;
            }
        }
    }
    if (flag == -1) {
        printf("Compile Error");
        return 0;
    }
    for (int i = 0; i < count; ++i) {
        if (ans[i] == 'n') {
            printf("\n");
        } else if (ans[i] == 'i') {
            printf("integer ");
        } else if (ans[i] == 'v') {
            printf("variable ");
        } else if (ans[i] == 'o') {
            printf("operator ");
        } else if (ans[i] == 'r') {
            printf("reserved ");
        } else if (ans[i] == 'f') {
            printf("float ");
        }
    }
    return 0;

}