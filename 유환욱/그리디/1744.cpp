#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ans = 0;      // 가능한 정답이 너무 커서 int형으로는 표현 불가

void Sum(vector<int> v) {    // 숫자가 큰 두 수의 곱을 통해 정답에 저장
  while (v.size() > 1) {
    ans += *(v.end() - 1) * *(v.end() - 2);
    v.pop_back();
    v.pop_back();
  }
  if (v.size())
    ans += v[0];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> plusNum, minusNum; // 양수 벡터, 음수 벡터를 따로 설정
  int N, number;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> number;
    if (number == 1) ans++;     // 1이면 항상 묶는것 보다 더해주는게 이득
    else if (number > 0)        // 양수이면 plusNum 벡터에 넣어줌
      plusNum.push_back(number);
    else                        // 음수, 0이면 minumNum 벡터에 넣어줌
      minusNum.push_back(number);
  }

  sort(plusNum.begin(), plusNum.end()); // 오름차순 정렬 ex) 1,2,3
  sort(minusNum.begin(), minusNum.end(), greater<>());  // 내림차순 정렬 ex) -1, -2, -3
  Sum(plusNum);
  Sum(minusNum);
  cout << ans;
}