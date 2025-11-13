#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pad5(int x, char s[]) {

    sprintf(s, "%05d", x);
}

void gen_lotto(int lotto[7]) {
    
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
}

int main(void) {
    int counter = 0;
    FILE *cf = fopen("counter.bin", "rb");
    if (cf != NULL) {
        fread(&counter, sizeof(int), 1, cf);
        fclose(cf);
    }
    counter += 1;

    char idstr[8];
    char fname[64];
    pad5(counter, idstr);
    sprintf(fname, "lotto[%s].txt", idstr);

    FILE *fp = fopen(fname, "w+");
    if (fp == NULL) {
        printf("open %s error!\n", fname);
        return 1;
    }

    int n;
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
    fprintf(fp, "===== %s %d %d =====\n",
            month_names[t->tm_mon],
            t->tm_mday,
            t->tm_year + 1900);

    for (int i = 1; i <= 5; i++) {
        if (i <= n) {
            int lotto[7];
            gen_lotto(lotto);
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

    cf = fopen("counter.bin", "wb");
    if (cf != NULL) {
        fwrite(&counter, sizeof(int), 1, cf);
        fclose(cf);
    }

    return 0;
}