#include <stdio.h>

// 定義 test 函式，回傳整數
int test(int a, int b) {
    int result = 0;

    // 檢查 a 和 b 是否小於 3 和 7
    if ((a < 3) && (b < 7)) {
        // 如果 b 等於 4，則 result 等於 a 減去 b
        if (b == 4) {
            result = (a - b);
        }
        // 否則 result 等於 a 乘上 b
        else {
            result = a * b;
        }
    }
    // 如果 a 和 b 不是都小於 3 和 7，則 result 等於 a 加上 b
    else {
        //result = (a + b);
        result = a + b + test (a/ 2, b/ 2);
    }

    // 回傳計算結果
    return result;
}

// 主函式
int main() {
    // 呼叫 test 函式，並印出計算結果
    printf("test(2, 4) = %d\n", test(2, 4));
    printf("test(4, 5) = %d\n", test(4, 5));
    printf("test(2, 5) = %d\n", test(2, 5));
    printf("test(8, 8) = %d\n", test(8, 8));

    return 0;
}
