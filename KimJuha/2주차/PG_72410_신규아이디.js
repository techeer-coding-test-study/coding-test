function solution(new_id) {
  let id = new_id;

  // 1단계: 소문자로 변환
  id = id.toLowerCase();

  // 2단계: 허용 안 된 문자 제거
  id = id.replace(/[^a-z0-9\-_.]/g, "");

  return id;
}
