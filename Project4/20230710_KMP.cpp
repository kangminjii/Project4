#include <iostream>
#include <string>
using namespace std;

void KMP_Search(string question, string pattern);
int main()
{
    string question = "ABDABCABCABD";
    string pattern = "ABCABD";

    KMP_Search(question, pattern);
    return 0;
}

void KMP_Search(string question, string pattern)
{
    // pi �迭 �����
    int* pi = new int[pattern.size()] { 0 }; // pi �迭 0���� �ʱ�ȭ

    for (int i = 1; i < pattern.size(); i++)
    {
        for (int j = 0; j < pattern.size(); j++) // 1ĭ �ű�� Ȯ��
        {
            if (pattern[i + j] == pattern[j])
            {
                pi[i]++;

            }
            else
                break;
        }
    }

    for (int i = 0; i < pattern.size(); i++)
        cout << pi[i];

    delete[] pi;
}