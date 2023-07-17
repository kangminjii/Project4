#include <iostream>
using namespace std;

const int SIZE = 8;
int* arr2;
int arr[SIZE] = { 6,5,3,1,8,7,2,4 }; // ������ �迭

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

    int i = left;         // arr2 ������ �ε���
    int tempL = left;   // �պκ� ������ �ε���
    mid = mid + 1;      // �޺κ� ������ �ε���

    // �¿�� ������ �迭�� ù��° ���ҳ��� ��
    while (tempL <= tempMid && mid <= right)
    {
        if (arr[tempL] > arr[mid])
            arr2[i++] = arr[mid++];
        else
            arr2[i++] = arr[tempL++];
    }

    // �޺κ��� ������ ���� ������ ��
    if (mid > right)
    {
        while (i <= right)
            arr2[i++] = arr[tempL++];
    }
    else // �պκ��� ������ ���� ������ ��
    {
        while (i <= right)
            arr2[i++] = arr[mid++];
    }

    // ������ arr2�� ���� �迭 arr�� �ٽ� ����
    for (int j = left; j <= right; j++)
        arr[j] = arr2[j];
}

void mergeSort(int left, int right)
{ // divide
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(left, mid);           //�迭 �պκ� ����
        mergeSort(mid + 1, right);  // �迭 �޺κ� ����

        merge(left, right);      // �迭 �պκ� �޺κ� ����
    }
}