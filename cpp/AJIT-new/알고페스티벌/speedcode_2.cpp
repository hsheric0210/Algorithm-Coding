#include<stdio.h>
int main() {
    int N, i, j, num;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        if (i % 2) {
            for (j = 0; j < N; j++) {
                printf("%d ", i * N + N - j);
            }
        }
        else {
            for (j = 0; j < N; j++) {
                printf("%d ", i * N + j + 1);
            }
        }
        printf("\\n");
    }
}