#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// 영단어 암기는 괴로워

int N, M;
unordered_map<string, int> sium;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    bool ret = a.first < b.first;
    if (a.first.size() != b.first.size()) ret = a.first.size() > b.first.size();
    if (a.second != b.second) ret = a.second > b.second;
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; ++i){
        cin >> s;
        if (s.size() >= M) sium[s]++;
    }
    vector<pair<string, int> > v(sium.begin(), sium.end());
    sort(v.begin(), v.end(), cmp);
    for (auto a : v) cout << a.first << '\n';
}   