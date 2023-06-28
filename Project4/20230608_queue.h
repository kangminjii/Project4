#pragma once

typedef struct
{
	int max; // 큐의 최대 용량
	int num; // 현재 요소 개수
	int front; // 프런트
	int rear;  // 리어
	int* que; // 큐의 맨 앞 요소 포인터
}IntQueue;

int Initialize(IntQueue* q, int max); // 초기화
int Enque(IntQueue* q, int x); // 큐에 데이터를 인큐
int Deque(IntQueue* q, int* x); // 큐에서 데이터를 디큐
int Peek(const IntQueue* q, int* x); // 큐에서 데이터를 피크
void Clear(IntQueue* q); // 모든 데이터 삭제
int Capacity(const IntQueue* q); // 큐의 최대 용량
int Size(const IntQueue* q); // 큐에 저장된 데이터 개수
int IsEmpty(const IntQueue* q); // 큐가 비었는가?
int IsFull(const IntQueue* q); // 큐가 가득찼는가?
int Search(const IntQueue* q, int x); // 큐에서 검색
void Print(const IntQueue* q); // 모든 데이터 출력
void Terminate(IntQueue* q);