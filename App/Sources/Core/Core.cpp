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



#include "Common/Base/Interface/Lang.hpp"
#include "Common/Operations/BitField.hpp"
#include "Core/Core.hpp"
#include "Shared/Task.hpp"


namespace app {

    template<const Size STACK_SIZE>
    Void Core<STACK_SIZE>::entry(Void* args) noexcept {
        mut ctx = static_cast<TaskCtx*>(args);
        mut obj = Core<STACK_SIZE>(ctx);

        obj._ctx->status.state = TaskState::Ready;

        loop {
            log_info_("This is `Core`!");
            obj._ctx->status.counter += 1;
            delayTask(200);
        }
    }
}
