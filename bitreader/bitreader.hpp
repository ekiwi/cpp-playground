/*
 * bitreader.hpp
 *
 * Copyright (c) 2015, Kevin Laeufer <kevin.laeufer@rwth-aachen.de>
 *
 * This file is part of ekiwi/cpp-playground.
 *
 * ekiwi/cpp-playground is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ekiwi/cpp-playground is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with ekiwi/cpp-playground.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>


struct BitSlice
{
	uint8_t* data;
	uint8_t bit_offset;
	uint32_t bit_length;
};




template<int Bits>
class Bitreader
{
public:
	using OutType = uint32_t;

	/// This reads Bits bits from the beginning of the BitSlice and updates the
	/// bitslice accordingly.
	/// returns false if there are not enough bits in the slice to be read
	bool read(BitSlice& input, OutType& result) {
		if(input.bit_length < Bits) {
			return false;
		}
	}



private:
	// TODO: deduce max number of bits based on OutType
	static_assert(Bits <= 32, "Error: can only read a maximum of 32 bits at once");
};
