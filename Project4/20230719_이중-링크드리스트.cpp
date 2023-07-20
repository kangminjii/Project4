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
    Student* prev;
};

//리스트
typedef struct StudentList
{
    Student* head;
};

void Insert(StudentList* list);
void Delete(StudentList* list);
void PrintForward(StudentList* list);
void PrintBackward(StudentList* list);

static int studentNumber = 0;

int main()
{
    StudentList* list = new StudentList;
    list->head = NULL;

    int number = 1;

    while (number != 0)
    {
        cout << "1. 입력  2. 삭제  3. 전체 출력(순방향) 4. 전체 출력(역방향)  (0. 종료)" << endl;
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
            PrintForward(list);
            break;
        case 4:
            PrintBackward(list);
        default:
            break;
        }
    }

    return 0;
}

void Insert(StudentList* list)
{
    Student* stu = new Student;
    int insertNumber = 0;

    // 새 노드 입력
    cout << endl;
    cout << "번호와 이름을 입력해주세요." << endl;
    cout << "번호 : ";
    cin >> stu->number;
    cout << "이름 : ";
    cin >> stu->name;
    
    Student* temp = list->head;
    studentNumber++;

    // list의 head가 비어있을 때
    if (list->head == NULL)
    {
        // 바로 입력
        list->head = stu;  
        stu->next = NULL;
        stu->prev = NULL;
    }
    // 값이 있을 때 탐색 후 입력
    else
    {
        while (1)
        {
            cout << "추가하고 싶은 위치 : ";
            cin >> insertNumber;

            if (0 < insertNumber && insertNumber <= studentNumber)
                break;
            else
                cout << "원하려는 위치가 존재하지 않습니다. 다시 입력해주세요." << endl;
        }

        // 맨 앞에 추가할 때
        if (insertNumber == 1)
        {
            temp->prev = stu;
            stu->next = temp;
            stu->prev = NULL;
            list->head = stu;
        }
        else
        {
            // head 위치 변경
            for (int i = 1; i < insertNumber; i++)
            {
                if (temp->next == NULL) break;
                temp = temp->next;
            }

            // 맨끝에 추가할 때
            if (studentNumber <= 2 && temp->next == NULL)
            {
                stu->prev = temp;
                stu->next = NULL;
                temp->next = stu;
            }
            // 중간에 추가할 때
            else
            {
                stu->next = temp;
                stu->prev = temp->prev;

                temp->prev->next = stu;
                temp->prev = stu;
            }

            // head 재정의
            //temp = list->head;
            while (temp->prev != NULL)
            {
                if (temp->prev == NULL)  break;
                temp = temp->prev;
            }
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

    if (list->head == NULL)
    {
        cout << "삭제할 노드가 존재하지 않습니다." << endl;
        return;
    }

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
        while (temp->number != eraseNumber)
        {
            temp = temp->next;
        }
        // 해당 리스트 삭제
        Student* afterErase = temp->next;
        Student* beforeErase = temp->prev;
        delete temp;
        if (afterErase == NULL)
            beforeErase->next = NULL;
        else
        {
            beforeErase->next = afterErase;
            afterErase->prev = beforeErase;
        }

        // head 재정의
        beforeErase = list->head;
        while (beforeErase->prev != NULL)
        {
            if (beforeErase->prev == NULL)  break;
            beforeErase = beforeErase->prev;
        }
    }

    studentNumber--;
}

void PrintForward(StudentList* list)
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

void PrintBackward(StudentList* list)
{
    Student* temp = list->head;
    if (temp == NULL)
        cout << "정보가 존재하지 않습니다." << endl;
    else
    {
        // head를 맨끝으로 이동
        while (temp != NULL)
        {
            if (temp->next == NULL)  break;
            temp = temp->next;
            
        }
        // 역순 출력
        while (temp != NULL)
        {
            cout << "======================" << endl;
            cout << "번호: " << temp->number << endl;
            cout << "이름: " << temp->name << endl;
            cout << "======================" << endl;
            temp = temp->prev;
        }
    }
}