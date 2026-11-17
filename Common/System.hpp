/**
 * ============================================================================
 * @file       System
 * @brief      ${DESCRIPTION}
 * 
 * Part of the My Project
 * 
 * @author     emad
 * @date       2026-11-17
 * ============================================================================
 */


#ifndef COMMON_SYSTEM_HPP
#define COMMON_SYSTEM_HPP

#include "Common/Types/Primitives/Inc.hpp"
#include "freertos/FreeRTOS.h"


namespace sys {

    using TaskHandle    = TaskHandle_t;
    using TaskFunction  = TaskFunction_t;
    using TaskStackType = StackType_t;
    using StaticTask    = StaticTask_t;
    using TickType      = TickType_t;



    inline TaskHandle createTask(
        TaskFunction         task_entry,
        const Char*          task_name,
        const U32            stack_size,
        Void*                parameters,
        U32                  priority,
        TaskStackType* const stack,
        StaticTask*    const tcb
    ) {
        return xTaskCreateStatic(
            task_entry,
            task_name,
            stack_size,
            parameters,
            priority,
            stack,
            tcb
        );
    }



    inline Void deleteTask(TaskHandle handle) {
        return vTaskDelete(handle);
    }


    inline Void delayTask(TickType tick) {
        return vTaskDelay(tick);
    }
}

#endif // COMMON_SYSTEM_HPP