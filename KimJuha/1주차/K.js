function solution(array, commands) {
  const result = [];
  for (let a = 0; a < commands.length; a++) {
    const i = commands[a][0];
    const j = commands[a][1];
    const k = commands[a][2];

    const sliced = array.slice(i - 1, j);
    const sorted = sliced.sort((a, b) => a - b);

    result.push(sorted[k - 1]);
  }
  return result;
}
