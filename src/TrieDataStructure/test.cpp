#include <iostream>
#include <vector>

class BIT {
public:
    BIT(int size) : bit(size + 1, 0), n(size) {}

    void update(int index, int value) {
        for (; index <= n; index += index & -index)
            bit[index] += value;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += bit[index];
        return sum;
    }

private:
    std::vector<int> bit;
    int n;
};

int solve(int N) {
    std::vector<int> ways(N + 1, 0);
    BIT bit(N);

    ways[1] = 1;
    bit.update(1, 1);

    for (int i = 2; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            ways[j] += ways[i];
            bit.update(j, ways[i]);
        }
    }

    return bit.query(N);
}

int main() {
    int N = 10;  // Example input
    std::cout << "Number of ways to reach Island " << N << " is: " << solve(N) << std::endl;
    return 0;
}
