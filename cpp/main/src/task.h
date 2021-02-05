#include "TaskSchedulerDeclarations.h"
#include "comms.h"
#include "inputs.h"
#include "outputs.h"

#ifndef TASK_H_
#define TASK_H_


void EncoderOut(void);          // Replicates the Encoder Input Pulse Signal

static Scheduler runner;
static Task CriticalEncoderOut(1, TASK_FOREVER, &EncoderOut, &runner, true);

#endif