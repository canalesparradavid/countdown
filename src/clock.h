/*
 * LIBRERIA: Reloj
 * FICHERO: clock.h
 * VERSION: 1.0
 * HISTORICO: Creado el 09/10/2023 por David Canales Parra
 * DESCRIPCION: Este modulo simula el funcionamiento de un reloj permitiendo
 *              hacer que pase el tiempo o echarlo hacia atrás.
 */

#ifndef HH_CLOCK_DCP
#define HH_CLOCK_DCP

typedef struct clock {
    int time;
} Clock;

/*
 * ACCION: newClock
 * ENTRADA: Un reloj sin inicializar y una hora
 * MODIFICA: Inicializa un reloj a la hora especificada
 */
void newClock(Clock *clock, int time);

/*
 * FUNCION: getTotalTime
 * ENTRADA: Un reloj inicializado
 * SALIDA: El tiempo total en segundos del reloj
 */
int getTotalTime(Clock clock);

/*
 * FUNCION: getTimeHours
 * ENTRADA: Un reloj inicializado
 * SALIDA: Las horas del reloj
 */
int getTimeHours(Clock clock);

/*
 * FUNCION: getTimeMinutes
 * ENTRADA: Un reloj inicializado
 * SALIDA: Los minutos del reloj
 */
int getTimeMinutes(Clock clock);

/*
 * FUNCION: getTimeSeconds
 * ENTRADA: Un reloj inicializado
 * SALIDA: Los segundos del reloj
 */
int getTimeSeconds(Clock clock);

/*
 * ACCION: increment
 * ENTRADA: Un reloj inicializado
 * MODIFICA: Añade un segundo al reloj
 */
 void increment(Clock *clock);

 /*
  * ACCION: decrement
  * ENTRADA: Un reloj inicializado
  * MODIFICA: Quita un segundo al reloj
  */
  void decrement(Clock *clock);

#endif
