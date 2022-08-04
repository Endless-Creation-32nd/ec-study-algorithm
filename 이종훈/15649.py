def probelmsolver(): # 함수
    if len(s) == m: # 입력된 m, s 리스트의 개수가 같을때 실행, 함수 탈출 조건
        print(' '.join(map(str, s))) #join 함수를 이용하여 ' '구분자를 통해 각 요소들을 출력
        return #함수 탈출

    for i in range(1, n+1): # 1부터 n까지 loop
        if visited[i]: # visited 리스트의 요소 방문 확인
            continue # 만약 방문하였다면 loop를 돌아 다른 visited 요소 확인
        visited[i] = True # 방문하지 않은 visited 요소를 방문처리
        s.append(i) # i를 s 리스트에 추가
        probelmsolver() # 함수를 재귀적으로 호출, 함수의 호출, 탈출은 스택의 append, pop과 동일한 동작원리로 작동함, 위 함수 탈출조건을 만족하면 s 리스트 출력 후 탈출하고 pop을 통해 마지막 요소를 빼줌으로써 백트래킹의 기본적인 원리를 구현함
        s.pop() # 함수가 탈출하였을때 실행됨, 가장 마지막 요소를 빼줌
        visited[i] = False # 다시 방문표시 제거

n, m = map(int, input().split()) # n, m 입력받기
s = [] # 리스트 요소를 넣기 위한 배열, 출력배열
visited = [False] * (n+1) # visited 가 n+1인 이유는 for loop를 1 부터 n+1 까지 돌기때문 - 0번째 리스트는 항상 False

probelmsolver() # 함수 시작