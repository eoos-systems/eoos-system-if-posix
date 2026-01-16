/**
 * @file      sys.System.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2026, Sergey Baigudin, Baigudin Software
 */
#include "sys.System.hpp"

namespace eoos
{
namespace sys
{

System* System::eoos_( NULLPTR );

System::System()
    : NonCopyable<NoAllocator>()
    , api::System()
    , heap_()
    , scheduler_()
    , mutexManager_()
    , semaphoreManager_()
    , streamManager_() {
    bool_t const isConstructed( construct() );
    setConstructed( isConstructed );
}

System::~System()
{
    eoos_ = NULLPTR;
}

bool_t System::isConstructed() const
{
    return Parent::isConstructed();
}

api::Scheduler& System::getScheduler()
{
    return scheduler_; ///< SCA MISRA-C++:2008 Justified Rule 9-3-2
}

api::Heap& System::getHeap()
{
    return heap_; ///< SCA MISRA-C++:2008 Justified Rule 9-3-2
}

api::MutexManager& System::getMutexManager()
{
    return mutexManager_; ///< SCA MISRA-C++:2008 Justified Rule 9-3-2
}

api::SemaphoreManager& System::getSemaphoreManager()
{
    return semaphoreManager_; ///< SCA MISRA-C++:2008 Justified Rule 9-3-2
}

api::StreamManager& System::getStreamManager()
{
    return streamManager_; ///< SCA MISRA-C++:2008 Justified Rule 9-3-2
}

int32_t System::run(api::Task& task)
{
    int32_t error( -1 );
    System eoos;
    if( eoos.isConstructed() )
    {
        task.start();
        error = 0;
    }
    return error;
}

System& System::getSystem()
{
    if(eoos_ == NULLPTR)
    {   ///< UT Justified Branch: Startup dependency
        ::exit(-1);
    }
    return *eoos_;
}

bool_t System::construct()
{
    bool_t res( false );
    if( ( isConstructed() )
     && ( eoos_ == NULLPTR )
     && ( heap_.isConstructed() )
     && ( scheduler_.isConstructed() )
     && ( mutexManager_.isConstructed() )
     && ( semaphoreManager_.isConstructed() )
     && ( streamManager_.isConstructed() ) )
    {
        eoos_ = this;
        res = true;
    }
    return res;
}

} // namespace sys
} // namespace eoos
