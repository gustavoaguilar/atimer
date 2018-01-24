#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
//Compare two strings
int strComp(const char str1[], const char str2[]){
  int i=0, j=0;
  while(str1[i] != '\x0' && str2[j] != '\x0'){

    if(str1[i] != str2[j]) return 1;
    i++;
    j++;
  }
  if(str1[i] == '\x0' && str2[j] == '\x0'){
    return 0;
  }else{
    return 1;
  }
}
//Convert string to integer
int strToInt(const char str[]){
  int n=0, size = strlen(str), i;
  for(i=0; i<size; i++){
    n = n*10+(str[i]-'0');
  }
  return n;
}

int main(int argc, char const *argv[]) {
  int hours = 0, minutes = 0, seconds = 0;
  char command[100] = "notify-send aTimer FINISHED";

  //Read the arguments
  int i;
  for(i=1; i<argc; i++){
    if(!strComp(argv[i], "-h")){
      hours = strToInt(argv[i+1]);
      i++;
    }
    else if(!strComp(argv[i], "-m")){
      minutes = strToInt(argv[i+1]);
      i++;
    }
    else if(!strComp(argv[i], "-s")){
      seconds = strToInt(argv[i+1]);
      i++;
    }
    else if(!strComp(argv[i], "-a")){
      strcpy(command, argv[i+1]);
      i++;
    }
  }
  //Timer loop
  while(seconds >= 0){
    printf("Time left: %4d hours %2d minutes %2d seconds\n",hours, minutes, seconds);
    seconds--;
    if(seconds == 0){
      if(minutes > 0){
         minutes--;
         seconds = 60;
      }else break;
    }
    if(minutes == 0){
      if(hours > 0){
         hours--;
         minutes = 60;
      }
    }
    sleep(1);
  }
  sleep(1);
  //Execute the command
  system(command);

  return 0;
}
