/*
 * gbreg.h
 *
 *  Created on: Aug 25, 2017
 *      Author: netdex
 *
 *      CPU registers definition
 */

#ifndef GBREG_H_
#define GBREG_H_

#include <stdint.h>

typedef struct {
	union {
		struct {
			union {
				struct {
					uint8_t :4;
					uint8_t z :1;	// zero
					uint8_t n :1;	// subtract
					uint8_t h :1;	// half
					uint8_t c :1;	// carry
				} fl;
				uint8_t f;
			};
			uint8_t a;
		};
		uint16_t af;
	};
	union {
		struct {
			uint8_t c;
			uint8_t b;
		};
		uint16_t bc;
	};
	union {
		struct {
			uint8_t e;
			uint8_t d;
		};
		uint16_t de;
	};
	union {
		struct {
			uint8_t l;
			uint8_t h;
		};
		uint16_t hl;
	};
	uint16_t sp;
	uint16_t pc;
} gbreg;

extern gbreg reg;

#endif /* GBREG_H_ */
