#include <iostream>
#include <functional>
using namespace std;
struct pair_hash{
    size_t operator() (const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ hash<int>{}(p.second);
    }
};
int main(){

    return 0;
}