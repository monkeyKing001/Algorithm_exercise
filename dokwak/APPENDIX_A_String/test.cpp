#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;

vector<string> test_split(string input, char dlim)
{
	cout << "#########   SPLIT TEST    ########\n";
	vector<string> result;	// 분리한 문자열들을 저장하는 vector

	stringstream ss(input);		// stringstream 객체인 ss 선언
	string stringBuffer;	// stringstream에서 문자열 자를 때마다 임시로 저장하는 변수
	
    // ss에서 dlim 직전까지의 문자열을 잘라서 stringBuffer에 저장. ss가 빌 때까지 실행
	while (getline(ss, stringBuffer, dlim))	{
		result.push_back(stringBuffer);	// stringBuffer에 저장된 값을 result에 push_back
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	return result;
}

void test_find(string hay, string &&needle){
	cout << "#########   FIND TEST    ########\n";
	if (hay.find(needle) == string::npos)
		cout << needle << " is nowhere\n";
	else
		cout << needle <<" is in index " << hay.find(needle);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//split test
	
	string test = "a b c dd e";
	test_split(test, ' ');
	test_split("test 1 d f,   ,,df,     sdf,, hi,", ',');
	string hay = "abcdefg";
	test_find(hay, "fgh");
	test_find(hay, "fg");
	return (0);
}

