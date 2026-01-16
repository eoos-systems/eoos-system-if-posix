/**
 * @file      sys.Heap.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022-2026, Sergey Baigudin, Baigudin Software
 */
#include "sys.Heap.hpp"
#include "lib.Assert.hpp"

namespace eoos
{
namespace sys
{

Heap::Heap()
    : api::Heap() {
}

Heap::~Heap()
{
}

bool_t Heap::isConstructed() const
{
    return true;
}

void* Heap::allocate(size_t const size, void* ptr)
{
    static_cast<void>(ptr); // Avoid MISRA-C++:2008 Rule 0–1–3 and AUTOSAR C++14 Rule A0-1-4
    #ifdef EOOS_GLOBAL_ENABLE_NO_HEAP
    static_cast<void>(size); // Avoid MISRA-C++:2008 Rule 0–1–3 and AUTOSAR C++14 Rule A0-1-4
    // @note The C++ language does not standardizes to return NULLPTR if allocation fails.
    // Moreover GCC compiler by default in such case would construct an object on NULLPTR returned.
    // EOOS philosophy does not state to use C++ exception mechanism, therefore we would call
    // assertion here to prevent NULLPTR returned.
    //
    // @todo Consider to introduce a global definition to return NULLPTR if it is defined.
    EOOS_ASSERT( false );
    return NULLPTR;
    #else
    return ::malloc(size);
    #endif // EOOS_GLOBAL_ENABLE_NO_HEAP
}

void Heap::free(void* ptr)
{
    #ifdef EOOS_GLOBAL_ENABLE_NO_HEAP
    static_cast<void>(ptr); // Avoid MISRA-C++:2008 Rule 0–1–3 and AUTOSAR C++14 Rule A0-1-4
    #else
    ::free(ptr);
    #endif // EOOS_GLOBAL_ENABLE_NO_HEAP
}

} // namespace sys
} // namespace eoos
