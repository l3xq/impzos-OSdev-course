
#include <syscalls.h>

using namespace impzos;
using namespace impzos::common;
using namespace impzos::hardwarecommunication;

SyscallHandler::SyscallHandler(InterruptManager* InterruptManager, uint8_t InterruptNumber)
:    InterruptHandler(InterruptManager, InterruptNumber  + InterruptManager->HardwareInterruptOffset())
{
}

SyscallHandler::~SyscallHandler()
{
}


void printf(char*);

uint32_t SyscallHandler::HandleInterrupt(uint32_t esp)
{
    CPUState* cpu = (CPUState*)esp;


    switch(cpu->eax)
    {
        case 4:
            printf((char*)cpu->ebx);
            break;

        default:
            break;
    }


    return esp;
}

