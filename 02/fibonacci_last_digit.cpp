// 0 1 1 2 3 5 8 13 21 34 55 89 144 223 377 610 987 1597 2584 4181 6765 10946 17711
// 0 1 1 2 3 5 8 3 1 4 4 5 9 4 3 7 0 7 7 4 1 5 6 1
#include <iostream>
#include <vector>


int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit(int n) {
    if (n <= 1) { return n; }

    int prev = 0;
    int curr = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = prev;
        prev = curr;
        curr = (tmp_previous + curr) % 10;
    }

    return curr % 10;
}


int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit(n);
    std::cout << d << '\n';
}
