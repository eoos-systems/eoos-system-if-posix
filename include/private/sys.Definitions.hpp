/**
 * @file      Definitions.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018-2026, Sergey Baigudin, Baigudin Software
 *
 * @brief System definitions.
 */
#ifndef SYS_DEFINITIONS_HPP_
#define SYS_DEFINITIONS_HPP_

/**
 * @brief Define number of static allocated resources.
 *
 * @note
 *  - If EOOS_GLOBAL_SYS_<name>_AMOUNT does not equal zero and EOOS_GLOBAL_ENABLE_NO_HEAP is any,
 *    the resource will be allocated in pre-allocated pool memory.
 *  - If EOOS_GLOBAL_SYS_<name>_AMOUNT equals zero and EOOS_GLOBAL_ENABLE_NO_HEAP is not defined,
 *    the resource will be allocated in heap memory.
 *  - If EOOS_GLOBAL_SYS_<name>_AMOUNT equals zero and EOOS_GLOBAL_ENABLE_NO_HEAP is defined,
 *    the resource will NOT be allocated.
 *  - EOOS_GLOBAL_SYS_<name>_AMOUNT less then zero is prohibbited.
 *
 * @note
 *  To comply MISRA-C++:2008 in Rule 18–4–1:
 *  - EOOS_GLOBAL_SYS_<name>_AMOUNT shall not equal zero
 *  - EOOS_GLOBAL_ENABLE_NO_HEAP shall be defined.
 *
 * @note
 * 	The EOOS_GLOBAL_SYS_<name>_AMOUNT shall be passed to the project build system through compile definition.
 *
 * @note
 *	Currently EOOS_GLOBAL_SYS_<name>_AMOUNT feature supported only by EOOS POSIX and EOOS FreeRTOS.
 *  For EOOS WIN32 these defines have no effects.
 */
#ifndef EOOS_GLOBAL_SYS_MUTEX_AMOUNT
    #define EOOS_GLOBAL_SYS_MUTEX_AMOUNT (0)
#endif

#ifndef EOOS_GLOBAL_SYS_SEMAPHORE_AMOUNT
    #define EOOS_GLOBAL_SYS_SEMAPHORE_AMOUNT (0)
#endif

#ifndef EOOS_GLOBAL_SYS_THREAD_AMOUNT
    #define EOOS_GLOBAL_SYS_THREAD_AMOUNT (0)
#endif

/**
 * @brief Sets child thread's CPU affinity mask to primary thread CPU..
 *
 * @note The definition shall be passed to the project build system through global compile definitions.
 * #define EOOS_GLOBAL_SYS_SCHEDULER_THREAD_AFFINITY
 */

/**
 * @brief Sets thread policy to the round-robin real-time scheduling.
 *
 * @note The definition shall be passed to the project build system through global compile definitions.
 * #define EOOS_GLOBAL_SYS_SCHEDULER_REALTIME
 */

#endif // SYS_DEFINITIONS_HPP_
