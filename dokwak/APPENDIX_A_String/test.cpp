#define ll long long
//#include <vector>
//#include <iostream>
//#include <cmath> 
//#include <algorithm>
//#include <climits>
//#include <map>
//#include <string>
//#include <bits/stdc++.h>
//
//using namespace std;
//int n, m;
//
//vector<string> test_split(string input, char dlim)
//{
//	cout << "#########   SPLIT TEST    ########\n";
//	vector<string> result;	// 분리한 문자열들을 저장하는 vector
//
//	stringstream ss(input);		// stringstream 객체인 ss 선언
//	string stringBuffer;	// stringstream에서 문자열 자를 때마다 임시로 저장하는 변수
//	
//    // ss에서 dlim 직전까지의 문자열을 잘라서 stringBuffer에 저장. ss가 빌 때까지 실행
//	while (getline(ss, stringBuffer, dlim))	{
//		result.push_back(stringBuffer);	// stringBuffer에 저장된 값을 result에 push_back
//	}
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << " ";
//	}
//	cout << "\n";
//	return result;
//}
//
//void test_find(string hay, string &&needle){
//	cout << "#########   FIND TEST    ########\n";
//	if (hay.find(needle) == string::npos)
//		cout << needle << " is nowhere\n";
//	else
//		cout << needle <<" is in index " << hay.find(needle);
//}
//
//int	main(int argc, char **argv)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	//split test
//	
//	string test = "a b c dd e";
//	test_split(test, ' ');
//	test_split("test 1 d f,   ,,df,     sdf,, hi,", ',');
//	string hay = "abcdefg";
//	test_find(hay, "fgh");
//	test_find(hay, "fg");
//	return (0);
//}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 문자열을 long long으로 변환 ("a" -> 1, "b" -> 2, ..., "z" -> 26, "aa" -> 27, ...)
long long stringToLongLong(const string &s) {
    long long num = 0;
    for (char c : s) {
        num = num * 26 + (c - 'a' + 1);
    }
    return num;
}

// long long을 문자열로 변환 (1 -> "a", 2 -> "b", ..., 26 -> "z", 27 -> "aa", ...)
string longLongToString(long long num) {
    string result;
    while (num > 0) {
        // 1을 빼준 후 나머지를 구하면 0~25 범위의 값이 나오며, 이를 다시 알파벳으로 매핑
        int rem = (num - 1) % 26;
        result.push_back('a' + rem);
        num = (num - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // 테스트 예제
    string s = "aa";
    long long num = stringToLongLong(s);
    num = 27;
    cout << s << " -> " << num << "\n";  // "aa"는 27이어야 합니다.
    cout << num << " -> " << longLongToString(num) << "\n"; // 27은 "aa"가 되어야 합니다.
    string s1 = "az";
    cout << s1 << " -> " << stringToLongLong(s1) << "\n";  // "aa"는 27이어야 합니다.


    return 0;
}
