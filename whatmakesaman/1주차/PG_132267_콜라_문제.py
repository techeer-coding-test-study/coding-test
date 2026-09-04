def solution(a, b, n):
    answer = 0
    
    while n>=a:
        cnt=n//a
        new=cnt*b
        answer+=new
        k=n%a
        n=new+k
    
    return answer


# a=3이면
# 빈 병 20개 일 때 6개 콜라,빈 병 2개
# 8개 빈병-> 2개 콜라, 빈 병 2개
# 4개 빈병-> 1개 콜라, 빈 병 1개
# 2개 빈병
