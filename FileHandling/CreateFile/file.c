#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
int main() {
int result = mkdir("/home/sriq/Rome", 0777);		//creates a directory named Rome

DIR *Rome;						//pointer to the directory
FILE *fp;						//pointer to a file

    Rome = opendir(".");
    if(Rome) {
	fp=fopen("/home/sriq/Rome/file.txt","a");	//creates file.txt if Rome available.
	fclose(fp);					//closes file
    }
    closedir(Rome);					//closes the directory

    return(0);
}
