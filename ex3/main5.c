#include <stdio.h>

int main()
{
    int i = 119;
    if (i <= 30) {
        printf("free");
    }
    else if (i >= 240) {
        printf("240元");
    }
    else {
        if (i % 30 == 0) {
            int n = (i / 30) * 30;
            printf("%d 元", n);
        }
        else {
            int m = ((i / 30) + 1) * 30;
            printf("%d 元", m);
        }
    }

    return 0;
}
