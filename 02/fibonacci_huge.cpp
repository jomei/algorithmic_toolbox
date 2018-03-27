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

int fib_fast_step(int n, std::vector<int>& fib) {
    int size = fib.size();
    if(size > n) { return fib[n]; }

    fib.push_back(fib[size - 1] + fib[size - 2]);
    return fib_fast_step(n, fib); 
}

int fibonacci_fast(int n) {
    std::vector<int> fib = {0, 1};
    return fib_fast_step(n, fib);
}

std::vector<int> buildTable(int m) {
    std::vector<int> table = {0, 1};
    if(m < 3) { return table; }
    for(int i = 2; i < m; i ++) {
        table.push_back(fibonacci_fast(i) % i);
    }
    return table;
}


// надо было воспользоваться периодом Пизано
// тут же считаются первые m чисел Фиббоначи + еще делится
// с периодом надо просто складывать числа, пока не получится последовательность {0 ,1}
long long get_fibonacci_huge_fast(long long n, long long m) {
     std::vector<int> table = buildTable(m);
     return table[n % m];
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << std::endl;
}
