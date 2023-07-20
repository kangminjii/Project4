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
    int number;      // ��ȣ
    string name;     // �̸�
    Student* left;   // ���
    Student* right;   // ���
};

//����Ʈ
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

void Insert(StudentList* list)
{
    Student* stu = new Student;

    studentNumber++;

    // �� ��� �Է�
    cout << endl;
    cout << "��ȣ�� �̸��� �Է����ּ���." << endl;
  
    cout << "��ȣ : ";
    cin >> stu->number;
    cout << "�̸� : ";
    cin >> stu->name;

    // root ���
    if (studentNumber == 1)
    {
        // �ٷ� �Է�
        list->root = stu;
        stu->left = NULL;
        stu->right = NULL;
    }
    // �ߺ��Ǵ� ��ȣ�� ���Բ� �Է¹���
    else
    {
        Student* numberCheck = list->root;

        // Ž��
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
                cout << "�̹� ��ȣ�� �ֽ��ϴ�. �ٽ� �Է����ּ��� : ";
                cin >> stu->number;
                Student* numberCheck = list->root;
            }
        }

        Student* temp = list->root;

        // Ž��
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
        // right �ڽ�
        if (stu->number > temp->number)
        {
            temp->right = stu;
            stu->left = NULL;
            stu->right = NULL;
        }
        // left �ڽ�
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
        cout << "������ �������� �ʽ��ϴ�." << endl;
    else
    {
        // ���� ���� ���� �̵�
        while (temp != NULL)
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
                continue;
            }
        }
        // �θ���� �̵�?????????
        while (temp != NULL)
        {
            cout << "======================" << endl;
            cout << "��ȣ: " << temp->number << endl;
            cout << "�̸�: " << temp->name << endl;
            cout << "======================" << endl;
            temp = temp->left;
        }
    }
}