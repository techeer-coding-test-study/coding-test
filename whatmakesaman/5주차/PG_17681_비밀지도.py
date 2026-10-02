def solution(n, arr1, arr2):
    answer = []
    d={'0':' ', '1':'#'}
    for i in range(n):
        value=bin(arr1[i] | arr2[i])[2:].zfill(n)
        result= ''
        
        for v in value:
            result+=d[v]
        answer.append(result)
        
    return answer