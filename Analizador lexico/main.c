#include<stdio.h>
extern int yylex();
extern FILE *yyin;
extern char *yytext;

int main(int argc , char** argv){
    FILE *f;
    if (argc <2)
    {
        printf("faltan argumentos");
        return -1;
    }

    f=fopen(argv[1], "r");
    if (!f)
    {
        printf("el archivo %s no se puede abrir \n", argv[1]);
        return -1;
    }
    
    yyin=f;
	int token;
	
	while ((token = yylex()) != 0) {
        printf("Token: %s %d\n", yytext, token);
    }
	
    fclose(yyin);
    return 0;
    
}