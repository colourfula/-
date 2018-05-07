1 #include<unistd.h>
  2 #include<sys/wait.h>
  3 #include<stdio.h>
  4 #include<stdlib.h>
  5 #include<string.h>
  6 
  7 char* argv[8];
  8 int argc;
  9 
 10 void do_parse(char* buf)
 11 {
 12  int i;
 13  int status = 0;
 14  
 15  for(argc = i = 0;buf[i] ;i++){
 16     if(!isspace(buf[i]) && status == 0){
 17         argv[argc++] == buf+i;
 18         status = 1;
 19      }else if(isspace(buf[i])){
 20         status = 0;
 21         buf[i] = 0;
 22      }
 23   }
24  argv[argc] = NULL;
 25 }
 26 
 27 void do_execute(void)
 28 {
 29   pid_t pid = fork();
 30   switch(pid){
 31     case -1:
 32        perror("fork");
 33        exit(EXIT_FAILURE);
 34        break;
 35     case 0:
 36        execvp(argv[0],argv);
 37        perror("execvp");
 38        exit(EXIT_FAILURE);
 39     default:
 40       {
 41        int st;
 42        while(wait(&st) != pid)
 43              ;
 44       }
 45   }
 46 }
 47 
 48 int main(void)
 49 {
 50   char buf[1024] = {};
 51   while(1){
 52     printf("myshell-> ");
 53     scanf("%[^\n]%*c",buf);
 54     do_parse(buf);
 55     do_execute();
 56   }
 57 }
                     
