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
	template<size_t N>
	BitSlice(const uint8_t(&data)[N]) : data(data), bitOffset(0), bitLength(8*N){}

	const uint8_t* data;
	uint8_t bitOffset;
	uint32_t bitLength;
};




template<typename OutType, uint8_t Bits>
class Bitreader
{
public:

	/// This reads Bits bits from the beginning of the BitSlice and updates the
	/// bitslice accordingly.
	/// This means that bits are read in network order!
	/// returns false if there are not enough bits in the slice to be read
	static bool read(BitSlice& slice, OutType& result) {
		if(slice.bitLength < Bits) {
			return false;
		}
		// read data
// TODO
//		result = 0;
//		uint8_t offset = 0;
//		while(offset < Bits) {
//			result |= 
//			uint8_t data =
//		}

		// update slice
		slice.bitLength -= Bits;
		slice.bitOffset += Bits;
		slice.data += (slice.bitOffset / 8);
		slice.bitOffset = slice.bitOffset % 8;
		return true;
	}



private:
	static constexpr uint32_t Mask = (1<<Bits)-1;

	// TODO: deduce max number of bits based on OutType
	static_assert(Bits <= 32, "Error: can only read a maximum of 32 bits at once");
};
