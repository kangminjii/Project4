///*
//Q3. ���� ����
//	[���� ǥ��� �����]
//	1. ������ �켱������ ( ) < + - < * /
//	2. ���� ǥ������� �ѱ��ھ� �о���δ�
//	3. �о���� ���ڰ� ������ �̸�
//		- ���� ��ȣ �̸� �׳� ���ÿ� �߰� ( Operator Stack )
//		- ������ ��ȣ �̸� ���ÿ��� ���� ��ȣ�� ���������� �ϳ��� ���� ť�� �Ű��ش�.
//			���� ��ȣ�� ������ �Ѵ� ������.
//		- ������ ��Ģ ������ �� �����ڰ� ���ÿ��� ���� �����ں��� 
//			�켱������ ���ų� ���� ���ȿ��� ��� ť�� �Ű��ش�.
//			�׸��� �ڽ��� ���ÿ� �߰��Ѵ�.
//	4. �о���� ���ڰ� �ǿ����� �̸� ť�� �ִ´�. ( PostFix Queue )
//
//	2~4�� ������ �ݺ��ؼ� ���� ǥ����� �����. ( PostFix Queue )
//	
//	[��� ����]
//	5. ť���� �����͸� �о� �������� �ű��. ( Operand Stack )
//		- ť���� ���� �ϳ��� �д´�.
//		- �ǿ����� �̸� ���ÿ� ����
//		- ������ �̸� ���ÿ��� ���� �ΰ� ������ �����ڿ� ���� ������ �ϰ�  
//			�� ����� �ٽ� ���ÿ� ����
//
//	ť�� ���� ���� ������ 5�� ������ �ݺ��ؼ� ���� ��갪�� ���Ѵ�.
//*/
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include "20230612_stackCalculate.h"
//
//using namespace std;
//
//int main()
//{
//	char ch[100]; // ��ȣ
//	string str = ""; // ����
//	char temp = ' ';
//	char x;
//
//	// ���� ǥ��� �����
//	ifstream file("calc.txt");
//	if (!file.is_open())
//	{
//		cout << "������ �� �� �����ϴ�." << endl;
//		return 1;
//	}
//
//	stackCalculate Operator_Stack, Operator_Queue;
//
//	if (Operator_Stack.InitializeStack(100) == "0")
//	{
//		puts("���� ������ �����߽��ϴ�.");
//		return 1;
//	}
//	if (Operator_Queue.InitializeQueue(100) == "0")
//	{
//		puts("ť ������ �����߽��ϴ�.");
//		return 1;
//	}
//	
//	file.getline(ch, strlen(ch) + 1);
//	ch[strlen(ch)] = '\0';
//
//
//	int i = 0;
//	while (ch[i] != '\0')
//	{
//		if (ch[i] == '(')
//		{
//			Operator_Stack.Push(ch[i]);
//		}
//		else if (ch[i] == ')')
//		{
//			temp = ' ';
//			while (temp != '(')
//			{
//				Operator_Stack.Pop(&temp);
//				if (temp == '(')	break;
//				else				Operator_Queue.Enque(temp);
//			}
//		}
//		else if (ch[i] == '+' || ch[i] == '-')
//		{
//			Operator_Stack.Peek(&temp);
//			if (temp == '*' || temp == '/')
//			{
//				Operator_Stack.Pop(&temp);
//				Operator_Queue.Enque(temp);
//				Operator_Stack.Push(ch[i]);
//			}
//			else // ( �Ǵ� ) �� ��
//			{
//				Operator_Stack.Push(ch[i]);
//			}
//		}
//		else if (ch[i] == '*' || ch[i] == '/')
//		{
//			Operator_Stack.Push(ch[i]);
//		}
//		else // �����϶�
//		{
//			if (48 <= ch[i - 1])
//			{
//				str += ch[i];
//				Operator_Queue.Peek(&temp);
//				if (48 <= temp)
//				{
//					Operator_Queue.Deque(&temp);
//					Operator_Queue.Enque(ch[i]);
//				}
//			}
//			else
//			{
//				str += ch[i];
//				Operator_Queue.Enque(ch[i]);
//			}
//			cout << "�����϶� : " << endl;
//			Operator_Queue.PrintQueue();
//		}
//
//		i++;
//	}
//
//	while (!Operator_Stack.IsEmptyStack())
//	{
//		Operator_Stack.Pop(&temp);
//		Operator_Queue.Enque(temp);
//	}
//
//	cout << "Final Stack : " << endl;
//	Operator_Stack.PrintStack();
//	cout << endl;
//	cout << "Final Queue : " << endl;
//	Operator_Queue.PrintQueue();
//	cout << endl;
//
//	// ��� ����
//
//
//	////5. ť���� �����͸� �о� �������� �ű��. ( Operand Stack )
//	//-ť���� ���� �ϳ��� �д´�.
//	//	- �ǿ����� �̸� ���ÿ� ����
//	//	- ������ �̸� ���ÿ��� ���� �ΰ� ������ �����ڿ� ���� ������ �ϰ�
//	//	�� ����� �ٽ� ���ÿ� ����
//
//	//	ť�� ���� ���� ������ 5�� ������ �ݺ��ؼ� ���� ��갪�� ���Ѵ�.
//
//	while (!Operator_Queue.IsEmptyQueue())
//	{
//		Operator_Queue.Deque(&temp);
//		if (isdigit(temp))
//		{
//			Operator_Stack.Push(temp);
//		}
//		else
//		{
//			char a, b;
//			int result;
//			Operator_Stack.Pop(&a);
//			Operator_Stack.Pop(&b);
//
//			switch (temp)
//			{
//			case '+':
//				result = a + b;
//				//cout << "result = " << result << endl;
//				Operator_Stack.Push(char(result));
//				break;
//			case '-':
//				result = a - b;
//				Operator_Stack.Push(result);
//				break;
//			case '*':
//				result = a * b;
//				Operator_Stack.Push(result);
//				break;
//			case '/':
//				result = a / b;
//				Operator_Stack.Push(result);
//				break;
//			}
//		}
//	}
//
//	//cout << "���� ��갪 : " << Operator_Stack.Peek(&temp) << endl;
//
//
//
//
//	return 0;
//}