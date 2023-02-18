#include <iostream>
using namespace std;
// 알파벳 개수

int arr[26];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    for (auto c : s) arr[c-'a'] += 1;
    for (int i = 0; i < 26; i++) cout << arr[i] << ' ';
}