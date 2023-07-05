/*
퀵정렬 알고리즘을 구현하라.
*/

#include <iostream>

const int SIZE = 9;
using namespace std;

void swap(int* a, int* b);
void QuickSort(int arr[], int pl, int pivot, int pr);

int main()
{
    // 정렬전
    int arr[SIZE] = { 5, 7, 1, 4, 6, 2, 3, 9, 8 };
    cout << "정렬 전 : " << endl;
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

    QuickSort(arr, 0, SIZE / 2, SIZE - 1);

    // 정렬후
    cout << "정렬 후 : " << endl;
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void swap(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void QuickSort(int arr[], int pl, int pivot, int pr)
{
    // 처음 인덱스 값 저장
    int left = pl;
    int right = pr;

    while (1)
    {
        //  pl과 pr 움직이기
        while (arr[pivot] > arr[pl])
            pl++;
        while (arr[pivot] < arr[pr])
            pr--;
        //  swap
        if (pl <= pr)
        {
            swap(arr[pl], arr[pr]);
            pl++;
            pr--;
        }
        // 종료조건
        if (pr <= pl)      break;
    }

    if (left < pr) QuickSort(arr, left, (left + pr) / 2, pr);         // pr이 0이 될때까지 정렬
    if (pl < right) QuickSort(arr, pl, (pl + right) / 2, right);  // pl이 NUM-1이 될때까지 정렬
}