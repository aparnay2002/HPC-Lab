#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 1 or n == 0)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void *func(void *arg)
{
    int n;
    cout << "\nEnter a number : ";
    cin >> n;
    cout << "\nFibonnaci series is : ";
    for (int i = 0; i <= n; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;

    pthread_exit(NULL);
}

int main()
{

    pthread_t ptid;
    // cout<<" Thread id is : "<<ptid<<endl;
    //   ptid thread address
    // Is the location where the ID of the newly created thread should be stored,
    // or NULL if the thread ID is not required.

    // attribute
    // thread attribute for the thread that is being created.
    // If attr is NULL, the thread is created with default attributes.

    // func this is a function which is called on thread

    // argc arguments passed to this func
    pthread_create(&ptid, NULL, &func, NULL); 

    printf("\nThis line may be printed before thread terminates\n");

    //  The pthread_join() function shall suspend execution of the calling thread
    // until the target thread terminates
    pthread_join(ptid, NULL); // Waiting for the created thread to terminate

    printf("\nThis line will be printed after thread ends\n");

    pthread_exit(NULL);
    return 0;
}

