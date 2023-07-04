#pragma once

#include "Worker.h"
#include "Timer.h"
// body가 있는, definition이 있는, cpp 파일 쪽에 헤더를 include 하는 것이 깔끔하다

void Worker::doSomething()
{
	Timer timer; // start timer

	// do some work here

	timer.elapsed(); // end timer and report elapsed time
}
