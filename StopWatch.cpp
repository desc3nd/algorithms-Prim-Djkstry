
#include <winnt.h>
#include <afxres.h>
#include "StopWatch.h"

void StopWatch::startCountingTime() {
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    start = read_QPC();
}

void StopWatch::stopCountingTime() {
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    stop1 = read_QPC();
}

long long int StopWatch::elapsedTime() {
    elapsed = stop1 - start;
    return 1000000000.0 * elapsed / frequency;
}

long long int StopWatch::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}