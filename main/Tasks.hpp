/**
 * ============================================================================
 * @file       tasks
 * @brief      ${DESCRIPTION}
 * 
 * Part of the My Project
 * 
 * @author     emad
 * @date       2026-11-22
 * ============================================================================
 */


#ifndef MAIN_TASKS_HPP_
#define MAIN_TASKS_HPP_


#include "Common/Utils/Assert.hpp"
#include "Core/Core.hpp"
#include "Shared/Task.hpp"


using namespace app;


enum class TaskIds: U8 {
    Core,
    // Sensors,
    // Communication,
    // Supervisor,

    Count
};

constexpr Size NUMBER_OF_TASKS = static_cast<Size>(TaskIds::Count);
constexpr size_t taskIdx(TaskIds id) { return static_cast<Size>(id); }


constexpr TaskInfo task_table[NUMBER_OF_TASKS] = {
    {
        .name        = "core",
        .id          = static_cast<U8>(TaskIds::Core),
        .stack_size  = 2048,
        .priority    = TaskPriority::Lowest,
        .wait_period = 1000,
        .task_stack  = Core<2048>::stack,
        .tcb         = &Core<2048>::tcb,
        .entry       = Core<2048>::entry
    }
};

constexpr bool idsMatch() {
    for (size_t i = 0; i < NUMBER_OF_TASKS; ++i)
        if (task_table[i].id != i) return false;
    return true;
}

SURE_STATIC_ASSERT(sizeof(task_table) / sizeof(task_table[0]) == NUMBER_OF_TASKS, "table must follow TaskId");
SURE_STATIC_ASSERT(idsMatch(), "table order must follow TaskId");

#endif // MAIN_TASKS_HPP_
