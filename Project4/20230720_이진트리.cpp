/*
Q1. 학생관리하는 구조체를 생성하고 번호, 이름을 멤버로 포함 / 구조체 리스트 만들고

   1. 입력
      > 번호, 이름받아 리스트에 추가
   2. 삭제
      > 번호 입력받아 리스트에서 삭제
   3. 전체 출력
      > 리스트에 있는 모든 학생의 번호, 이름 출력
*/

#include <iostream>
#include <string>
using namespace std;

//노드
typedef struct Student
{
    int number;      // 번호
    string name;     // 이름
    Student* left;   // 노드
    Student* right;   // 노드
};

//리스트
typedef struct StudentList
{
    Student* root;
};

void Insert(StudentList* list);
void Delete(StudentList* list);
void Print(StudentList* list);

static int studentNumber = 0;

int main()
{
    StudentList* list = new StudentList;
    list->root = NULL;

    int number = 1;

    while (number != 0)
    {
        cout << "1. 입력  2. 삭제  3. 전체 출력  (0. 종료)" << endl;
        cin >> number;
        switch (number)
        {
        case 1:
            Insert(list);
            break;
        case 2:
            Delete(list);
            break;
        case 3:
            Print(list);
            break;
        default:
            break;
        }
    }

    return 0;
}

void Insert(StudentList* list)
{
    Student* stu = new Student;

    studentNumber++;

    // 새 노드 입력
    cout << endl;
    cout << "번호와 이름을 입력해주세요." << endl;
  
    cout << "번호 : ";
    cin >> stu->number;
    cout << "이름 : ";
    cin >> stu->name;

    // root 노드
    if (studentNumber == 1)
    {
        // 바로 입력
        list->root = stu;
        stu->left = NULL;
        stu->right = NULL;
    }
    // 중복되는 번호가 없게끔 입력받음
    else
    {
        Student* numberCheck = list->root;

        // 탐색
        while (1)
        {
            if (stu->number > numberCheck->number)
            {
                if (numberCheck->right == NULL) break;
                numberCheck = numberCheck->right;
            }
            else if (stu->number < numberCheck->number)
            {
                if (numberCheck->left == NULL) break;
                numberCheck = numberCheck->left;
            }
            else
            {
                cout << "이미 번호가 있습니다. 다시 입력해주세요 : ";
                cin >> stu->number;
                Student* numberCheck = list->root;
            }
        }

        Student* temp = list->root;

        // 탐색
        while (1)
        {
            if (stu->number > temp->number)
            {
                if (temp->right == NULL) break;
                temp = temp->right;
            }
            else
            {
                if (temp->left == NULL) break;
                temp = temp->left;
            }
        }
        // right 자식
        if (stu->number > temp->number)
        {
            temp->right = stu;
            stu->left = NULL;
            stu->right = NULL;
        }
        // left 자식
        else
        {
            temp->left = stu;
            stu->left = NULL;
            stu->right = NULL;
        }
    }
}

void Delete(StudentList* list)
{

}

void Print(StudentList* list)
{
    Student* temp = list->root;
    if (temp == NULL)
        cout << "정보가 존재하지 않습니다." << endl;
    else
    {
        // 제일 왼쪽 노드로 이동
        while (temp != NULL)
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
                continue;
            }
        }
        // 부모노드로 이동?????????
        while (temp != NULL)
        {
            cout << "======================" << endl;
            cout << "번호: " << temp->number << endl;
            cout << "이름: " << temp->name << endl;
            cout << "======================" << endl;
            temp = temp->left;
        }
    }
}