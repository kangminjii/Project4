// p.448
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

void Insert(StudentList* list);
void Delete(StudentList* list);
void Print(StudentList* list);
const int SIZE = 13;

int main()
{
    // �ؽ� ���̺� ����
    StudentList* list = new StudentList[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        list[i].head = NULL;
    }

    int number = 1;

    while (number != 0)
    {
        cout << endl << "1. �Է�  2. ����  3. ��ü ���  (0. ����)" << endl;
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

// �Է�
void Insert(StudentList* list)
{
    Student* stu = new Student;

    // �� ��� �Է�
    cout << "��ȣ�� �̸��� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> stu->number;
    cout << "�̸� : ";
    cin >> stu->name;
    stu->next = NULL;

    int hashNum = stu->number % SIZE; // �ؽð�

    Student* temp = list[hashNum].head;

    // ó�� �߰��� ��
    if(list[hashNum].head == NULL)
        list[hashNum].head = stu;
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
    cout << "�����ϰ���� ��ȣ�� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> eraseNumber;

    int hashNum = eraseNumber % SIZE;

    if (list[hashNum].head == NULL)
    {
        cout << "������ ��尡 �������� �ʽ��ϴ�." << endl;
        return;
    }

    Student* temp = list[hashNum].head;

    // ������ ��尡 head�϶�
    if (temp->number == eraseNumber)
    {
        // �ش� ����Ʈ ����
        Student* afterErase = temp->next;
        delete temp;
        list[hashNum].head = afterErase;
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