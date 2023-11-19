#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include <mosquitto.h>
#include <mqtt_protocol.h>

struct mosquitto *g_mosq = NULL;
int sensorco=20,sensorco2=10,sensornh3=5;
void timer_callback(int signum)
{
	char output[10];
	sprintf(output, "%d %s", sensorco," ppm");
	mosquitto_publish(g_mosq,NULL,"SensorCO",11,output,1,false);
	sensorco++;
	if(sensorco >25)
	{
		sensorco=20;
	}
	sprintf(output, "%d %s", sensorco2," ppm");
	mosquitto_publish(g_mosq,NULL,"SensorCO2",11,output,1,false);
	sensorco2++;
	if(sensorco2 >15)
	{
		sensorco2=10;
	}
	sprintf(output, "%d %s", sensornh3," ppm");
	mosquitto_publish(g_mosq,NULL,"SensorNH3",11,output,1,false);
	sensornh3++;
	if(sensornh3 >10)
	{
		sensornh3=5;
	}
}
  
int main()
{
	struct sigaction sa;
	struct itimerval timer;
	int rc;
	void *ptr=NULL;
	mosquitto_lib_init();
	
	g_mosq = mosquitto_new(NULL,true,ptr);
	if(!g_mosq){
		goto cleanup;
	}
	
	rc = mosquitto_connect(g_mosq,"ayyappan-Inspiron-5559",1883,10);
	if(rc){
		goto cleanup;
	}
	
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &timer_callback;
	
	timer.it_value.tv_sec = 5;
	timer.it_value.tv_usec = 0;

	timer.it_interval.tv_sec = 4;
	timer.it_interval.tv_usec = 0;
	sigaction (SIGALRM, &sa, NULL);
	setitimer (ITIMER_REAL, &timer, NULL);
	//signal(SIGALRM, timer_callback);
	
	rc = mosquitto_loop_forever(g_mosq, -1, 1);

	mosquitto_destroy(g_mosq);
	mosquitto_lib_cleanup();

cleanup:
	mosquitto_destroy(g_mosq);
	mosquitto_lib_cleanup();
	return 0;
}
