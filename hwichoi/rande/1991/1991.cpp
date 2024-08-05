#include <iostream>
#include <algorithm>

using namespace std;
int n;
char arr[30][2];

void rec1(int num) {
	char c = 'A'+num;
	cout << c;
	if (arr[num][0] != '.') rec1(arr[num][0]-'A');
	if (arr[num][1] != '.') rec1(arr[num][1]-'A');
}

void rec2(int num) {
	if (arr[num][0] != '.') rec2(arr[num][0]-'A');
	char c = 'A'+num;
	cout << c;
	if (arr[num][1] != '.') rec2(arr[num][1]-'A');
}

void rec3(int num) {
	if (arr[num][0] != '.') rec3(arr[num][0]-'A');
	if (arr[num][1] != '.') rec3(arr[num][1]-'A');
	char c = 'A'+num;
	cout << c;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		arr[i][0] = b;
		arr[i][1] = c;
	}

	rec1(0); cout << '\n';
	rec2(0); cout << '\n';
	rec3(0); cout << '\n';
}

