from collections import Counter

def solution(participant, completion):
    answer = ''

    p_count = Counter(participant)
    c_count = Counter(completion)
    for n in p_count:
        if p_count[n] != c_count[n]:
            return n


# 회고
# 처음에 각 배열들 2중 반복문으로 하려 했는데 비교가 잘 안됨
# 없는 걸 넣을려고 비교했는데 다르기만 하면 추가가 됨, 문자로 비교는 힘들겠다
# 라이브러리 이용해서 이름당 몇 번 나왔는지, 각 배열 비교해서
