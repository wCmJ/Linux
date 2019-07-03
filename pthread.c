pthread_:   pthread_create(), pthread_join(), pthread_detach()
pthread_attr_:
pthread_mutex_: pthread_mutex_t, pthread_mutex_init(), pthread_mutex_lock(), pthread_mutex_unlock(), pthread_mutex_destroy()
pthread_mutexattr_:
pthread_cond_:  pthread_cond_t, pthread_cond_wait(), pthread_cond_signal(),
pthread_condattr_:
pthread_key_:


pthread_t tid;
typedef unsigned long int pthread_t;

pthread_create();
#include<pthread.h>
int pthread_create(pthread_t *tid, const pthread_attr_t *tarrt, void*(*start_routine)(void*), void* arg);
pthread_attr_t() tarrt;
pthread_t tid;
extern void* start_routine(void* arg);
void *arg;
int ret;
ret = pthread_create(&tid, NULL, start_routine, arg);//ret == 0 success, otherwise fail.
ret = pthread_attr_init(&tattr);
ret = pthread_create(&tid, &tattr, start_routine, arg);

pthread_join():阻塞调用线程，直到指定的线程终止
int pthread_join(pthread_t tid, void **status);
#include<pthread.h>
pthread_t tid;
void *status;
ret = pthread_join(tid, &status);
//指定的线程必须位于当前的进程中，而且不得是分离线程。 当status不是NULL时，status指向某个位置，
//多个线程等待同一个线程终止，一个等待线程成功返回，其余的线程将失败并返回ESRCH错误。
//ESRCH:没有找到与给定的线程ID相对应的线程
//EDEADLK:出现死锁，如一个线程等待其本身(实验验证并未死锁)，或者A和B互相等待。

