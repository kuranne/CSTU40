/*
LANG: C
COMPILER: WCB
*/
/*
NAME: kuranne
SID: 6800000000
*/

#include <stdio.h>

int main() {
    int n, i, s, m, h;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &s);
        m = s / 60;
        h = m / 60;
        printf("%d %d %d\n", h, m %= 60, s %= 60);
    }
    return 0;
}