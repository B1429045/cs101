#include <stdio.h>

int main() {
    int i = 119;
    if (i <= 30) {
        printf("free");
    }
    else if (i >= 240) {
        printf("240元");
    }
    else {
        int n = 0;
        if (i % 30 == 0) {
            n = (i / 30) * 30;
        }
        else {
            n = ((i / 30) + 1) * 30;
        }
        printf("%d 元", n);
    }

    return 0;
}
