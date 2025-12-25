#include <stdio.h>
#include <inttypes.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "includes.h"

void TimerCallback(union sigval sv) {
    PeriodicFunction_IRQTick();
    DelayedFunctions_IRQTick();
}


static void Setup_Timer(void) {
    struct sigevent sev;
    struct itimerspec its;
    timer_t timerid;
    int interval_ms = 2;  // Timer interval in milliseconds (for some reason 2 is 1ms)

    // Set up the signal event structure
    sev.sigev_notify = SIGEV_THREAD;        // Notify via a separate thread
    sev.sigev_notify_function = TimerCallback;  // The callback function
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr = NULL;

    // Create the timer
    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        perror("timer_create");
        exit(EXIT_FAILURE);
    }

    // Set up the timer to expire every ms
    its.it_value.tv_sec = 0;                          // Initial expiration in seconds
    its.it_value.tv_nsec = interval_ms * 1000000;     // Convert ms to ns
    its.it_interval.tv_sec = 0;                       // Periodic timer
    its.it_interval.tv_nsec = interval_ms * 1000000;  // Convert ms to ns

    // Start the timer
    if (timer_settime(timerid, 0, &its, NULL) == -1) {
        perror("timer_settime");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv)
{
	void Userinput_Init(void); Userinput_Init();
    void FileHandler_Init(void); FileHandler_Init();
    void Tradfri_Init(void); Tradfri_Init();
	Setup_Timer();

	while(1) {
		Run_Closures();
	}
	return 0;
}
