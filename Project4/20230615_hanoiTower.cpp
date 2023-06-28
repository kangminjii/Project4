// p.188 알고리즘 하노이탑 문제

#include <iostream>
#include "Stack.h"

using namespace std;

const int n = 4;

void print(Stack* A, Stack* B, Stack* C, int, int);
void move(Stack* A, Stack* B, Stack* C, int, int, int, int);

int main()
{
    Stack A, B, C;

    A.Initialize(n);
    B.Initialize(n);
    C.Initialize(n);

    // A 설정
    for (int i = n; i > 0; i--)
    {
        A.Push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (A.getS(i) == 0)
            cout << "[ ]" << "\t";
        else
            cout << "[" << A.getS(i) << "]" << "\t";
        if (B.getS(i) == 0)
            cout << "[ ]" << "\t";
        else
            cout << "[" << B.getS(i) << "]" << "\t";
        if (C.getS(i) == 0)
            cout << "[ ]" << "\t" << endl;
        else
            cout << "[" << C.getS(i) << "]" << "\t" << endl;
    }

    cout << " A\t B\t C" << endl << endl;

    move(&A, &B, &C, n, 1, 2, 3);

    return 0;
}

void print(Stack* A, Stack* B, Stack* C, int start, int end)
{
    cout << start << "에서 " << end << "로 옮김" << endl;
    int temp;

    switch (start)
    {
    case 1:
        A->Pop(&temp);

        if (end == 2)
            B->Push(temp);
        else // end = 3
            C->Push(temp);
        break;
    case 2:
        B->Pop(&temp);

        if (end == 1)
            A->Push(temp);
        else // end = 3
            C->Push(temp);
        break;
    case 3:
        C->Pop(&temp);

        if (end == 1)
            A->Push(temp);
        else // end = 2
            B->Push(temp);
        break;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (A->getS(i) == 0)
            cout << "[ ]" << "\t";
        else
            cout << "[" << A->getS(i) << "]" << "\t";
        if (B->getS(i) == 0)
            cout << "[ ]" << "\t";
        else
            cout << "[" << B->getS(i) << "]" << "\t";
        if (C->getS(i) == 0)
            cout << "[ ]" << "\t" << endl;
        else
            cout << "[" << C->getS(i) << "]" << "\t" << endl;
    }

    cout << " A\t B\t C" << endl << endl;
}


void move(Stack* A, Stack* B, Stack* C, int n, int start, int mid, int end)
{
    if (n > 1)   move(A, B, C, n - 1, start, end, mid);

    print(A, B, C, start, end);

    if (n > 1)   move(A, B, C, n - 1, mid, start, end);
}