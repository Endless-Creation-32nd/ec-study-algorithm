#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N; // N개의 정수가 A[1]~A[N] 으로 주어짐
    int M; // 확인 대상인 정수의 갯수
    int A[100000];
    
    cin >> N; // N 입력
    
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }

    sort(A, A+N);

    cin >> M;

    for(int i = 0; i<M; i++)
    {
        int target;
        cin >> target;

        int st = 0;
        int en = N-1;
        int mid;

        while(st <= en)
        {
            mid = (st + en) / 2;

            if(A[mid] == target)
            {
                cout << 1 << endl;
                break;
            }
            else if(A[mid] < target)
            {
                st = mid + 1;
            }
            else if(A[mid] > target)
            {
                en = mid - 1;
            }
            
            if(en < st)
            {
                cout << 0 << endl;
                break;
            }
        }
    }
}