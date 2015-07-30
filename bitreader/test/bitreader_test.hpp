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

#include <unittest/testsuite.hpp>

class BitreaderTest : public unittest::TestSuite
{
public:
	void
	testLeftAligned();
};
