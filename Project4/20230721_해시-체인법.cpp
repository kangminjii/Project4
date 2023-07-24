// p.448
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

void Insert(StudentList* list);
void Delete(StudentList* list);
void Print(StudentList* list);
const int SIZE = 13;

int main()
{
    // 해시 테이블 구성
    StudentList* list = new StudentList[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        list[i].head = NULL;
    }

    int number = 1;

    while (number != 0)
    {
        cout << endl << "1. 입력  2. 삭제  3. 전체 출력  (0. 종료)" << endl;
        cin >> number;
        cout << endl;
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

// 입력
void Insert(StudentList* list)
{
    Student* stu = new Student;

    // 새 노드 입력
    cout << "번호와 이름을 입력해주세요." << endl;
    cout << "번호 : ";
    cin >> stu->number;
    cout << "이름 : ";
    cin >> stu->name;
    stu->next = NULL;

    int hashNum = stu->number % SIZE; // 해시값

    Student* temp = list[hashNum].head;

    // 처음 추가할 때
    if(list[hashNum].head == NULL)
        list[hashNum].head = stu;
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
    cout << "삭제하고싶은 번호를 입력해주세요." << endl;
    cout << "번호 : ";
    cin >> eraseNumber;

    int hashNum = eraseNumber % SIZE;

    if (list[hashNum].head == NULL)
    {
        cout << "삭제할 노드가 존재하지 않습니다." << endl;
        return;
    }

    Student* temp = list[hashNum].head;

    // 삭제할 노드가 head일때
    if (temp->number == eraseNumber)
    {
        // 해당 리스트 삭제
        Student* afterErase = temp->next;
        delete temp;
        list[hashNum].head = afterErase;
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
    for (int i = 0; i < SIZE; i++)
    {
        Student* temp = list[i].head;
        if (temp == NULL)
        {
            cout << i << "." << endl;
            continue;
        }
        else
        {
            cout << i << ".  ";
            while (temp != NULL)
            {
                cout << "  -> " << temp->number << "(" << temp->name << ")";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}