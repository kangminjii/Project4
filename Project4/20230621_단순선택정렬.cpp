/*
p.226 Q7ó�� �ܼ� ���� ���� ������ ǥ���϶�.
���� �ӵ��� ���϶� (����, ���� ���� 1/2)
*/

//�ܼ� ���� ���� �� Ƚ��: (n^2-n)/2

#include <iostream>
using namespace std;

const int SIZE = 7;
void swap(int* a, int* b);

int main()
{
    // #1
    //int array[SIZE] = { 6,4,8,3,1,9,7 };

    //for (int i = 0; i < SIZE; i++)
    //{
    //   // print
    //   int temp = i;
    //   while (temp > 0)
    //   {
    //      cout << "  ";
    //      temp--;
    //   }
    //   if (i != SIZE - 1)
    //      cout << "*";
    //   // ����
    //   int min = array[i];
    //   int temp2 = 0;
    //   int swapIndex = 0;
    //   for (int j = i + 1; j < SIZE; j++)
    //   {
    //      if (array[j] < min)
    //      {
    //         min = array[j];
    //         temp2 = j;
    //         swapIndex = j;
    //      }
    //   }
    //   // print
    //   while ((temp2 - i) > 0)
    //   {
    //      if(temp2-i == 1)
    //         cout << " ";
    //      else
    //         cout << "  ";
    //      temp2--;
    //   }
    //   cout << "+" << endl;
    //   // �迭���
    //   for (int k = 0; k < SIZE; k++)
    //      cout << array[k] << ' ';

    //   cout << endl;
    //   swap(array[i], array[swapIndex]);
    //}

    // #2
    int array[SIZE] = { 6,4,8,3,1,9,7 };

    for (int i = 0; i < SIZE; i++)
    {
        // ����
        int min = array[i];
        int temp2 = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                temp2 = j;

                // print
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
                    if (temp2 - i == 1)
                        cout << " ";
                    else
                        cout << "  ";

                    temp2--;
                }
                cout << "+" << endl;

                // �迭 ���
                for (int k = 0; k < SIZE; k++)
                    cout << array[k] << ' ';

                cout << endl;

                swap(array[i], array[j]);
            }
        }
    }

    return 0;
}

void swap(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}