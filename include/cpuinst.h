
#ifndef CPUINST_H_
#define CPUINST_H_

#include "types.h"

typedef struct {
	const char *disasm;			// disassembly
	const char *desc;           // description
	void (*impl)(u8 *op);  // implementation
	u8 len;		        // operand length excluding opcode
	u8 cycles;             // real cpu cycles
} cpuinst;

#endif /* CPUINST_H_ */
