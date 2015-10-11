// Copyright (C) 2007 Michael Niedermayer <michaelni@gmx.at>
// Copyright (C) 2013 James Almer <jamrial@gmail.com>
// Copyright (C) 2015 Zhe Wang <0x1998@gmail.com>
//
// Based on the RIPEMD-128 implementation from libavutil
//
// This program is a free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3 of the License.
//
// You can get a copy of GNU General Public License along this program
// But you can always get it from http://www.gnu.org/licenses/gpl.txt
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.

#ifndef __RIPEMD_HH_INCLUDED__
#define __RIPEMD_HH_INCLUDED__

#include <stdint.h>
#include <stddef.h>


class RIPEMD128
{
public:
  RIPEMD128();

  // Update hash value
  void update( const uint8_t * data, size_t len );

  // Finish hashing and output digest value.
  void digest( uint8_t * digest );

private:
  uint64_t count;       // number of bytes in buffer
  uint8_t  buffer[64];  // 512-bit buffer of input values used in hash updating
  uint32_t state[10];   // current hash value

  void transform( const uint8_t buffer[64] );
};

#endif // __RIPEMD_HH_INCLUDED__
