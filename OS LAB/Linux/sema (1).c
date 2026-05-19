#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
sem_t mutex;
int main(int argc, char *argv[]) {
sem_init(&mutex, 1, 1);
int rc1 = fork();
int rc2 = fork();
if (rc1 == 0) {
// In the first child process
printf("Child Process (pid = %d, parent pid = %d)\n", getpid(), getppid());
} else if (rc2 == 0) {
printf("Child Process (pid = %d, parent pid = %d)\n", getpid(), getppid());
} else {
printf("Parent Process (pid = %d)\n", getpid());
}
// Each process prints twice
for (int i = 0; i < 2; i++) {
sem_wait(&mutex);
printf("Hello from (pid = %d)\n", (int)getpid());
sem_post(&mutex);
}
return 0;
}