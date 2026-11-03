
#include "vm.h"
#include <stdio.h>

int main() {
    VM vm = vmNew();
    
    vmLoadProgram(vm, "test.txt");
    printf("\nexited after %x instructions. \n", execProgram(vm));

    vmFree(vm);
}