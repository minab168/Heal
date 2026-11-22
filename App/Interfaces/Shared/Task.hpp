/**
 * ============================================================================
 * @file       task
 * @brief      ${DESCRIPTION}
 * 
 * Part of the My Project
 * 
 * @author     emad
 * @date       2026-11-22
 * ============================================================================
 */


#ifndef APP_COMMON_TASK_HPP_
#define APP_COMMON_TASK_HPP_

#include "System.hpp"


namespace app {

    using namespace sys;


    enum class TaskPriority: U8 {
        Lowest = 0,
        VeryLow,
        Low,
        Normal,
        High,
        VeryHigh,
        Highest,
    };


    enum class TaskState: U8 {
        Uninitialized = 0,
        Ready,
        Running,
        Faulted,
    };


    struct TaskInfo {
        const Char*             name;
        U8                      id;
        Size                    stack_size;
        TaskPriority            priority;
        Size                    wait_period;
        TaskStackType*          task_stack;
        StaticTask*             tcb;
        TaskFunction            entry;
    };


    struct TaskStatus {
        U8        counter: 5;
        TaskState state:   3;
        U8        error:   8;
    };

    struct TaskCtx {
        TaskStatus status;
    };
}

#endif // APP_COMMON_TASK_HPP_
