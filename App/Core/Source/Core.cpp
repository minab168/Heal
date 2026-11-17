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


#include "../Interface/Core.hpp"

#include "Common/Base/Interface/Lang.hpp"
#include "Common/Operations/BitField.hpp"


namespace app {

    template<const Size STACK_SIZE>
    Void Core<STACK_SIZE>::entry(Void* args) noexcept {
        mut status = static_cast<TaskStatus*>(args);
        mut obj = Core<STACK_SIZE>(status);

        let bit_counter = sure::BitField<U8>(0, 4);

        loop {
            log_info_("This is `Core`!");

            let count = bit_counter.extract(*status);
            *status = bit_counter.write(*status, count + 1);

            delayTask(200);
        }
    }
}
