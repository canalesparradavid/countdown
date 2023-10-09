/*
 * LIBRERIA: Reloj
 * FICHERO: clock.c
 * VERSION: 1.0
 * HISTORICO: Creado el 09/10/2023 por David Canales Parra
 * DESCRIPCION: Este modulo simula el funcionamiento de un reloj permitiendo
 *              hacer que pase el tiempo o echarlo hacia atrás.
 */

#include "clock.h"

void newClock(Clock *clock, int time) {
    clock->time = time;
}

int getTotalTime(Clock clock) {
    return clock.time;
}

int getTimeHours(Clock clock) {
    return (int)(clock.time / (60*60));
}

int getTimeMinutes(Clock clock) {
    return clock.time % (60*60) / 60;
}

int getTimeSeconds(Clock clock) {
    return  clock.time % 60;
}

void increment(Clock *clock) {
    clock->time += 1;
}

void decrement(Clock *clock) {
    if (clock->time == 0) return;

    clock->time -= 1;
}
