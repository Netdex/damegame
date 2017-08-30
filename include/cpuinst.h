
#ifndef CPUINST_H_
#define CPUINST_H_

typedef struct {
	const char *disasm;			// disassembly
	const char *desc;           // description
	void (*impl)(uint8_t *op);  // implementation
	uint8_t len;		        // operand length excluding opcode
	uint8_t cycles;             // real cpu cycles
} cpuinst;

#endif /* CPUINST_H_ */
