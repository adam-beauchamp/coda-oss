/* =========================================================================
 * This file is part of io-c++ 
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2009, General Dynamics - Advanced Information Systems
 *
 * io-c++ is free software; you can redistribute it and/or modify
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

#include "io/FileInputStreamOS.h"

#if !defined(USE_IO_STREAMS)

/*!
 * Returns the number of bytes that can be read
 * without blocking by the next caller of a method for this input
 * 
 * \throw except::IOException
 * \return number of bytes which are readable
 * 
 */
sys::Off_T io::FileInputStreamOS::available()
{
    sys::Off_T where = mFile.getCurrentOffset();
    mFile.seekTo(0, io::File::FROM_END);
    sys::Off_T until = mFile.getCurrentOffset();
    mFile.seekTo(where, io::File::FROM_START);

    return (until - where);
}


sys::SSize_T io::FileInputStreamOS::read(sys::byte* b, sys::Size_T len)
{
    ::memset(b, 0, len);
    sys::Off_T avail = available();
    if (!avail)
        return io::InputStream::IS_EOF;
    if (len > (sys::Size_T)avail)
        len = (sys::Size_T)avail;

    mFile.readInto((char *)b, len);
    return (sys::SSize_T)len;

}


#endif

