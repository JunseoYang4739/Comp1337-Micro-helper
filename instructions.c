
#include <stdio.h>

#include "instructions.h"
#define OUTPUT_STREAM stdout

void halt(VM vm) {
    vm->halted = true;
}

void incR0(VM vm) {
    vmSetRegister(vm, R0, vm->registers[R0] + 1);
}

void decR0(VM vm) {
    vmSetRegister(vm, R0, vm->registers[R0] - 1);
}

void incR1(VM vm) {
    vmSetRegister(vm, R1, vm->registers[R1] + 1);
}

void decR1(VM vm) {
    vmSetRegister(vm, R1, vm->registers[R1] - 1);
}

void add(VM vm) {
    vmSetRegister(vm, R0, vm->registers[R0] + vm->registers[R1]); 
}

void sub(VM vm) {
    vmSetRegister(vm, R0, vm->registers[R0] - vm->registers[R1]);
}

void printR0(VM vm) {
    fprintf(OUTPUT_STREAM, "%X", vm->registers[R0]);
}

void BEQZ(VM vm, int dest) {
    if (vm->registers[R0] == 0) {
        vmSetRegister(vm, IP, dest);
        return;
    }
}

void BNEQZ(VM vm, int dest) {
    if (vm->registers[R0] != 0) {
        vmSetRegister(vm, IP, dest);
        return;
    }
}

void LI0(VM vm, int value) {
    vmSetRegister(vm, R0, value);
}

void LI1(VM vm, int value) {
    vmSetRegister(vm, R1, value);
}

void LFA0(VM vm, int src) {
    vmSetRegister(vm, R0, vm->instructions[src]);
}

void LFA1(VM vm, int src) {
    vmSetRegister(vm, R0, vm->instructions[src]);
}

void push(VM vm, Register reg) {
    vmSetAddress(vm, vm->registers[SP], reg);
    vmSetRegister(vm, SP, vm->registers[SP] - 1);
}

static int peakStack(VM vm) {
    return vm->instructions[vm->registers[SP]];
}

void pop(VM vm, Register reg) {
    vmSetRegister(vm, reg, peakStack(vm));
    vmSetRegister(vm, SP, vm->registers[SP] + 1);
}