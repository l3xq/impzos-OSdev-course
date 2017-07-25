
#ifndef __impzos__DRIVERS__KEYBOARD_H
#define __impzos__DRIVERS__KEYBOARD_H

#include <common/types.h>
#include <hardwarecommunication/interrupts.h>
#include <drivers/driver.h>
#include <hardwarecommunication/port.h>

namespace impzos{
    namespace drivers
    {

        class KeyboardEventHandler
        {
        public:
            KeyboardEventHandler();

            virtual void OnKeyDown(char);
            virtual void OnKeyUp(char);
        };

        class KeyboardDriver : public impzos::hardwarecommunication::InterruptHandler, public Driver
        {
            impzos::hardwarecommunication::Port8Bit dataport;
            impzos::hardwarecommunication::Port8Bit commandport;

            KeyboardEventHandler* handler;
        public:
            KeyboardDriver(impzos::hardwarecommunication::InterruptManager* manager, KeyboardEventHandler *handler);
            ~KeyboardDriver();
            virtual impzos::common::uint32_t HandleInterrupt(impzos::common::uint32_t esp);
            virtual void Activate();
        };

    }
}

#endif