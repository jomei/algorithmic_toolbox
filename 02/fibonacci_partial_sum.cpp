#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_pisano_period(long long m) {
    long long prev = 0;
    long long cur = 1;
    long long len = 0;
    long long next;

    while(true) {
        next = (prev + cur) % m;
        prev = cur;
        cur = next;
        ++len;
        if (prev == 0 && cur == 1) { break; }
    }
    return len;
}

long long get_fibonacci_last_digit(long long n) {
    long long prev = 0;
    long long cur = 1;
    long long next;
    long long period = get_pisano_period(10);

    long long sum = 0;

    for(long long i = 1; i < n % period; ++i) {
        next = (prev + cur) % 10;
        prev = cur;
        cur = next;
    }

    return cur;
}

long long fibonacci_sum(long long n, long long m) {
    long long period = get_pisano_period(m);
    
    long long previous = 0;
    long long current  = 1;
    long long next;

    for (long long i = 1; i < (n + 2) % period; ++i) {
        next = (previous + current) % m;
        previous = current;
        current = next;
    }

    return current - 1;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
    if(from == to) {
        get_fibonacci_last_digit(to);  
    }

    return (fibonacci_sum(to, 100) - fibonacci_sum(from -1, 10)) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << std::endl;
}
