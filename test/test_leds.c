/**
 * @file test_leds.c
 * 
 * @author Ing. Pablo E. Gimenez
 *
 * @brief Archivo de configuracion de Test en Ceedling para Led Port
 * 
 **/

#include "leds.h"
#include "unity.h"

/** Lista de test desarrollados
 * 1 - Inicializacion de leds en puerto
 * 2 - Prender un LED individual
 * 3 - Apagar un LED individual
 * 4 - Prender y apagar varios LEDs
 * 5 - Apagar TODOS los LEDs
 * 6 - Encender TODOS los LEDs
 * 7 - Consultar por un LED encendido
 * 8 - Consultar por un LED apagado
 * 9 - Verificar limites de los parametros
 * 10 - Verificar parametros fuera de limites
 * 11 - Verificación de puntero nulo
 **/

/**Definición de variables globales */
static uint16_t puerto_virtual;

// Se ejecutan antes de cada prueba
void setUp(void){
    
    LedsCreate(&puerto_virtual);

}

// Se ejecutan luego de cada prueba
void tearDown(void){
}

// Test 1: Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void){
    uint16_t puerto_virtual = 0xFFFF;

    LedsCreate(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Test 2: Prender un LED individual.
void test_prender_un_led_individual(void){

    TEST_ASSERT_TRUE(LedsSetOn(3));
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// Test 3: Apagar un LED individual.
void test_prender_y_apagar_un_led_individual(void){

    TEST_ASSERT_TRUE(LedsSetOn(3));
    TEST_ASSERT_TRUE(LedsSetOff(3));

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Test 4: Prender y apagar multiples LEDs.
void test_prender_y_apagar_varios_leds(void){

    TEST_ASSERT_TRUE(LedsSetOn(5));
    TEST_ASSERT_TRUE(LedsSetOff(2));
    TEST_ASSERT_TRUE(LedsSetOn(7));
    TEST_ASSERT_TRUE(LedsSetOff(7));

    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// Test 5: Prender todos los LEDs de una vez.
void test_apagar_todos_LEDs(void){

    LedsSetAllOn();

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// Test 6: Apagar todos los LEDs de una vez.
void test_perder_todos_LEDs(void){

    LedsSetAllOff();

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

 // Test 7: Consultar el estado de un LED que está encendido.
 void test_consultar_estado_encendido(void){

    TEST_ASSERT_TRUE(LedsSetOn(9));
    TEST_ASSERT_EQUAL_INT(1,IsLedOn(9));
 }

 // Test 8: Consultar el estado de un LED que esta apagado.
 void test_consultar_estado_apagado(void){
    
    TEST_ASSERT_EQUAL(0,IsLedOn(9));
 }

 // Test 9: Verificar limites de los parametros
void test_verificar_limites_parametros(void){

    TEST_ASSERT_TRUE(LedsSetOn(1));
    TEST_ASSERT_TRUE(LedsSetOn(16));
    TEST_ASSERT_EQUAL_HEX16(1 << 0 | 1 << 15, puerto_virtual);
}

// Test 10: Verificar parametros fuera de limites
void test_verificar_parametros_fuera_limites(void){
    
    TEST_ASSERT_FALSE(LedsSetOn(0));
    TEST_ASSERT_FALSE(LedsSetOn(17));
    TEST_ASSERT_FALSE(LedsSetOn(-100));

    TEST_ASSERT_FALSE(LedsSetOff(0));
    TEST_ASSERT_FALSE(LedsSetOff(17));
    TEST_ASSERT_FALSE(LedsSetOff(-100));

    TEST_ASSERT_EQUAL_INT(-1,IsLedOn(19));
}

// Test 11: Verificación de puntero nulo
void test_verificar_puntero_nulo(void){
    uint16_t *puntero_nulo = NULL;
 
    TEST_ASSERT_FALSE(LedsCreate(puntero_nulo));
}
