#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 500
enum {SUCCESS, FAIL};

void CheckWords(FILE *fin, FILE *fout){
    char tmp[20];

    typedef struct element_t {
        char word[20];
        int length;
        int appr;
    } element;

    element ele[MAX];
    int count[MAX] = {0};
    int n = 0;
    int i, j;

    while ((fscanf(fin,"%s", tmp)) != EOF) {
        int check_flag = 0;
        int k = 0;
        char c1;
        char *tmp1;

        tmp1 = (char*) malloc (20 * sizeof(char));
  
        for (j = 0; j < strlen(tmp); j++) {
                    tmp[j] = tolower(tmp[j]);
        } 

        for (i = 0; i < strlen(tmp); i++) {
            if ((tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] >= 'a' && tmp[i] <= 'z')) {
                c1 = tmp[i];
                strcpy(tmp1 + k, &c1);
                k++; 
            }
        }
        
        for (i = 0; i < n; i++) {
            if (strcmp(tmp1, ele[i].word) == 0) {
                ele[i].appr++;
                check_flag = 1;
                break;
            }
        } 
        
        if (check_flag == 1) continue;
        else {
            strcpy(ele[n].word, tmp1);
            ele[n].length = strlen(tmp1);
            ele[n].appr = 1;
            n++;
        }

        free(tmp1);
    }

    for (i = 0; i < n; i++) {
        fprintf(fout, "%20s %4d %4d\n", ele[i].word, ele[i].length, ele[i].appr);
    }
}

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "vanban.txt";
    char filename2[] = "stopw.txt";
    int flag = SUCCESS;

    if ((fptr1 = fopen(filename1,"r")) == NULL) {
        printf("Cannot open %s.\n",filename1);
        flag = FAIL;
    } else if ((fptr2 = fopen(filename2,"w")) == NULL) {
        printf("Cannot open %s.\n",filename2);
        flag = FAIL;
    } else {
        CheckWords(fptr1, fptr2);
        fclose(fptr2);
        fclose(fptr1);
    }

    return flag;
}