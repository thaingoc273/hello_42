#include <stdio.h>

void thayDoiMang(int m, int n, int a[m][n]) {
    a[0][0] = 100;
    a[1][1] = 200;
}

int main(void) {
    int m = 2, n = 3;
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    thayDoiMang(m, n, a);

    printf("%d\n", a[0][0]); // 100
    printf("%d\n", a[1][1]); // 200

    return 0;
}
