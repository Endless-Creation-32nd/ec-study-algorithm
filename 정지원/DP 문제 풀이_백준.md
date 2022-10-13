## Dinamic programing 문제 풀이

백준 2447번 별찍기 10 

처음에 문자열로 구성된 2차원 배열을 어떻게 처리하는지에 대해서 고민을 많이 했었다.
2차원 배열을 2차원 배열에 넣으면 4포인터 써야된다 라고 잘못 생각했다.

결국 풀이 방법이 두가지 있는데
## 1. 분할 정복 방식 - 비어있는 칸의 좌표를 보고 일반화하는 방식
## 2. 2차원 배열을 사용하되, 증가량을 조절하는 방법(ex- 어디서는 3이고 다음은 9씩, 그 다음은 9씩 i의 증가량을 늘려주기)
이렇게 있다.

검색하면 주로 1번으로 많이 풀었다.
### 1번 방식
비어있는 칸에 대해서 일반화를 하자면 다음과 같다.
n=3일 때 비어있는 2차원 배열의 좌표는 (1,1)
![image](https://user-images.githubusercontent.com/101682617/195578399-a98003ba-7b8d-46c9-a6ac-73eba692a86e.png)
n=9일 때 3x3 크기로 잘라주자
비어있는 부분의 가로좌표는 1,4,7,10 ...
3으로 나누면 1이 남는다.
![image](https://user-images.githubusercontent.com/101682617/195578764-b1acfe4e-476b-4370-b806-ac942f34c035.png)

이 점을 이용해서 풀면
이제 N=9일 때, 중앙 빈 부분의 좌표를 살펴보면

(3,3), (3,4), (3,5), (4,3), (4,4), (4,5), (5,3), (5,4), (5,5)

 

이것을 기본 형태로 일반화해보기 위해 각 좌표들을 3으로 나눠보면

위 그림의 빨간색 숫자와 같고, 이는 기본 형태의 (1,1)이 비었던 것과 동일한 양상을 보인다!

위 좌표에서 중앙의 빈 곳들은 (i / 3) % 3 == 1 && (j / 3) % 3 == 1 로 일반화할 수 있다.

 

이를 바탕으로 빈칸임을 검사하는 조건을 작성하면

(i / n) % 3 == 1 && (j / n) % 3 == 1

이 조건식을 재귀적으로 검사하면 문제를 해결할 수 있다.
```cpp
	if (i / n % 3 == 1 && j / n % 3 == 1) {
		cout << " ";
	}
	else if (n / 3 == 0) {
		cout << "*";
	}
	else {
		star(i, j, n / 3);
	}
  ```
  
  그러므로 최종코드는 다음과 같다.
```cpp
#include <iostream>
using namespace std;

void star(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1) {
		cout << " ";
	}
	else if (n / 3 == 0) {
		cout << "*";
	}
	else {
		star(i, j, n / 3);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << '\n';
	}
}
```

출처)https://codesyun.tistory.com/75


### 2번 방식은 2차원 배열을 사용한 방식인데,
g(n)이 정 가운데 뚫린 빈칸 빼고 배열의 구성요소가 3개의 g(n-1)가 한 변이 되는 정사각형으로 둘러쌓인 꼴이면
2차원 배열의 인덱스 증가량을 다르게 설정해줘야 한다.
처음 기본형은 3이 증가하면 다음은 9가, 그 다음은 27이 증가하게끔

```cpp
#include <iostream>

using namespace std;
int n;
char star[6562][6562];

void printStar(int col, int row, int size) {
	int tempsize = size / 3;
	if (size == 3) {
		for (int i = col; i < col+size; i++) {
			for (int j = row; j < row+size; j++) {
				if (i >= col+tempsize && i < col+tempsize * 2 && j >= row+tempsize && j < row+tempsize * 2) {
					star[i][j] = ' ';
				}
				else {
					star[i][j] = '*';
				}
			}
		}
	}

	else {
		for (int i = col; i < col + size; i += tempsize) {
			for (int j = row; j < row + size; j+= tempsize) {
				if (i >= col + tempsize && i < col + tempsize * 2 && j >= row + tempsize && j < row + tempsize * 2) {
					star[i][j] = ' ';
				}
				else {
					printStar(i, j, tempsize);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star[i][j] = ' ';
		}
	}

	printStar(0,0,n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}

}
```

출처)https://bbeomgeun.tistory.com/m/44

