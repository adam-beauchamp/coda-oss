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


#if defined(__sgi)
#include <ulocks.h>
#include "mt/SemaphoreIrix.h"


mt::SemaphoreIrix::SemaphoreIrix(unsigned int count)
{
    if (!mt::SyncFactoryIrix().createSemaphore(*this, count))
        throw mt::ThreadResourceException("Semaphore initialization failed");
}

mt::SemaphoreIrix::~SemaphoreIrix()
{
    dbg_printf("~SemaphoreIrix()\n");
    mt::SyncFactoryIrix().destroySemaphore(*this);
    dbg_printf("done.\n");
}

void mt::SemaphoreIrix::wait()
{
    dbg_printf("SemaphoreIrix::wait()\n");
    if (!mt::SyncFactoryIrix().waitSemaphore(*this))
        throw mt::ThreadResourceException("Semaphore wait failed");
}

void mt::SemaphoreIrix::signal()
{
    dbg_printf("SemaphoreIrix::signal()\n");
    if (!mt::SyncFactoryIrix().signalSemaphore(*this))
        throw mt::ThreadResourceException("Semaphore signal failed");
}

usema_t*& mt::SemaphoreIrix::getNative()
{
    // We don't actually use this, but SemaphoreIrix uses usema_t* as its template..
    return (usema_t*) NULL;
}

#endif // __sgi

