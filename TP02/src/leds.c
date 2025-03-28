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

/** @file leds.c
 ** @brief Definición de la biblioteca para el control de LEDs
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */
 
/** @brief Máscara para apagar todos los LEDs */
#define ALL_LEDS_OFF      0x0000

/**
 * The macro LEDS_TO_BIT_OFFSET is used instead of a plain -1 to convert from a 1-based LED index
 * (LEDs numbered from 1 to 16) to a 0-based bit position (bit 0 to 15). This practice improves
 * code readability and self-documentation, making it clear why the subtraction is needed.
 * Using a named constant avoids the use of "magic numbers" like -1, which can obscure intent.
 * It also centralizes the logic, making it easier to adapt if LED numbering conventions change
 * in the future.
 */
/** @brief Diferencia entre el número de led y el número de bit */
#define LEDS_TO_BIT_OFFSET 1

/** @brief Constante con el primer bit en uno para generar una máscara */
#define FIRST_BIT         1

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/** @brief Variable privada para almacenar la direccíon del puerto de salida */
static uint16_t * port_address;

/* === Private function declarations =========================================================== */

/**
 * @brief función privada para convertir el número de un led en una máscara de bits
 * 
 * @param led Número de led para el que se desea generar la máscara de bits
 * @return uint16_t Máscara de bits con 1 en la posición correspondiente al led
 */
static uint16_t LedToMask(uint8_t led);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
uint16_t LedToMask(uint8_t led) {
    return (FIRST_BIT << (led - LEDS_TO_BIT_OFFSET)); // Mask that gives a 1 according to input.
}

/* === Public function implementation ========================================================== */
void LedsInit(uint16_t * direccion){
    port_address = direccion;
    *port_address = ALL_LEDS_OFF;
}

void LedsTurnOnSingle(uint8_t led) {
    *port_address |= LedToMask(led);
}

void LedsTurnOffSingle(uint8_t led) {
    *port_address &= ~LedToMask(led); // 0b00001000 becomes 0b11110111 to gain precision shutting down specific led.
}

// TODO: IsLedTurnedOnLeds() True | False

/* === End of documentation ==================================================================== */