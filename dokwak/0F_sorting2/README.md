# 0F_sorting2
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [15688](https://www.acmicpc.net/problem/15688) | [15688.cpp](./15688/15688.cpp) | std::endl(x) "\n"(o) |

## danger of pow(a, n)
because of floating point, pow(a, n) can be wrong!
use
`pa[n]`
```
pa[0] = 1;
for (int i = 0; i < n - 1 ; i++)
{
	pa[i + 1] = pa[i] * a;
}
a^n = pa[n]
	
```
| easy | [11652](https://www.acmicpc.net/problem/11652) | [11652.cpp](./11652/11652.cpp) | be caution for overflow |
