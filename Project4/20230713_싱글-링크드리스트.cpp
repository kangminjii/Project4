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
    int number; // 번호
    string name;     // 이름
    Student* next;   // 노드
};

//리스트
typedef struct StudentList
{
    Student* head;
};

void Initialize(StudentList* list);
void Insert(StudentList* list);
void Delete(StudentList* list);
void Print(StudentList* list);

int main()
{
    StudentList* list = new StudentList;
    Initialize(list);

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

// 리스트 초기화
void Initialize(StudentList* list)
{
    list->head = NULL;
}

// 입력
void Insert(StudentList* list)
{
    Student* stu = new Student;

    // 새 노드 입력
    cout << endl;
    cout << "번호와 이름을 입력해주세요." << endl;
    cout << "번호 : ";
    cin >> stu->number;
    cout << "이름 : ";
    cin >> stu->name;
    stu->next = NULL;

    Student* temp = list->head;

    // list의 head가 비어있을 때
    if (list->head == NULL)
        list->head = stu;  // 바로 입력
    else
    {
        //  탐색후
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = stu; // 입력
    }
}

// 삭제
void Delete(StudentList* list)
{
    int eraseNumber = 0;
    cout << endl;
    cout << "삭제하고싶은 번호를 입력해주세요." << endl;
    cout << "번호 : ";
    cin >> eraseNumber;

    if (list->head == NULL)
    {
        cout << "삭제할 노드가 존재하지 않습니다." << endl;
        return;
    }

    // 삭제 할 노드 탐색
    Student* temp = list->head;

    // 삭제할 노드가 head일때
    if (temp->number == eraseNumber)
    {
        // 해당 리스트 삭제
        Student* afterErase = temp->next;
        delete temp;
        list->head = afterErase;
    }
    // 삭제할 노드가 head가 아닐때
    else
    {
        // 탐색후
        while (temp->next->number != eraseNumber)
        {
            temp = temp->next;
        }
        // 해당 리스트 삭제
        Student* afterErase = temp->next->next;
        delete temp->next;
        temp->next = afterErase;
    }
}

// 전체 출력
void Print(StudentList* list)
{
    Student* temp = list->head;
    if (temp == NULL)
        cout << "정보가 존재하지 않습니다." << endl;
    else
    {
        while (temp != NULL)
        {
            cout << "======================" << endl;
            cout << "번호: " << temp->number << endl;
            cout << "이름: " << temp->name << endl;
            cout << "======================" << endl;
            temp = temp->next;
        }
    }
}