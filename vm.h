
#ifndef VM_H
#define VM_H

#include <stdint.h>
#include <stdbool.h>

#define uint8_t int

typedef enum {
    R0 = 0,
    R1 = 1,
    IP = 0xF,
    IS = 0xE,
    SP = 0xD
} Register;

typedef struct vm {
    int *registers;
    int *instructions;

    bool halted;
} *VM; 

/**
 * Makes a new vm object
 * O(1)
 */
VM vmNew(void);

/**
 * Frees a vm object
 * O(1)
 */
void vmFree(VM vm);

/**
 * Sets a given register to a value
 * O(1)
 */
void vmSetRegister(VM vm, Register reg, int value); 

void vmSetAddress(VM vm, int address, int value);

void vmLoadProgram(VM vm, char *filename);

void vmDoInstruction(VM vm, int instruction, int next);

int execProgram(VM vm);

#endif