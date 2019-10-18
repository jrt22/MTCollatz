nclude <iostream>
#include <pthread.h>
#include <ctime>
#include <string>
#include <cstdlib>


using namespace std;

//Functions
int collatz(int i);
void *mainThread(void *param);

//Global Variables
pthread_mutex_t lock;
int counter;
int histogram[1000];


int main(int argc, char** argv)
{
    clock_t stop, start=clock();
    int range = atoi(argv[1]);
    int threads = atoi(argv[2]);

    //checks for invalid commands
    if(range<2||threads<1)
        return -1;

    //initialize variables
    pthread_mutex_init(&lock, NULL);
    pthread_t t[threads];
    counter=2;

    int i;
    for(i=0; i<threads; i++) //creates threads, outputs error code if thread fails to create
    {
        if(pthread_create(&t[i], NULL, &mainThread, (void *)range))
        {
            cout << "ERROR: Unable to create thread: " << i <<  endl;
            return -1;
        }
    }


    for(i=0; i<threads; i++) //destroys threads, outputs error code if thread fails to join
    {
        if(pthread_join(&t[i], NULL))
        {
            cout << "ERROR: Unable to join thread: " << i <<  endl;
            return -1;
        }
        cout<< "Joined thread: " << i << endl;
    }
    stop = clock();

    cout << range << "," << threads << "," << stop-start << endl;

    return 0;
}


int collatz(int i)
{
    if(i<1)
    {
        cout << "ERROR: Negative Collatz Number" << endl;
        return -1;
    }
    int x=0;
    while(i>1)
    {
        if(i%2)
            i=3*i+1;
        else
            i=i/2;
        x++;
    }
    return x;
}


void *mainThread(void *param)
{
    int range = (int)param;
    int current, freq;

    pthread_mutex_lock(&lock);
    current= counter++;
    while(counter<=range)
    {
        pthread_mutex_unlock(&lock);

        //not critical section of thread
        freq=collatz(current);
        if(freq>999)
            freq=999;

        pthread+mutex_lock(&lock);
        histogram[freq]++;
        current=counter++;
    }
    pthread_mutex_unlock(&lock);
    pthread_exit();
}
