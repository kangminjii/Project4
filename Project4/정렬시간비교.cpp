#include <iostream>
#include "StopWatch.h"
using namespace std;

const int SIZE = 9;
static int exchangeNumber = 0;
static int compareNumber = 0;

int* arr2;
int arr[SIZE] = {6,9,1,4,5,2,3,7,8};

void swap(int* a, int* b);
void BubbleSort3(int* arr);
void SelectionSort2(int* arr);
void shellSort(int* arr);
void QuickSort(int arr[], int pl, int pivot, int pr);
void merge(int left, int right);
void mergeSort(int left, int right);
void HeapSort(int* arr);

int main()
{
    StopWatch s;

    s.start();
    for (int z = 0; z < 1000000; z++)
    {
        int arr[SIZE] = { 6,9,1,4,5,2,3,7,8 }; // ������ �迭
        BubbleSort3(arr);
    }
    s.stop();

    cout << "1. Bubble Sort" << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ, �� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    s.start();
    for (int z = 0; z < 1000000; z++)
    {
        int arr[SIZE] = { 6,9,1,4,5,2,3,7,8 };
        SelectionSort2(arr);
    }
    s.stop();
    cout << "2. Selection Sort" << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ, �� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    s.start();
    for (int z = 0; z < 1000000; z++)
    {
        int arr[SIZE] = { 6,9,1,4,5,2,3,7,8 };
        shellSort(arr);
    }
    s.stop();
    cout << "3. Shell Sort" << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ, �� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    s.start();
    for (int z = 0; z < 1000000; z++)
    {
        int arr[SIZE] = { 6,9,1,4,5,2,3,7,8 };
        compareNumber = 0;
        exchangeNumber = 0;
        QuickSort(arr, 0, SIZE / 2, SIZE - 1);
    }
    s.stop();
    cout << "4. Quick Sort" << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ, �� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    s.start();
    for (int z = 0; z < 1000000; z++)
    {
        int arr[SIZE] = { 6,9,1,4,5,2,3,7,8 };
        compareNumber = 0;
        exchangeNumber = 0;
        arr2 = new int[SIZE];

        mergeSort(0, SIZE - 1);
    }
    s.stop();
    cout << "5. Merge Sort" << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ, �� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    s.start();
    for (int z = 0; z < 1000000; z++)
    {
        int arr[SIZE] = { 6,9,1,4,5,2,3,7,8 };
        HeapSort(arr);
    }
    s.stop();
    cout << "6. Heap Sort" << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ, �� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort3(int* arr)
{
    int count = 0;
    int temp = 0;
    exchangeNumber = 0;
    compareNumber = 0;
    int location = 0;
    int symbol = 0;

    while (temp < SIZE - 1)
    {
        int last = SIZE - 1; // ������ �ε��� ��

        for (int j = SIZE - 1; j > temp; j--)
        {
            if (arr[j] < arr[j - 1])  // ���� ����
            {
                last = j;
                symbol = 1;
                swap(arr[j], arr[j - 1]);
                exchangeNumber++;
                compareNumber++;
            }
            else
            {
                symbol = -1;
                compareNumber++;
            }
        }
        temp = last;

    }
}

void SelectionSort2(int* arr)
{
    compareNumber = 0;
    exchangeNumber = 0;
    for (int i = 0; i < SIZE; i++)
    {
        // ����
        int min = arr[i];
        int temp2 = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            compareNumber++;
            if (arr[j] < min)
            {
                min = arr[j];
                temp2 = j;
                swap(arr[i], arr[j]);
                exchangeNumber++;
            }
        }
    }
}

void shellSort(int* arr)
{
    int temp[3] = { 4, 2, 1 }; // 4-����, 2-����, 1-����
    compareNumber = 0;
    exchangeNumber = 0;

    for (int i = 0; i < 3; i++)
    {
        int count = 0, j = 0;

        // ����
        while (SIZE != j + temp[i])
        {
            if (arr[j] > arr[j + temp[i]])
            {
                swap(arr[j], arr[j + temp[i]]);
                exchangeNumber++;
            }
            compareNumber++;
            j++;
        }

        // �ٽ� �����ϴ� ������ ���ư�
        for (int k = 0; k < SIZE - temp[i]; k++)
        {
            compareNumber++;
            if (arr[k] > arr[k + temp[i]])
            {
                i--;
                count = 1;
                break;
            }
        }
    }
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
        {
            compareNumber++;
            pl++;
        }
        while (arr[pivot] < arr[pr])
        {
            compareNumber++;
            pr--;
        }
        //  swap
        if (pl <= pr)
        {
            compareNumber++;
            exchangeNumber++;
            swap(arr[pl], arr[pr]);
            pl++;
            pr--;
        }
        // ��������
        if (pr <= pl)
        {
            compareNumber++;
            break;
        }
    }

    if (left < pr) QuickSort(arr, left, (left + pr) / 2, pr);         // pr�� 0�� �ɶ����� ����
    if (pl < right) QuickSort(arr, pl, (pl + right) / 2, right);  // pl�� NUM-1�� �ɶ����� ����
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
        exchangeNumber++;
        compareNumber++;
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

void maxNumber(int* top, int* left, int* right)
{
    compareNumber++;
    if (*top < *left)
    {
        if (*left < *right) // top < left < right
        {
            swap(top, right);
            exchangeNumber++;
        }
        else // top, right < left
        {
            swap(top, left);
            exchangeNumber++;
        }
    }
    else
    {
        if (*top < *right) // left <= top < right
        {
            swap(top, right);
            exchangeNumber++;
        }
    }
}

void HeapSort(int* arr)
{
    exchangeNumber = 0;
    compareNumber = 0;
    int j = 0;
    int temp = SIZE;

    // ������ �����
    for (int k = 0; k <= SIZE / 2 - 1; k++)
    {
        for (int i = 0; i <= (temp / 2) - 1; i++)
        {
            if (temp > i * 2 + 2)
                maxNumber(&arr[i], &arr[i * 2 + 1], &arr[i * 2 + 2]);
            else
            {
                if (arr[i] < arr[i * 2 + 1])
                    swap(arr[i], arr[i * 2 + 1]);
                exchangeNumber++;
            }
        }
    }

    while (j != SIZE)
    {
        for (int i = 0; i <= (temp / 2) - 1; i++)
        {
            if (temp > i * 2 + 2)
                maxNumber(&arr[i], &arr[i * 2 + 1], &arr[i * 2 + 2]);
            else
            {
                if (arr[i] < arr[i * 2 + 1])
                    swap(arr[i], arr[i * 2 + 1]);
                exchangeNumber++;
            }
        }

        swap(arr[0], arr[SIZE - 1 - j]);
        exchangeNumber++;
        j++;
        temp -= 1;
    }
}