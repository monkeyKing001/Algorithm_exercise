#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int cards[53];
char lett[5] = {'T', 'J', 'Q', 'K', 'A'};
char suit[4] = {'D', 'C', 'H', 'S'};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		fill(cards, cards+53, 0);
		for (int i = 0; i < 26; ++i) {
			string input;
			int tmp = 0;
			cin >> input;
			if (input[0] >= '2' && input[0] <= '9') tmp += (input[0]-'2') * 4;
			else {
				for (int i = 0; i < 5; ++i) {
					if (lett[i] == input[0]) tmp += (i+8) * 4;
				}
			}
			for (int i = 0; i < 4; ++i) {
				if (suit[i] == input[1]) tmp += i;
			}
			cards[tmp] = 1;
		}
		int g = 0;
		int w = 0;
		int score = 0;
		while (1) {
			while (g < 52 && cards[g] == 1) g++;
			while (w < 52 && cards[w] == 0) w++;
			if (w == 52 || g == 52) break;
			if (g < w) {
				w++;
				g++;
				score++;
			}
			else {
				while (w < g) w++;
			}
		}
		cout << score << '\n';
	}
}

