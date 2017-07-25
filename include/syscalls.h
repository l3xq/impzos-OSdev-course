
#ifndef __impzos__SYSCALLS_H
#define __impzos__SYSCALLS_H

#include <common/types.h>
#include <hardwarecommunication/interrupts.h>
#include <multitasking.h>

namespace impzos{

    class SyscallHandler : public hardwarecommunication::InterruptHandler
    {

    public:
        SyscallHandler(hardwarecommunication::InterruptManager* InterruptManager, impzos::common::uint8_t InterruptNumber);
        ~SyscallHandler();

        virtual impzos::common::uint32_t HandleInterrupt(impzos::common::uint32_t esp);

    };

}

#endif