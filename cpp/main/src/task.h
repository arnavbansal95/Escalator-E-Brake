#include "TaskSchedulerDeclarations.h"
#include "comms.h"
#include "inputs.h"
#include "outputs.h"
#include "disp.h"

#ifndef TASK_H_
#define TASK_H_


void MainLoop(void);                                            // Main Logic Loop

static Scheduler runner;
static Task MainTask(1, TASK_FOREVER, &MainLoop, &runner, true);
static Task DisplayTask(5, TASK_FOREVER, &Display, &runner, true);

#endif