/*
Q2. 셀정렬을 구현하고 비교 횟수와 교환 횟수를 이전 알고리즘과 비교하여 출력하라.
	다른 알고리즘과 정렬 속도를 비교 출력하라.
*/

#include <iostream>
using namespace std;

const int SIZE = 8;

void swap(int* a, int* b);
void shellSort(int* arr);

int main()
{
    int arr[SIZE] = { 8, 1, 4, 2, 7, 6, 3, 5 };

    // before sort
    cout << "정렬 전 : " << endl;
    for (int k = 0; k < SIZE; k++)
        cout << arr[k] << " ";
    cout << endl << endl;

    shellSort(arr);

    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int* arr)
{
    int temp[3] = { 4, 2, 1 }; // 4-정렬, 2-정렬, 1-정렬
    int exchangeCount = 0, compareCount = 0;

    for (int i = 0; i < 3; i++)
    {
        int count = 0, j = 0;

        // 정렬
        while (SIZE != j + temp[i])
        {
            if (arr[j] > arr[j + temp[i]])
            {
                swap(arr[j], arr[j + temp[i]]);
                exchangeCount++;
            }
            compareCount++;
            j++;
        }

        // 다시 정렬하는 곳으로 돌아감
        for (int k = 0; k < SIZE - temp[i]; k++)
        {
            compareCount++;
            if (arr[k] > arr[k + temp[i]])
            {
                i--;
                count = 1;
                break;
            }
        }

        // 출력
        if (count == 0)
        {
            cout << temp[i] << "정렬 수행" << endl;
            for (int k = 0; k < SIZE; k++)
                cout << arr[k] << " ";
            cout << endl << endl;
        }
    }

    cout << "비교 횟수 : " << compareCount << endl;
    cout << "교환 횟수 : " << exchangeCount << endl;
}