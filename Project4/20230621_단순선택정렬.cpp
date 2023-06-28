/*
p.226 Q7ó�� �ܼ� ���� ���� ������ ǥ���϶�.
���� �ӵ��� ���϶� (����, ���� ���� 1/2)
*/

//�ܼ� ���� ���� �� Ƚ��: (n^2-n)/2

#include "StopWatch.h"
#include <iostream>
using namespace std;

const int SIZE = 7;
void swap(int* a, int* b);
void print(int i, int temp2, int* array);

int main()
{
    // #1
    StopWatch s;

    s.start();
    for (int k = 0; k < 1000000; k++)
    {
        int array[SIZE] = { 6,4,8,3,1,9,7 };
        for (int i = 0; i < SIZE; i++)
        {
            int min = array[i];
            int temp2 = 0;
            int swapIndex = 0;
            for (int j = i + 1; j < SIZE; j++)
            {
                if (array[j] < min)
                {
                    min = array[j];
                    temp2 = j;
                    swapIndex = j;
                }
            }
            //print(i, temp2, array);
            swap(array[i], array[swapIndex]);
        }
    } 
    s.stop();
    cout << "�ܼ��������� 1����� �鸸�� ���� �� : " << s.getElapsedTime() << "ms ���" << endl;

    // #2
   
    s.start();

    for (int k = 0; k < 1000000; k++)
    {
        int array2[SIZE] = { 6,4,8,3,1,9,7 };
        for (int i = 0; i < SIZE; i++)
        {
            // ����
            int min = array2[i];
            int temp2 = 0;
            for (int j = i + 1; j < SIZE; j++)
            {
                if (array2[j] < min)
                {
                    min = array2[j];
                    temp2 = j;

                    //print(i, temp2, array2);
                    swap(array2[i], array2[j]);
                }
            }
        }
    } 
    s.stop();
    cout << "�ܼ��������� 2����� �鸸�� ���� �� : " << s.getElapsedTime() << "ms ���" << endl;

    return 0;
}

void swap(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void print(int i, int temp2, int* array)
{
    int temp = i;
    while (temp > 0)
    {
        cout << "  ";
        temp--;
    }
    if (i != SIZE - 1)
        cout << "*";

    while ((temp2 - i) > 0)
    {
        if(temp2-i == 1)
            cout << " ";
        else
            cout << "  ";
        temp2--;
    }
    cout << "+" << endl;

    // �迭���
    for (int k = 0; k < SIZE; k++)
        cout << array[k] << ' ';

    cout << endl;
}