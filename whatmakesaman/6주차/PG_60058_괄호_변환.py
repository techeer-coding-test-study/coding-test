def solution(p):
    if not p:
        return ''
    dic={'(':1,
          ')':-1}
    answer = ''
    u=[]
    v=[]
    val=0
    for i in range(len(p)):
        val+=dic[p[i]]
        if val==0:
            break
    u,v=p[:i+1], p[i+1:]

    if u[0]=='(':
        return u+solution(v)
    else:
        answer+='('
        answer+=solution(v)
        answer+=')'
        
        for c in u[1:-1]:
            if dic[c]==1:
                answer+=')'
            else:
                answer+='('
    
        
    return answer




