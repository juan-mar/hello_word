#ifndef _TIEMPO_H
#define _TIEMPO_H

/* ----- Bibliotecas externas ----- */
#include <unistd.h>
#include <pthread.h>

/* ----- Constantes de tiempo ----- */
/*
 * Precision del tiempo en millisegundos
 * Valor de 1 a 20
 * */
#define ACCTIME 10

/* ----- Macros de conversion de timepo ----- */
/*Contviete segundos a milis*/
#define STOMS(t) ((t)*1000) 
/*Convierete millis a micros*/
#define MSTOUS(t) ((t)*1000) 

/* ----- estructura tiempo ----- */
/*
 * timer id, con valor de tiempo
 * 
typedef struct{
	const pthread_t timer_id;
	unsigned long int my_timer;
}timer_t;
*/
/* -----  Prototipos de funciones publicas ----- */
/*
 * time_init(), se encarga de inicializar el hilo (thread) del tiempo 
 * Devuelve: 
 * 0 si no hubo errores al momento de crear el hilo. 
 * -1 si no se pudo crear el thread
 * */
int timer_init(void);

/*
 * 
 * 
void timepo_fin(void);
*/

/*
 * get_time(), devuevle el tiempo transcurrido desde que se inicio el tiempo,
 * o desde que se reseteo por ultima vez.
 * Devuelve: la variable tiempo.
 * */
unsigned long int get_timer(void);

/*
 * reset_time(), resetea el contador, dejandolo en 0.
 * 	
 * */
void reset_timer(void);


#endif

