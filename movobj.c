#include <stdio.h>
#include "tiempo.h"
#define V1 10
#define V2 20

int main(void){
	int obj1=0,obj2=0, error;
	error=timer_init();
	if(error==0){
		unsigned long int prevtime1,prevtime2;
		int llegada1=0,llegada2=0;
		while(llegada1==0 || llegada2==0){
			/*objeto 1 */
			if(((get_timer()-prevtime2)>=50)&&(llegada2==0)){ /*50 ms*/
				prevtime2=get_timer();
				obj2++;
			}
			if(((get_timer()-prevtime1)>=100)&&(llegada1==0)){ /*100 ms*/
				prevtime1=get_timer();
				obj1++;
				printf("pos obj1: %d ; Tiempo parcial %ld\n",obj1,get_timer());
			}
			if(obj2==100 && llegada2==0){
				llegada2=1;
				printf("Llegada obj2 ; Tiempo: %ld \n",get_timer());
			}
			if(obj1==100 && llegada1==0){
				llegada1=1;
				printf("Llegada obj1 ; Tiempo: %ld \n",get_timer());
			}
		}	
				
	}
	else{
		return -1;
	}
	return 0;
}
