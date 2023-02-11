#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//시리얼 번호

int N;
vector<string> v;

bool cmp(const string& a, const string& b){
    int lena = a.size(), lenb = b.size();
    if (lena!= lenb) return lena < lenb;

    int suma = 0, sumb = 0;
    for (int i=0; i<lena; i++){
        if (isdigit(a[i])) suma += (a[i] - '0');
    }
    for (int i=0; i<lenb; i++){
        if (isdigit(b[i])) sumb += (b[i] - '0');
    }

    if (suma!= sumb) return suma < sumb;
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        string st;
        cin >> st;
        v.push_back(st);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) cout << i << '\n';
    return 0;
}