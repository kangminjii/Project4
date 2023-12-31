#include <iostream>
#include <string>
using namespace std;

//노드
typedef struct Student
{
    int number;          // 번호
    string name;     // 이름
    Student* next;  // 노드
    int nextNumber;
};

//리스트
typedef struct StudentList
{
    Student* head;
};

void Insert(StudentList* list);
void Delete(StudentList* list);
void Print(StudentList* list);
static int indexCount = 0;
const int SIZE = 10;
int main()
{
    StudentList* list = new StudentList;
    list->head = NULL;

    int number = 1;

    int nextNumber[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        nextNumber[i] = i;
    }

    while (number != 0)
    {
        cout << "1. 입력  2. 삭제  3. 전체 출력  (0. 종료)" << endl;
        cin >> number;
        switch (number)
        {
        case 1:
            if (indexCount >= SIZE)
            {
                cout << "지정된 크기를 넘어서 입력이 불가능합니다." << endl;
                break;
            }
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
    {
        list->head = stu;  // 바로 입력
        stu->nextNumber = -1;
    }
    else
    {
        //  탐색후 입력
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->nextNumber = indexCount;
        stu->nextNumber = -1;
        temp->next = stu;
    }

    indexCount++;
}

// 삭제 구현 X
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