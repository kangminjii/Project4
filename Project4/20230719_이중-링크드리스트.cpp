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
    Student* prev;
};

//����Ʈ
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
        cout << "1. �Է�  2. ����  3. ��ü ���(������) 4. ��ü ���(������)  (0. ����)" << endl;
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

    // �� ��� �Է�
    cout << endl;
    cout << "��ȣ�� �̸��� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> stu->number;
    cout << "�̸� : ";
    cin >> stu->name;
    
    Student* temp = list->head;
    studentNumber++;

    // list�� head�� ������� ��
    if (list->head == NULL)
    {
        // �ٷ� �Է�
        list->head = stu;  
        stu->next = NULL;
        stu->prev = NULL;
    }
    // ���� ���� �� Ž�� �� �Է�
    else
    {
        while (1)
        {
            cout << "�߰��ϰ� ���� ��ġ : ";
            cin >> insertNumber;

            if (0 < insertNumber && insertNumber <= studentNumber)
                break;
            else
                cout << "���Ϸ��� ��ġ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
        }

        // �� �տ� �߰��� ��
        if (insertNumber == 1)
        {
            temp->prev = stu;
            stu->next = temp;
            stu->prev = NULL;
            list->head = stu;
        }
        else
        {
            // head ��ġ ����
            for (int i = 1; i < insertNumber; i++)
            {
                if (temp->next == NULL) break;
                temp = temp->next;
            }

            // �ǳ��� �߰��� ��
            if (studentNumber <= 2 && temp->next == NULL)
            {
                stu->prev = temp;
                stu->next = NULL;
                temp->next = stu;
            }
            // �߰��� �߰��� ��
            else
            {
                stu->next = temp;
                stu->prev = temp->prev;

                temp->prev->next = stu;
                temp->prev = stu;
            }

            // head ������
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
    cout << "�����ϰ���� ��ȣ�� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> eraseNumber;

    if (list->head == NULL)
    {
        cout << "������ ��尡 �������� �ʽ��ϴ�." << endl;
        return;
    }

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
        while (temp->number != eraseNumber)
        {
            temp = temp->next;
        }
        // �ش� ����Ʈ ����
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

        // head ������
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

void PrintBackward(StudentList* list)
{
    Student* temp = list->head;
    if (temp == NULL)
        cout << "������ �������� �ʽ��ϴ�." << endl;
    else
    {
        // head�� �ǳ����� �̵�
        while (temp != NULL)
        {
            if (temp->next == NULL)  break;
            temp = temp->next;
            
        }
        // ���� ���
        while (temp != NULL)
        {
            cout << "======================" << endl;
            cout << "��ȣ: " << temp->number << endl;
            cout << "�̸�: " << temp->name << endl;
            cout << "======================" << endl;
            temp = temp->prev;
        }
    }
}