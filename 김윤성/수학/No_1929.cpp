#include <iostream>
#include <vector>
using namespace std;

bool isprime(int n)  //에라토스테네스의 채로만 해결 가능!
{
	if(n==1) return 0;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int main(void)
{
    int M, N;
    cin >> M >> N;
    
    vector<int> vec;
    vector<bool> is_number_prime(N+1, true);
    is_number_prime[1] = false;
    
    for(int i=2; i<=N; i++)
    {
        if(is_number_prime[i] != 1) continue;

        cout << i <<endl;

        // 이후 모든 배수를 소수로 바꿔버림

        for(int j= 2 * i; i<=N; i += i)
        {
            is_number_prime[j] = false;
        }
    }
}