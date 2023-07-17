#include <iostream>
using namespace std;

const int SIZE = 8;
int* arr2;
int arr[SIZE] = { 6,5,3,1,8,7,2,4 }; // 정렬할 배열

void merge(int left, int right);
void mergeSort(int left, int right);

int main()
{
    arr2 = new int[SIZE];

    cout << "BEFORE : ";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(0, SIZE - 1);

    cout << "AFTER : ";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void merge(int left, int right)
{
    int mid = (left + right) / 2;
    int tempMid = mid;

    int i = left;         // arr2 증가용 인덱스
    int tempL = left;   // 앞부분 증가용 인덱스
    mid = mid + 1;      // 뒷부분 증가용 인덱스

    // 좌우로 나눠진 배열의 첫번째 원소끼리 비교
    while (tempL <= tempMid && mid <= right)
    {
        if (arr[tempL] > arr[mid])
            arr2[i++] = arr[mid++];
        else
            arr2[i++] = arr[tempL++];
    }

    // 뒷부분의 병합이 먼저 끝났을 때
    if (mid > right)
    {
        while (i <= right)
            arr2[i++] = arr[tempL++];
    }
    else // 앞부분의 병합이 먼저 끝났을 때
    {
        while (i <= right)
            arr2[i++] = arr[mid++];
    }

    // 정렬한 arr2를 실제 배열 arr에 다시 넣음
    for (int j = left; j <= right; j++)
        arr[j] = arr2[j];
}

void mergeSort(int left, int right)
{ // divide
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(left, mid);           //배열 앞부분 분할
        mergeSort(mid + 1, right);  // 배열 뒷부분 분할

        merge(left, right);      // 배열 앞부분 뒷부분 정렬
    }
}