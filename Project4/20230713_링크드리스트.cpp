/*
Q1. �л������ϴ� ����ü�� �����ϰ� ��ȣ, �̸��� ����� ���� / ����ü ����Ʈ �����

   1. �Է�
      > ��ȣ, �̸��޾� ����Ʈ�� �߰�
   2. ����
      > ��ȣ �Է¹޾� ����Ʈ���� ����
   3. ��ü ���
      > ����Ʈ�� �ִ� ��� �л��� ��ȣ, �̸� ���
*/

#include <iostream>
#include <string>
using namespace std;


//���
typedef struct Student
{
    int number; // ��ȣ
    string name;     // �̸�
    Student* next;   // ���
};

//����Ʈ
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
        cout << "1. �Է�  2. ����  3. ��ü ���  (0. ����)" << endl;
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

// ����Ʈ �ʱ�ȭ
void Initialize(StudentList* list)
{
    list->head = NULL;
}

// �Է�
void Insert(StudentList* list)
{
    Student* stu = new Student;

    // �� ��� �Է�
    cout << endl;
    cout << "��ȣ�� �̸��� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> stu->number;
    cout << "�̸� : ";
    cin >> stu->name;
    stu->next = NULL;

    Student* temp = list->head;

    // list�� head�� ������� ��
    if (list->head == NULL)
        list->head = stu;  // �ٷ� �Է�
    else
    {
        //  Ž����
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = stu; // �Է�
    }
}

// ����
void Delete(StudentList* list)
{
    int eraseNumber = 0;
    cout << endl;
    cout << "�����ϰ���� ��ȣ�� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> eraseNumber;

    if (list->head == NULL)
    {
        cout << "������ ��尡 �������� �ʽ��ϴ�." << endl;
        return;
    }

    // ���� �� ��� Ž��
    Student* temp = list->head;

    // ������ ��尡 head�϶�
    if (temp->number == eraseNumber)
    {
        // �ش� ����Ʈ ����
        Student* afterErase = temp->next;
        delete temp;
        list->head = afterErase;
    }
    // ������ ��尡 head�� �ƴҶ�
    else
    {
        // Ž����
        while (temp->next->number != eraseNumber)
        {
            temp = temp->next;
        }
        // �ش� ����Ʈ ����
        Student* afterErase = temp->next->next;
        delete temp->next;
        temp->next = afterErase;
    }
}

// ��ü ���
void Print(StudentList* list)
{
    Student* temp = list->head;
    if (temp == NULL)
        cout << "������ �������� �ʽ��ϴ�." << endl;
    else
    {
        while (temp != NULL)
        {
            cout << "======================" << endl;
            cout << "��ȣ: " << temp->number << endl;
            cout << "�̸�: " << temp->name << endl;
            cout << "======================" << endl;
            temp = temp->next;
        }
    }
}