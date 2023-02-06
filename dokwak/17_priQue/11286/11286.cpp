#include <bits/stdc++.h>

using namespace std;

int pq[110000] = {};
int pq_size = 0;

void see()
{
	cout << "pq : ";
	for (int i = 0; i < pq_size; i++)
		cout << pq[i] << ", ";
	cout << "\n";
}


void swap(int src, int dest)
{
	int temp = pq[src];
	pq[src] = pq[dest];
	pq[dest] = temp;
}

int getHighPriorityIndext(int ia, int ib)
{
	if (abs(pq[ia]) < abs(pq[ib]))
		return (ia);
	else if (abs(pq[ia]) == abs(pq[ib]))
	{
		if (pq[ia] < pq[ib])
			return (ia);
	}
	return (ib);
}

void update()
{
	int pos = 0;
	int l = (pos * 2) + 1;
	int r = (pos * 2) + 2;
	while (pq[pos] && (pq[r] || pq[l]))
	{
		int next_pos = pos;
		if (pq[l] && pq[r])
		{
			next_pos = getHighPriorityIndext(l, r);
			next_pos = getHighPriorityIndext(next_pos, pos);
		}
		else if (pq[l] && !pq[r])
			next_pos = getHighPriorityIndext(l, pos);
		if (next_pos == pos)
			break;
		swap(pos, next_pos);
		pos = next_pos;
		r = (pos * 2) + 2;
		l = (pos * 2) + 1;
		if (pos > 100000 || r > 100000 || l > 100000)
			break ;
	}
}

void push(int val)
{
	int pos = pq_size;
	int parent = (pos - 1 ) / 2;
	pq[pos] = val;
	while (pos)
	{
		int prior_pos = getHighPriorityIndext(pos, parent);
		if (prior_pos != pos)
			break;
		swap(pos, parent);
		pos = parent;
		parent = (pos - 1) / 2;
	}
//	cout << "pushed " << val << "\n";
	pq_size++;
//	see();
}

void pop()
{
	int pos = 0;
	int r, l;
	int first_pri = pq[0];
	cout << first_pri << "\n";
	if (pq_size > 1)
	{
		int last_pri = pq[pq_size - 1];
		pq[0] = last_pri;
		pq[pq_size - 1] = 0;
		update();
	}
	else if (pq_size == 1)
		pq[0] = 0;
	pq_size = (pq_size > 0) ?  pq_size - 1 : 0;
//	cout << "poping " << pq[0] << "\n";
//	cout << "before updating\n";
//	see();
//	cout << "after updating\n";
//	see();
}

//int	main(int argc, char **argv)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n;
//	cin >> n;
////	for (int i = 0; i < 10; i++)
////	{
////		cout << pq[i] << "\n";
////	}
//	for (int i = 0; i < n; i++)
//	{
//		int cmd;
//		cin >> cmd;
//		if (cmd == 0)
//		{
////			cout << "pop out!\n";
//			pop();
//		}
//		else
//		{
//			push(cmd);
////			cout << "push " << cmd << "\n";
//		}
//	}
//	return (0);
//}
//
int main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	return (0);
}
