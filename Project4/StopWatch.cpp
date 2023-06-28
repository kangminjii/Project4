#define _CRT_SECURE_NO_WARNINGS
#include "StopWatch.h"
#include <ctime>
/*
Q1. StopWatch class ����
	������ ������ �����ϴ� Ŭ������ �����϶�.
	- get�Լ��� ���� ������ �ʵ� startTime�� endTime
	- startTime�� ���� �ð����� �ʱ�ȭ�ϴ� �μ� ���� ������
	- startTime�� ���� �ð����� �缳���ϴ� start()�Լ�
	- endTime�� ���� �ð����� �����ϴ� stop() �Լ�
	- �����ġ�� ��� �ð��� �и���(millisecond)�� ��ȯ�ϴ� getElapsedTime() �Լ�
	- UML Ŭ���� ���̾� �׷��� �ۼ�

	�ϳ���, 8���� �ð� ���� ��� ���� ����
*/

clock_t StopWatch::getStartTime()
{
	return startTime;
}

clock_t StopWatch::getEndTime()
{
	return endTime;
}

StopWatch::StopWatch()
{
	startTime = clock();
	endTime = clock();
}

StopWatch::~StopWatch()
{
}

void StopWatch::start()
{
	startTime = clock();
}

void StopWatch::stop()
{
	endTime = clock();
}

clock_t StopWatch::getElapsedTime()
{
	return getEndTime() - getStartTime();
}
