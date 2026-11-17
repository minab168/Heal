/**
 * ============================================================================
 * @file       Core
 * @brief      ${DESCRIPTION}
 * 
 * Part of the My Project
 * 
 * @author     emad
 * @date       2026-11-17
 * ============================================================================
 */


#ifndef APP_CORE_INTERFACE_CORE_HPP_
#define APP_CORE_INTERFACE_CORE_HPP_

#include "System.hpp"
#include "../../Supervisor/Interface/Supervisor.hpp"
#include "Common/Types/Array.hpp"

namespace app {

    template<const Size STACK_SIZE = 2048>
    class Core {
        TaskStatus* _status = NULL_PTR;

      public:
        static sys::TaskStackType stack[STACK_SIZE];
        static sys::StaticTask    tcb;

        [[noreturn]]
        static Void entry(Void*) noexcept;

        constexpr Core(TaskStatus* status) noexcept : _status(status) {}
    };
}

#endif // APP_CORE_INTERFACE_CORE_HPP_
