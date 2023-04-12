#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nA, nB;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> nA >> nB;
    vector<int> av(nA);
    vector<int> bv(nB);
    vector<int> ansv;

    for (int i = 0; i < nA; i++) cin >> av[i];
    for (int i = 0; i < nB; i++) cin >> bv[i];

    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());

    for (auto& i : av) {
        if (binary_search(bv.begin(), bv.end(), i)) continue;
        ansv.push_back(i);
    }

    cout << ansv.size() << '\n';
    for (auto& i : ansv) cout << i << ' ';
}