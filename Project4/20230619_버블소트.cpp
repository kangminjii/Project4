/*
Q3. 버블소트를 구현하라.
   버전 1, 2, 3 각각에 대해 프로그램을 작성하고 각각의 성능을 비교하라.
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
    // 버젼 1.
    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int sort1[SIZE] = { 1,3,9,4,7,8,6 }; // 정렬할 배열
        exchangeNumber = 0, compareNumber = 0;
        
        location = 0, symbol = 0;
       
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE - 1; j > i; j--)
            {
                if (sort1[j] < sort1[j - 1])  // 정렬 시행
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
                //print(sort1, SIZE, 0, 0); // 마지막행 출력
            //cout << endl;
        }
    }
    s.stop();

    cout << "버블 정렬 버전 1 : " << endl;
    //cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
    //cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl << endl;
    cout << s.getElapsedTime() << "ms 경과" << endl;

    // 버전 2.

  //  s.start();
   // for (int z = 0; z < 10000000; z++)
   // {
        int sort2[SIZE] = { 1,3,9,4,7,8,6 }; // 정렬할 배열
        count = 0;
        temp = 0;
        exchangeNumber = 0, compareNumber = 0;
        location = 0, symbol = 0;


        for (int i = 0; i < SIZE ; i++)
        {
            count = 0;
            for (int j = SIZE - 1; j > i; j--)
            {
                if (sort2[j] < sort2[j - 1])  // 정렬 시행
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
                print(sort2, SIZE, 0, 0); // 마지막행 출력
             cout << endl;
        }
   // }
   // s.stop();

    cout << "버블 정렬 버전2 : " << endl;
    cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
    cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl << endl;
   // cout << s.getElapsedTime() << "ms 경과" << endl;

    // 버전 3.

    s.start();
    for (int z = 0; z < 10000000; z++)
    {
        int sort3[SIZE] = { 1,3,9,4,7,8,6 }; // 정렬할 배열
        count = 0;
        temp = 0;
        exchangeNumber = 0, compareNumber = 0;
        location = 0;

        while (temp < SIZE - 1)
        {
            int last = SIZE - 1; // 마지막 인덱스 값

            for (int j = SIZE - 1; j > temp; j--)
            {
                if (sort3[j] < sort3[j - 1])  // 정렬 시행
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
                //print(sort3, SIZE, 0, 0); // 마지막행 출력
            //cout << endl;
        }
    }
    s.stop();

    cout << "버블 정렬 버전3 : " << endl;
    //cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
    //cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl << endl;
    cout << s.getElapsedTime() << "ms 경과" << endl;

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