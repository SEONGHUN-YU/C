#pragma once

#include "Worker.h"
#include "Timer.h"
// body�� �ִ�, definition�� �ִ�, cpp ���� �ʿ� ����� include �ϴ� ���� ����ϴ�

void Worker::doSomething()
{
	Timer timer; // start timer

	// do some work here

	timer.elapsed(); // end timer and report elapsed time
}
