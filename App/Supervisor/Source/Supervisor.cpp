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


#include "../Interface/Supervisor.hpp"

#include "Common/Base/Interface/Lang.hpp"

namespace app {

    Void Supervisor::_initializeTasks() noexcept {
        for (mut i = 0; i < NUM_OF_TASKS; ++i) {
            let task_info = task_table[i];
            mut handle = createTask(
                task_info.entry,
                task_info.name,
                task_info.stack_size,
                &this->_task_status_map[i],
                static_cast<U32>(task_info.priority),
                task_info.task_stack,
                task_info.tcb
            );

            this->_task_handle_map[i] = handle;
        }
    }

    Void Supervisor::takeControl() noexcept {
        this->_initializeTasks();

        loop {
            this->_checkTasksStatus();
            this->_feedWatchdog();
        }
    }
}
