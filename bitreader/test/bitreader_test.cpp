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

#include "bitreader_test.hpp"
#include "../bitreader.hpp"

void
BitreaderTest::testBitSlice()
{
	const uint8_t data[2] = {0b00111010, 0b11111111};
	BitSlice slice(data);
	TEST_ASSERT_EQUALS(slice.data, data);
	TEST_ASSERT_EQUALS(slice.bitOffset, 0);
	TEST_ASSERT_EQUALS(slice.bitLength, 16);
}

void
BitreaderTest::testLeftAligned()
{
	const uint8_t data[2] = {0b00111010, 0b11111111};
	BitSlice slice(data);
	uint8_t result;
	int8_t iresult;

	TEST_ASSERT_TRUE((Bitreader<uint8_t, 4>::read(slice, result)));
	TEST_ASSERT_EQUALS(result, 0b0011);
	TEST_ASSERT_TRUE((Bitreader<uint8_t, 3>::read(slice, result)));
	TEST_ASSERT_EQUALS(result, 0b101);
	TEST_ASSERT_TRUE((Bitreader<uint8_t, 2>::read(slice, result)));
	TEST_ASSERT_EQUALS(result, 0b01);
	TEST_ASSERT_TRUE((Bitreader<uint8_t, 5>::read(slice, result)));
	TEST_ASSERT_EQUALS(result, 0b11111);
	TEST_ASSERT_FALSE((Bitreader<uint8_t, 5>::read(slice, result)));
	TEST_ASSERT_TRUE((Bitreader<int8_t, 2>::read(slice, iresult)));
	TEST_ASSERT_EQUALS(iresult, -1);
}
