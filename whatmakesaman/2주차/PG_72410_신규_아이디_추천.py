import re

def solution(new_id):
    answer = ''
    answer = new_id.lower()
   
    #2단계
    answer=re.sub('[^a-z0-9\-_.]','',answer)
    #3단계
    answer=re.sub('\.+','.',answer)
    #4단계
    answer=answer.strip('.')
    #5단계
    if len(answer)==0:
        answer='a'
    
    #6단계
    if len(answer)>=16:
        answer=answer[:15]
        answer=answer.rstrip('.')
        
    #7단계
    if len(answer)<=2:
        answer=answer+answer[-1]*(3-len(answer))
    
    
    return answer



# 문자열을 리스트로 바꿔서 반복문으로 돌면서 조건문 추가?
# 조건문 밖에서 길이 조건, 첫/끝 .(마침표) 조건 끝내고
# 코드 실행은 되는데 제출에서 실패한다
#