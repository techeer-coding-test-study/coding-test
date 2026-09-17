def solution(sizes):
    answer = 0
    
    for size in sizes:
        
        #한 변에 큰 것들 모으고, 다른 변에 작은 것들 모으고
        if size[0]>size[1]:
            size[0], size[1]=size[1],size[0]   
    #최댓값 갱신        
    max_w=max(size[0] for size in sizes)
    max_h=max(size[1] for size in sizes)
    answer=max_w*max_h
    
    return answer

