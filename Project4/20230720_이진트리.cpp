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
void Print(Student* list);

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
        // �߰�
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
    int eraseNumber = 0;
    cout << endl;
    cout << "�����ϰ���� ��ȣ�� �Է����ּ���." << endl;
    cout << "��ȣ : ";
    cin >> eraseNumber;

    if (list->root == NULL)
    {
        cout << "������ ��尡 �������� �ʽ��ϴ�." << endl;
        return;
    }

    Student* temp = list->root;
    Student* parent = list->root;

    // Ž��
    while (temp->number != eraseNumber)
    {
        // ������ Ʈ��
        if (eraseNumber > temp->number)
        {
            if (temp->right == NULL) break;
            parent = temp;
            temp = temp->right;
        }
        // ���� Ʈ��
        else
        {
            if (temp->left == NULL) break;
            parent = temp;
            temp = temp->left;
        }
    }

    // ����
    while (1)
    {
        // �ڽ��� ���� ��
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
        // �ڽ��� �ϳ��� ��(right)
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
        // �ڽ��� �ϳ��� ��(left)
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
        // �ڽ��� ���� ��
        else
        {
            // ���� Ʈ���� ���� ū ���� ���� ��ġ ���� ��ü �� ����
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
        // ���� ��ȸ : ���� �ڽ� -> ��� -> ������ �ڽ�
        if(temp->left != NULL)
            Print(temp->left);
        cout << "======================" << endl;
        cout << "��ȣ: " << temp->number << endl;
        cout << "�̸�: " << temp->name << endl;
        cout << "======================" << endl;
        if(temp->right != NULL)
            Print(temp->right);
        break;
    }
}