#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void * a, const void* b){
    return(*(int *)a - *(int *)b);
}
// number_len은 배열 number의 길이입니다.
int solution(int number[], size_t number_len) {
    int answer = 0;
    qsort(number, number_len, sizeof(int), compare);
    for(int i = 0;i<(int)number_len;i++){
        int right = (int)number_len - 1;
        int left = i+1;
        while(right > left){
            int sum = number[i] + number[right] + number[left];
            if(sum == 0){
                if (number[left] == number[right]) {
                    int count = right - left + 1;
                    answer += (count * (count - 1)) / 2;
                    break;
                }
                int left_val = number[left];
                int left_count = 0;
                while (left <= right && number[left] == left_val) {
                    left_count++;
                    left++;
                }

                int right_val = number[right];
                int right_count = 0;
                while (left <= right && number[right] == right_val) {
                    right_count++;
                    right--;
                }
                answer += left_count * right_count;
            }
            else if(sum < 0){
                left++;
            }
            else
                right--;
        }
    }
    return answer;
}
