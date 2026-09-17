def solution(id_list, report, k):
    answer = []
    
    #중복 신고는 1번으로 치니까 중복 제거
    new_report=list(set(report))
    
    #신고자가 신고한 사람들 목록
    a_report={}
    for id in id_list:
        a_report[id]=[]
        
    #신고당한 횟수 기록
    cnt_report={}
    for id in id_list:
        cnt_report[id]=0
        
    #신고 목록들 보면서 기록
    for r in new_report:
        reporter,reported=r.split()
        a_report[reporter].append(reported)
        cnt_report[reported]=cnt_report[reported]+1
        
    #k번 이상 신고
    k_over=[]
    for id in id_list:
        if cnt_report[id] >=k:
            k_over.append(id)
            
    # 유저별 메일 받은 횟수, 신고한 사람들 중 처리된 사람 수
    for id in id_list:
        cnt_mail=0
        for r in a_report[id]:
            if r in k_over:
                cnt_mail+=1
        answer.append(cnt_mail)
    
    
    
    return answer








