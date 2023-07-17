/*
Q2. �������� �����ϰ� �� Ƚ���� ��ȯ Ƚ���� ���� �˰���� ���Ͽ� ����϶�.
	�ٸ� �˰���� ���� �ӵ��� �� ����϶�.
*/

#include <iostream>
using namespace std;

const int SIZE = 8;

void swap(int* a, int* b);
void shellSort(int* arr);

int main()
{
    int arr[SIZE] = { 8, 1, 4, 2, 7, 6, 3, 5 };

    // before sort
    cout << "���� �� : " << endl;
    for (int k = 0; k < SIZE; k++)
        cout << arr[k] << " ";
    cout << endl << endl;

    shellSort(arr);

    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int* arr)
{
    int temp[3] = { 4, 2, 1 }; // 4-����, 2-����, 1-����
    int exchangeCount = 0, compareCount = 0;

    for (int i = 0; i < 3; i++)
    {
        int count = 0, j = 0;

        // ����
        while (SIZE != j + temp[i])
        {
            if (arr[j] > arr[j + temp[i]])
            {
                swap(arr[j], arr[j + temp[i]]);
                exchangeCount++;
            }
            compareCount++;
            j++;
        }

        // �ٽ� �����ϴ� ������ ���ư�
        for (int k = 0; k < SIZE - temp[i]; k++)
        {
            compareCount++;
            if (arr[k] > arr[k + temp[i]])
            {
                i--;
                count = 1;
                break;
            }
        }

        // ���
        if (count == 0)
        {
            cout << temp[i] << "���� ����" << endl;
            for (int k = 0; k < SIZE; k++)
                cout << arr[k] << " ";
            cout << endl << endl;
        }
    }

    cout << "�� Ƚ�� : " << compareCount << endl;
    cout << "��ȯ Ƚ�� : " << exchangeCount << endl;
}