# Sorting(정렬)

## 목차
### 1. 정렬이란?

### 2. 정렬의 종류
- 선택 정렬
- 삽입 정렬
- 퀵 정렬
- 계수 정렬
- 파이썬의 정렬 라이브러리
  
### 3. 정리
### 4. 파이썬 내장함수 sorted(sort)의 활용
#
## 1. 정렬이란?
* 정의: 데이터를 특정한 기준에 따라 나열하는 것
* 종류: 선택 정렬, 삽입 정렬, 퀵 정렬, 계수 정렬 등
* 중요한 이유: 데이터를 정렬해야만 사용할 수 있는 알고리즘들이 존재함 (예, 이진 탐색)
* 내림차순과 오름차순은 서로 결과를 뒤집기만 하면 되기 때문에 둘 중 하나만 확실하게 할 줄 아는 것이 중요함
#
## 2. 정렬의 종류
### 2.1 선택정렬
* 리스트에서 가장 작은 데이터를 선택해 맨 앞에 있는 데이터와 바꾸고, 그다음 작은 데이터를 선택해 앞에서 두 번째 데이터와 바꾸는 과정을 반복하는 방법

* 이해를 돕기 위한 그림
  ![선택 정렬](https://t1.daumcdn.net/cfile/tistory/256B9C34545081D835)
  ** 처음 단계에서는 최솟값을 맨 앞으로 가져옴
* 선택 정렬 코드(파이썬)
  ```python
  array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

  for i in range(len(array)):
    min_index = i
    for j in range(i + 1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
    
    array[i], array[min_index] = arrray[min_index], array[i] # 스와프
    print(array)

    # 결과: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

* 시간 복잡도: O(N^2)

### 2.2 삽입 정렬
* 리스트의 각 데이터를 하나씩 확인하며, 각 데이터를 적절한 위치에 삽입하는 방법

* 이해를 돕기 위한 그림
![삽입 정렬](https://t1.daumcdn.net/cfile/tistory/2569FD3854508BE811)

* 삽입 정렬 코드(python)
```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
    for j in range(i, 0, -1):
        if array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
        else: # 자기 보다 작은 데이터를 만났을 경우
            break
```

* 시간 복잡도
  * 최선의 경우: O(N) 
  * 최악의 경우: O(N^2)
  * 데이터가 정렬되어 있을 수록 유리
#
### 2.3 퀵 정렬
* 기준 데이터(Pivot)를 정하고, 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 방법
* 이해를 돕기 위한 그림
![퀵 정렬](https://gmlwjd9405.github.io/images/algorithm-quick-sort/quick-sort.png)

* 퀵 정렬 코드(python)
```python
array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(array, start, end):
    if start >= end: # 원소가 1개인 경우
        return
    pivot = start
    left = start + 1
    right = end
    while left <= right:
        while left <= end and array[left] <= array[pivot]:
            left += 1
        while right > start and array[right] >= array[pivot]:
            right -= 1
        if left > right:
            array[right], array[pivot] = array[pivot], array[right]
        else:
            array[left], array[right] = array[right], array[left]

    quick_sort(array, start, right - 1)
    quick_sort(array, right + 1, end)

quick_sort(array, 0, len(array) - 1)
print(array)
```
* 시간 복잡도: O(NlogN)
* 보충: 퀵 정렬의 경우 대부분의 경우에서 사용되는 빠른 알고리즘임
#
### 2.4 계수 정렬    
* 특정한 조건이 부합할 때만 사용할 수 있지만 매우 빠른 정렬 알고리즘
* 특정 조건: 가장 큰 데이터와 가장 작은 데이터의 차이가 1,000,000 이하여서 0을 포함한 총 1,000,001개의 리스트 공간이 확보 가능한 상태

* 이해를 돕기 위한 그림
![계수 정렬](https://velog.velcdn.com/images%2Fluvlik207%2Fpost%2F0f5454ab-b88d-4e1f-8a49-80b5d88e6f30%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-09-24%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%2011.03.27.png)

* 계수 정렬 코드(python)
```python
array = [7, 5, 9, 0 3, 1, 6, 2 9, 1, 4, 8, 0, 5, 2]
count = [0] * (max(array) + 1)

for i in range(len(array)):
    count[array[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=' ')
```
* 시간 복잡도: O(N + K)
* 주의: 계수 정렬의 경우 데이터가 0과 999,999처럼 단 2개만 존재하는 경우 공간을 낭비하므로 데이터의 특성을 파악하기 어려울 때는 퀵 정렬을 사용하는 것이 좋음

# 
### 2.5 파이썬의 정렬 라이브러리
* 파이썬의 기본 정렬 라이브러리인 sorted() 함수는 퀵 정렬과 비슷한 병합 정렬을 기반으로 만들어졌기 때문에 시간 복잡도 O(NlogN)을 보장한다.
* 파이썬의 정렬 라이브러리 코드(python)
```python
array = [('바나나', 2), ('사과', 5), ('당근', 3)]

def setting(data):
    return data[1]

result = sorted(array, key=setting)
print(result)

#결과: [('바나나', 2), ('당근', 3), ('사과', 5)]
```
#
## 3. 정리
1. 정렬 알고리즘으로 풀 수 있는 문제: 단순히 정렬 기법을 알고 있나 물어보는 문제
2. 정렬 알고리즘 원리를 묻는 문제: 위에서 소개한 다양한 정렬 알고리즘의 원리를 알아야 해결할 수 있는 문제
3. 더 빠른 정렬이 필요한 문제: 퀵 정렬 기반의 기법으로는 풀 수 없고, 계수 정렬 등의 다른 알고리즘을 이용하거나 기존에 알려진 알고리즘의 구조적 개선을 거쳐야 하는 문제
#
## 4. 파이썬 내장함수 sorted(sort)의 활용
1. lambda 표현을 잘 활용하자
* 코드 예시
```python
# 2차원 배열에서 정렬을 요구할 때 (백준 11650번)
array = [('바나나', 2), ('사과', 5), ('당근', 3)]
# x[0]을 기준으로 먼저 정렬을 한 후, x[1]을 기준으로 정렬 함
array = sorted(array, key=lambda x: (x[0], x[1]))

# 2차원 배열에서 오름차순 정렬과 내림차순 정렬이 섞여 있을 때 (백준 10825번)
# 기본 오름차순, 음수 붙이면 내림차순
# 문자열도 ASCII 코드 순서로 알아서 정렬해줌
lst = sorted(lst, key=lambda x:(-x[1], x[2], -x[3], x[0])) 

# 딕셔너리 자료형을 정렬해야 할 때 
temp = {2:3, 1:2} # 나온 숫자:반복 횟수
# lambda에서 오름차순으로 정렬된 리스트를 내림차순으로 바꿀 때 reverse도 사용 가능
# items()는 딕셔너리 자료형을 리스트로 바꾸어줌 (sorted 함수가 리스트 내장 함수여서 리스트만 정렬 가능함)
# 아래의 경우 temp.items() 하면 temp = [(2, 3), (1, 2)]로 바꾸어 줌
temp = sorted(temp.items(), key=lambda x: x[1], reverse=True)
```