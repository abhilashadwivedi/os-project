#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#define MAX_CUSTOMERS 20

void *customer(void *num);
void *barber(void *);

void r_wait(int secs);
sem_t waitingRoom;

sem_t barberChair;

sem_t barber_sleep;

sem_t seat;

int jobDone = 0;

int main(int argc, char *argv[]) {
pthread_t btid;
pthread_t tid[MAX_CUSTOMERS];
int Number[MAX_CUSTOMERS];
int i, numCustomers, numChairs;

printf("Enter the number of Customers : ");
scanf("%d",&numCustomers) ;
printf("Enter the number of Chairs : ");
scanf("%d",&numChairs);

if (numCustomers > MAX_CUSTOMERS) {
printf("The maximum number of Customers is %d.\n", MAX_CUSTOMERS);
exit(-1);
}

for (i=0; i<MAX_CUSTOMERS; i++) {
Number[i] = i;
}

sem_init(&waitingRoom, 0, numChairs);
sem_init(&barberChair, 0, 1);
sem_init(&barber_sleep,0, 0);
sem_init(&seat, 0, 0);

pthread_create(&btid, NULL, barber, NULL);

for (i=0; i<numCustomers; i++) {
pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
sleep(1);
}

for (i=0; i<numCustomers; i++) {
pthread_join(tid[i],NULL);
sleep(1);
}

jobDone = 1;
sem_post(&barber_sleep);
pthread_join(btid,NULL);
}

void *customer(void *number) {
int num = *(int *)number;

printf("Customer number %d leaving for barber shop.\n", num);
r_wait(2);
printf("Customer number %d arrived at barber shop.\n", num);


sem_wait(&waitingRoom);
printf("Customer number %d entering waiting room.\n", num);

sem_wait(&barberChair);

sem_post(&waitingRoom);

printf("Customer number %d waking the barber.\n", num);
sem_post(&barber_sleep);

sem_wait(&seat);

sem_post(&barberChair);
printf("Customer number %d leaving barber shop.\n", num);
}

void *barber(void *junk) {

while (!jobDone {

printf("The barber is sleeping\n");
sem_wait(&barber_sleep);

if (!jobDone {

printf("The barber is cutting hair\n");
r_wait(2);
printf("The barber has finished his job of cutting hair.\n");

sem_post(&seat);
}
else {
printf("The barber is not working and going home for the day.\n");
}
}
}

void r_wait(int secs) {
int len;

len = (int) ((1 * secs) + 1);
sleep(len);
}


