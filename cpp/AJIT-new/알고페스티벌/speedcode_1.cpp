#include<stdio.h>
int main() {
    char A[5], B[5], tmp;
    int i, T;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%s %s", A, B);
        tmp = A[0];
        A[0] = B[0];
        B[0] = tmp;
        printf("%s %s\\n", A, B);
    }
    return 0;
}