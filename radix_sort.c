#include <stdint.h>
#include "radix_sort.h"
#include <stdio.h>

int16_t FindMaxDigit(int16_t* arr, int16_t arrSize);

void RadixSort(int16_t* arr, int16_t arrSize)
{
    int16_t digit = FindMaxDigit(arr, arrSize);
    int16_t bucket[10][128];
    int16_t num, n = 1;

    for (int16_t i = 0; i < 10; i++)
    {
        bucket[i][0] = 0;
    }
    
    for (int16_t i = 0; i < digit; i++)
    {
        for (int16_t j = 0; j < arrSize; j++)
        {
            num = (arr[j]/n)%10;
            bucket[num][0]++;
            bucket[num][bucket[num][0]] = arr[j];
        }

        int16_t p = 0;
        
        for (int16_t k = 0; k < 10; k++)
        {
            for (int16_t m = 1; m <= bucket[k][0]; m++)
            {
                
                *(arr + p) = bucket[k][m];
                p++;
            }
            
            bucket[k][0] = 0;
        }

        n *= 10;
    }

}

int16_t FindMaxDigit(int16_t* arr, int16_t arrSize)
{
    int16_t temp = arr[0];
    int16_t i, digit = 0;

    for (i = 0; i < arrSize; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }
    }

    while (temp > 0)
    {
        temp /= 10;
        digit++;
    }

    return digit;
}