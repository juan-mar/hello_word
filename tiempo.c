/*
 *	source tiempo.c
 *
 */
#include "tiempo.h"
/*variable timepo propia del modulo*/
static unsigned long int var_tm;

/*prototipos propios del modulo*/
static void * mgr_timer(void *arg);	

/*
 * Thread que acumula tiempo
 * */
static void * mgr_timer(void *arg){
	while(1){
		usleep(MSTOUS(ACCTIME));
		var_tm+=ACCTIME;/* acumulo tiempo equivalente a la presicion dada en compilacion */
	}
//	return NULL;
}

/*Inicializacion de timpo*/
int timer_init(void){
	int error;
	pthread_t timer_th;
	error=pthread_create(&timer_th,NULL,mgr_timer,NULL);
//	pthread_join(tiempo_th,NULL);
	return error; /*error=0 implica que se pudo crear el thread de tiempo correctamente*/
}

/*Terminador de conctador de tiempo
void tiempo_fin(void){
	pthread_exit();

}*/

/*
 * funcion para devolver el tiempo trasncurrido
 * */
unsigned long int get_timer(void){
	return var_tm;
}

/*
 *funcion para resetear el tiempo
 * */
void reset_timer(void){
	var_tm=0;
}


