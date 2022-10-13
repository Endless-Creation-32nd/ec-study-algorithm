#include <iostream>

using namespace std;

int main()
{
    int N;                      // 수열의 크기
    int input[1001] = {0, };    // 수열을 저장하는 배열
    int dp[1001] = {0, };       // dp를 이용하는 배열

    int result = 0; // 최대 길이에 해당하는

    //dp[i] 에는 무엇을 저장할 건가? -> 수열의 길이가 i 일 때의 길이 최대?
    
    cin >> N;

    for(int i=1; i<=N; i++)
    {
        cin>> input[i];
    }

    // 수열의 길이가 1인 경우부터 차근차근 시작

    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(input[i]>input[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                if(dp[i] > result)
                    result = dp[i];
            }
        }
    }

    cout << result;
}