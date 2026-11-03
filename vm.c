
#include "vm.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXEC 0xFFFF

/**
 * Makes a new vm object
 * O(1)
 */
VM vmNew(void) {
    VM vm = malloc(sizeof(*vm));
    
    vm->registers = calloc(0x10, sizeof(int));
    vm->registers[SP] = 0xF;
    vm->instructions = calloc(0x10, sizeof(int));
    vm->halted = false;

    return vm;
}

/**
 * Frees a vm object
 * O(1)
 */
void vmFree(VM vm) {
    free(vm->registers);
    free(vm->instructions);
    free(vm);
}

/**
 * Sets a given register to a value
 * O(1)
 */
void vmSetRegister(VM vm, Register reg, int value) {
    value = value & 0xF;
    vm->registers[reg] = value;
}

void vmSetAddress(VM vm, int address, int value) {
    value = value & 0xF;
    vm->instructions[address] = value;
}

void vmLoadProgram(VM vm, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open program.\n");
        return;
    }

    int value;
    int i = 0;
    while (fscanf(file, "%x", &value) == 1 && i < 0x10) {
        vmSetAddress(vm, i, value);
        i++;
    }

    fclose(file);
}

void vmDoInstruction(VM vm, int instruction, int next) {
    switch (instruction) {
        case 0x0:
            halt(vm);
            break;

        case 0x1:
            incR0(vm);
            break;
        
        case 0x2:
            decR0(vm);
            break;

        case 0x3:
            incR1(vm);
            break;
        
        case 0x4:
            decR1(vm);
            break;
        
        case 0x5:
            add(vm);
            break;

        case 0x6:
            sub(vm);
            break;
        
        case 0x7:
            printR0(vm);
            break;

        case 0x8:
            BEQZ(vm, next);
            break;
        
        case 0x9:
            BNEQZ(vm, next);
            break;
        
        case 0xA:
            LI0(vm, next);
            break;
        
        case 0xB:
            LI1(vm, next);
            break;
        
        case 0xC:
            LFA0(vm, next);
            break;
        
        case 0xD:
            LFA1(vm, next);
            break;
        
        case 0xE:
            push(vm, next);
            break;
        
        case 0xF: 
            push(vm, next);
            break;
    }
 }   

int execProgram(VM vm) {
    int instructionBytes[0x10] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

    int i = 0;
    while (!vm->halted && i < MAX_EXEC) {
        vm->registers[SP] = vm->instructions[vm->registers[IP]];
        int next = vm->instructions[vm->registers[IP] + 1];
        vmSetRegister(vm, IP, vm->registers[IP] + instructionBytes[vm->registers[SP]]);
        vmDoInstruction(vm, vm->registers[SP], next);
        i++;
    }

    return i;
}


