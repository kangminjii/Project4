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
void Print(Student* list);

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
            Print(list->root);
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
        // 추가
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
    int eraseNumber = 0;
    cout << endl;
    cout << "삭제하고싶은 번호를 입력해주세요." << endl;
    cout << "번호 : ";
    cin >> eraseNumber;

    if (list->root == NULL)
    {
        cout << "삭제할 노드가 존재하지 않습니다." << endl;
        return;
    }

    Student* temp = list->root;
    Student* parent = list->root;

    // 탐색
    while (temp->number != eraseNumber)
    {
        // 오른쪽 트리
        if (eraseNumber > temp->number)
        {
            if (temp->right == NULL) break;
            parent = temp;
            temp = temp->right;
        }
        // 왼쪽 트리
        else
        {
            if (temp->left == NULL) break;
            parent = temp;
            temp = temp->left;
        }
    }

    // 삭제
    while (1)
    {
        // 자식이 없을 때
        if (temp->left == NULL && temp->right == NULL)
        {
            if (parent->right == temp)
                parent->right = NULL;
            else if (parent->left == temp)
                parent->left = NULL;
            else // parent == temp == root
                list->root = NULL;

            studentNumber--;
            delete temp;
            break;
        }
        // 자식이 하나일 때(right)
        else if (temp->left == NULL)
        {
            Student* tempRight = temp->right;

            if (parent->right == temp)
                parent->right = tempRight;
            else if (parent->left == temp)
                parent->left = tempRight;
            else // parent == temp == root
                list->root = tempRight;

            studentNumber--;
            delete temp;
            break;
        }
        // 자식이 하나일 때(left)
        else if (temp->right == NULL)
        {
            Student* tempLeft = temp->left;

            if (parent->right == temp)
                parent->right = tempLeft;
            else if (parent->left == temp)
                parent->left = tempLeft;
            else // parent == temp == root
                list->root = tempLeft;

            studentNumber--;
            delete temp;
            break;
        }
        // 자식이 둘일 때
        else
        {
            // 왼쪽 트리의 가장 큰 값을 삭제 위치 값과 교체 후 삭제
            Student* search = temp;
            search = search->left;

            while (search->right != NULL)
            {
                parent = search;
                search = search->right;
            }
            temp->number = search->number;

            temp = search;
        }
    }
}

void Print(Student* temp)
{
    while (temp != NULL)
    {
        // 중위 순회 : 왼쪽 자식 -> 노드 -> 오른쪽 자식
        if(temp->left != NULL)
            Print(temp->left);
        cout << "======================" << endl;
        cout << "번호: " << temp->number << endl;
        cout << "이름: " << temp->name << endl;
        cout << "======================" << endl;
        if(temp->right != NULL)
            Print(temp->right);
        break;
    }
}