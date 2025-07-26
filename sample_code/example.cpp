#include <iostream>

int main() {
    int x = 42;  // Unclear variable name + Magic number

    // Deep Nesting example
    if (x > 0) {
        for (int i = 0; i < 5; i++) {
            while (x < 100) {
                if (x % 2 == 0) {
                    x++;
                }
            }
        }
    }

    // Long function (over 20 lines) + Missing comment
    int veryLongFunction(int a) {
        int sum = 0;
        for (int i = 0; i < a; i++) {
            sum += i;
        }
        for (int j = 0; j < a; j++) {
            sum += j;
        }
        for (int k = 0; k < a; k++) {
            sum += k;
        }
        for (int l = 0; l < a; l++) {
            sum += l;
        }
        for (int m = 0; m < a; m++) {
            sum += m;
        }
        return sum;
    }

    std::cout << veryLongFunction(x) << std::endl;
    return 0;
}