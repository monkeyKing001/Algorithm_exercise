N = int(input())
arr = [list(input().strip()) for _ in range(N)]
# print("original")
# print(_arr)


def maxcnt(_arr):
    _ans = 0
    # print(_arr)
    for i in range(N):
        cnt = 1
        for j in range(1, N):
            if _arr[i][j-1] == _arr[i][j]:
                cnt += 1
            else:
                cnt = 1
            _ans = max(_ans, cnt)
    for j in range(N):
        cnt = 1
        for i in range(1, N):
            if _arr[i-1][j] == _arr[i][j]:
                cnt += 1
            else:
                cnt = 1
            _ans = max(_ans, cnt)
    return _ans


ans = 0
for i in range(1, N):
    for j in range(N):
        # 위와 swap
        if arr[i-1][j] != arr[i][j]:  # 다를 때만 swap
            arr[i-1][j], arr[i][j] = arr[i][j], arr[i-1][j]
            ans = max(ans, maxcnt(arr))
            # 원위치
            arr[i-1][j], arr[i][j] = arr[i][j], arr[i-1][j]

for j in range(1, N):
    for i in range(N):
        # 오른쪽과 swap
        if arr[i][j-1] != arr[i][j]:  # 다를 때만 swap
            arr[i][j-1], arr[i][j] = arr[i][j], arr[i][j-1]
            ans = max(ans, maxcnt(arr))
            # 원위치
            arr[i][j-1], arr[i][j] = arr[i][j], arr[i][j-1]
print(ans)
