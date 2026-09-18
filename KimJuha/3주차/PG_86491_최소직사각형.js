function solution(sizes) {
  let maxW = 0;
  let maxH = 0;

  for (let i = 0; i < sizes.length; i++) {
    let w = sizes[i][0];
    let h = sizes[i][1];

    if (w < h) {
      const temp = w;
      w = h;
      h = temp;
    }
    if (w > maxW) maxW = w;
    if (h > maxH) maxH = h;
  }
  return maxW * maxH;
}

// 시간복잡도는 O(n)
// 명함이 n개 있으면 for문은 n번 반복하기 때문.
