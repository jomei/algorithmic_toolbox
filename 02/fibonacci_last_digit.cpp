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

int get_pisano_period(long long m) {
    int prev = 0;
    int cur = 1;
    int len = 0;
    int next;

    while(true) {
        next = (prev + cur) % m;
        prev = cur;
        cur = next;
        ++len;
        if (prev == 0 && cur == 1) { break; }
    }
    return len;
}

int get_fibonacci_last_digit(int n) {
    long long prev = 0;
    long long cur = 1;
    long long next;
    int period = get_pisano_period(10);

    int sum = 0;

    for(int i = 1; i < n % period; ++i) {
        next = (prev + cur) % 10;
        prev = cur;
        cur = next;
    }

    return cur;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    std::cout << d << '\n';
}
