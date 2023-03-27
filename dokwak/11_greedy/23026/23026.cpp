#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, n, b;
	long long r;
	int v[4001];
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++)
	{
		scanf("%d %d %lld", &n, &b, &r);
		long long truck_frq = 0;
		long long box_frq = 1;
		int found_fre = 0;
		int box_max = b;
		vector <long long> need_box_for_one_truck;
		long long sol = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			v[i] = temp;
		}
		//calculate
		int i = 0;//input_box_index
		need_box_for_one_truck.reserve(1000);
		while (!found_fre)
		{
			//has space
			if (box_max >= v[i])
			{
				box_max -= v[i];
				i++;
				if (i == n)
				{
					i = 0;
					truck_frq++;
					//no more space for this box?
					if (box_max < v[0])
						found_fre = 1;
					else 
						need_box_for_one_truck.push_back(box_frq);
					if (truck_frq == r)
					{
						sol = box_frq;
						break;
					}
					else if (truck_frq > r)
					{
						sol = need_box_for_one_truck[r - 2];
						break;
					}
				}
			}
			//np space
			else
			{
				box_frq++;
				box_max = b;
			}
		}
//		cout << "n, b, r : " << n << ", "<< b << ", "<< r << "\n";
//		for (int i = 0; i < need_box_for_one_truck.size(); i++)
//			cout << "need_box for " << i + 1 << "'s truck : "<< need_box_for_one_truck[i] << "\n";
//		cout << "box_frq : " << box_frq << "\n";
//		cout << "truck_frq : " << truck_frq << "\n";
//		if (truck_frq > r)
//			sol += need_box_for_one_truck[r - 2]; 
//		else if (truck_frq == r)
//			sol = box_frq; 
		if (truck_frq < r)
		{
			long long div = r / truck_frq;
			long long mod = r % truck_frq;
			sol += box_frq * div;
//			cout << "div : " << div << "\n";
//			cout << "box_frq : " << box_frq << "\n";
			if (mod != 0)
				sol += need_box_for_one_truck[mod - 1];
		}
		printf("%lld\n", sol);
	}
	return (0);
}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int tc;
//    cin >> tc;
//    while (tc--) {
//        long long N, B, R;
//        cin >> N >> B >> R;
//        vector<int> v(N);
//        for (int i = 0; i < N; i++) {
//            cin >> v[i];
//        }
//        vector<int> box_count(1, 0), has_left(1, 0);
//        vector<int> visited(B, 0);
//        int left = 0, count = 0, index = 1;
//        while (true) {
//            for (int i = 0; i < N; i++) {
//                left += v[i];
//                if (left + v[(i + 1) % N] > B) { //box full
//                    count += 1;
//                    left = 0;
//                }
//            }
//            box_count.push_back(count);
//            has_left.push_back(left ? 1 : 0);
//            if (visited[left]) {
//                break;
//            }
//            visited[left] = index;
//            index += 1;
//        }
//        int ed = index, st = visited[left];
//        if (R < ed) {
//            cout << box_count[R] + has_left[R] << '\n';
//        } else {
//            long long ans = box_count[st];
//            R -= st;
//            ans += (R / (ed - st)) * (box_count[ed] - box_count[st]);
//            if (R % (ed - st)) {
//                ans += box_count[st + R % (ed - st)] - box_count[st] + has_left[st + R % (ed - st)];
//            } else {
//                ans += has_left[ed];
//            }
//            cout << ans << '\n';
//        }
//    }
//    return 0;
//}
