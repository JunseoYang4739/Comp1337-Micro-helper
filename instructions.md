# QT4004 Spec

## Qt4004 Desc

The QT4004 is a simple 4 bit microprocessor that has 2 general purpose registers, 
an instruction pointer, an instruction store and a stack pointer. 

## Qt4004 Instruction Set

### Instruction Reference Set

| Opcode | Mnemonic | Operands | Description | Length |
|:---:|---|---|---|:---:|
| `0` | `HALT` | None | Halt program execution. | 1 |
| `1` | `INC0` | None | Increment R0 by 1. | 1 |
| `2` | `DEC0` | None | Decrement R0 by 1. | 1 |
| `3` | `INC1` | None | Increment R1 by 1. | 1 |
| `4` | `DEC1` | None | Decrement R1 by 1. | 1 |
| `5` | `ADD` | None | Add R1 to R0. Store the result in R0. | 1 |
| `6` | `SUB` | None | Subtract R1 from R0. Store the result in R0. | 1 |
| `7` | `PRT0` | None | Print R0 in hexadecimal. | 1 |
| `8` | `JZ` | Address | Jump to the specified address if R0 equals zero. | 2 |
| `9` | `JNZ` | Address | Jump to the specified address if R0 does not equal zero. | 2 |
| `A` | `LDI0` | Value | Load an immediate value into R0. | 2 |
| `B` | `LDI1` | Value | Load an immediate value into R1. | 2 |
| `C` | `LDR0` | Address | Load the value at the specified memory address into R0. | 2 |
| `D` | `LDR1` | Address | Load the value at the specified memory address into R1. | 2 |
| `E` | `PUSH` | Register | Push the specified register's value onto the stack. | 2 |
| `F` | `POP` | Register | Pop the stack's top value into the specified register. | 2 |


