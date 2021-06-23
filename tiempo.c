/*
 *	MODULO TIMEPO
 *
 */
#include "tiempo.h"
/*variable timepo propia del modulo*/
static unsigned long int var_tm;

/*prototipos propios del modulo*/
static void * tiempo(void *arg);	

/*
 * Thread que acumula tiempo
 * */
static void * tiempo(void *arg){
	while(1){
		usleep(MSTOUS(ACCTIME));
		var_tm+=ACCTIME;/* acumulo tiempo equivalente a la presicion dada en compilacion */
	}
//	return NULL;
}

/*Inicializacion de timpo*/
int tiempo_init(void){
	int error;
	pthread_t tiempo_th;
	error=pthread_create(&tiempo_th,NULL,tiempo,NULL);
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
unsigned long int get_tiempo(void){
	return var_tm;
}

/*
 *funcion para resetear el tiempo
 * */
void reset_tiempo(void){
	var_tm=0;
}


