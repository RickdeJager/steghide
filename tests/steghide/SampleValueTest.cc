/*
 * steghide 0.5.1 - a steganography program
 * Copyright (C) 1999-2003 Stefan Hetzl <shetzl@chello.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#include "SampleValueTest.h"
#include "utcommon.h"

#include "SampleValue.h"

bool SampleValueTest::genericTestIsNeighbour(SampleValue *s1, SampleValue *s2, bool res) {
    bool retval = ((s1->isNeighbour(s2) == s2->isNeighbour(s1)) && (s1->isNeighbour(s2) == res));
    if (ArgVerbose && !retval) {
        std::cerr << std::endl << "---- FAILED: genericIsNeighbour ----" << std::endl;
        std::cerr << "is: " << s1->isNeighbour(s2) << ", shouldbe: " << res << std::endl;
        std::cerr << "distance of s1 (0x" << std::hex << s1->getKey() << ") and s2 (0x";
        std::cerr << s2->getKey() << std::dec << ") is: " << s1->calcDistance(s2) << std::endl;
        std::cerr << "-------------------------------------" << std::endl;
    }
    return retval;
}

bool SampleValueTest::genericTestDistance(SampleValue *s1, SampleValue *s2, UWORD32 dist) {
    bool retval =
        ((s1->calcDistance(s2) == s2->calcDistance(s1)) && (s1->calcDistance(s2) == dist));
    if (ArgVerbose && !retval) {
        std::cerr << std::endl << "---- FAILED: genericTestDistance ----" << std::endl;
        std::cerr << "distance of s1 (0x" << std::hex << s1->getKey() << ") and s2 (0x";
        std::cerr << s2->getKey() << std::dec << ") is: " << s1->calcDistance(s2) << std::endl;
        std::cerr << "should be: " << dist << std::endl;
        std::cerr << "-------------------------------------" << std::endl;
    }
    return retval;
}

bool SampleValueTest::genericTestEValue(SampleValue *s, EmbValue ev) {
    bool retval = (s->getEmbeddedValue() == ev);
    return retval;
}
