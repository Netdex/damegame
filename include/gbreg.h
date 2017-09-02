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
#include "types.h"

typedef struct {
	union {
		struct {
			union {
				struct {
					u8 :4;
					u8 z :1;	// zero
					u8 n :1;	// subtract
					u8 h :1;	// half
					u8 c :1;	// carry
				} fl;
				u8 f;
			};
			u8 a;
		};
		u16 af;
	};
	union {
		struct {
			u8 c;
			u8 b;
		};
		u16 bc;
	};
	union {
		struct {
			u8 e;
			u8 d;
		};
		u16 de;
	};
	union {
		struct {
			u8 l;
			u8 h;
		};
		u16 hl;
	};
	u16 sp;
	u16 pc;
} gbreg;

extern gbreg reg;

#endif /* GBREG_H_ */
