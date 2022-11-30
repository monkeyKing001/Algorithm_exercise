#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int	dat[MX];
int	pos = 0;

void	push(int x) {
	dat[pos] = x;
	pos++;
}

void	pop(void) {
	pos--;
}

int	top(void) {
	return (dat[pos-1]);
}

void	test() {
	push(5); push(4); push(3);
	cout << top() << '\n';
	pop(); pop();
	cout << top() << '\n';
	push(10); push(12);
	cout << top() << '\n';
	pop();
	cout << top() << '\n';
}

int	main(int argc, char **argv)
{
	test();
}

