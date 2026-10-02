def solution(n, arr1, arr2):
    answer = []

    for i in range(n):
        # 두 지도를 겹친다: 둘 중 하나라도 1이면 1
        combined = arr1[i] | arr2[i]

        # n자리 이진수로 맞춘 뒤 1은 #, 0은 공백으로 변환
        line = format(combined, f"0{n}b")
        line = line.replace("1", "#").replace("0", " ")

        answer.append(line)

    return answer