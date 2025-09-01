#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int num1=0, num2=1 , out = num1 + num2 , in, i = 1;
printf("Enter a positive integer to print Fibonacci sequence: ");
scanf("%d", &in);

 if(in < 0){

printf("ERROR invalid number. Please give a valid input.");

}else{

pid_t pid = fork();
if (pid == 0)   {              // child process. Here print out the Fibonacci numbers.
printf("Child process process id = %d\n",getppid());
printf("fib%d = %d\n", num1 , num1);

while (i <= in){
printf("fib%d = %d\n", i, out);
out = num1 + num2;
num1 = num2;
num2 = out;
i++;
if (i > in){ // parent process

printf("Child process terminated\n");
}
}
}else{
printf("Parent process id = %d\n",getppid());
printf("Parent process is at waiting state.\n");
waitpid(pid, NULL, 0);
printf("Parent process terminated.\n");

}
} return 0;

}
