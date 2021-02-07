#include "TaskSchedulerDeclarations.h"
#include "comms.h"
#include "inputs.h"
#include "outputs.h"
#include "disp.h"

#ifndef TASK_H_
#define TASK_H_


void EncoderOut(void);          // Replicates the Encoder Input Pulse Signal

static Scheduler runner;
static Task DisplayTask(5, TASK_FOREVER, &Display, &runner, true);

#endif