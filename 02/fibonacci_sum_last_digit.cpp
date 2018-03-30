// 0 1 1 2 3 5 8 13 21 34 55 89 144 223 377 610 987 1597 2584 4181 6765 10946 17711
// 0 1 2 4 7 12 20 33 54 88 
// 0 1 1 2 3 5 8 3 1 4 4 5 9 4 3 7 0 7 7 4 1 5 6 1
// 0 1 2 4 7 12 20 23 24 8

#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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


int fibonacci_sum(long long n) {
    long long prev = 0;
    long long cur = 1;
    long long sum = 0;
    long long next;

    int period = get_pisano_period(10);

    for(int i = 0; i < n % period; ++i) {
        next = prev + cur;
        sum += cur;
        prev = cur;
        cur = next;
    }

    return sum % 10 ;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << fibonacci_sum(n) << std::endl;
}
