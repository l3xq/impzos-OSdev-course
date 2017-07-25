
#ifndef __impzos__DRIVERS__MOUSE_H
#define __impzos__DRIVERS__MOUSE_H

#include <common/types.h>
#include <hardwarecommunication/port.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>

namespace impzos{
    namespace drivers
    {

        class MouseEventHandler
        {
        public:
            MouseEventHandler();

            virtual void OnActivate();
            virtual void OnMouseDown(impzos::common::uint8_t button);
            virtual void OnMouseUp(impzos::common::uint8_t button);
            virtual void OnMouseMove(int x, int y);
        };


        class MouseDriver : public impzos::hardwarecommunication::InterruptHandler, public Driver
        {
            impzos::hardwarecommunication::Port8Bit dataport;
            impzos::hardwarecommunication::Port8Bit commandport;
            impzos::common::uint8_t buffer[3];
            impzos::common::uint8_t offset;
            impzos::common::uint8_t buttons;

            MouseEventHandler* handler;
        public:
            MouseDriver(impzos::hardwarecommunication::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual impzos::common::uint32_t HandleInterrupt(impzos::common::uint32_t esp);
            virtual void Activate();
        };

    }
}

#endif
