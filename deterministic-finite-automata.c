#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int matrice_trecere[100][100];
char alfabet[10];


int verificare(int st_cur, char a,int nr_l_alfabet,int matrice_trecere[100][100])
{
    int i;
    for(i=0;i<nr_l_alfabet;i++)
        if(a==alfabet[i])
           return matrice_trecere[i][st_cur];
    return -1;
}


int main()
{
    int nr_stari,nr_l_alfabet,nr_st_finale,i,j;
    int stari_finale[10];
    char cuvant[50];
    int st_cur=0;                                   //se pleaca mereu de la q0
    int ok=0;

     printf("Cate stari are acest DFA? \n");
     scanf("%d",&nr_stari);
     printf("Cate litere are alfabetul acestui DFA? \n");
     scanf("%d",&nr_l_alfabet);
     printf("\nIntroduceti literele alfabetului:");

     scanf("%s",&alfabet);


     printf("Cate stari finale are acest DFA? \n");
     scanf("%d",&nr_st_finale);

     printf("Introduceti starile finale: \n");

     for(i=0;i<nr_st_finale;i++)
     {
         printf("q");
         scanf("%d",&stari_finale[i]);
     }


     printf("Definiti tranzitiile (stare initiala,litera) = stare finala:\n");

     for(i=0; i<nr_l_alfabet; i++)
     {
          for(j=0; j<nr_stari; j++)
          {
               printf("\n(q%d , %c ) = q",j,alfabet[i]);
               scanf("%d",&matrice_trecere[i][j]);
          }
     }

     do{
            ok=0;
            st_cur=0;
            printf("\n\nIntroduceti cuvantul de testat:   ");
            fscanf(stdin,"%s",cuvant);

            if(!strcmp(cuvant,"~"))
            {
                for(j=0;j<nr_st_finale;j++)
                {
                    if(0==stari_finale[j])
                        ok=1;
                }

                if(ok==1)
                    printf("Cuvantul apartine alfabetului!\n");
                else
                    printf("Cuvantul NU apartine alfabetului!\n");
            }
            else
            {
                for(i=0;i<strlen(cuvant);i++)
                {
                    st_cur=verificare(st_cur,cuvant[i],nr_l_alfabet,matrice_trecere);
                    if(st_cur<0)
                        break;
                }


                for(j=0;j<nr_st_finale;j++)
                {
                    if(st_cur==stari_finale[j])
                        ok=1;
                }

                if(ok==1)
                    printf("Cuvantul apartine alfabetului!\n");
                else
                    printf("Cuvantul NU apartine alfabetului!\n");
            }



                printf("\n\n\n");
                printf("Testati alt cuvant?  \n(y/n)");

        }while(getch()=='y');
}
