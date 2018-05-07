  1 #include<stdio.h>
  2 #include<unistd.h>
  3 
  4 int main()
  5 {
  6   int i=0;
  7   char bar[102];
  8   memset(bar,0,sizeof(bar));
  9   const char* lable = "|/_\\";
 10   while(i<=100){
 11     printf("[%-100s][%d%%][%c]\r",bar,i,lable[i%4]);
 12     fflush(stdout);
 13     bar[i++] = '#';
 14     usleep(10000);
 15   }
 16   printf("\n");
 17   return 0;
 18 }
~             
