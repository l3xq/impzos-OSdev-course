#ifndef __impzos__GDT_H
#define __impzos__GDT_H

#include <common/types.h>

namespace impzos{

    class GlobalDescriptorTable
    {
        public:
            // ova nestovana klasa mora da bude byte-perfect zato se koristi
            //  attribute--packed da bi kompajler izricito pratio zadate instrukcije
            class SegmentDescriptor
            {
                private:
                    impzos::common::uint16_t limit_lo;    // ogranicenje nizih bajtova
                    impzos::common::uint16_t base_lo;     // lo bajt pokazivaca
                    impzos::common::uint8_t base_hi;      // hi bajt produzetak pokazivaca
                    impzos::common::uint8_t type;         // bajtovi za dozvole pristupa
                    impzos::common::uint8_t limit_hi;     // ogranicenje visih bajtova
                    impzos::common::uint8_t base_vhi;     // hi bajt pokazivaca

                public:
                    // konstruktor za kupljenje podataka kao 32bit_int, za jednostavniju dalju manipulaciju
                    SegmentDescriptor(impzos::common::uint32_t base, impzos::common::uint32_t limit, impzos::common::uint8_t type);

                    // Metode za vracanje baze i limita na originalne velicine
                    impzos::common::uint32_t Base();
                    impzos::common::uint32_t Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            // postojace samo po jedan code i data segment, koji ce alocirati kompletnu memoriju
            //  radi lakse manipulacije
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            // kupi se offset code/data segment descriptor-a
            impzos::common::uint16_t CodeSegmentSelector();
            impzos::common::uint16_t DataSegmentSelector();
    };

}

#endif