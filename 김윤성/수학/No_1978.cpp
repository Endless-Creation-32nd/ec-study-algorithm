#include <iostream>

using namespace std;

bool isprime(int n)
{
	if(n==1) return 0;
	for(int i=2; i<n; i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int main(void)
{
    int N;
    int arr[101] = {0, };
    int result = 0;

    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
        
        result += isprime(arr[i]);
    }

    cout << result;
}