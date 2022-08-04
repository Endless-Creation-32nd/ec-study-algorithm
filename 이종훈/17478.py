import sys
input = sys.stdin.readline
n = int(input())

def recursive(num): #재귀함수로 자기 자신을 호출
    print("____" * (n - num), end="") #n-num을 해주어 해당 숫자에서 불려준 수를 빼줌으로써 ____의 개수를 일치시켜줌
    print('"재귀함수가 뭔가요?"')
    if num == 0:
        print("____" * (n-num), end="")
        print('"재귀함수는 자기 자신을 호출하는 함수라네"')
        print("____" * (n - num), end="")
        print("라고 답변하였지.")
        return 0
    else:
        print("____" * (n - num), end="")
        print('"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.')
        print("____" * (n - num), end="")
        print('마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.')
        print("____" * (n - num), end="")
        print('그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."')

    recursive(num-1) # 재귀함수를 먼저 불러들인 이후 return을 해줌으로써 호출이 끝난 뒤 반환값을 돌려줌
    print("____" * (n - num), end="")
    result = print("라고 답변하였지.")
    return result

print("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.")

recursive(n)