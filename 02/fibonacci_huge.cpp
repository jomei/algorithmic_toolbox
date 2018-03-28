// Input: n - fibonacci, m - divider
// Ouput: Fn mod m

#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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

long long get_fibonacci_huge(long long n, long long m) {
    if(n <= 1) { return n; }
    long long prev = 0;
    long long cur = 1;
    long long next;
    int period = get_pisano_period(m);

    for(int i = 0; i < n % m; ++i) {
        next = (prev + cur) % m;

        prev = cur;
        cur = next;
    }

    return prev;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << std::endl;
}
