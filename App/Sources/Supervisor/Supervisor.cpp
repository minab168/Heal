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


#include "Supervisor/Supervisor.hpp"

#include "Common/Utils/Assert.hpp"


namespace app {

    template<Size NUM_OF_TASKS>
    Void Supervisor<NUM_OF_TASKS>::_initializeTasks() noexcept {
        for (mut i = 0; i < NUM_OF_TASKS; ++i) {
            let& task_info = this->_tasks[i];
            log_info_("Creating task `%s`...", task_info.name);
            mut handle = createTask(
                task_info.entry,
                task_info.name,
                task_info.stack_size,
                &this->_status_map[i],
                static_cast<U32>(task_info.priority),
                task_info.task_stack,
                task_info.tcb
            );
            SURE_RET_VOID_ON_INV_PTR(handle, "Failed to create task `%s`", task_info.name);

            this->_handle_map[i] = handle;
        }

        // wait for all task initialized
        delayTask(1);

        log_info_("Checking tasks initialized...");
        for (mut i = 0; i < NUM_OF_TASKS; ++i) {
            if (this->_status_map[i].state != TaskState::Ready) {
                log_err_("Task `%s` failed to run", this->_tasks[i].name);
                SURE_LOG_ERR_ON_TRUE(
                    this->_status_map[i].state == TaskState::Faulted,
                    "Error code is `%d`", this->_status_map[i].error
                );
                return;
            }
        }
    }

    template <Size NUM_OF_TASKS>
    Void Supervisor<NUM_OF_TASKS>::_checkTasksStatus() noexcept {
    }


    template<Size NUM_OF_TASKS>
    Void Supervisor<NUM_OF_TASKS>::takeControl() noexcept {
        log_info_("Initializing tasks...");
        this->_initializeTasks();

        loop {
            this->_checkTasksStatus();
            this->_feedWatchdog();
        }
    }
}
