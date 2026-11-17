/**
 * ============================================================================
 * @file       Error
 * @brief      ${DESCRIPTION}
 * 
 * Part of the My Project
 * 
 * @author     emad
 * @date       2026-11-17
 * ============================================================================
 */


#ifndef COMMON_ERROR_HPP
#define COMMON_ERROR_HPP

enum class Status {
    Ok      = 0,
    Unknown = 1,

    // ...
};


#define STATUS_OK Status::Ok

#endif // COMMON_ERROR_HPP
