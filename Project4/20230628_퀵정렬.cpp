/*
������ �˰����� �����϶�.
*/

#include <iostream>

const int SIZE = 9;
using namespace std;

void swap(int* a, int* b);
void QuickSort(int arr[], int pl, int pivot, int pr);

int main()
{
    // ������
    int arr[SIZE] = { 5, 7, 1, 4, 6, 2, 3, 9, 8 };
    cout << "���� �� : " << endl;
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

    QuickSort(arr, 0, SIZE / 2, SIZE - 1);

    // ������
    cout << "���� �� : " << endl;
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
    // ó�� �ε��� �� ����
    int left = pl;
    int right = pr;

    while (1)
    {
        //  pl�� pr �����̱�
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
        // ��������
        if (pr <= pl)      break;
    }

    if (left < pr) QuickSort(arr, left, (left + pr) / 2, pr);         // pr�� 0�� �ɶ����� ����
    if (pl < right) QuickSort(arr, pl, (pl + right) / 2, right);  // pl�� NUM-1�� �ɶ����� ����
}