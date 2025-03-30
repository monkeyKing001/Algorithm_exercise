# 09_bfs

### Lessons
---
* poping queue and visiting check do not need to be executed simutaneously

### Problems
---

| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| hard | [4179](https://www.acmicpc.net/problem/4179) | [4179.cpp](./4179/4179.cpp) | 1. be careful for Fire numbers. pushing queue and visited writing executed simutaneously |
| easy | [1697](https://www.acmicpc.net/problem/1697) | [1697.cpp](./1697/1697.cpp) | 1. pushing queue and visited writing executed simutaneously |
| easy | [1012](https://www.acmicpc.net/problem/1012) | [1012.cpp](./1012/1012.cpp) | 1. be caution for confusing n, m/ x, y/ r, c etc |
| easy | [10026](https://www.acmicpc.net/problem/10026) | [10026.cpp](./10026/10026.cpp) | 1. change color(RED or GREEN) at the first bfs. 2. be caution for counting sol. |
| mid | [7569](https://www.acmicpc.net/problem/7569) | [7569.cpp](./7569/7569.cpp) | 1. coordinates precision 2. pushing queue start point |
| easy | [7569](https://www.acmicpc.net/problem/7576) | [7569.cpp](./7569/7569.cpp) | |
| easy | [7562](https://www.acmicpc.net/problem/7562) | [7562.cpp](./7562/7562.cpp) | global or main local var need to be cleaned.(board, queue) |
| mid | [13549](https://www.acmicpc.net/problem/13549) | [13549.cpp](./13549/13549.cpp) | bfs but count carefully |
| ? | [16236](https://www.acmicpc.net/problem/16236) | [16236.cpp](./16236/16236.cpp) |  |
| ? | [14940](https://www.acmicpc.net/problem/14940) | [14940.cpp](./14940/14940.cpp) |  |
| mid | [1520](https://www.acmicpc.net/problem/1520) | [1520.cpp](./1520/1520.cpp) | TLE how to solve? visited no need. but path finding need optimization |
| hard | [samsung_1855](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LnipaDvwDFAXc) | [samsung_1855.cpp](./samsung_1855/samsung_1855.cpp) | LCA2 + bfs. Queue Entry int[] -> be carefule which index value is which. arr index out err. -> if (dp_parent[node1][exp(worng) -> i(correct)] != dp_parent[node2][exp(wrong) -> i(correct)]) |
| hard | [11438](https://www.acmicpc.net/problem/11438) | [11438.cpp](./11438/11438.cpp) | 1) how to update current's 2 ^ k depth parent? -> half_parent(i - 1). 2) OutIndexErr -> depth diff update. 3) makeing same depth and find anc must be in binary jumpUp. 4) while finding anc exp must be bigger until u, v parents are different. |
| hard | [14442](https://www.acmicpc.net/problem/14442) | [14442.cpp](./14442/14442.cpp) | 8.txt case. with biggest chance visiting. visited[][][] |
| hard | [2606](https://www.acmicpc.net/problem/2606) | [2606.cpp](./2606/2606.cpp) | bfs |
| hard | [2589](https://www.acmicpc.net/problem/2589) | [2589.cpp](./2589/2589.cpp) | bfs + dfs |
| hard | [27440](https://www.acmicpc.net/problem/27440) | [27440.cpp](./27440/27440.cpp) | bug 1. set.find() is not working -> problem was <= vs <  sol 1. TLE. reason : long vs long long |
| easy | [1260](https://www.acmicpc.net/problem/1260) | [1260.cpp](./1260/1260.cpp) |  |
| ? | [2573](https://www.acmicpc.net/problem/2573) | [2573.cpp](./2573/2573.cpp) |  |
| ? | [3109](https://www.acmicpc.net/problem/3109) | [3109.cpp](./3109/3109.cpp) |  |
| ? | [6593](https://www.acmicpc.net/problem/6593) | [6593.cpp](./6593/6593.cpp) |  |
| ? | [14716](https://www.acmicpc.net/problem/14716) | [14716.cpp](./14716/14716.cpp) |  |
| ? | [10282](https://www.acmicpc.net/problem/10282) | [10282.cpp](./10282/10282.cpp) |  |
| ? | [2468](https://www.acmicpc.net/problem/2468) | [2468.cpp](./2468/2468.cpp) |  |
