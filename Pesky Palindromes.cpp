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

    string input;
    while(cin >> input) {
        set<string> palindromes;
        for(int i = 0; i < input.length(); i++) {
            for(int j = 1; j < input.length() - i + 1; j++) {
                string current = input.substr(i,j);
                string reversed(current.rbegin(), current.rend());
                if(current == reversed) {
                    palindromes.insert(current);
                }
            }
        }
        cout << "The string '" << input << "' contains " << palindromes.size() << " palindromes." << endl;
    }
    return 0;
}