#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int n;
	int dp[1000] = {};          // 길이를 나타내는 배열
	int arr[1000] = {};         // 수열
	int len = 0;

	cin >> n;

	for (int i = 0; i < n; i++) // 입력
	{
		cin >> arr[i];
	}

	


	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;              // 초기 길이는 1이므로 1로 설정

		for (int j = 0; j < i; j++)     // 현재 인덱스보다 앞의 인덱스의 값들과 모두 비교
		{
			if (arr[i] > arr[j])    // 수열의 값이 이전 수열의 값보다 크다면
			{
				dp[i] = max(dp[i], dp[j] + 1);  // 길이 배열의 값을 이전 인덱스의 값+1로 해준다
			}
		}
		len = max(len, dp[i]);      // 최대 길이를 저장해준다
	}
	
	cout << len << endl;
}