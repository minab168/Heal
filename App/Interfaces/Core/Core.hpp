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
#include "Communication/Interface.hpp"
#include "Shared/Task.hpp"


namespace app {

    using namespace sys;

    template<const Size STACK_SIZE = 2048>
    class Core {
        TaskCtx*               _ctx = NULL_PTR;
        CommunicationInterface _comm = {};

      public:
        static TaskStackType stack[STACK_SIZE];
        static StaticTask    tcb;

        [[noreturn]]
        static Void entry(Void*) noexcept;

        explicit constexpr Core(TaskCtx* ctx) noexcept : _ctx(ctx) {}
    };
}

#endif // APP_CORE_INTERFACE_CORE_HPP_
