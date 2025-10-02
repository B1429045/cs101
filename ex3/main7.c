#include <stdio.h>

int main() {
    
    int i = 1599;
    int n = i - 1500;
    int m = 0;
    if (i <= 1500) {
        printf("70元");
    }
    else {
        if (i % 100 == 0) {
            m = 70 + ((n / 100) * 10);
        }
        else {
            m = 70 + (((n / 100) + 1) * 10);
        }
        printf("%d 元", m);
    }

    return 0;
}
