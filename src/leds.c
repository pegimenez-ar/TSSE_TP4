/**
 * @file leds.c
 * 
 * @author Ing. Pablo E. Gimenez
 * 
 * @brief Archivo .c que contiene las implementaciones de las funciones de control del Puerto Led
 *
 **/

#include "leds.h"


#define LSB 0x0001
#define LED_OFFSET 1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF
#define LED_FIRST 1
#define LED_LAST 16
/*Variables globales privadas*/
static uint16_t * puerto;

/**
 * @brief Genera la mascara correspondiente al LED.
 *
 * @param led Número de led.
 * 
 * @return La mascara deseada en uint16_t.
 */
uint16_t LedToMask(int led){
    return LSB << (led -LED_OFFSET);
}

bool LedsCreate(uint16_t *direccion){
    if(NULL == direccion)
        return false;

    puerto = direccion;
    *puerto = ALL_LEDS_OFF;
    return true;
}

bool LedsSetOn(int led){
    if((led < LED_FIRST) || (led > LED_LAST))
        return false;

    *puerto |= LedToMask(led);
    return true;
}

bool LedsSetOff(int led){
    if((led < LED_FIRST) || (led > LED_LAST))
        return false;

    *puerto &= ~LedToMask(led);
    return true;
}

void LedsSetAllOn(void){
    *puerto = ALL_LEDS_ON;
}

void LedsSetAllOff(void){
    *puerto = ALL_LEDS_OFF;
}

ledstatus_t IsLedOn(int led){
    if((led < LED_FIRST) || (led > LED_LAST))
        return -1;

    if(*puerto & LedToMask(led))
        return 1;
    else
        return 0;
}