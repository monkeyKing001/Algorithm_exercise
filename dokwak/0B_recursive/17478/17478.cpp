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
#define START_MESSAGE "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."
#define LINE_1 "\"재귀함수가 뭔가요?\"" 
#define LINE_2 "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어."
#define LINE_3 "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." 
#define LINE_4 "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" 
#define LINE_5 "라고 답변하였지."
#define ANSWER "\"재귀함수는 자기 자신을 호출하는 함수라네\""
#define DELIMITER "____"

void answer(int depth){
	string curDel = "";
	for (int i = 0; i < depth; i++) 
		curDel += DELIMITER;
	cout << curDel + LINE_1 + "\n";
	if (depth == n)
		cout << curDel + ANSWER << "\n";
	else {
		cout << curDel + LINE_2 + "\n";
		cout << curDel + LINE_3 + "\n";
		cout << curDel + LINE_4 + "\n";
		answer(depth + 1);
	}
	cout << curDel + LINE_5 + "\n";
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << START_MESSAGE << "\n";
	answer(0);
	return (0);
}

