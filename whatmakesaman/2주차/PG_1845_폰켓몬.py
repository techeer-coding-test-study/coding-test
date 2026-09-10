def solution(nums):
    answer = 0
    new_num=set(nums)
    answer=len(new_num)
    result=min(answer, len(nums)//2)
    return result
# 같지 않는 수를 뽑아야 함
# 다중 반복문으로 비교하기에는 시간복잡도가 너무 커짐
# 그냥 set으로 묶어도 되나-> 묶기만 하니까 n/2 충족을 안하네
# 중복 제거 리스트 길이보다 n/2가 작으면 n/2개이고
# 중복 제거한 길이보다 n/2가 크면 중복제거한 길이
