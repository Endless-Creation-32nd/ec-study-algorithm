#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int m, int n)
{
    vector<int> primes; // 소수를 저장하는 vector 
    vector<bool> state(n+1, true); // 1~n 까지 소수인지를 나타내는 벡터 처음엔 모두가 소수라고 가정
    
    state[1] = false; // 1은 소수가 아님을 명시

    for(int i=2; i<=n; i++) // 2부터 n까지 소수인지 판별
    {
        if(!state[i]) continue; // i가 소수가 아닌 pass
        for(int j= 2*i; j<=n; j+=i) // i가 소수라면 i의 배수를 모두 소수로 표시
        state[j] = false;
    }

    for(int i=2; i<=n; i++)
    {
        if(state[i]) primes.push_back(i); // 소수인 경우 primes에 추가
    }

    return primes;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> vec = sieve(M, N);
    
    for(int i = 0; i< vec.size(); i++)
    {
        if(vec[i] >= M)
        {
            cout << vec[i] <<endl;
        }
        
    }

    return 0;
}