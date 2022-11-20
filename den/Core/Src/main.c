#define RCCAHB1ENR *((unsigned volatile int *) 0x40023830U)
#define gpiodmodregister *((unsigned volatile int *) 0x40020c00U)
#define gpioddataregister *((unsigned volatile int *) 0x40020c14U)

char my_name[]="aslican";
char my_surname[]="kayikci";

int y,z=0; //letter counters for blinking
int colour1,colour2; //the led colours according to the mod of the name&surname
int sum,summ=0; //ascii sums of name&surname

void ascii_finder(char a[99],char b[99])
{
    while(a[z]!='\0'){
        sum+=a[z];
        z++;
    }
    colour1=sum%4;
    while(b[y]!='\0'){
        summ+=b[y];
        y++;
    }
    colour2=summ%4;
}
void delay(){
	int delay0 = 0xdcdc9;
	while (delay0--){
		}
}
void init_led () {
	 	//RCCAHB1ENR = 0x8;
	RCCAHB1ENR = 1<<3;
}
void turn_name_on(){
	    if(colour1==0){
	    gpiodmodregister |= 1<<28;
	    gpioddataregister |= 1<<14;
	    }
	    else if(colour1==1){
	    gpiodmodregister |= 1<<30;
	    gpioddataregister |= 1<<15;
	   	}
	    else if(colour1==2){
	    gpiodmodregister |= 1<<26;
	    gpioddataregister |= 1<<13;
		}
		else if(colour1==3){
	    gpiodmodregister |= 1<<24;
	    gpioddataregister |= 1<<12;
		}
}
void turn_surname_on(){
	    if(colour2==0){
	    gpiodmodregister |= 1<<28;
	    gpioddataregister |= 1<<14;
	    }
	    else if(colour2==1){
	    gpiodmodregister |= 1<<30;
	    gpioddataregister |= 1<<15;
	   	}
	    else if(colour2==2){
	    gpiodmodregister |= 1<<26;
	    gpioddataregister |= 1<<13;
		}
		else if(colour2==3){
	    gpiodmodregister |= 1<<24;
	    gpioddataregister |= 1<<12;
		}
}
void turn_name_off(){
		gpioddataregister=0x0000u;
}
void turn_surname_off(){
		gpioddataregister=0x0000u;
}

int main(){

	ascii_finder(my_name,my_surname);

	init_led();

	int a,b;
	for(a=0;a<z;a++){
		turn_name_on();
		delay();
		turn_name_off();
		delay();
	}
	for(b=0;b<y;b++){
		turn_surname_on();
		delay();
		turn_surname_off();
		delay();
	}

	return 0;

}
