#include "TaskSchedulerDeclarations.h"
#include "comms.h"
#include "inputs.h"
#include "outputs.h"
#include "disp.h"

#ifndef TASK_H_
#define TASK_H_


static Scheduler runner;
static Task RawRPMCalcTask(2, TASK_FOREVER, &calcRawRPM, &runner, true);
static Task RPMCalcTask(1, TASK_FOREVER, &CalcRPM, &runner, true);
static Task DisplayTask(5, TASK_FOREVER, &Display, &runner, true);

#endif