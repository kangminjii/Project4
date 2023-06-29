/*
Q3. �����Ʈ�� �����϶�.
   ���� 1, 2, 3 ������ ���� ���α׷��� �ۼ��ϰ� ������ ������ ���϶�.
   p.219
*/

#include <iostream>
#include "StopWatch.h"
using namespace std;

const int SIZE = 7;
void swap(int* a, int* b);
void print(int*, int, int, int);

int main()
{
    StopWatch s;
    int count, temp;
    int exchangeNumber, compareNumber;

    int location, symbol;
    // ���� 1.
    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int sort1[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
        exchangeNumber = 0, compareNumber = 0;
        
        location = 0, symbol = 0;
       
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE - 1; j > i; j--)
            {
                if (sort1[j] < sort1[j - 1])  // ���� ����
                {
                    location = j - 1;
                    symbol = 1;
                    //print(sort1, SIZE, location, symbol);
                    swap(sort1[j], sort1[j - 1]);
                    exchangeNumber++;
                    compareNumber++;
                }
                else
                {
                    location = j - 1;
                    symbol = -1;
                    //print(sort1, SIZE, location, symbol);
                    compareNumber++;
                }
            }
            //if (i != SIZE - 1)
                //print(sort1, SIZE, 0, 0); // �������� ���
            //cout << endl;
        }
    }
    s.stop();

    cout << "���� ���� ���� 1 : " << endl;
    //cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
    //cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl << endl;
    cout << s.getElapsedTime() << "ms ���" << endl;

    // ���� 2.

  //  s.start();
   // for (int z = 0; z < 10000000; z++)
   // {
        int sort2[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
        count = 0;
        temp = 0;
        exchangeNumber = 0, compareNumber = 0;
        location = 0, symbol = 0;


        for (int i = 0; i < SIZE ; i++)
        {
            count = 0;
            for (int j = SIZE - 1; j > i; j--)
            {
                if (sort2[j] < sort2[j - 1])  // ���� ����
                {
                    count++;
                    location = j - 1;
                    symbol = 1;
                    print(sort2, SIZE, location, symbol);
                    swap(sort2[j], sort2[j - 1]);
                    exchangeNumber++;
                    compareNumber++;
                }
                else
                {
                    location = j - 1;
                    symbol = -1;
                    print(sort2, SIZE, location, symbol);
                    compareNumber++;
                }
            }
            if (count == 0)  break;
            if (i != SIZE - 1)
                print(sort2, SIZE, 0, 0); // �������� ���
             cout << endl;
        }
   // }
   // s.stop();

    cout << "���� ���� ����2 : " << endl;
    cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
    cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl << endl;
   // cout << s.getElapsedTime() << "ms ���" << endl;

    // ���� 3.

    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int sort3[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
        count = 0;
        temp = 0;
        exchangeNumber = 0, compareNumber = 0;
        location = 0;

        while (temp < SIZE - 1)
        {
            int last = SIZE - 1; // ������ �ε��� ��

            for (int j = SIZE - 1; j > temp; j--)
            {
                if (sort3[j] < sort3[j - 1])  // ���� ����
                {
                    last = j;
                    symbol = 1;
                    //print(sort3, SIZE, j-1, symbol);
                    swap(sort3[j], sort3[j - 1]);
                    exchangeNumber++;
                    compareNumber++;
                }
                else
                {
                    symbol = -1;
                    //print(sort3, SIZE, j - 1, symbol);
                    compareNumber++;
                }
            }
            temp = last;

            //if (temp != SIZE - 1)
                //print(sort3, SIZE, 0, 0); // �������� ���
            //cout << endl;
        }
    }
    s.stop();

    cout << "���� ���� ����3 : " << endl;
    //cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
    //cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl << endl;
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