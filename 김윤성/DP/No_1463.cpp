#include <iostream>

using namespace std;


// 3의 배수인지 확인하는 함수
bool check_3(int k)
{
    if(k % 3 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 2의 배수인지 확인하는 함수
bool check_2(int k)
{
    if(k % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int cal_1(int k)
{
    k= k/3;
    return k;
}

int cal_2(int k)
{
    k = k/2;
    return k;
}

int cal_3(int k)
{
    return k-1;
}

int restore_K(int k)
{
    return 0;
}


int main()
{
    unsigned short arr[1000001] = {0, };

    int N;

    for(int i=1; i< 1000001; i++)
    {
        unsigned short result = i;

        if(i == 1)
        {
            continue;
        }

        if(check_3(i) == true)
        {
            if(1 + arr[i/3] < result)
                result = 1 + arr[i/3];
        }
        if(check_2(i) == true)
        {
            if(1 + arr[i/2] < result)
                result = 1 + arr[i/2];
        }
        
            if(1 + arr[i-1] < result)
                result = 1 + arr[i-1];
        

        arr[i] = result;
    }
    

    cin >> N;
    cout << arr[N];
}