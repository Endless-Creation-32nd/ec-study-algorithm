Backtracking과 DFS
===

## 목차

* 1. Backtracking 이란?
* 2. Backtracking 구현방법
  - 재귀와 DFS
* 3. Python 꿀팁

---
## 1. Backtracking 이란?

* 해를 찾는 도중 해가 아니면, 되돌아가서 다시 해를 찾아가는 방법으로 최적화 문제와 결정 문제를 푸는 방법이다.

* 설명: DFS는 가능한 모든 경로를 탐색함. -> 해가 없는 경로를 탐색. -> 비효율 발생(시간 낭비)
* 이것을 해결하는 것이 백트래킹!


## 2. Backtracking 구현방법

### 어떻게 구현하지?
* 가지치기: 지금의 경로가 해가 될 것 같지 않으면 이전 경로로 되돌아가는 것
  
* 구현방법: 일반적으로 DFS에 조건문을 걸어 답이 절대로 될 수 없는 상황을 정의함. -> 만약 현재 경로가 이 조건문에 걸리면? -> 이전 경로로 되돌아감.

* 문제 상황에 명확한 종료 조건과 단순한 반복이 있다면? 재귀를 활용할 수 있음.

### 재귀와 DFS
* 재귀의 경우 경험상 처음에는 난해하지만 기본 개념이 단순하다보니 계속 하다보면 쉽게 받아드릴 수 있다.

* DFS을 설명하는 그림
  
![DFS](https://mblogthumb-phinf.pstatic.net/MjAyMTAyMDlfMTY3/MDAxNjEyODc1MDg2ODYx.HzFxde96_WVMsPrBdYie6nvbRC5u8yotFq34-CGx33cg.fII_wQqx5yXSNQ-tpfLSdJKczw_Tb492SMXHSQGuoIsg.PNG.judy6647/SE-176b9420-9dc9-4602-8c64-959406536c00.png?type=w800)

* DFS 하면 그래프를 많이 예시로 들지만, 경험상 그 그림보다 좌표평면 같은 이 그림이 실제로 DFS를 구현할 때 더 도움이 되었던 것 같다.


## 3. Python 꿀팁
* 만들어주신 문제집을 풀다보면 중복 여부를 검사할 수 있는 새로운 list를 만들고 싶을 때가 있다. 
* 이때 다른 리스트를 새로운 리스트에 추가하는 방식을 사용하면 이전 리스트가 바뀔 때마다 새로운 리스트도 변한다.
```python
result = [1, 2, 3, 4]
check = []
check.append(result)
result.pop()
print(check)
```
* 결과: [[1, 2, 3]]
  
* 이유: java와 비슷한 참조 개념이라서 그렇다. 
* 해결: 리스트 내부의 값을 하나씩 빼서 대입해줘야 한다.
```python
result = [1, 2, 3, 4]
check = []
check.append([i for i in result])
result.pop()
print(check)
```
* 결과: [[1, 2, 3, 4]]

* 주의할 점!: 이렇게 하면 시간초과남. 다른 방법으로 찾아야 하지만 나중에 리스트를 복사하고 그대로 간직하고 싶다면 이런 방법도 있다.