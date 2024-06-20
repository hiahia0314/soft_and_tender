#include <stdio.h>
char map[55][55];
int main(){
    for (int i = 0; i < 3; ++i) {
        scanf("%s",map[i]);
    }
    for (int i = 0; i < 3; ++i) {
        printf("%s\n",map[i]);
    }
    return 0;
}