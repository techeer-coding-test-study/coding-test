def solution(sizes):
    max_width = 0
    max_height = 0

    for width, height in sizes:
        if width < height:
            width, height = height, width

        max_width = max(max_width, width)
        max_height = max(max_height, height)

    return max_width * max_height