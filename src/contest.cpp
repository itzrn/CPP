#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Contest {
    private:
        vector<int> input_vector(int n) {
            vector<int> vec;

            for (int i = 0; i < n; i++)
            {
                int num;
                cin >> num;
                vec.push_back(num);
            }

            return vec;
        }

    public:
        void solve() {
            int n;
            cin >> n;
            vector<int> vec1 = input_vector(n);
            vector<int> vec2 = input_vector(n + 1);

            int count = 0;
            int min_ = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                count += abs(vec1[i] - vec2[i]);
                min_ = min(min_, abs(vec1[i] - vec2[n]));
            }

            count += min_ + 1;
            cout << count << endl;
        }

} contest;

int main() {
    int t = 1;
    cin >> t;
    while (t-- > 0) {
        contest.solve();
    }

    return 0;
}