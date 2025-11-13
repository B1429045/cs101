#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    FILE *fp = fopen("lotto.txt", "w+");

    int n;
    printf("請輸入購買彩券組數(1-5): ");
    scanf("%d", &n);
    if (n < 1) n = 1;
    if (n > 5) n = 5;

    srand(time(NULL));
    
    fprintf(fp, "======== lotto649 ========\n");

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    const char *month_names[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int month = rand() % 12;
    int day   = rand() % 31 + 1;

    fprintf(fp, "===== %s %d 2025 =====\n", month_names[month], day);

    for (int i = 1; i <= 5; i++) {
        if (i <= n) {
            int lotto[7];
            
            for (int j = 0; j < 7; j++) {
                int number;
                int repeat;
                do {
                    number = rand() % 69 + 1;
                    repeat = 0;
                    for (int k = 0; k < j; k++) {
                        if (lotto[k] == number) {
                            repeat = 1;
                            break;
                        }
                    }
                } while (repeat);
                lotto[j] = number;
            }

            fprintf(fp, "[%d]: ", i);
            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", lotto[j]);
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "[%d]: ---------------------\n", i);
        }
    }

    fprintf(fp, "======== csie@CGU ========\n");
    fclose(fp);


    int win1, win2, win3;
    printf("請輸入中獎號碼三個: ");
    scanf("%d %d %d", &win1, &win2, &win3);
    printf("輸入中獎號碼為: %02d %02d %02d\n", win1, win2, win3);
    printf("以下為中獎彩卷:\n");

    fp = fopen("lotto.txt", "r");
    if (fp == NULL) {
        printf("open lotto.txt error!\n");
        return 1;
    }

    char line[256];
    int idx;
    int nums[7];

    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp)) {
        int cnt = sscanf(line, "[%d]: %d %d %d %d %d %d %d",
                         &idx,
                         &nums[0], &nums[1], &nums[2],
                         &nums[3], &nums[4], &nums[5], &nums[6]);
        if (cnt != 8) {
            continue;
        }

        int hit = 0;
        for (int i = 0; i < 7; i++) {
            if (nums[i] == win1 || nums[i] == win2 || nums[i] == win3) {
                hit = 1;
                break;
            }
        }

        if (hit) {
            printf("售出時間: %s %d 2025: [%d]: ",
                   month_names[month], day, idx);
            for (int i = 0; i < 7; i++) {
                printf("%02d ", nums[i]);
            }
            printf("\n");
        }
    }

    fclose(fp);
    return 0;
}