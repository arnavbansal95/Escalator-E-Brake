#include "TaskSchedulerDeclarations.h"
#include "comms.h"
#include "inputs.h"
#include "outputs.h"
#include "disp.h"

#ifndef TASK_H_
#define TASK_H_


void MainTask(void);                            // Main Logic Task

static Scheduler runner;
static Task MainTask(1, TASK_FOREVER, &MainTask, &runner, true);
static Task DisplayTask(5, TASK_FOREVER, &Display, &runner, true);

#endif