#include <bits/stdc++.h>

static const double PI = acos(-1.0);
static const double DIAMETER = 60.0;             // 원의 지름 (피트)
static const double CIRCUMFERENCE = DIAMETER * PI; // 원의 둘레 (피트)
static const int NUM_POINTS = 28;                // 둘레 위의 점 개수
static const double DIST_PER_SEGMENT = CIRCUMFERENCE / NUM_POINTS; 
static const double SPEED = 15.0;                // 달리는 속도 (피트/초)
static const double PICKUP_TIME = 1.0;           // 토큰 줍는 데 걸리는 시간 (초)

using namespace std;

int n, m;

int char_to_pos(char c){
  if (c >= 'A' && c <= 'Z')
    return (c - 'A');
  if (c ==  ' ')
    return (26);
  return (27);
}

// 문자 인덱스 매핑
unordered_map<char, int> createCharToIndex() {
    unordered_map<char, int> charToIndex;
    for (int i = 0; i < 26; ++i) {
        charToIndex['A' + i] = i;
    }
    charToIndex[' '] = 26;
    charToIndex['\''] = 27;
    return charToIndex;
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cout << fixed;
  cout << setprecision(10);
  unordered_map<char, int> charToIndex = createCharToIndex();
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 개행 버퍼 비우기
  for (int i = 0; i < n; i++) {
    string buf;
    getline(cin, buf);
    //cout << "string : " << buf << "\n";
    double time = 1.0;
    int cur_pos = char_to_pos(buf[0]);
    for (int j = 1; j < buf.size(); j++) {
      int next_pos = charToIndex[buf[j]];
       // 시계 방향으로 이동했을 때의 세그먼트 개수
      int clockwiseSegments = (next_pos - cur_pos + NUM_POINTS) % NUM_POINTS;
        // 반시계 방향으로 이동했을 때의 세그먼트 개수
      int counterSegments  = (cur_pos - next_pos + NUM_POINTS) % NUM_POINTS;
        // 더 짧은 세그먼트 선택
      int shortestSegments = min(clockwiseSegments, counterSegments);

        // 실제 물리적 거리
      double distance = shortestSegments * DIST_PER_SEGMENT;

        // 이동 시간 = 거리 / 속도
      double travelTime = distance / SPEED;

        // 이동 + 픽업 시간 추가
      time += travelTime + PICKUP_TIME;
      cur_pos = next_pos;
    }
    cout << fixed << setprecision(10) << time << "\n";
  }
  return (0);
}

