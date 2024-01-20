#include <stdio.h>
#include <string.h>

void compressString(char *str) {
    int len = strlen(str);
    if (len == 0) {
        return;
    }

    int count = 1;
    char current = str[0];

    for (int i = 1; i <= len; i++) {
        if (str[i] == current) {
            count++;
        } else {
            printf("%c%d", current, count);
            count = 1;
            current = str[i];
        }
    }
}

int main() {
    char input[] = "aababcba";
    printf("Original String: %s\n", input);
    printf("Compressed String: ");
    compressString(input);
    printf("\n");

    return 0;
}
