
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "vm.h"

void halt(VM vm);

void incR0(VM vm);

void decR0(VM vm);

void incR1(VM vm);

void decR1(VM vm);

void add(VM vm);

void sub(VM vm);

void printR0(VM vm);

void BEQZ(VM vm, uint8_t dest);

void BNEQZ(VM vm, uint8_t dest);

void LI0(VM vm, uint8_t value);

void LI1(VM vm, uint8_t value);

void LFA0(VM vm, uint8_t src);

void LFA1(VM vm, uint8_t src);

void push(VM vm, Register reg);

void pop(VM vm, Register reg);

#endif