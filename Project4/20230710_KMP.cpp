#include <iostream>
#include <string>
using namespace std;

void KMP_Search(string question, string pattern);
int main()
{
    string question = "ABABABABBABABABABC";
    string pattern = "ABABABAC";

    KMP_Search(question, pattern);
    return 0;
}

void KMP_Search(string question, string pattern)
{
    // pi �迭 �����
    int* pi = new int[pattern.size()] { 0 }; // pi �迭 0���� �ʱ�ȭ

    string leftString, rightString;
    int length;

    for (int i = 0; i < pattern.size(); i++)
    {
        length = 0;
        leftString = "", rightString = "";

        length = (i + 1) / 2; // �߰�����

        for (int j = 0; j < length; j++)
        {
            leftString = leftString + pattern[j]; // ���λ�
            rightString = rightString + pattern[i - j]; // ���̻�
        }

        if (leftString.compare(rightString) == 0) // ������ 0 ��ȯ
        {
            pi[i] = leftString.size();
        }


    }



    delete[] pi;
}