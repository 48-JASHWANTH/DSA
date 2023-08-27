#include <stdio.h>

void towersOfHanoi(int n, char s, char a, char d) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", s, d);
        return;
    }

    towersOfHanoi(n - 1, s, d, a);
    printf("Move disk %d from %c to %c\n", n, s, d);
    towersOfHanoi(n - 1, a, s, d);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Steps to solve the Towers of Hanoi problem:\n");
    towersOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

