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
    // pi 배열 만들기
    int* pi = new int[pattern.size()] { 0 }; // pi 배열 0으로 초기화

    for (int i = 1; i < pattern.size(); i++)
    {
        for (int j = 0; j < pattern.size(); j++) // 1칸 옮긴뒤 확인
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