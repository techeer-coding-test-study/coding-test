def solution(array, commands):
    answer = []
    
    for com in commands:
        new_array=array[com[0]-1:com[1]]
        new_array.sort()
        result=new_array[com[2]-1]
        answer.append(result)
    
    return answer