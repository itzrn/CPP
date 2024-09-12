#include <iostream>
#include <regex>
#include <string>
#include <algorithm> // contains replace function, replace(start, end, old character, new character);
#include <vector>
using namespace std;

int main() {
    // Sample strings to test
    vector<string> strings = {"cat", "bat", "map", "pen", "man"};

    // Define multiple regex patterns
    vector<regex> patterns = {regex(".at"), regex("ma."), regex(".a."), regex("..n"),};

    for(const auto& pattern:patterns){
        int count = 0;
        for(const auto& str:strings){
            if(regex_match(str, pattern)){
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}
