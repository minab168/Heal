/**
 * ============================================================================
 * @file       Supervisor
 * @brief      ${DESCRIPTION}
 * 
 * Part of the My Project
 * 
 * @author     emad
 * @date       2026-11-17
 * ============================================================================
 */


#ifndef APP_SUPERVISOR_INTERFACE_SUPERVISOR_HH_
#define APP_SUPERVISOR_INTERFACE_SUPERVISOR_HH_

#include "Core.hpp"
#include "System.hpp"
#include "../../../Common/Status.hpp"
#include "Common/Types/Primitives/Inc.hpp"


namespace app {

    using namespace sure;
    using namespace sys;


    #define NUM_OF_TASKS 1

    enum class TaskPriority: U8 {
        Lowest = 0,
        VeryLow,
        Low,
        Normal,
        High,
        VeryHigh,
        Highest,
    };


    struct TaskInfo {
        const Char*             name;
        Size                    stack_size;
        TaskPriority            priority;
        Size                    wait_period;
        TaskStackType*          task_stack;
        StaticTask*             tcb;
        TaskFunction            entry;
    };


    constexpr TaskInfo task_table[NUM_OF_TASKS] = {
        {
            .name        = "core",
            .stack_size  = 2048,
            .priority    = TaskPriority::Lowest,
            .wait_period = 1000,
            .task_stack  = Core<2048>::stack,
            .tcb         = &Core<2048>::tcb,
            .entry       = Core<2048>::entry
        }
    };


    using TaskStatus = U8;


    class Supervisor {
        TaskStatus _task_status_map[NUM_OF_TASKS] = {};
        TaskHandle _task_handle_map[NUM_OF_TASKS] = {};

        Void _initializeTasks() noexcept;

        Void _checkTasksStatus() noexcept;

        Void _feedWatchdog() noexcept;

    public:
        constexpr Supervisor() = default;

        [[noreturn]]
        Void takeControl() noexcept;
    };
}

#endif // APP_SUPERVISOR_INTERFACE_SUPERVISOR_HH_
