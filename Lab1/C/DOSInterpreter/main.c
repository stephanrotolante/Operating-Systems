#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char command[4];
    char cd[]="cd";
    char dir[]="dir";
    char type[]="type";
    char del[]="del";
    char ren[]="ren";
    char copy[]="copy";
    char  exit[]="exit";
    int switcher;
    while(1>0) {
        printf("*************************** \n"
               "These are the commands:\n"
               "cd: Change directory\n"
               "dir: See contents of current directory\n"
               "type: See contents of file\n"
               "del: Delete file\n"
               "ren: Rename file\n"
               "copy: Copy file\n"
               "Please enter one: ");
        scanf("%s", command);

       if(strcmp(command,cd)==0){
            switcher =0;
        } else if(strcmp(command,dir)==0){
            switcher=1;
        } else if(strcmp(command,type)==0) {
            switcher=2;
        } else if(strcmp(command,del)==0) {
            switcher=3;
        } else if(strcmp(command,ren)==0) {
            switcher=4;
        } else if (strcmp(command,copy)==0) {
            switcher=5;
        } else if(strcmp(command,exit)==0){
            printf("Exiting...\n");
            break;
        } else {
            switcher=-1;
            printf("Command does not exist\n");
        }

        char arg1[100]="";
        char arg2[100]="";
        char space[]=" ";
        char result[300]="";

        switch (switcher){
            case -1:
                //breakout
                break;
            case 0 :
                printf("Please choose a directory you would like to change to: ");
                scanf("%s", arg1);
                strcat(result,command);
                strcat(result,space);
                strcat(result,arg1);
                printf("Changing to %s \n",result);
                system(result);
                system("ls");
                //cd
                break;
            case 1 :
                //ls
                system("ls");
                break;
            case 2 :
                printf("Please select a file you would like to peak at: ");
                scanf("%s", arg1);
                strcat(result,"cat");
                strcat(result,space);
                strcat(result,arg1);
                system(result);
                printf("Peaking at %s \n",result);
                //cat
                break;
            case 3 :
                printf("Please select a file you would like to remove: ");
                scanf("%s", arg1);
                strcat(result,"rm");
                strcat(result,space);
                strcat(result,arg1);
                system(result);
                printf("Removing %s \n",result);
                //rm
                break;
            case 4 :
                printf("Please select a file you would like to rename and enter the new name: ");
                scanf("%s %s", arg1, arg2);
                strcat(result,"mv");
                strcat(result,space);
                strcat(result,arg1);
                strcat(result,space);
                strcat(result,arg2);
                system(result);
                printf("Renaming %s \n",result);
                //mv
                break;
            case 5 :
                printf("Please select a file you would like to copy and the folder you'd like it copied to: ");
                scanf("%s %s", arg1, arg2);
                strcat(result,"mv");
                strcat(result,space);
                strcat(result,arg1);
                strcat(result,space);
                strcat(result,arg2);
                system(result);
                printf("Copying %s \n",result);
                //cp
                break;
        }

    }

    return 0;
}