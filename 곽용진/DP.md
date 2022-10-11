# 다이나믹 프로그래밍

## 목차
* 1. 다이나믹 프로그래밍(DP)란 무엇인가
>
* 2. 분할 정복과 차이점
>
* 3. 구현 방법 
>
* 4. 여렵게 느껴지는 이유
>
* 5. 11053번 코드 
#

## 1. 다이나믹 프로그래밍(DP)란 무엇인가
* 정의: 큰 문제를 한 번에 해결하기 힘들 때 작은 여러 개의 문제로 나누어 해결하는 기법

* 예시) 피보나치 수열

#
## 2. 분할 정복과 차이점
* 분할 정복
1. 재귀를 공부할 떄 문제 풀다 한 번쯤 봤던 용어(백준)

2. 큰 문제를 작은 문제로 나누어 해결한 후 다시 하나로 합쳐 해결하는 방법

* DP와 분할 정복의 차이점
>
    -> DP는 한 번 해결했던 문제를 다시금 해결함
>
* 이해를 돕기 위한 그림
![DP](https://ialy1595.github.io/images/dynamic_programming/fntree1.png)
#
## 3. 구현 방법
>
### 3.1 보텀업(Botton-Up) = 상향식
* 정의: 작은 문제부터 해결하여 큰 문제를 해결하는 방법

* 예시 코드
``` python
d = [0] * 100 # DP 테이블 초기화

d[1] = 1
d[2] = 1
n = 99

for i in range(3, n+1):
    d[i] = d[i-1] + d[i-2]

print(d[n])
```
### 3.2 탑다운(Top-Down)
* 정의: 큰 문제를 해결하기 위해 작은 문제를 호출하는 방법
* 예시 코드
``` python
d = [0] * 100

def pibo(x):
    print('f(' + str(x) + ')', end=' ')
    if x == 1 or x == 2:
        return 1

    if d[x] != 0:
        return d[x]

    d[x] = pibo(x-1) + pibo(x-2)

    return d[x]

pibo(6)
``` 
#
## 4. 어렵게 느껴지는 이유
1. DP인지 아닌지 판단해야 함
2. 점화식을 알 수 있는지 직접 계산하며 확인해야 함
3. 구현이 어렵지는 않지만, 문제 해결 방법을 알아내는 것이 어려움(수학..같다)

#
## 5. 11053번 코드
``` python
import sys
input = sys.stdin.readline

n = int(input().rstrip())
a = list(map(int, input().split()))
d = [0 for _ in range(n)]
d[0] = 1

for i in range(1, n):
    s = []
    for j in range(i):
        if a[i] > a[j]:
            s.append(d[j])
    
    if not s:
        d[i] = 1
    else:
        d[i] = max(s) + 1

print(max(d))
```
