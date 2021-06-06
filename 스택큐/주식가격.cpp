#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len�� �迭 prices�� �����Դϴ�.
int* solution(int prices[], size_t prices_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    
    for (int i = 0; i < prices_len; i++)
        answer[i] = 0;    
    
    for (int i = 0; i < prices_len; i++)
    {
        if (i == prices_len)
        {
            answer[i] = 0;
            break;
        }
        for (int j = i + 1; j < prices_len; j++)
        {
            answer[i]++;
            if (prices[i] > prices[j])
            {
                break;
            }
        }
    }
    return answer;
}