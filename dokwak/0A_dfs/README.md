# 0A_dfs
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| hard | [16946](https://www.acmicpc.net/problem/16946) | [16946.cpp](./16946/16946.cpp) | not dfs, bfs. instead, union-find. |
| hard | [11437](https://www.acmicpc.net/problem/11437) | [11437.cpp](./11437/11437.cpp) | LCA. err1 : indexOutBound -> parent -1 not update. bidirect connection. so think about how visit in bfs way. small number doesn't mean parent |
| ? | [1240](https://www.acmicpc.net/problem/1240) | [1240.cpp](./1240/1240.cpp) |  |
| hard | [1937](https://www.acmicpc.net/problem/1937) | [1937.cpp](./1937/1937.cpp) |  |
| hard | [16947](https://www.acmicpc.net/problem/16947) | [16947.cpp](./16947/16947.cpp) | undirected graph cycle(cycle_start) detection -> union-find, cycle_path -> dfs. test case 6, 7 error -> cycle_parent cannot be cycle start. error 2. find p[u] cannot be u. if it is, get in loop. |
| hard | [9466](https://www.acmicpc.net/problem/9466) | [9466.cpp](./9466/9466.cpp) | direct graph cycle detection -> u-f, cycle_path -> dfs. union error : p[p_v] = p_u not p[p_u]. cycle_member error :  |
| ? | [2823](https://www.acmicpc.net/problem/2823) | [2823.cpp](./2823/2823.cpp) |  |
