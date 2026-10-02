def solution(survey, choices):
    answer = ''
    
    score={'R':0, 'T':0, 'C':0, 'F':0, 'J':0, 'M':0, 'A':0, 'N':0}
    
    for i in range(len(survey)):
        front=survey[i][0]
        back=survey[i][1]
        c=choices[i]
        
        if c==1:
            score[front]+=3
        elif c==2:
            score[front]+=2
        elif c==3:
            score[front]+=1
        elif c==5:
            score[back]+=1
        elif c==6:
            score[back]+=2
        elif c==7:
            score[back]+=3
            
    for v in ['RT', 'CF', 'JM','AN']:
        first=v[0]
        second=v[1]
        if score[first]>=score[second]:
            answer+=first
        else:
            answer+=second
    
            
    
    return answer



# 몇 번 지표인지 하고 이후 선택지에 따라 무슨형 몇 점인지 갈림
# 형은 안정해져 있는데, 점수는 정해져 있음

# 검사 결과는 모든 질문의 성격 유형 점수를 더해서 -> 각 지표에서 더 높은 점수르 받은 유형
# survey에서 첫번째가 비동의, 두번째가 동의

# 먼저 choice 숫자 보고 동의, 비동의인지 파악 -> 1,2,3이면 앞에 거 / 5,6,7이면 뒤에 거
# 그러면 choice 반복문 돌면서 조건문으로 수 범위 다르게 해서
# 그리고 survey 원소 안의 두 글자도 각각 하나로 나누어야 함