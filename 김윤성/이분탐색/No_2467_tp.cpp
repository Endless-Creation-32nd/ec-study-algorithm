#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long arr[100000];

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int en = N-1;
    long sum;

    int st_result = 0;
    int en_result = N-1;
    long sum_result = arr[st] + arr[en];

    while(st < en)
    {
        sum = arr[st] + arr[en];

        if(sum == 0)
        {
            st_result = st;
            en_result = en;
            break;
        }
        else if(sum < 0)
        {
            st++;
        }
        else if(sum > 0)
        {
            en--;
        }

        if(abs(sum) < abs(sum_result))
        {
            st_result = st;
            en_result = en;
            sum_result = sum;
        }
    }

    cout << arr[st_result] << " " << arr[en_result];
}