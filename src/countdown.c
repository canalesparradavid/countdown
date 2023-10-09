/*
 * PROGRAMA: Countdown Counter
 * VERSION: 1.0
 * HISTORICO: Creado el 09/10/2023 por David Canales Parra
 * DESCRIPCION: Este programa crea un temporizador que se puede inicializar con
 *              un tiempo específico pasado como argumento o por consola con el
 *              formato HH:MM:ss
 *              Una vez acabe el tiempo aparecera por pantalla y con color rojo
 *              un texto que diga "Tiempo Agotado" y se podrá cerrar el programa
 *              presionando enter.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "clock.h"

/*
 * FUNCION: extractTime
 * ENTRADA: Un texto que representa tiempo en formato HH:MM:ss
 * SALIDA: Un timestamp en segundos del tiempo indicado
 */
int extractTime(char *formatedTime);

/*
 * ACCION: getFormatedTime
 * ENTRADA: Un reloj y una cadena de texto
 * MODIFICA: Un texto que representa tiempo en formato HH:MM:ss
 */
void getFormatedTime(Clock clock, char *time);

int main(int argc, char **argv) {
    Clock reloj;
    int totalTime;
    char actualTimeString[110];

    if (argc > 1) {
        totalTime = extractTime(argv[1]);
    }
    else {
        char buff[1024];
        printf("Introduzca un tiempo con el formato HH:MM:ss -> ");
        scanf("%[^\n]s", buff);
        totalTime = extractTime(buff);
    }

    printf("\e[2J");

    newClock(&reloj, totalTime);

    while (getTimeHours(reloj) != 0 || getTimeMinutes(reloj) != 0 || getTimeSeconds(reloj) != 0) {
        getFormatedTime(reloj, actualTimeString);
        printf("\r%s", actualTimeString);
        fflush(stdout);
        sleep(1);
        decrement(&reloj);
    }

    char *textos[] = {"\x1b[31mFin del tiempo.\x1b[30m", "               "};
    while (1) {
        for (int i = 0; i < 2; i++) {
            printf("\r%s", textos[i]);
            fflush(stdout);
            usleep(700000);
        }
    }

    return 0;
}

int extractTime(char *formatedTime) {
    char hoursStr[100], minutesStr[3], secondsStr[3];
    int hours, minutes, seconds;

    char *token = strtok(formatedTime, ":");
    if (token != NULL) {
        strcpy(hoursStr, token);
        token = strtok(NULL, ":");
    }
    if (token != NULL) {
        strcpy(minutesStr, token);
        token = strtok(NULL, ":");
    }
    if (token != NULL) {
        strcpy(secondsStr, token);
    }

    hours = atoi(hoursStr);
    minutes = atoi(minutesStr);
    seconds = atoi(secondsStr);

    return hours*3600 + minutes*60 + seconds;
}

void getFormatedTime(Clock clock, char *time) {
    sprintf(time, "%02d:%02d:%02d", getTimeHours(clock), getTimeMinutes(clock), getTimeSeconds(clock));
}
