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

bool check(vector<vector<int>> array) {
    for(int i = 0; i < array.size(); i++) {
        for(int j = 0; j < array[0].size(); j++) {
            if(array[i][j] != -1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    int t;
    cin >> t;
    int elevator = 10;
    int belt = 5;
    for(int m = 0; m < t; m++) {
        int h, l;
        cin >> h >> l;
        int time = 0;
        vector<vector<int>> array;
        for(int i = 0; i < h; i++) {
            VI a;
            array.push_back(a);
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < l; j++) {
                int value;
                cin >> value;
                array[i].push_back(value);
            }
        }
        int currentCar = 1;
        while(!check(array)) {
            int searchI;
            int searchJ;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < l; j++) {
                    if(array[i][j] == currentCar) {
                        searchI = i;
                        searchJ = j;
                        goto done;
                    }
                }
            }
            done:
            int distance = min(searchJ, l - searchJ);
            bool leftRotate = false;
            if(distance == searchJ) {
                leftRotate = true;
            }
            int floor = searchI;
            time += floor * 2 * elevator;
            time += distance * belt;
            array[searchI][searchJ] = -1;
            if(leftRotate) {
                for(int i = 0; i < distance; i++) {
                    array[searchI].push_back(array[searchI][0]);
                    array[searchI].erase(array[searchI].begin());
                }
            }
            else {
                for(int i = 0; i < distance; i++) {
                    int end = array[searchI][array[searchI].size() - 1];
                    array[searchI].erase(array[searchI].begin() + array[searchI].size() - 1);
                    array[searchI].insert(array[searchI].begin(), end);
                }
            }
            currentCar++;
        }
        cout << time << endl;
    }
    return 0;
}