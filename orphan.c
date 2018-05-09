1 #include<stdio.h>
  2 #include<stdlib.h>
  3 #include<unistd.h>
  4 
  5 int main()
  6 {
  7  pid_t id = fork();
  8  if(id<0){
  9   perror("fork");
 10   return 1;
 11  }
 12  else if(id == 0){
 13   printf("i am child,pid:%d\n",getpid());
 14   sleep(10);
 15  }else{
 16   printf("i am parent,pid:%d\n",getpid());
 17   sleep(3);
 18   exit(0);
 19  }
 20  return 0;
 21 }
