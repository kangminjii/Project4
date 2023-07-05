/*
Q3. �����Ʈ�� �����϶�.
   ���� 1, 2, 3 ������ ���� ���α׷��� �ۼ��ϰ� ������ ������ ���϶�.
   p.219
*/

#include <iostream>
#include "StopWatch.h"
using namespace std;

const int SIZE = 7;
static int exchangeNumber = 0;
static int compareNumber = 0;

void swap(int* a, int* b);
void print(int*, int, int, int);
void BubbleSort1(int* arr);
void BubbleSort2(int* arr);
void BubbleSort3(int* arr);

int main()
{
    StopWatch s;

    // ���� 1.
    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int arr[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
        BubbleSort1(arr);
    }
    s.stop();

    cout << "���� ���� ���� 1 : " << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
    cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    // ���� 2.

    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int arr[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
        BubbleSort2(arr);
    }
    s.stop();

    cout << "���� ���� ����2 : " << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
    cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    // ���� 3.

    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int arr[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
        BubbleSort3(arr);
    }
    s.stop();

    cout << "���� ���� ����3 : " << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
    cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int* arr, int n, int loc, int pm)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i == loc)
        {
            if (pm > 0)
                cout << "+";
            else if (pm < 0)
                cout << "-";
            else
                cout << " ";
        }
        else
            cout << " ";
    }
    cout << endl;
}

void BubbleSort1(int* arr)
{
    exchangeNumber = 0;
    compareNumber = 0;

    int location = 0;
    int symbol = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = SIZE - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])  // ���� ����
            {
                location = j - 1;
                symbol = 1;
                //print(arr, SIZE, location, symbol);
                swap(arr[j], arr[j - 1]);
                exchangeNumber++;
                compareNumber++;
            }
            else
            {
                location = j - 1;
                symbol = -1;
                //print(arr, SIZE, location, symbol);
                compareNumber++;
            }
        }
        //if (i != SIZE - 1)
            //print(arr, SIZE, 0, 0); // �������� ���
        //cout << endl;
    }
}

void BubbleSort2(int* arr)
{
    int count = 0;
    int temp = 0;
    exchangeNumber = 0;
    compareNumber = 0;
    int location = 0;
    int symbol = 0;

    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = SIZE - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])  // ���� ����
            {
                count++;
                location = j - 1;
                symbol = 1;
                //print(arr, SIZE, location, symbol);
                swap(arr[j], arr[j - 1]);
                exchangeNumber++;
                compareNumber++;
            }
            else
            {
                location = j - 1;
                symbol = -1;
                //print(arr, SIZE, location, symbol);
                compareNumber++;
            }
        }
        if (count == 0)  break;
        //if (i != SIZE - 1)
        //    print(arr, SIZE, 0, 0); // �������� ���
        //cout << endl;
    }
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
                //print(arr, SIZE, j-1, symbol);
                swap(arr[j], arr[j - 1]);
                exchangeNumber++;
                compareNumber++;
            }
            else
            {
                symbol = -1;
                //print(arr, SIZE, j - 1, symbol);
                compareNumber++;
            }
        }
        temp = last;

        //if (temp != SIZE - 1)
            //print(arr, SIZE, 0, 0); // �������� ���
        //cout << endl;
    }
}