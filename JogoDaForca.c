// Bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Função Principal:
int main () {
	int i, contador, n, nchar, e1, e2, e3, e4, e5, certo, animacao, animacao2;
	char frase[100], resposta[100], tentativa, confirmar, continuar;	
do {
	system("cls");
	puts("___________   \n|         |   \n|        _|_\n|         O   Jogo da Forca por Luiz Gustavo Nunes \n|        /|\\   Versao 1.0 - 2017 \n|        / \\ \n| \n| \n| \n");
	puts("Instruções: esse jogo e para ser jogado de duas pessoas do seguinte modo: a primeira pessoa digita uma palavra ou frase e a segunda tenta advinhar o que foi digitado.\n");
	confirmar = 'n';
	
	while(confirmar != 'S') {
      certo = 0;
      nchar=0;
      n = 0;
      i=0;
      contador = 0;
      e1 = ' ';
      e2 = ' ';
      e3 = ' ';
      e4 = ' ';
      e5 = ' ';
      printf("\nCertifique-se de que o outro jogador não veja e digite a palavra desejada: ");
      fflush(stdin);
      gets (frase);
      printf("%s, confirmar? (digite 's' para confirmar e 'n' para digitar novamente: ", frase);
      fflush(stdin);
      scanf("%c", &confirmar);
      switch(confirmar)
        {
          case 's':
          printf("O jogo será iniciado...\n");
          system("pause");
          system("cls");
          for(i = 0; i < 100; i++)
            {
              resposta[i]='_';
            }
          while(contador < 6)
            {
              n=0;
              certo=0;
              switch(contador)
                {
                  case 0: printf("___________   \n|         |   \n|        _|_\n|          \n|        \ \n|         \n| \n| \n| \n\n"); 
                          break;
                      
                  case 1: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         \n|       \n| \n| \n| \n\n");
                          break;
                      
                  case 2: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         |    \n|         \n| \n| \n| \n\n");
                          break;
                      
                  case 3: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|    \n|         \n| \n| \n| \n\n");
                          break;
                      
                  case 4: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|         \n| \n| \n| \n\n");
                          break;
                      
                  case 5: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        /  \n| \n| \n| \n\n");
                          break;
                }
              for(i=0; i < 100; i++)
                {
                  if(frase[i]=='\0')
                    {
                      nchar = i;
                      break;
                     }
                  else
                    {
                      if(frase[i]==' ')
                        {
                          resposta[i]=' ';
                          printf("%c", resposta[i]);
                        }
                      else
                        {
                          if(frase[i]==tentativa)
                            {
                              resposta[i]=frase[i];
                            }
                        }
                    }
                  printf("%c ", resposta[i]);    
                }
              printf("\n\n%c %c %c %c %c\n", e1, e2, e3, e4, e5);
              switch(contador)
                {
                  case 0: puts("\n\nVocê tem 5 chances!");
                          break;
                  case 1: puts("\n\nVocê tem 4 chances!");
                          break;
                  case 2: puts("\n\nVocê tem 3 chances!");
                          break;
                  case 3: puts("\n\nVocê tem 2 chances!");
                          break;
                  case 4: puts("\n\nÚltima chance!");
                          break;
                  case 5: puts("\n\nSe errar agora morre!");
                }
                for(i = 0; i <= nchar; i++)
                {
                 if(tentativa!=' ')
                   {
                    if(resposta[i]!='_')
                      {
                        certo++;
                        if(certo==nchar)
                          {
                            contador=7;                          
                            break;
                          }
                      }
                   }
                }
              if(certo!=nchar)
              {
              printf("\n\nDigite uma letra: ");
              fflush(stdin);
              scanf("%c", &tentativa);
              tentativa = tolower(tentativa);
              }
              for(i = 0; i < nchar; i++)
                {
                  if(tentativa!=frase[i])
                    {
                      n++;
                      if(n==nchar)
                        {
                          contador++;
                          if(contador==1) 
                            {
                              e1 = tentativa;
                            }
                          if(contador==2) 
                            {
                              e2 = tentativa;
                            }
                          if(contador==3) 
                            {
                              e3 = tentativa;
                            }
                          if(contador==4) 
                            {
                              e4 = tentativa;
                            }
                          if(contador==5) 
                            {
                              e5 = tentativa;
                            }
                        }
                    }
              }
              system("cls");
            }
          default: confirmar = 'n'; 
        }
      if(contador==6)
        {
          printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        / \\ \n| \n| \n| \n\n");
          for(i = 0; i < nchar; i++)
            {
              if(resposta[i]==frase[i])
                {
                  printf("%c ", resposta[i]);
                }
              else
                {
                  printf("(%c) ", frase[i]);
                }
            }
          printf("\n\n%c %c %c %c %c %c\n", e1, e2, e3, e4, e5, tentativa);
          printf("\n\n\nVocê perdeu!\n");
          system("PAUSE");
        }
      if(contador==7)
        {
          for(animacao=0;animacao<7;animacao++)
            {
              for(animacao2=0;animacao2<5;animacao2++)
              {
                system("cls");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|         O \n|        /|\\ \n|        / \\\n|\n\n");
              }
              for(animacao2=0;animacao2<5;animacao2++)
              {
                system("cls");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        _O_\n|         | \n|        / \\\n\n");                
              }
              for(animacao2=0;animacao2<5;animacao2++)
              {
                system("cls");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|        \\O/\n|         | \n|        / \\\n|\n\n");
              }
            }
          system("cls");
          printf("Parabens!! Voce Venceu!!\n");
          printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        \\O/\n|         | \n|        / \\\n\n");
          tentativa='_';
        }
      confirmar = 'S';
      printf("Deseja jogar novamente (S/N)? ");
      fflush(stdin);
      continuar = toupper(getchar());
    }
 }while(continuar=='S');
 system("PAUSE");
 return 0;
}
