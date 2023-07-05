/*
p.226 Q7처럼 단순 선택 정렬 과정을 표시하라.
정렬 속도를 비교하라 (버블, 선택 정렬 1/2)
*/

//단순 선택 정렬 비교 횟수: (n^2-n)/2

#include "StopWatch.h"
#include <iostream>
using namespace std;

const int SIZE = 7;
static int exchangeNumber = 0;
static int compareNumber = 0;

void swap(int* a, int* b);
void print(int i, int temp2, int* array);
void SelectionSort1(int* arr);
void SelectionSort2(int* arr);

int main()
{
    // #1
    StopWatch s;

    s.start();
    for (int k = 0; k < 1000000; k++)
    {
        int arr[SIZE] = { 6,4,8,3,1,9,7 };
        SelectionSort1(arr);
    } 
    s.stop();
    cout << "단순선택정렬 1번" << endl;
    cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
    cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl << endl;
    cout << s.getElapsedTime() << "ms 경과" << endl;

    // #2
   
    s.start();
    for (int k = 0; k < 1000000; k++)
    {
        int arr[SIZE] = { 6,4,8,3,1,9,7 };
        SelectionSort2(arr);
    } 
    s.stop();
    cout << "단순선택정렬 2번" << endl;
    cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
    cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl << endl;
    cout << s.getElapsedTime() << "ms 경과" << endl;

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

    // 배열출력
    for (int k = 0; k < SIZE; k++)
        cout << array[k] << ' ';

    cout << endl;
}

void SelectionSort1(int* arr)
{
    compareNumber = 0;
    exchangeNumber = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int min = arr[i];
        int temp2 = 0;
        int swapIndex = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            compareNumber++;
            if (arr[j] < min)
            {
                min = arr[j];
                temp2 = j;
                swapIndex = j;
            }
        }
        //print(i, temp2, arr);
        swap(arr[i], arr[swapIndex]);
        exchangeNumber++;
    }
}

void SelectionSort2(int* arr)
{
    compareNumber = 0;
    exchangeNumber = 0;
    for (int i = 0; i < SIZE; i++)
    {
        // 정렬
        int min = arr[i];
        int temp2 = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            compareNumber++;
            if (arr[j] < min)
            {
                min = arr[j];
                temp2 = j;
                //print(i, temp2, arr);
                swap(arr[i], arr[j]);
                exchangeNumber++;
            }
        }
    }
}