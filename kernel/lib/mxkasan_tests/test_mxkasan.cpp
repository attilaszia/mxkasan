// Copyright 2017 Attila Szasz
//
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0])) 

void malloc_oob_right(void)
{
	uint8_t *ptr;
	size_t size = 123;

	printf("out-of-bounds to right\n");
	ptr = (uint8_t*)malloc(size);
	if (!ptr) {
		printf("Allocation failed\n");
		return;
	}

	ptr[size] = 'x';
	free(ptr);
}

void malloc_oob_left(void)
{
	uint8_t *ptr;
	size_t size = 150;

	printf("out-of-bounds to left\n");
	ptr = (uint8_t*)malloc(size);
	if (!ptr) {
		printf("Allocation failed\n");
		return;
	}

	*ptr = *(ptr - 5);
	free(ptr);
}

void malloc_uaf(void)
{
	uint8_t *ptr;
	size_t size = 10;

	printf("use-after-free\n");
	ptr = (uint8_t *)malloc(size);
	if (!ptr) {
		printf("Allocation failed\n");
		return;
	}

	free(ptr);
	*ptr = *(ptr + 8);
}

static char global_array[10];

void mxkasan_global_oob(void)
{
	volatile int i = 3;
	char *p = &global_array[ARRAY_SIZE(global_array) + i];

	printf("out-of-bounds global variable\n");
	*(volatile char *)p;
}