/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//If you are looking at my solution this is just a shortcut method and is not always used
vector<string> split(string input, char c) {
    stringstream test(input);
    string segment;
    vector<string> list;
    while(getline(test, segment, c))
    {
        list.push_back(segment);
    }
    return list;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;

    int N;
    cin >> N;
    int length = 1;
    int oppositeLength = 1;
    vector<int64> dp(N);
    int64 firstValue;
    cin >> firstValue;
    dp[0] = firstValue;
    bool positive;
    bool firstoppositeFound = false;
    if(dp[0] > 0) {
        positive = true;
    }
    else {
        positive = false;
    }
    bool firstNumber = positive;
    bool oppositePositive = !firstNumber;
    int lastIndex = 0;
    int lastoppositeIndex;
    for(int i = 1; i <= N - 1; i++) {
        int64 value;
        cin >> value;
        if(firstoppositeFound) {
            if((value > 0 && !oppositePositive || value < 0 && oppositePositive) && abs(value) > abs(dp[lastoppositeIndex])) {
                oppositePositive = !oppositePositive;
                oppositeLength++;
                lastoppositeIndex = i;
            }
        }
        if((value < 0 && firstNumber || value > 0 && !firstNumber) && !firstoppositeFound) {
            firstoppositeFound = true;
            lastoppositeIndex = i;
        }
        if((value > 0 && !positive || value < 0 && positive) && abs(value) > abs(dp[lastIndex])) {
            positive = !positive;
            length++;
            lastIndex = i;
        }
        dp[i] = value;
    }
    cout << max(length, oppositeLength);
    return 0;
}