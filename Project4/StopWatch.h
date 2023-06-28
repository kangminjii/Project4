#pragma once
#include <ctime>

class StopWatch
{
private:
	clock_t startTime;
	clock_t endTime;
public:
	clock_t getStartTime();
	clock_t getEndTime();

	StopWatch();
	~StopWatch();

	void start();
	void stop();

	clock_t getElapsedTime();
};