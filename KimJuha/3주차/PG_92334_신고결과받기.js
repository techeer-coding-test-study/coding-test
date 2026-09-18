function solution(id_list, report, k) {
  const newReport = [...new Set(report)];

  const reportedCount = {};
  const reportedBy = {};

  for (let i = 0; i < id_list.length; i++) {
    reportedCount[id_list[i]] = 0;
    reportedBy[id_list[i]] = [];
  }

  for (let i = 0; i < newReport.length; i++) {
    const parts = newReport[i].split(" ");
    const reporter = parts[0];
    const reported = parts[1];

    reportedCount[reported]++;
    reportedBy[reporter].push(reported);
  }
  const result = [];

  for (let i = 0; i < id_list.length; i++) {
    const me = id_list[i];
    let mailCount = 0;

    for (let j = 0; j < reportedBy[me].length; j++) {
      const meReported = reportedBy[me][j];
      if (reportedCount[meReported] >= k) {
        mailCount++;
      }
    }
    result.push(mailCount);
  }
  return result;
}

// 시간복잡도는 O(n+m)
// 이중 for문처럼 보이지만 j는 me가 신고한 사람 수만큼만 반복됨
// -> newReport의 전체 갯수를 넘지 못함 (ReportedBy는 모두 newReport를 순회하면서 push 한 것들)
