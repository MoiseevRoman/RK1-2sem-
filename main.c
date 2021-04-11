#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//function for searching identical words
int check(char *input, char *dict){
        for(int i=0; input[i]!='\0' && dict[i]!='\0'; i++){
            if(input[i]==dict[i]){
                continue;
            }
            else{
                return NULL;
            }
        }
        return 1;
}


int main(int argc, char *argv[])
{
    FILE *dict;
    dict = fopen(argv[1], "r");
    if(dict == NULL)
    {
        printf("ERROR with dictionary\n");
    }
    FILE * input;
    if((input = fopen(argv[2], "r")) == NULL)
    {
        printf("ERROR with input\n");
    }
    FILE * output;
    remove("output.txt");
    int i = 0;
    int j;
    int k;
    int pr, re, repeat;
    int out = 0;
    char d_cha, cha;
    char words[80] = " ";
    char d_words[80] = " " ;
    char re_words[80] =" ";
        while ((cha=getc(input)) != EOF)
            {if((cha == ' ') || (cha == ',' ) ||(cha == '-') || (cha == '.')){
                pr = 0;
                d_cha = " ";
                memset(d_words,0,sizeof(d_words));
                j = 0;
                fseek(dict,0,SEEK_SET);
                while ((d_cha = getc(dict)) != "\n"){
                    if(d_cha != EOF){
                        if(strcmp(words, d_words)==0){
                            pr++;
                            }
                        if (pr==1){
                            break;
                        }
                        if((d_cha == '\n')){
                            memset(d_words,0,sizeof(d_words));
                            j=0;
                            d_cha = getc(dict);
                        }
                        d_words[j] = d_cha;
                        j++;
                    }
                    else  break;
                }
                    if(pr ==0){
                        output = fopen(argv[3], "a+");
                        repeat = 0;
                        while((re=getc(output))!=EOF){
                            k=0;
                            while((re!=' ') && (re!=EOF)){
                            re_words[k]=re;
                            re=getc(output);
                            k++;
                            }
                            if((check(words,re_words))) repeat++;
                        }
                        if(repeat==0){
                            fputs(words, output);
                            fputc(' ', output);
                            fclose(output);
                        }
                        out++;
                    }
                    memset(words,0,sizeof(words));
                    i=0;
            }
                    else if(cha != '\n')
                        {words[i] = cha;
                        i++;}
        }
        if (out ==0){
            printf("OK\n");
        }
        else printf("WARNING\n");
    return 0;
}

