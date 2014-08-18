/* =========================================================================
 * This file is part of mt-c++ 
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2009, General Dynamics - Advanced Information Systems
 *
 * mt-c++ is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef __MT_SEMAPHORE_WIN32_H__
#define __MT_SEMAPHORE_WIN32_H__

#if defined(WIN32)

#if !defined(USE_NSPR_THREADS)

#include <sys/Conf.h>
#include <mt/SemaphoreInterface.h>

namespace mt
{

class SemaphoreWin32 : public SemaphoreInterface
{
public:
    enum { MAX_COUNT = 10 };
    SemaphoreWin32(unsigned int count = 0);
    
    virtual ~SemaphoreWin32()
    {}

    void wait();
    
    void signal();
    
    HANDLE& getNative();
    
    /*!
     *  Return the type name.  This function is essentially free,
     *  because it is static RTTI.
     */
    const char* getNativeType() const
    {
        return typeid(mNative).name();
    }
private:
    HANDLE mNative;
};

}
#endif
#endif
#endif
