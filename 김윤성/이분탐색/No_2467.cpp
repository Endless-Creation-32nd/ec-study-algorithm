#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[100000];

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int en = N-1;
    int mid;

    int st_result = 0;
    int en_result = N-1;
    int sum_result = arr[st] + arr[en];

    for(int i=0; i<N; i++)
    {
        
        // arr[i] + arr[j] = 0
        // i를 순환하여 arr[i] 값 결정
        // arr[j] 배열의 다른 값들을 이분탐색 하여 -arr[i] 에 가까운 arr[j] 값 탐색
        // sum_result보다 가까운 수인지 확인
        
        // arr[i] 값 결정
        int target = -arr[i];
        if(i != N) st = i;
        else st = i-1;
        en = N-1;

        // 이분탐색
        while(true)
        {
            mid = (st + en) / 2;
            cout << "test" << " " << st << " " << en <<endl;

            if(arr[mid] == target)
            {
                cout << arr[st] << " " << arr[en];
                return 0;
            }
            else if(arr[mid] < target)
            {
                st = mid + 1;
            }
            else if(arr[mid] > target)
            {
                en = mid - 1;
            }

            if(st >= en)
            {
                int sum_cur = arr[st] + arr[en];
                if(sum_cur > sum_result)
                {
                    if(sum_cur + sum_result < 0)
                    {
                        st_result = st;
                        en_result = en;
                        sum_result = arr[st] + arr[en]; 
                    }
                }
                else
                {
                    if(sum_cur + sum_result > 0)
                    {
                        st_result = st;
                        en_result = en;
                        sum_result = arr[st] + arr[en]; 
                    }
                }
                break;
            }
        }
    }

    cout << arr[st_result] << " " << arr[en_result];
    

}