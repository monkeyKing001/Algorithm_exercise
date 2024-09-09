# 10_dp
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [1463](https://www.acmicpc.net/problem/1463) | [1463.cpp](./1463/1463.cpp) | if? else if? |
| mid | [9095](https://www.acmicpc.net/problem/9095) | [9095.cpp](./9095/9095.cpp) | postfix |
| mid | [2579](https://www.acmicpc.net/problem/2579) | [2579.cpp](./2579/2579.cpp) | 2d matrix or case classify |
| mid | [1149](https://www.acmicpc.net/problem/1149) | [1149.cpp](./1149/1149.cpp) | |
| hard | [17404](https://www.acmicpc.net/problem/17404) | [17404.cpp](./17404/17404.cpp) | dp need at least one held point. 3 cases of start rgb. last house cannot choose first_house_color. memset can set only 1 or 0. -> setting each one byte. |
| hard | [9251](https://www.acmicpc.net/problem/9251) | [9251.cpp](./9251/9251.cpp) | 2d array |
| hard | [9252](https://www.acmicpc.net/problem/9252) | [9252.cpp](./9252/9252.cpp) | concat input1, 2. trace the reason dp[i][j] = num. (same char? or why?) |
| easy | [2407](https://www.acmicpc.net/problem/2407) | [2407.cpp](./2407/2407.cpp) | use BigInteger, Pascal triangle |
| mid | [16953](https://www.acmicpc.net/problem/16953) | [16953.cpp](./16953/16953.cpp) | no visited array. number is not dup, only increment. Long wrapper class comparation is not `==` but `compare` |
| easy | [1932](https://www.acmicpc.net/problem/1932) | [1932.cpp](./1932/1932.cpp) |  |
| easy | [9465](https://www.acmicpc.net/problem/9465) | [9465.cpp](./9465/9465.cpp) | n == 1 -> ? |
| mid | [2206](https://www.acmicpc.net/problem/2206) | [2206.cpp](./2206/2206.cpp) | bfs + dp |
| easy | [11053](https://www.acmicpc.net/problem/11053) | [11053.cpp](./11053/11053.cpp) | dp or bst. lower_bound returns what? |
| hard | [11444](https://www.acmicpc.net/problem/11444) | [11444.cpp](./11444/11444.cpp) | dp and matrix fibonacci |
| easy | [12852](https://www.acmicpc.net/problem/12852) | [12852.cpp](./12852/12852.cpp) | dp + brute + bfs |
| mid | [12865](https://www.acmicpc.net/problem/12865) | [12865.cpp](./12865/12865.cpp) | looks like greedy but it's not. use 2d dp. 99% index error why? -> in case j = 0 ~ cur_w and cur_w over max_w |
| hard | [7579](https://www.acmicpc.net/problem/7579) | [7579.cpp](./7579/7579.cpp) | 2d dp, think when is the change point(copy past state -----> change point ---->  ignition), when solving with 1d dp, be careful for overlapping update.(update from end to starc) |
| hard | [2098](https://www.acmicpc.net/problem/2098) | [2098.cpp](./2098/2098.cpp) | no path -> max, bits max doesn't mean sol case |
| hard | [10971](https://www.acmicpc.net/problem/10971) | [10971.cpp](./10971/10971.cpp) | same as TSP |
| mid | [1987](https://www.acmicpc.net/problem/1987) | [1987.cpp](./1987/1987.cpp) | bit masking, dfs |
| easy | [11659](https://www.acmicpc.net/problem/11659) | [11659.cpp](./11659/11659.cpp) |  |
| mid | [12015](https://www.acmicpc.net/problem/12015) | [12015.cpp](./12015/12015.cpp) |  |
| hard | [1208](https://www.acmicpc.net/problem/1208) | [1208.cpp](./1208/1208.cpp) | 2 ^ n vs 2 ^ (n / 2) + 2 ^ (n / 2) |
| hard | [14003](https://www.acmicpc.net/problem/14003) | [14003.cpp](./14003/14003.cpp) | memoization the index |
| hard | [1562](https://www.acmicpc.net/problem/1562) | [1562.cpp](./1562/1562.cpp) | bits masking |
| mid | [5582](https://www.acmicpc.net/problem/5582) | [5582.cpp](./5582/5582.cpp) | different with LCS. |
| mid | [samsung_sw_02](https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYkfkR6KLT4DFASe&categoryId=AYkf6zw6MwMDFASe&categoryType=BATTLE&battleMainPageIndex=1) | [samsung_sw_02.cpp](./samsung_sw_02/samsung_sw_02.cpp) |  |
| hard | [1039](https://www.acmicpc.net/problem/1039) | [1039.cpp](./1039/1039.cpp) | bfs, exhaust searching |
| hard | [samsung_3316](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBnFuhqxE8DFAWr) | [samsung_3316.cpp](./samsung_3316/samsung_3316.cpp) | today_bits & tomorrow_bits != 0 -> there is at least one person who had attended yesterday attended today too, tomorrow_bits & (1 << charge_tomorrow) != 0 -> in charge person will attend tomorrow too! |
| ? | [2156](https://www.acmicpc.net/problem/2156) | [2156.cpp](./2156/2156.cpp) |  |
| mid | [11660](https://www.acmicpc.net/problem/11660) | [11660.cpp](./11660/11660.cpp) |  |
| ? | [1756](https://www.acmicpc.net/problem/1756) | [1756.cpp](./1756/1756.cpp) |  |
| easy | [11054](https://www.acmicpc.net/problem/11054) | [11054.cpp](./11054/11054.cpp) | inc, rev |
| hard | [2473](https://www.acmicpc.net/problem/2473) | [2473.cpp](./2473/2473.cpp) |  |
| hard | [15486](https://www.acmicpc.net/problem/15486) | [15486.cpp](./15486/15486.cpp) | from to day, update last day |
| hard | [12970](https://www.acmicpc.net/problem/12970) | [12970.cpp](./12970/12970.cpp) |  |
| mid | [1018](https://www.acmicpc.net/problem/1018) | [1018.cpp](./1018/1018.cpp) | bruteForce |
| easy | [1436](https://www.acmicpc.net/problem/1436) | [1436.cpp](./1436/1436.cpp) |  |
| easy | [1003](https://www.acmicpc.net/problem/1003) | [1003.cpp](./1003/1003.cpp) |  |
| easy | [1904](https://www.acmicpc.net/problem/1904) | [1904.cpp](./1904/1904.cpp) |  |
| easy | [2293](https://www.acmicpc.net/problem/2293) | [2293.cpp](./2293/2293.cpp) |  |
| mid | [2294](https://www.acmicpc.net/problem/2294) | [2294.cpp](./2294/2294.cpp) | 1) coin range be caution. 2) 2D array dp 3) 128MB -> 30000000 3) n vs m vs max |
| easy | [1010](https://www.acmicpc.net/problem/1010) | [1010.cpp](./1010/1010.cpp) | all case mCn |
| hard | [2225](https://www.acmicpc.net/problem/2225) | [2225.cpp](./2225/2225.cpp) | 2d dp[selectedNums][sum] = dp[selectedNums -1][0 ~ sum] |
| hard | [2565](https://www.acmicpc.net/problem/2565) | [2565.cpp](./2565/2565.cpp) | LIS |
| mid | [2096](https://www.acmicpc.net/problem/2096) | [2096.cpp](./2096/2096.cpp) | same like RGB |
| easy | [1912](https://www.acmicpc.net/problem/1912) | [1912.cpp](./1912/1912.cpp) | solely vs dp + me |
| easy | [10844](https://www.acmicpc.net/problem/10844) | [10844.cpp](./10844/10844.cpp) | easy step number |
| mid | [2193](https://www.acmicpc.net/problem/2193) | [2193.cpp](./2193/2193.cpp) | same with stepping order (1, 2 steps) |
| mid | [14501](https://www.acmicpc.net/problem/14501) | [14501.cpp](./14501/14501.cpp) | look at all the series of exit. |
| mid | [1027](https://www.acmicpc.net/problem/1027) | [1027.cpp](./1027/1027.cpp) | if left can see right, right also can see left. No Such Element |
| mid | [13164](https://www.acmicpc.net/problem/13164) | [13164.cpp](./13164/13164.cpp) | total length - (biggest diff) |
| mid | [9461](https://www.acmicpc.net/problem/9461) | [9461.cpp](./9461/9461.cpp) | find the frequency |
| easy | [2003](https://www.acmicpc.net/problem/2003) | [2003.cpp](./2003/2003.cpp) |  |
| easy | [2559](https://www.acmicpc.net/problem/2559) | [2559.cpp](./2559/2559.cpp) |  |
| hard | [10986](https://www.acmicpc.net/problem/10986) | [10986.cpp](./10986/10986.cpp) | 1) long, 2) case branching |
| ? | [1915](https://www.acmicpc.net/problem/1915) | [1915.cpp](./1915/1915.cpp) |  |
| easy | [1343](https://www.acmicpc.net/problem/1343) | [1343.cpp](./1343/1343.cpp) | 2 ~ 50 dp |
| ? | [16493](https://www.acmicpc.net/problem/16493) | [16493.cpp](./16493/16493.cpp) |  |
| hard | [1202](https://www.acmicpc.net/problem/1202) | [1202.cpp](./1202/1202.cpp) | greedy |
| hard | [1679](https://www.acmicpc.net/problem/1679) | [1679.cpp](./1679/1679.cpp) | memset error : memset only set 0 or 1(set by one byte). use fill_n. make single combination |
| easy | [14719](https://www.acmicpc.net/problem/14719) | [14719.cpp](./14719/14719.cpp) | leftMax rightMax |
| easy | [11052](https://www.acmicpc.net/problem/11052) | [11052.cpp](./11052/11052.cpp) | dp for every price |
| ? | [11057](https://www.acmicpc.net/problem/11057) | [11057.cpp](./11057/11057.cpp) |  |
| hard | [2143](https://www.acmicpc.net/problem/2143) | [2143.cpp](./2143/2143.cpp) | prefix Sum. fail 1 : seg Fault |
| mid | [11501](https://www.acmicpc.net/problem/11501) | [11501.cpp](./11501/11501.cpp) | memoization for future max price |
| mid | [1106](https://www.acmicpc.net/problem/1106) | [1106.cpp](./1106/1106.cpp) |  |
| hard | [2515](https://www.acmicpc.net/problem/2515) | [2515.cpp](./2515/2515.cpp) | memo : limitHeight[n], dp[n] |
