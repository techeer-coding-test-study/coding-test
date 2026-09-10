function solution(nums) {
  const maxSelect = nums.length / 2;
  const pocketmon = new Set(nums).size;
  return Math.min(pocketmon, maxSelect);
}
