#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[3] = {0,1,2};
    char b[3] = "ABC";
    float c[3] = {1.1,1.2,1.3};
    int read_a[3];
    char read_b[3];
    float read_c[3];
    
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(read_a, sizeof(int), 3, fp);
    fread(read_b, sizeof(char), 3, fp);
    fread(read_c, sizeof(float), 3, fp);
    
    return 0;
}
