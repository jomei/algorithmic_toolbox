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

int fast_step(int n, std::vector<int>& fib) {
    int size = fib.size();
    if(size > n) { return fib[n]; }

    fib.push_back((fib[size - 1] + fib[size - 2]) % 10);
    return fast_step(n, fib);
}

int get_fibonacci_last_digit_fast(int n) {
    std::vector<int> fib = {0 , 1};
    return fast_step(n, fib);
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
