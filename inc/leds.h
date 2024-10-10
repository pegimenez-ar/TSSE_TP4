/**
 * @file leds.h
 * 
 * @author Ing. Pablo E. Gimenez
 * 
 * @brief Archivo .h que contiene las declaraciones de las funciones de control del Puerto Led
 *
 **/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef enum {
  ON = 1,
  OFF = 0,
  ERROR = -1,
} ledstatus_t;

/**
 * @brief Inicializa el puerto y coloca todos los leds apagados.
 *
 * @param puerto Puntero al puerto LED.
 * 
 * @return true Si se ha podido inicializar el puerto corectamente.
 * 
 * @return false Si ha ocurrido error y no se ha podido inicializar el puerto correctamente.
 */
bool LedsCreate(uint16_t *puerto);

/**
 * @brief Enciende un LED en particular.
 *
 * @param led Número de led que se desea encender.
 * 
 * @return true Si se ha podido encender el led corectamente.
 * 
 * @return false Si ha ocurrido error y no se ha podido encender el led correctamente.
 */
bool LedsSetOn(int led);

/**
 * @brief Apagaa un LED en particular.
 *
 * @param led Número de led que se desea apagar.
 * 
 * @return true Si se ha podido apagar el led corectamente.
 * 
 * @return false Si ha ocurrido error y no se ha podido apagar el led correctamente.
 */
bool LedsSetOff(int led);

/**
 * @brief Enciende todos los LEDs.
 * 
 */
void LedsSetAllOn(void);

/**
 * @brief Apaga todos los LEDs.
 * 
 */
void LedsSetAllOff(void);

/**
 * @brief Consulta el estado de un led en particular.
 *
 * @param led Número de led que se desea obtener estado.
 * 
 * @return 1 Si el led se encuentra encendido.
 * 
 * @return 0 Si el led se encuentra apagado.
 * 
 * @return -1 Si ha ocurrido error y no se ha podido leer el led correctamente.
 */
ledstatus_t IsLedOn(int led);