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
    // pi 배열 만들기
    int* pi = new int[pattern.size()] { 0 }; // pi 배열 0으로 초기화

    string leftString, rightString;
    int length;

    for (int i = 0; i < pattern.size(); i++)
    {
        length = 0;
        leftString = "", rightString = "";

        length = (i + 1) / 2; // 중간지점

        for (int j = 0; j < length; j++)
        {
            leftString = leftString + pattern[j]; // 접두사
            rightString = rightString + pattern[i - j]; // 접미사
        }

        if (leftString.compare(rightString) == 0) // 같으면 0 반환
        {
            pi[i] = leftString.size();
        }


    }



    delete[] pi;
}