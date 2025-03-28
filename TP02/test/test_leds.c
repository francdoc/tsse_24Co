/************************************************************************************************
Copyright (c) 2025, Franco Chiesa Docampo <fchiesadoc@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file test_leds.c
 ** @brief Pruebas unitarias de la biblioteca para el control de LEDs
 **/

/**
• @test Prender todos los LEDs de una vez.
• @test Apagar todos los LEDs de una vez.
• @test Consultar el estado de un LED que está encendido.
• @test Consultar el estado de un LED que está apagado.
• @test Revisar limites de los parametros.
• @test Revisar parámetros fuera de los limites.
*/

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

static uint16_t leds_virtuales = 0xFFFF;

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

void setUp(void) {
    LedsInit(&leds_virtuales); // Passes the address of leds_virtuales to port_address.
}

//! @test Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void){
    uint16_t leds_virtuales = 0xFFFF;
    
    LedsInit(&leds_virtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales); // NOTE: Class 3 - 53:15.
}

//! @test Prender un LED individual.
void test_prender_led_individual(void) {   
   LedsTurnOnSingle(4); // Sets *port_address = 0x0008, this updates leds_virtuales. Then in the next line we evaluate leds_virtuales value.
   TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuales); // NOTE: Class 3 - 53:15. |  Verifies the effect of the function call by checking leds_virtuales.
}

//! @test Apagar un LED individual.
void test_apagar_led_individual(void) {
    LedsTurnOnSingle(4);
    LedsTurnOffSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

//! @test Prender y apagar múltiples LED's.
void test_prender_y_apagar_algunos_leds(void) {
    LedsTurnOnSingle(4);
    LedsTurnOnSingle(6);

    LedsTurnOffSingle(4);
    LedsTurnOffSingle(8);

    TEST_ASSERT_EQUAL_HEX16(0x0020, leds_virtuales); // Led ON should be 5 -> 0x0020, but LedsTurnOffSingle is wrong because it shuts down all leds panel
}

/* === End of documentation ==================================================================== */