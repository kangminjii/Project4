#define _CRT_SECURE_NO_WARNINGS
#include "StopWatch.h"
#include <ctime>
/*
Q1. StopWatch class 설계
	다음의 내용을 포함하는 클래스를 설계하라.
	- get함수를 갖는 데이터 필드 startTime과 endTime
	- startTime을 현재 시간으로 초기화하는 인수 없는 생성자
	- startTime을 현재 시간으로 재설정하는 start()함수
	- endTime을 현재 시간으로 설정하는 stop() 함수
	- 스톱워치의 경과 시간을 밀리초(millisecond)로 반환하는 getElapsedTime() 함수
	- UML 클래스 다이어 그램도 작성

	하노이, 8퀸의 시간 측정 결과 포함 제출
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
