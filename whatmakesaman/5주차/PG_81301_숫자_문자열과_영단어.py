def solution(s):
    answer = 0
    dic={
        'zero':'0',
        'one':'1',
        'two':'2',
        'three':'3',
        'four':'4',
        'five':'5',
        'six':'6',
        'seven':'7',
        'eight':'8',
        'nine':'9'
    }
    
    for d in dic:
        s=s.replace(d,dic[d])
        
    
    return int(s)



# 숫자의 일부 자릿수를 영단어로 바꾸는
# one4seveneight -> 1478로 출력되도록 one/4/seven/eight
# 딕셔너리로 매핑
# 문자열 안을 어떻게 나누지
# seven eight
