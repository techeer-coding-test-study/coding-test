def solution(numbers, hand):
    position = {
        1: (0, 0), 2: (0, 1), 3: (0, 2),
        4: (1, 0), 5: (1, 1), 6: (1, 2),
        7: (2, 0), 8: (2, 1), 9: (2, 2),
        0: (3, 1)
    }

    left = (3, 0)   # *
    right = (3, 2)  # #
    answer = []

    for number in numbers:
        target = position[number]

        # 왼쪽 열은 무조건 왼손
        if number in [1, 4, 7]:
            answer.append("L")
            left = target

        # 오른쪽 열은 무조건 오른손
        elif number in [3, 6, 9]:
            answer.append("R")
            right = target

        # 가운데 열은 거리 비교
        else:
            left_distance = abs(left[0] - target[0]) + abs(left[1] - target[1])
            right_distance = abs(right[0] - target[0]) + abs(right[1] - target[1])

            if left_distance < right_distance:
                answer.append("L")
                left = target

            elif left_distance > right_distance:
                answer.append("R")
                right = target

            # 거리가 같으면 주 사용 손
            else:
                if hand == "left":
                    answer.append("L")
                    left = target
                else:
                    answer.append("R")
                    right = target

    return "".join(answer)