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

#include "Common/Types/Array.hpp"
#include "Common/Types/Primitives/Inc.hpp"
#include "System.hpp"
#include "Shared/Task.hpp"


namespace app {

    using namespace sure;
    using namespace sys;

    template<Size NUM_OF_TASKS>
    class Supervisor {
        const TaskInfo (&_tasks)[NUM_OF_TASKS] = {}; // TODO: Change it to sure::Array
        TaskStatus     _status_map[NUM_OF_TASKS] = {};
        TaskHandle     _handle_map[NUM_OF_TASKS] = {};

        Void _initializeTasks() noexcept;

        Void _checkTasksStatus() noexcept;

        Void _feedWatchdog() noexcept;

    public:
        constexpr Supervisor() = default;

        explicit Supervisor(const TaskInfo (&tasks)[NUM_OF_TASKS]) noexcept : _tasks(tasks) {}

        [[noreturn]]
        Void takeControl() noexcept;
    };
}

#endif // APP_SUPERVISOR_INTERFACE_SUPERVISOR_HH_
