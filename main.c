#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
void main()
{

    char path[127],new_name[127],new_path[255],old_path[255];

    printf("Give me your folder path :");
    fgets(path,sizeof(path),stdin);

    path[strcspn(path,"\n")]='\0';

    printf("Give me your new name :");
    fgets(new_name,sizeof(new_name),stdin);

    new_name[strcspn(new_name,"\n")]='\0';

    DIR *d;
    int i=1;
    char it[4]={'0','0','1','\0'};
    struct dirent *dir;

    d=opendir(path);

    if(d!=NULL){

        printf("The folder has this files :\n");

        while ((dir = readdir(d)) != NULL){

            if((strcmp(dir->d_name,".") != 0 ) && (strcmp(dir->d_name,"..") != 0)){

                printf("%s\\%s\n",path,dir->d_name);
                sprintf(old_path,"%s/%s",path,dir->d_name);
                //snprintf(it, sizeof(it), "%03d", i);
                if(i<10){
                     it[2]='0'+i;

                }else{
                    if(i>10 && i<100){
                        it[0] = '0';
                        it[1]='0'+(i/10);
                        it[2]='0'+(i%10);
                    }
                    else{
                        it[0]='0'+i/100;
                        it[1]='0'+((i/10)%10);
                        it[2]='0'+(i%10);
                    }
                }

                sprintf(new_path,"%s/%s %s.mp4",path,new_name,it);

                if (rename(old_path,new_path) == 0){
                    printf("Renamed: %s -> %s\n", old_path, new_path);
                    i++;


                }else{
                    perror("An Error has been occurred :");
                }

            }
        }
    }else{
        perror("An Error has been accurred 1 :");
    }

    closedir(d);

}
