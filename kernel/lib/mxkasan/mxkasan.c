// Copyright 2017 Attila Szasz
//
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <lib/mxkasan.h>

void mxkasan_test(void) {
    uint8_t* testptr = (uint8_t*) 0xffffde0000000000 ;

    testptr += 0xdead;
    printf("writing MXKASAN shadow memory at %#" PRIxPTR "\n", (unsigned long)testptr);
    *testptr = 0xaa;
    printf("reading back value at %#" PRIxPTR ": %x\n", (unsigned long)testptr, *testptr);
}