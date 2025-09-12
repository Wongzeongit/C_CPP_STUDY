#include <stdio.h>
#include <math.h>

// 判断是否为素数
int isPrime(int num) {
    if (num < 2) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    int i = 5;
    int w = 2;
    while (i * i <= num) {
        if (num % i == 0) return 0;
        i += w;
        w = 6 - w;
    }
    return 1;
}

// 计算递归数
int recursiveNumber(int n) {
    if (n == 1 || n == 2) return 1;
    if (isPrime(n)) {
        int power = (int)(log(n) / log(2));
        return recursiveNumber((int)pow(2, power));
    } else {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += recursiveNumber(i);
            }
        }
        return sum;
    }
}

int main() {
    int a;
    printf("请输入一个正整数（1 - 1000）：");
    scanf("%d", &a);
    int result = recursiveNumber(a);
    printf("%d 的递归数为：%d\n", a, result);
    return 0;
}