
#ifndef __impzos__HARDWARECOMMUNICATION__PCI_H
#define __impzos__HARDWARECOMMUNICATION__PCI_H

#include <hardwarecommunication/port.h>
#include <drivers/driver.h>
#include <common/types.h>
#include <hardwarecommunication/interrupts.h>

#include <memorymanagement.h>

namespace impzos{
    namespace hardwarecommunication
    {

        enum BaseAddressRegisterType
        {
            MemoryMapping = 0,
            InputOutput = 1
        };



        class BaseAddressRegister
        {
        public:
            bool prefetchable;
            impzos::common::uint8_t* address;
            impzos::common::uint32_t size;
            BaseAddressRegisterType type;
        };



        class PeripheralComponentInterconnectDeviceDescriptor
        {
        public:
            impzos::common::uint32_t portBase;
            impzos::common::uint32_t interrupt;

            impzos::common::uint16_t bus;
            impzos::common::uint16_t device;
            impzos::common::uint16_t function;

            impzos::common::uint16_t vendor_id;
            impzos::common::uint16_t device_id;

            impzos::common::uint8_t class_id;
            impzos::common::uint8_t subclass_id;
            impzos::common::uint8_t interface_id;

            impzos::common::uint8_t revision;

            PeripheralComponentInterconnectDeviceDescriptor();
            ~PeripheralComponentInterconnectDeviceDescriptor();

        };


        class PeripheralComponentInterconnectController
        {
            Port32Bit dataPort;
            Port32Bit commandPort;

        public:
            PeripheralComponentInterconnectController();
            ~PeripheralComponentInterconnectController();

            impzos::common::uint32_t Read(impzos::common::uint16_t bus, impzos::common::uint16_t device, impzos::common::uint16_t function, impzos::common::uint32_t registeroffset);
            void Write(impzos::common::uint16_t bus, impzos::common::uint16_t device, impzos::common::uint16_t function, impzos::common::uint32_t registeroffset, impzos::common::uint32_t value);
            bool DeviceHasFunctions(impzos::common::uint16_t bus, impzos::common::uint16_t device);

            void SelectDrivers(impzos::drivers::DriverManager* driverManager, impzos::hardwarecommunication::InterruptManager* interrupts);
            impzos::drivers::Driver* GetDriver(PeripheralComponentInterconnectDeviceDescriptor dev, impzos::hardwarecommunication::InterruptManager* interrupts);
            PeripheralComponentInterconnectDeviceDescriptor GetDeviceDescriptor(impzos::common::uint16_t bus, impzos::common::uint16_t device, impzos::common::uint16_t function);
            BaseAddressRegister GetBaseAddressRegister(impzos::common::uint16_t bus, impzos::common::uint16_t device, impzos::common::uint16_t function, impzos::common::uint16_t bar);
        };

    }
}

#endif