//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h>
#include <conio.h>
#include<ctype.h>
#include <windows.h>

//Cores da exibição da consulta de emprestimo e devolução
#define EMPRESTADO 0
#define DEVOLVIDO 1
#define ATRASADO 2

//Cores
#define BLACK  0
#define BLUE 1
#define GREEN 2
#define GREENBLUE 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define GREENWATER 11
#define LIGHTRED 12
#define LILAC 13
#define LIGHTYELLOW 14
#define BRIGHTWHITE 15

//Teclas
#define CIMA 72
#define BAIXO 80
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define TAB 9	
#define ESQUERDA 75
#define DIREITA 77	

// Quadrado
#define CANTO1 218
#define CANTO2 191
#define CANTO3 192
#define CANTO4 217

#define CIMA1 196
#define LADO 179

//Estrutura de Cadastro de Usuario
typedef struct Cadastro{
	char cpf[12];
	char nome[100];
	char curso[12];
	char matricula[13];
	char identidade[9];
	
}Cadastro;

//Estrutura de Cadastro de Publicacao
typedef struct Publicacao{
	char autor[100];
	char titulo[50];
	char codigo[20];
	
}Publicacao;

//Estrutura de Emprestimo de Publicação
typedef struct Emprestimo{
	char autor[100];
	char titulo[50];
	char codigo[20];
	char nome[100];
	char matricula[13];
	char cpf[12];
	char rg[9];
	char curso[12];
	int numeroTombo;
	int situacao;
		
}Emprestimo,Devolucao;

;
//Variaveis Globais
Cadastro cadastro; //variavel que recebe os dados do cadastro
Publicacao publicar; //variavel que recebe os dados da publicacao
Emprestimo emprestar; //variavel que recebe os dados do emprestimo
Devolucao devolver; //variavel que recebe os dados da devolucacao

int numero;
char campo1[] = "NOME: ";
char campo2[] = "MATRICULA: ";
char campo3[] = "CPF: ";
char campo4[] = "IDENTIDADE: ";
char campo5[] = "CURSO: ";
char autor[] = "AUTOR: ";
char titulo[] = "TITULO: ";
char codigo1[] = "CODIGO: ";
char id[] = "IDENTIFICADOR: ";
char data[] = "DATA: ";
char matriculaA[13];
char matriculaUsuario[13];
char identificar[50];
char codigoPublicacao[20];
char emprestarMatricula[13];
char cadastrar_arq[] = "./cadastrar.dat"; //diretorio do arquivo de cadastro
char cadastrar_arqaux[] = "./cadastraraux.dat"; //diretorio do arquivo de cadastro auxiliar
char publicacao_arq[] = "./publicacao.dat";
char publicacao_arqaux[] = "./publicacaoaux.dat" ;
char emprestimo_arq[] = "./emprestimo.dat";
char emprestimo_arqaux[] = "./emprestimoaux.dat";


//Prototipos das Funcoes
void gotoxy(int,int);
void textcolor (int );
void espacamento(int,char);
void barras(int,int,int,int,char);
void barrinha(int,int,int);
void criar_caixinha(int,int,int,int);
void quadrado(int,int,int,int,int);
void quad();
void Titulo();
void livro();
void livro2();
void carregando();
void reescreverPontinhos(int);
void reescreverMenu(int,int,int,int);
void reescreverCadastro(int,int,int,int);
void reescreverAlteracao(int,int,int,int,int);
void reescreverAlteracaoPublic(int,int,int);
void reescreverMovimentacao(int,int);
void reescreverAcervo(int,int);
void reescreverSimNao(int,int,int,int);
void reescreverCarteira(int,int,int,int);
void menu();
void cadastroUsuario();
void matricula();
void inclusaoUsuario();
void menuAlteracao();
void alteracaoUsuario();	
void consultaUsuario();
void exclusaoUsuario();
void cadastroPublicacao();
void codigo();
void inclusaoPublicacao();
void alteracaoPublicacao();
void menuAlterarPublicacao();
void consultaPublicacao();
void exclusaoPublicacao();
void movimentacao();
void Identificador();
void numeroTombo();
void emprestimoPublicacao();
void dadosUsuario();
void devolucao();
void consultarAcervo();
void matriculaEmprestimo();
void carteiraUsuario(char,char,char,char,char);
void acervoUsuario();
void consulta_de_acervo();
void relatorios();
int sim_nao(int,int);
int opcoes();
int verificarNumeros(char,int);
int verificarLetra(char,int);
int validarCPF(char);
void verificarCPF(int,int,char,char,int);
void verificacaoChar(int,int,char,char,int,int);
void verificacaoInt(int,int,char,char,int,int);
void getString(char[]);

//Função de Mover o Curso
void gotoxy(int x, int y){
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
} 

//Função de Colorir o Texto 
void textcolor (int i){
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= i);
}

// Função para Criar Espaçamentos 
void espacamento(int tamanho, char codigo){
    int i;
    for(i = 0; i <= tamanho; i++)
        printf("%c", codigo);
    return;
}

//Função para Criar Barrinhas Laterais do Quadrado
void barras(int alt, int larg, int x, int y, char codigo){
    int i;

    for(i = 0; i < alt; i++, y++){
        gotoxy(x,y + 1);
        printf("%c", codigo);
        espacamento(larg + 1, ' ');
        gotoxy(x + larg + 2,y + 1);
        printf("%c\n", codigo);
    }
    return;
}

//Função para Cria a Barra Inferior dos Campos 
void barrinha(int x, int y, int larg){
    int i;

    for(i = 0; i < larg; i++){
        gotoxy(i + x, y);
        printf("%c", 196);
    }
}

//Função para Cria o Modelo do Quadrado
void criar_caixinha(int x, int y, int larg, int alt){

    gotoxy(x,y);
    printf("%c", CANTO1); espacamento(larg, CIMA1); printf("%c\n", CANTO2);

    barras(alt, larg, x, y, LADO);

    gotoxy(x, alt + y);
    printf("%c",CANTO3); espacamento(larg, CIMA1); printf("%c\n", CANTO4);
}

//Função para Criar o Quadrado Externo
void quadrado(int x, int y,int larg,int alt,int cor){

	int i;
	
	time_t tp = time(NULL);
	struct tm lt = *localtime(&tp);
	
	//canto superior direito
	gotoxy(1,1);
	textcolor(cor);
	printf("%c",201);
	
	//linha de cima
	for(i = 2; i <= 125; i++){
		gotoxy(i,1);
		textcolor(cor);
		printf("%c",205);
	}
	
	//canto superior esquerdo
	gotoxy(125,1);
	textcolor(cor);
	printf("%c",187);
	
	//canto inferior direiro
	gotoxy(1,36);
	textcolor(cor);
	printf("%c",200);
	
	//linha de baixo
	for(i = 2; i <= 125; i++){
		gotoxy(i,36);
		textcolor(cor);
		printf("%c",205);
	}
	
	//canto inferior esquerdo
	gotoxy(125,36);
	textcolor(cor);
	printf("%c",188);
	
	//linha da esquerda
	for(i = 2; i < 36; i++){
		gotoxy(1,i);
		textcolor(cor);
		printf("%c",186);
	}
	
	//linha da direita
	for(i = 2; i < 36; i++){
		gotoxy(125,i);
		textcolor(cor);
		printf("%c",186);
	}
	
	criar_caixinha(x,y,larg,alt);
	gotoxy(111,32);
	printf("%d:%d",lt.tm_hour,lt.tm_min);
	gotoxy(108,33);
	printf("%d/%d/%d",lt.tm_mday,lt.tm_mon,lt.tm_year + 1900);
	gotoxy(1,1);
}

//qudrado sem a funcao de criar caixinha dentro
void quad(){
	int i;
	
	//canto superior direito
	gotoxy(1,1);
	textcolor(GREENWATER);
	printf("%c",201);
	
	//linha de cima
	for(i = 2; i <= 125; i++){
		gotoxy(i,1);
		textcolor(GREENWATER);
		printf("%c",205);
	}
	
	//canto superior esquerdo
	gotoxy(125,1);
	textcolor(GREENWATER);
	printf("%c",187);
	
	//canto inferior direiro
	gotoxy(1,36);
	textcolor(GREENWATER);
	printf("%c",200);
	
	//linha de baixo
	for(i = 2; i <= 125; i++){
		gotoxy(i,36);
		textcolor(GREENWATER);
		printf("%c",205);
	}
	
	//canto inferior esquerdo
	gotoxy(125,36);
	textcolor(GREENWATER);
	printf("%c",188);
	
	//linha da esquerda
	for(i = 2; i < 36; i++){
		gotoxy(1,i);
		textcolor(GREENWATER);
		printf("%c",186);
	}
	
	//linha da direita
	for(i = 2; i < 36; i++){
		gotoxy(125,i);
		textcolor(GREENWATER);
		printf("%c",186);
	}
}

//Função que desenha o livro
void livro(){
                                                        
	textcolor(GREENWATER);
	
	gotoxy(19,5+3);  printf("    _______________________________________   _______________________________________    ");
	gotoxy(19,6+3);  printf(".-/|                                       %c /                                       |%c-.",92,92);
	gotoxy(19,7+3);  printf("||||                                        |                                        ||||");
	gotoxy(19,8+3);  printf("||||                                        |                                        ||||");
	gotoxy(19,9+3);  printf("||||                                        |                                        ||||");
	gotoxy(19,10+3); printf("||||                                        |                                        ||||");
	gotoxy(19,11+3); printf("||||                                        |                                        ||||");
	gotoxy(19,12+3); printf("||||                                        |                                        ||||");
	gotoxy(19,13+3); printf("||||                                        |                                        ||||");
	gotoxy(19,14+3); printf("||||                                        |                                        ||||",92,92,92,92,92,92,92);
	gotoxy(19,15+3); printf("||||                                        |                                        ||||");
	gotoxy(19,16+3); printf("||||                                        |                                        ||||",92,92,92,92,92,92,92);
	gotoxy(19,17+3); printf("||||                                        |                                        ||||");
	gotoxy(19,18+3); printf("||||                                        |                                        ||||");
	gotoxy(19,19+3); printf("||||                                        |                                        ||||");
	gotoxy(19,20+3); printf("||||                                        |                                        ||||");
	gotoxy(19,21+3); printf("||||                                        |                                        ||||");
	gotoxy(19,22+3); printf("||||                                        |                                        ||||");
	gotoxy(19,23+3); printf("||||                                        |                                        ||||");
	gotoxy(19,24+3); printf("||/========================================%c|/========================================%c||",92,92);
	gotoxy(19,25+3);printf("`-----------------------------------------~___~----------------------------------------''");

	textcolor(BRIGHTWHITE);
	
	gotoxy(27,12+3); printf(" ____                    _               ____    _                           ");
	gotoxy(27,13+3); printf("| __ )    ___     ___   | | __          / ___|  | |_    ___    _ __    ___   ");
	gotoxy(27,14+3); printf("|  _ %c   / _ %c   / _ %c  | |/ /      |   %c___ %c  | __|  / _ %c  | '__|  / _ %c  ",92,92,92,92,92,92,92);
	gotoxy(27,15+3); printf("| |_) | | (_) | | (_) | |   <           _ __) | | |_  | (_) | | |    |  __/  ");
	gotoxy(27,16+3); printf("|____/   %c___/   %c___/  |_|%c_%c      |   |____/   %c__|  %c___/  |_|     %c___|  ",92,92,92,92,92,92,92);
	
	textcolor(GREENWATER);
	
	gotoxy(63,12+3); printf("|");
	gotoxy(63,13+3); printf("|");
	gotoxy(63,14+3); printf("|");
	gotoxy(63,15+3); printf("|");
	gotoxy(63,16+3); printf("|");
	
	gotoxy(1,1);

}

//Função de Printar o Titulo na Tela Inicial
void Titulo(){
	
	quadrado(4,4,116,30,GREENWATER);
	gotoxy(111,32);
	printf("         ");
	gotoxy(108,33);
	printf("             ");
	livro();
	
	carregando();
	getchar();
	system("cls");
}

//Função de Printar na Tela Carregado
void carregando(){
	
	int i = 0;
	gotoxy(58,32);
	textcolor(GREENWATER);
	printf("CARREGANDO");
	
	reescreverPontinhos(BRIGHTWHITE);
	do{
		i+=1;
		
		switch(i){
			case 1:
				reescreverPontinhos(GREENWATER);
				break;
			case 2:
				reescreverPontinhos(BRIGHTWHITE);
				break;
		}
	}while(i != 3);
}

//Função que Troca as Cores dos Pontinhos Carregando
void reescreverPontinhos(int cor){
	
	Sleep(300);
	gotoxy(62,33);
	textcolor(cor);
	printf(".");
	printf("  ");
	gotoxy(1,1);
	
	Sleep(300);
	gotoxy(63,33);
	textcolor(cor);
	printf(".");
	printf("  ");
	gotoxy(1,1);
	
	Sleep(300);
	gotoxy(64,33);
	textcolor(cor);
	printf(".");
	printf("  ");
	gotoxy(1,1);
			
}

//Função que Trocar as Cores das Opções do Menu Principal a Cada Opção Selecionada
void reescreverMenu(int cor1, int cor2, int cor3, int cor4){
	
	textcolor(cor1);
	criar_caixinha(44,9,32,2);
	gotoxy(51,10);
	printf("CADASTRO DE USU%cRIOS",181);
	
	textcolor(cor2);
	criar_caixinha(44,12,32,2);
	gotoxy(50,13);
	printf("CADASTRO DE PUBLICA%c%cES",128,229);

	textcolor(cor3);
	criar_caixinha(44,15,32,2);
	gotoxy(55,16);
	printf("MOVIMENTA%c%cO",128,199);
	
	textcolor(cor4);
	criar_caixinha(44,18,32,2);
	gotoxy(52,19);
	printf("CONSULTA DE ACERVO");
	
    gotoxy(1,1);
}    

//Função que Trocar as Cores das Opcoes do Menu de Cadastro a Cada Opção Selecionada
void reescreverCadastro(int cor1, int cor2, int cor3, int cor4){
	
	textcolor(cor1);
	criar_caixinha(47,9,26,2);
	gotoxy(57,10);
	printf("INCLUS%cO",199);
	
	textcolor(cor2);
	criar_caixinha(47,12,26,2);
	gotoxy(57,13);
	printf("CONSULTA");
	
	textcolor(cor3);
	criar_caixinha(47,15,26,2);
	gotoxy(57,16);
	printf("ALTERA%c%cO",128,199);
	
	textcolor(cor4);
	criar_caixinha(47,18,26,2);
	gotoxy(57,19);
	printf("EXCLUS%cO",199);

    gotoxy(1,1);
}   

//Função que Trocar as Cores das Opções do Emprestimo e Devolução de Publicacao a Cada Opção Selecionada
void reescreverMovimentacao(int cor1, int cor2){
	
	textcolor(cor1);
	criar_caixinha(44,9,32,2);
	gotoxy(49,10);
	printf("EMPRESTIMO DE PUBLICA%c%cO",128,199);
	
	textcolor(cor2);
	criar_caixinha(44,12,32,2);
	gotoxy(49,13);
	printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);
	
	gotoxy(1,1);	
}

//Função que Trocar as Cores das Opções de Consulta de Arcevo eConsulta de Usuário a Cada Opção Selecionada
void reescreverAcervo(int cor1, int cor2){
	
	textcolor(cor1);
	criar_caixinha(47,9,26,2);
	gotoxy(58,10);
	printf("USU%cRIO",181);
	
	textcolor(cor2);
	criar_caixinha(47,12,26,2);
	gotoxy(58,13);
	printf("ACERVO");
	
	gotoxy(1,1);
}

//Função que reescreve os campos da alteracão, e troca de cor se o usuario selecionar alterar
void reescreverAlteracao(int cor1,int cor2, int cor3, int cor4, int cor5){
	
	textcolor(cor1);
	gotoxy(38,10);
	puts(campo1);
	barrinha(38,11,47);
	
	textcolor(cor2);
	gotoxy(38,13);
	puts(campo2);
	barrinha(38,14,47);
	
	textcolor(cor3);
	gotoxy(38,16);
	puts(campo3);
	barrinha(38,17,47);
		
	textcolor(cor4);
	gotoxy(38,19);
	puts(campo4);
	barrinha(38,20,47);
	
	textcolor(cor5);
	gotoxy(38,22);
	puts(campo5);
	barrinha(38,23,47);
	
	gotoxy(1,1);
}

//Função que reescreve os campos da alteracão, e troca de cor se o usuario selecionar alterar
void reescreverAlteracaoPublic(int cor1,int cor2, int cor3){
	
	textcolor(cor1);
	gotoxy(38,11);
	puts(codigo1);
	barrinha(38,12,47);
	
	textcolor(cor2);
	gotoxy(38,14);
	puts(titulo);
	barrinha(38,15,47);
	
	textcolor(cor3);
	gotoxy(38,17);
	puts(autor);
	barrinha(38,18,47);
	
	gotoxy(1,1);
}

//Função que reescreve os campos das opções SIM e NÃO, e troca as cores conforme o usuario seleciona as opções 
void reescreverSimNao(int cor1, int cor2,int x, int y){
	
	textcolor(cor1);
	criar_caixinha(x,y,6,2);
	gotoxy(x+3,y+1);
	printf("SIM");
	
	textcolor(cor2);
	criar_caixinha(x+15,y,6,2);
	gotoxy(x+18,y+1);
	printf("N%cO",199);
	
	gotoxy(1,1);
}

void reescreverCarteira(int cor1, int cor2,int x, int y){
	
	textcolor(cor1);
	criar_caixinha(x,y,21,2);
	gotoxy(x+8,y+1);
	printf("RETORNAR");
	
	textcolor(cor2);
	criar_caixinha(x+32,y,23,2);
	gotoxy(x+35,y+1);
	printf("CONSULTAR EMPRESTIMO");
	
	gotoxy(1,1);
}

//Função do SIM e NÃO
int sim_nao(int x, int y){
	
	int tecla;
	int op = 1;
	
	reescreverSimNao(LIGHTGREEN,BRIGHTWHITE,x,y);
	
	do{
		tecla = getch();
		
		if(tecla == ESQUERDA){
			op++;
		}
		if(tecla == DIREITA){
			op--;
		}
		
		switch(op){
			case 0:
				op = 2;
				reescreverSimNao(BRIGHTWHITE,LIGHTRED,x,y);
				break;
					
			case 1:
				reescreverSimNao(LIGHTGREEN,BRIGHTWHITE,x,y);
				break;
				
			case 2:
				reescreverSimNao(BRIGHTWHITE,LIGHTRED,x,y);
				break;
			case 3:
				op = 1;
				reescreverSimNao(LIGHTGREEN,BRIGHTWHITE,x,y);
				break;
		}
	}while(tecla != 13);
	
	return op;
}

void finalizado(){
	
	quad();
	
    textcolor(BRIGHTWHITE);
    gotoxy(25 + 11,4 - 1); printf("______________________________________________________");
    gotoxy(25 + 11,5 - 1); printf("|	                                                |");
    gotoxy(25 + 11,6 - 1); printf("|                                                    |");
    gotoxy(25 + 11,7 - 1); printf("|____________________________________________________|");
    gotoxy(25 + 11,8 - 1); printf("| __     __   ____   ___ ||  ____    ____     _  __  |");
    gotoxy(25 + 11,9 - 1); printf("||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |");
    gotoxy(25 + 11,10 - 1); printf("||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |");
    gotoxy(25 + 11,11 - 1); printf("||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |");
    gotoxy(25 + 11,12 - 1); printf("||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|");
    gotoxy(25 + 11,13 - 1); printf("||_______________________||__________________________|");
    gotoxy(25 + 11,14 - 1); printf("| _____________________  ||      __   __  _  __    _ |");
    gotoxy(25 + 11,15 - 1); printf("||=|=|=|=|=|=|=|=|=|=|=|        |  |_|  ||#||==|  / /|",92);
    gotoxy(25 + 11,16 - 1); printf("|| | | | | | | | | | | |        |++|=|  || ||==| / / |",92,92,92,92);
    gotoxy(25 + 11,17 - 1); printf("||_|_|_|_|_|_|_|_|_|_|_          __|_|__||_||__|/_/__|",92,92);
    gotoxy(25 + 11,18 - 1); printf("|____________________              __________________|",92,92);
    gotoxy(25 + 11,19 - 1); printf("| __   __    _  _                  _    ___     _____|",92);
    gotoxy(25 + 11,20 - 1); printf("||~~|_|..|__| || |_ _             |=|__|~|~|___| | | |",92,92,92);
    gotoxy(25 + 11,21 - 1); printf("||--|+|^^|==|1||2| | |            | |==|x|x|+|+|=|=|=|",92,92);
    gotoxy(25 + 11,22 - 1); printf("||__|_|__|__|_||_|_|               _|__|_|_|_|_|_|_|_|",92,92,92);
    gotoxy(25 + 11,23 - 1); printf("|_________________ _                _ _______________|",92,92,92,92);
    gotoxy(25 + 11,24 - 1); printf("| _____   _   __  |                  |  __   __   ___|",92,92);
    gotoxy(25 + 11,25 - 1); printf("||_____|_| |_|##|_|                  |_|==|_|++|_|-|||",92);
    gotoxy(25 + 11,26 - 1); printf("||______||=|#|--| |                  | |  |~|  | | |||",92,92);
    gotoxy(25 + 11,27 - 1); printf("||______||_|_|__|_|_                _|_|__|_|__|_|_|||",92,92);
    gotoxy(25 + 11,28 - 1); printf("|_________ __________              ___________ ______|",92,92);
    gotoxy(25 + 11,29 - 1); printf("|__    _  /    ________     ______           /| _ _ _|");
    gotoxy(25 + 11,30 - 1); printf("|%c %c  |=|/   //    /| //   /  /  / |        / ||%c|%c|%c|",92,92,37,37,37);
    gotoxy(25 + 11,31 - 1); printf("| %c/%c |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|",92,92);
    gotoxy(25 + 11,32 - 1); printf("|  %c/%c|/   /(____|/ //                    /  /||~|~|~|",92,92);
    gotoxy(25 + 11,33 - 1); printf("|___%c_/   /________//   ________         /  / ||_|_|_|",92);
    gotoxy(25 + 11,34 - 1); printf("|___ /   (|________/   |%c_______%c       /  /| |______|",92,92);
    gotoxy(25 + 11,35 - 1); printf("    /                  %c|________)     /  / | |       ",92);
    
    textcolor(GREENWATER);
    gotoxy(50 + 11,15 - 1); printf("__..%c/",92);
    gotoxy(49 + 11,16 - 1); printf("/%c %c  %c%c",92,92,92,92);
    gotoxy(48 + 11,17 - 1); printf("/_/%c_.___%c",92,92,92);
    gotoxy(47 + 11,18 - 1); printf("/%c~()/()~//%c",92,92);
    gotoxy(47 + 11,19 - 1); printf("%c_  (_ .  _/",92);
    gotoxy(49 + 11,20 - 1); printf("%c //%c%c /",92,92,92);
    gotoxy(47 + 11,21 - 1); printf("__/%c __ /%c__",92,92);
    gotoxy(46 + 11,22 - 1); printf("/  %c %c  / /  %c",92,92,92);
    gotoxy(45 + 11,23 - 1); printf("/    %c/%c/%c/    %c",92,92,92,92);
    gotoxy(44 + 11,24 - 1); printf("/      %c../      %c",92,92);
    gotoxy(44 + 11,25 - 1); printf("|   |   %c/ __|   |",92);
    gotoxy(44 + 11,26 - 1); printf("%c   %c   o    /   /",92,92);
    gotoxy(45 + 11,27 - 1); printf("%c   %c  o   /   /",92,92);
    gotoxy(46 + 11,28 - 1); printf("%c___%c____/___/",92,92);
  
    textcolor(GREENWATER);
    gotoxy(32 + 12,5);
    printf("OBRIGADA POR UTILIZAR NOSSOS SERVI%cOS",128);
    
    gotoxy(1,1);

}

//Função do Menu Principal
void menu(){
	
	int op = 1;
	int tecla1;
	
	quadrado(4,4,116,30,GREENWATER);
	
	textcolor(GREENWATER);
	criar_caixinha(45,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(55,4);
	printf("MENU PRINCIPAL");
	
	reescreverMenu(GREENWATER, BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE);
	
	do{
		
		tecla1 = getch();
		
		if(tecla1 == BAIXO){
			op++;
		}
		if(tecla1 == CIMA){
			op--;
		}
		if(tecla1 == ESC){
			system("cls");
			finalizado();
			getchar();
			system("cls");
			exit(0);
		}
		
		switch(op){
			
			case 0:
				op = 4;
				reescreverMenu(BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE, GREENWATER);
				break;
			
			case 1:
				reescreverMenu(GREENWATER, BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE);
				break;
			
			case 2:
				reescreverMenu(BRIGHTWHITE, GREENWATER, BRIGHTWHITE, BRIGHTWHITE);
				break;
			
			case 3:
				reescreverMenu(BRIGHTWHITE, BRIGHTWHITE, GREENWATER, BRIGHTWHITE);
				break;
				
			case 4:
				reescreverMenu(BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE, GREENWATER);
				break;
				
			case 5:
				op = 1;
				reescreverMenu(GREENWATER, BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE);
				break;
		}
	
	}while(tecla1 != ENTER || tecla1 == ESC);
	
	system("cls");
	
	switch(op){
		case 1:
			cadastroUsuario();
			break;
			
		case 2:
			cadastroPublicacao();
			break;
			
		case 3:
			movimentacao();
			break;
				
		case 4:
			consulta_de_acervo();
			break;
			
	}
}

//Função que Exibe as Opções do Cadastro de Usuário
void cadastroUsuario(){

	int op = 1;
	int tecla;

	quadrado(4,4,116,30,GREENWATER);
	
	textcolor(GREENWATER);
	criar_caixinha(45,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(51,4);
	printf("CADASTRO DE USU%cRIOS",181);
	
	reescreverCadastro(GREENWATER, BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE);
	
	do{
		
		tecla = getch();
		
		if(tecla == BAIXO){
			op++;
		}
		if(tecla == CIMA){
			op--;
		}
		if(tecla == ESC){
			menu();
		}
		
		switch(op){
			
			case 0:
				op = 4;
				reescreverCadastro(BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE, GREENWATER);
				break;
			
			case 1:
				reescreverCadastro(GREENWATER, BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE);
				break;
			
			case 2:
				reescreverCadastro(BRIGHTWHITE, GREENWATER, BRIGHTWHITE, BRIGHTWHITE);
				break;
			
			case 3:
				reescreverCadastro(BRIGHTWHITE, BRIGHTWHITE, GREENWATER, BRIGHTWHITE);
				break;
				
			case 4:
				reescreverCadastro(BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE, GREENWATER);
				break;
				
			case 5:
				op = 1;
				reescreverCadastro(GREENWATER, BRIGHTWHITE, BRIGHTWHITE, BRIGHTWHITE);
				break;
		}
	
	}while(tecla != ENTER || tecla == ESC);
	
	system("cls");
	
	switch(op){
		case 1:
		 	inclusaoUsuario();
			break;
			
		case 2:
			consultaUsuario();
			break;
			
		case 3:
			alteracaoUsuario();	
			break;
				
		case 4:
			exclusaoUsuario();
			break;
	}
}

/*A partir daqui será feito as funções de verificação,
onde o usuário terá que entrar apenas com os dados correspondentes ao campo*/

/*Função que verifica se a variável está recebendo apenas números,
caso não esteja ela retornará à 0, se não retornará à 1*/
int verificarNumeros(char var[], int tam1){
	
	int i;
	
	for(i = 0; i < tam1; i++){
		
		if(isdigit(var[i]) || var[0] == ESC || var[i] == ' ' || var[0] == '\0'){
			return 1;
		}
		else
		return 0;
	}
}

/*Função que verifica se a variável está recebendo apenas letras,
caso não esteja ela retornará à 0, se não retornará à 1*/
int verificarLetra(char var[], int tam1){
	
	int i;
	
	for(i = 0; i < tam1; i++){
		
		if(isalpha(var[i]) || var[i] == ' ' || var[0] == ESC || var[0] == '\0'){
			return 1;
		}
		else
		return 0;
	}
}

/*Função que verifica se o CPF é válido, 
caso não seja a função retornará à 0, se não ela retornrá à 1*/
int validarCPF(char cpf[]){
	
    int i, j, digito1 = 0, digito2 = 0;
    
    if(strlen(cpf) != 11)
    
        return 0;
        
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
            
        return 0; //se o CPF tiver todos os números iguais ele é inválido.
        
    else
    {
        //digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) //multiplica os números de 10 a 2 e soma os resultados dentro de digito1
			digito1 += (cpf[i]-48) * j;
        	digito1 %= 11;
        
		if(digito1 < 2)
        	digito1 = 0;
        
		else
        	digito1 = 11 - digito1;
        
		if((cpf[9]-48) != digito1)
        
		    return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        
		else{
        //digito 2--------------------------------------------------

            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) //multiplica os números de 11 a 2 e soma os resultados dentro de digito2
				digito2 += (cpf[i]-48) * j;		
				digito2 %= 11;
        
		if(digito2 < 2)
		    digito2 = 0;
        
		else
		    digito2 = 11 - digito2;
        
		if((cpf[10]-48) != digito2)
		    return 0; //se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

//Função que Verifica se os Dados do CPF são Válidos
void verificarCPF(int x, int y, char campo[], char var[], int cor){
	
	int cpf;
	int tecla;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(x,y);
	puts(campo);
	barrinha(x,y+1,47);
	
		do{
			textcolor(GREENWATER);
			gotoxy(x + strlen(campo),y);
			setbuf(stdin, NULL);
			gets(var);
			setbuf(stdin, NULL);
			//cpf = validarCPF(var);
			
			if(var[0] == '\0'){
		        gotoxy(x + strlen(campo),y);
		        printf("                                       ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("CAMPO OBRIGAT%cRIO!",224);
				Sleep(1000);
			}
			/*if(cpf == 0){
				gotoxy(x + strlen(campo),y);
		        printf("                                       ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("INV%cLIDO",181);
				Sleep(1000);
			}|| cpf  == 0*/
			
	        gotoxy(x + strlen(campo),y);
	        printf("                                           ");
	        
	}while(var[0] == '\0' );
	
	//Troca a Cor se Preenchido Corretamente
	if(var[0] != ESC){
		
		textcolor(cor);
		gotoxy(x,y);
		puts(campo);
		gotoxy(x + strlen(campo),y);
		setbuf(stdin, NULL);
		puts(var);
		barrinha(x,y+1,47);
	}
}

//Verifica se os Dados Fornecidos não Contém Números
void verificacaoChar(int x, int y, char campo[], char var[], int tam, int cor){
	
	int aux;
	int tamanho;
	int verificar;
	int tecla;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(x,y);
	puts(campo);
	barrinha(x,y+1,47);
	
	do{
			
		textcolor(GREENWATER);
		gotoxy(x + strlen(campo),y);
		setbuf(stdin, NULL);
		getString(var);
		setbuf(stdin, NULL);
		tamanho = strlen(var);
		aux = verificarLetra(var,tam);
	
		if(var[0] == '\0'){
	       	gotoxy(x + strlen(campo),y);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(1000);
		}
		
		if(aux == 0){
			gotoxy(x + strlen(campo),y);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(tamanho > tam){
			gotoxy(x + strlen(campo),y);
		    printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		
        gotoxy(x + strlen(campo),y);
        printf("                                            ");	
		        
	}while(var[0] == '\0' || aux == 0 || tamanho > tam);
	
	//Troca a Cor se Preenchido Corretamente
	if(var[0] != ESC){
		
		textcolor(cor);
		gotoxy(x,y);
		puts(campo);
		gotoxy(x + strlen(campo),y);
		setbuf(stdin, NULL);
		puts(var);
		barrinha(x,y+1,47);
	}
}

//Função que Verifica se os Dados Fornecidos não Contém Caracter
void verificacaoInt(int x, int y, char campo[], char var[], int tam, int cor){
	
	int tamanho;
	int tecla;
	int aux;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(x,y);
	puts(campo);
	barrinha(x,y+1,47);
	
		do{
			textcolor(GREENWATER);
			gotoxy(x + strlen(campo),y);
			setbuf(stdin, NULL);
			getString(var);
			setbuf(stdin, NULL);
			tamanho = strlen(var);
			aux = verificarNumeros(var,tam);
		
			if(var[0] == '\0'){
		        gotoxy(x + strlen(campo),y);
		        printf("                                       ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("CAMPO OBRIGAT%cRIO!",224);
				Sleep(1000);
			}
			if(aux == 0){
				gotoxy(x + strlen(campo),y);
		        printf("                                        ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("INV%cLIDO",181);
				Sleep(1000);
			}
			if(tamanho > tam){
				gotoxy(x + strlen(campo),y);
		        printf("                                        ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("INV%cLIDO",181);
				Sleep(1000);
			}
				
	        gotoxy(x + strlen(campo),y);
	        printf("                                            ");
	        
	}while(var[0] == '\0' || aux == 0 || tamanho > tam);
	
	//Troca a Cor se Preenchido Corretamente
	if(var[0] != ESC){
		
		textcolor(cor);
		gotoxy(x,y);
		puts(campo);
		gotoxy(x + strlen(campo),y);
		setbuf(stdin, NULL);
		puts(var);
		barrinha(x,y+1,47);
	}
}

//Função que faz a Leitura das Váriaveis fornecida pelo usuário
void getString(char var[]){
	
	int tecla;
	int pos = 0;
	
	var[0] = '\0';
	
	do{
		tecla = getch();
		
		if(isprint(tecla)){
			var[pos] = tecla;
			var[pos + 1] = '\0';
			pos++;
			
			printf("%c",tecla);
		}
		
		else{
			if(tecla == BACKSPACE){
				if(var[0] != '\0'){
					pos--;
					printf("\b \b");
					var[pos] = '\0';
				}
			}
		}
		if(var[0] == ' '){
			pos--;
			var[pos] = '\0';
		}
		
		if(tecla == ESC){
			var[0] = tecla;
			return;
		}	
	}while(tecla != ENTER);	
}

//Função que lê os dados e verifica se não existe no arquivo
void matricula(){
	
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	
	int encontrou;
	int tamanho;
	int aux;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(38,13);
	puts(campo2);
	barrinha(38,14,47);
	
	do{
		encontrou = FALSE;
		
		textcolor(GREENWATER);
		gotoxy(38 + strlen(campo2),13);
		setbuf(stdin, NULL);
		getString(matriculaUsuario);
		tamanho = strlen(matriculaUsuario);
		aux = verificarNumeros(matriculaUsuario,12);
	
		if(matriculaUsuario[0] == '\0'){
	        gotoxy(38 + strlen(campo2),13);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),13);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(1000);
		}
		if(tamanho > 12){
			gotoxy(38 + strlen(campo2),13);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),13);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(aux == 0){
			gotoxy(38 + strlen(campo2),13);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),13);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(cadastrar != NULL){
			
			rewind(cadastrar);
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(cadastro.matricula,matriculaUsuario) == 0){
					encontrou = TRUE;
				}
			}
		}
		if(encontrou == TRUE){
			gotoxy(38 + strlen(campo2),13);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),13);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
				
	    gotoxy(38 + strlen(campo2),13);
	    printf("                                            ");
	        
	}while(matriculaUsuario[0] == '\0' || tamanho > 12 || aux == 0 || encontrou == TRUE);
	
	fclose(cadastrar);
	
	//Troca a Cor se Preenchido Corretamente
	if(matriculaUsuario[0] != ESC){
		
		textcolor(BRIGHTWHITE);
		gotoxy(38,13);
		puts(campo2);
		gotoxy(38 + strlen(campo2),13);
		setbuf(stdin, NULL);
		puts(matriculaUsuario);
		barrinha(38,14,47);
	}
}

void inclusaoUsuario(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	int op;
	int op1;
	int tecla;
	int op3;
	char nomeUsuario[100];
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("INCLUS%cO",199);
	
	//Entrada de dados
	
	textcolor(BRIGHTWHITE);
	gotoxy(38,13);
	puts(campo2);
	barrinha(38,14,47);
	
	textcolor(BRIGHTWHITE);
	gotoxy(38,16);
	puts(campo3);
	barrinha(38,17,47);
	
	textcolor(BRIGHTWHITE);
	gotoxy(38,19);
	puts(campo4);
	barrinha(38,20,47);
	
	textcolor(BRIGHTWHITE);
	gotoxy(38,22);
	puts(campo5);
	barrinha(38,23,47);
	
	//Nome
	verificacaoChar(38,10,campo1,nomeUsuario,100,BRIGHTWHITE);
	
	if(nomeUsuario[0] == ESC){
		system("cls");
		cadastroUsuario();
	}
	
	//Matricula
	matricula();
	if(matriculaUsuario[0] == ESC){
		system("cls");
		cadastroUsuario();
	}
	
	strcpy(cadastro.matricula,matriculaUsuario);
	
	//CPF
	verificarCPF(38,16,campo3,cadastro.cpf,BRIGHTWHITE);
	
	//Identidade
	verificacaoInt(38,19,campo4,cadastro.identidade,8,BRIGHTWHITE);
	
	if(cadastro.identidade[0] == ESC){
		system("cls");
		cadastroUsuario();
	}
	
	//Curso
	verificacaoChar(38,22,campo5,cadastro.curso,11,BRIGHTWHITE);
	
	if(cadastro.curso[0] == ESC){
		system("cls");
		cadastroUsuario();
	}
	
	strcpy(cadastro.nome,nomeUsuario);
	
	//Interagindo com o usuario
	
	textcolor(GREENWATER);
	gotoxy(46,27);
	printf("DESEJA SALVAR OS DADOS DA INCLUS%cO?",199);
	op = sim_nao(52,29);
	
	if(op == 1){
		//abrir o arquivo
		FILE* cadastrar = fopen(cadastrar_arq,"ab");
		
		//verificar se o arquivo foi criado
		if(cadastrar == NULL){
			quadrado(4,4,116,30,GREENWATER);
			textcolor(LIGHTRED);
			gotoxy(49,14);
			printf("ERRO AO SALVAR ARQUIVO");
			gotoxy(45,15);
			printf("PRESSIONE ENTER PARA CONTINUAR");
			gotoxy(1,1);
			getchar();
			system("cls");
			cadastroUsuario();
		}
		
		else{
		fwrite(&cadastro,sizeof(Cadastro),1,cadastrar);
		fclose(cadastrar);
		
		}
		textcolor(GREENWATER);
		gotoxy(46,27);
		printf("                                                         ");
		gotoxy(57,27);
		printf("NOVA INCLUS%cO?",199);
		op1 = sim_nao(52,29);
		
		if(op1 == 1){
			system("cls");
			inclusaoUsuario();
		}
		else
			system("CLS");
			cadastroUsuario();
	}
	else
		system("CLS");
		cadastroUsuario();
}

//Consulta de Dados no Arquivo
void consultaUsuario(){
	
	int y = 7;
	int tecla;
	int cont = 0;
	
	//abrindo o arquivo em modo de leitura binaria
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	
	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(cadastrar == NULL){ 
	
		quadrado(4,4,116,30,GREENWATER);
		criar_caixinha(46,3,30,2);
		textcolor(BRIGHTWHITE);
		gotoxy(58,4);
		printf("CONSULTA");
		
		textcolor(LIGHTRED);
		gotoxy(51,15);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(46,16);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		cadastroUsuario();
	}
	
	//Caso não tenha nenhum erro ele exibe o que tem no arquivo
	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		cont++;
	}
	
	fclose(cadastrar);
	
	if(cont <= 3){
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,34);
		criar_caixinha(4,3,116,30);
		
		textcolor(GREENWATER);
		gotoxy(43,31);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
		
	}else{
		int aux = cont * 9 + 5;
		
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,aux);
		criar_caixinha(3,3,116,aux - 4);
		
		textcolor(GREENWATER);
		gotoxy(43,aux - 3);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
	}
	
	criar_caixinha(46,2,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,3);
	printf("CONSULTA");
	
	
	cadastrar = fopen(cadastrar_arq,"rb");
	
	//Caso não tenha nenhum erro ele exibe o que tem no arquivo
	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		
		textcolor(GREENWATER);
		criar_caixinha(38,y,45,6);
		
		y+=1;
			
		gotoxy(39,y++);
		textcolor(BRIGHTWHITE);
		setbuf(stdin, NULL);
		printf("NOME: ");
		puts(cadastro.nome);
			
		gotoxy(39,y++);
		textcolor(BRIGHTWHITE);
		printf("MATRICULA: ");
		puts(cadastro.matricula);
			
		gotoxy(39,y++);
		textcolor(BRIGHTWHITE);
		printf("CPF: ");
		puts(cadastro.cpf);
			
		gotoxy(39,y++);
		textcolor(BRIGHTWHITE);
		printf("IDENTIDADE: ");
		puts(cadastro.identidade);
			
		gotoxy(39,y++);
		setbuf(stdin, NULL);
		textcolor(BRIGHTWHITE);
		printf("CURSO: ");
		puts(cadastro.curso);
		gotoxy(39,y++);

	}	
	
	gotoxy(1,1);
	tecla = getch();
	
			
	//fecha o arquivo
	fclose(cadastrar);
	system("CLS");
	cadastroUsuario();
}

void menuAlteracao(){
	
	int tecla;
	int op = 1;
	int op2;
	int aux1;
	int aux2;
	int cpf;
	int aux4;
	int aux5;
	
	reescreverAlteracao(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
	
	do{
		tecla = getch();
		
		if(tecla == BAIXO){
			op++;
		}
		
		if(tecla == CIMA){
			op--;
		}
		
		if(tecla == ESC){
			system("cls");
			cadastroUsuario();
		}
		
		if(tecla == TAB){
		
			FILE* cadastrar = fopen(cadastrar_arq,"rb");
			FILE* cadastraraux = fopen(cadastrar_arqaux,"ab");
			rewind(cadastrar);
			
			if(cadastrar == NULL || cadastraraux == NULL){
				quadrado(3,3,117,30,LIGHTBLUE);
				textcolor(LIGHTRED);
				gotoxy(49,14);
				printf("ERRO AO SALVAR ARQUIVO");
				gotoxy(45,15);
				printf("PRESSIONE ENTER PARA CONTINUAR");
				gotoxy(1,1);
				getchar();
				system("cls");
				cadastroUsuario();
			}
			else{
				fwrite(&cadastro,sizeof(Cadastro),1,cadastraraux);
					while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
						if(strcmp(matriculaA, cadastro.matricula) != 0){
							fwrite(&cadastro,sizeof(Cadastro),1,cadastraraux);
					}
				}
			}
			
			fclose(cadastrar);
			fclose(cadastraraux);
			
			remove(cadastrar_arq);
			rename(cadastrar_arqaux,cadastrar_arq);
				
			textcolor(GREENWATER);
			gotoxy(55,26);
			printf("NOVA ALTERA%c%cO?",128,199);
			op2 = sim_nao(50,28);
		
			if(op2 == 1){
				system("CLS");
				alteracaoUsuario();
			}
			else{
				system("CLS");
				cadastroUsuario();
			}
		}
		
		switch(op){
			
			case 0:
				op = 5;
				reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,GREENWATER);
				break;
			case 1:
				reescreverAlteracao(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
				break;
			case 2:
				reescreverAlteracao(BRIGHTWHITE,GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
				break;
			case 3:
				reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
				break;
			case 4:
				reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,GREENWATER,BRIGHTWHITE);
				break;
			case 5:
				reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,GREENWATER);
				break;
			case 6:
				op = 1;
				reescreverAlteracao(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
				break;	
		}
		
	}while(tecla != ENTER || tecla == ESC);
	
	switch(op){
		case 1:
			reescreverAlteracao(LIGHTYELLOW,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
			gotoxy(38 + strlen(campo1),10);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo1),10);
				getString(cadastro.nome);
				aux1 = verificarLetra(cadastro.nome,100);
	
				if(cadastro.nome[0] == '\0'){
			       	gotoxy(38 + strlen(campo1),10);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo1),10);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(campo1),10);
		        	printf("                                            ");
				}
				
				if(aux1 == 0 ){
					gotoxy(38 + strlen(campo1),10);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo1),10);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo1),10);
		        	printf("                                            ");
				}
				
				if(strlen(cadastro.nome) > 100){
					gotoxy(38 + strlen(campo1),10);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo1),10);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo1),10);
		        	printf("                                            ");
				}	
			        
			}while(cadastro.nome[0] == '\0' || aux1 == 0 || strlen(cadastro.nome) > 100);
			if(cadastro.nome[0] == ESC){
				system("cls");
				cadastroUsuario();
			}
			menuAlteracao();
			break;
			
		case 2:
			reescreverAlteracao(BRIGHTWHITE,LIGHTYELLOW,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
			gotoxy(38 + strlen(campo2),13);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo2),13);
				getString(cadastro.matricula);
				aux2 = verificarNumeros(cadastro.matricula,12);
	
				if(cadastro.matricula[0] == '\0'){
			       	gotoxy(38 + strlen(campo2),13);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo2),13);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(campo2),13);
		        	printf("                                            ");
				}
				
				if(aux2 == 0){
					gotoxy(38 + strlen(campo2),13);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo2),13);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo2),13);
		        	printf("                                            ");
				}	
				
				if(strlen(cadastro.matricula) > 12){
					gotoxy(38 + strlen(campo2),13);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo2),13);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo2),13);
		        	printf("                                            ");
				}
			        
		}while(cadastro.matricula[0] == '\0' || aux2 == 0 || strlen(cadastro.matricula) > 12);
			if(cadastro.matricula[0] == ESC){
				system("cls");
				cadastroUsuario();
			}
			menuAlteracao();
			break;
			
		case 3:
			reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,LIGHTYELLOW,BRIGHTWHITE,BRIGHTWHITE);
			gotoxy(38 + strlen(campo3),16);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo3),16);
				getString(cadastro.cpf);
				cpf = validarCPF(cadastro.cpf);
			
				if(cadastro.cpf[0] == '\0'){
			        gotoxy(38 + strlen(campo3),16);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo3),16);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(campo3),16);
		        	printf("                                           ");
				}
				
				if(cpf == 0){
					gotoxy(38 + strlen(campo3),16);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo3),16);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo3),16);
		        	printf("                                           ");
				}
		        
			}while(cadastro.cpf[0] == '\0');
			if(cadastro.cpf[0] == ESC){
				system("cls");
				cadastroUsuario();
			}
			menuAlteracao();
			break;
			
		case 4:
			reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,LIGHTYELLOW,BRIGHTWHITE);
			gotoxy(38 + strlen(campo4),19);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo4),19);
				getString(cadastro.identidade);
				aux4 = verificarNumeros(cadastro.identidade,8);
	
				if(cadastro.identidade[0] == '\0'){
			       	gotoxy(38 + strlen(campo4),19);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo4),19);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(campo4),19);
		        	printf("                                            ");
				}
				
				if(aux4 == 0){
					gotoxy(38 + strlen(campo4),19);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo4),19);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo4),19);
		        	printf("                                            ");
				}	
				
				if(strlen(cadastro.identidade) > 8){
					gotoxy(38 + strlen(campo4),19);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo4),19);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo4),19);
		        	printf("                                            ");
				}
			        
			}while(cadastro.identidade[0] == '\0' || aux4 == 0 || strlen(cadastro.identidade) > 8);
			if(cadastro.identidade[0] == ESC){
				system("cls");
				cadastroUsuario();
			}
			menuAlteracao();
			break;
			
		case 5:
			reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,LIGHTYELLOW);
			gotoxy(38 + strlen(campo5),22);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo5),22);
				getString(cadastro.curso);
				aux5 = verificarLetra(cadastro.curso,11);
	
				if(cadastro.curso[0] == '\0'){
			       	gotoxy(38 + strlen(campo5),22);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo5),22);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(campo5),22);
		        	printf("                                            ");
				}
				
				if(aux5 == 0){
					gotoxy(38 + strlen(campo5),22);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo5),22);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo5),22);
		        	printf("                                            ");
				}
				
				if(strlen(cadastro.curso) > 11){
					gotoxy(38 + strlen(campo5),22);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo5),22);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(campo5),22);
		        	printf("                                            ");
				}	
			        
			}while(cadastro.curso[0] == '\0' || aux5 == 0 || strlen(cadastro.curso) > 11);
			if(cadastro.curso[0] == ESC){
				system("cls");
				cadastroUsuario();
			}
			menuAlteracao();
			break;
	}
}	

//Alteracao de Dados do Arquivo
void alteracaoUsuario(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("ALTERA%c%cO",128,199);
	
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	
	int op;
	int op1;
	int y = 9;
	int tecla;
	int encontrou = FALSE;
	
	textcolor(GREENWATER);
	gotoxy(43,9);
	printf("INFORME A MATRICULA QUE DESEJA ALTERAR");
	textcolor(BRIGHTWHITE);
	gotoxy(43,11);
	printf("MATRICULA: ");
	setbuf(stdin, NULL);
	gotoxy(54,11);
	getString(matriculaA);
	if(matriculaA[0] == ESC){
		system("cls");
		cadastroUsuario();
	}
	setbuf(stdin, NULL);
	
	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		if(strcmp(cadastro.matricula,matriculaA)==0){
			encontrou = TRUE;
			break;
		}
	}
	
	fclose(cadastrar);
	
	//NAO ENCONTROU
	if(!encontrou){
		textcolor(LIGHTRED);
		gotoxy(50,16);
		printf("MATRICULA N%cO ENCONTRADA\n",199);
		gotoxy(35,17);
		printf("PRESSIONE QUALQUER TECLA PARA INSIRA OS DADOS NOVAMENTE!");
		gotoxy(1,1);
		tecla = getch();
		if(tecla == ESC){
			system("cls");
			cadastroUsuario();
		}
		system("cls");
		alteracaoUsuario();
	}
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("ALTERA%c%cO",128,199);
	
	gotoxy(39,y++);
	textcolor(BRIGHTWHITE);
	setbuf(stdin, NULL);
	printf("NOME: ");
	puts(cadastro.nome);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("MATRICULA: ");
	puts(cadastro.matricula);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("CPF: ");
	puts(cadastro.cpf);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("IDENTIDADE: ");
	puts(cadastro.identidade);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	setbuf(stdin, NULL);
	printf("CURSO: ");
	puts(cadastro.curso);
	barrinha(39,y++,45);
	
	textcolor(GREENWATER);
	gotoxy(51,y+=2);
	printf("DESEJA ALTERAR OS DADOS?\n");
	op = sim_nao(51,y+=2);
	
	if(op == 1){
		quadrado(4,4,116,30,GREENWATER);
		
		criar_caixinha(46,3,30,2);
		textcolor(BRIGHTWHITE);
		gotoxy(58,4);
		printf("ALTERA%c%cO",128,199);
		
		textcolor(GREENWATER);
		gotoxy(53,7);
		printf("INSIRA OS NOVOS DADOS\n");
		
		menuAlteracao();
	}
	else{
		system("cls");
		cadastroUsuario();
	}
	
}

//Exclusao dos Dados do Arquivo
void exclusaoUsuario(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("EXCLUS%cO",199);
	
	int y = 8;
	int encontrou = FALSE;
	char matricula[13];
	int op;
	int op2;
	int tecla;
	
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	
	textcolor(GREENWATER);
	gotoxy(43,9);
	printf("INFORME A MATRICULA QUE DESEJA EXCLUIR");
	textcolor(BRIGHTWHITE);
	gotoxy(43,11);
	printf("MATRICULA: ");
	setbuf(stdin, NULL);
	gotoxy(54,11);
	getString(matricula);
	if(matricula[0] == ESC){
		system("cls");
		cadastroUsuario();
	}
	setbuf(stdin, NULL);
	
	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		if(strcmp(cadastro.matricula,matricula)==0){
			encontrou = TRUE;
			break;
		}
	}
	
	fclose(cadastrar);
	setbuf(stdin, NULL);
	
	//NAO ENCONTROU
	if(!encontrou){
		textcolor(LIGHTRED);
		gotoxy(50,16);
		printf("MATRICULA N%cO ENCONTRADA\n",199);
		gotoxy(35,17);
		printf("PRESSIONE QUALQUER TECLA PARA INSIRA OS DADOS NOVAMENTE!");
		gotoxy(1,1);
		tecla = getch();
		if(tecla == ESC){
			system("cls");
			cadastroUsuario();
		}
		system("cls");
		exclusaoUsuario();
	}
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("EXCLUS%cO",199);
	
	gotoxy(39,y++);
	textcolor(BRIGHTWHITE);
	setbuf(stdin, NULL);
	printf("NOME: ");
	puts(cadastro.nome);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("MATRICULA: ");
	puts(cadastro.matricula);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("CPF: ");
	puts(cadastro.cpf);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("IDENTIDADE: ");
	puts(cadastro.identidade);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	setbuf(stdin, NULL);
	printf("CURSO: ");
	puts(cadastro.curso);
	barrinha(39,y++,45);
	
	textcolor(GREENWATER);
	gotoxy(51,y+=2);
	printf("DESEJA EXCLUIR OS DADOS?\n");
	op = sim_nao(51,y+=2);
	
	if(op == 1){
		
		FILE* cadastraraux = fopen(cadastrar_arqaux,"ab");
		cadastrar = fopen(cadastrar_arq, "rb");
		
	
		if(cadastrar == NULL || cadastraraux == NULL){
			quadrado(4,4,116,30,GREENWATER);
			textcolor(LIGHTRED);
			gotoxy(49,14);
			printf("ERRO AO SALVAR ARQUIVO");
			gotoxy(45,15);
			printf("PRESSIONE ENTER PARA CONTINUAR");
			gotoxy(1,1);
			getchar();
			system("cls");
			cadastroUsuario();
		}
		else{
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(matricula,cadastro.matricula) != 0){
					fwrite(&cadastro,sizeof(Cadastro),1,cadastraraux);
				}
			}
		}
	
		fclose(cadastrar);
		fclose(cadastraraux);
		
		remove(cadastrar_arq);
		rename(cadastrar_arqaux,cadastrar_arq);
		
		textcolor(GREENWATER);
		gotoxy(51,20);
		printf("                                ");
		gotoxy(56,20);
		printf("NOVA EXCLUS%cO?",199);
		op2 = sim_nao(51,22);
		
		if(op2 == 1){
			exclusaoUsuario();
		}
		else{
			system("CLS");
			cadastroUsuario();
			}
		}
		else{
			system("CLS");
			cadastroUsuario();
		}
}

void cadastroPublicacao(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	int tecla;
	int op = 1;
	
	textcolor(GREENWATER);
	criar_caixinha(45,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(51,4);
	printf("CADASTRO DE PUBLICA%c%cO",128,199);
	
	reescreverCadastro(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
	
	do{
		tecla = getch();
		
		if(tecla == BAIXO){
			op++;
		}
		if(tecla == CIMA){
			op--;
		}
		if(tecla == ESC){
			menu();
		}
		
		switch(op){
			
			case 0:
				op = 4;
				reescreverCadastro(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,GREENWATER);
				break;
				
			case 1:
				reescreverCadastro(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
				break;
				
			case 2:
				reescreverCadastro(BRIGHTWHITE,GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
				break;
				
			case 3:
				reescreverCadastro(BRIGHTWHITE,BRIGHTWHITE,GREENWATER,BRIGHTWHITE);
				break;
				
			case 4:
				reescreverCadastro(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,GREENWATER);
				break;
				
			case 5:
				op = 1;
				reescreverCadastro(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
				break;
		}
	}while(tecla != ENTER || tecla == ESC);
	
	system("cls");
	
	switch(op){
		
		case 1:
			inclusaoPublicacao();
			break;
			
		case 2:
			consultaPublicacao();
			break;
			
		case 3:
			alteracaoPublicacao();
			break;
			
		case 4:
			exclusaoPublicacao();
			break;
	}
}

//Função que lê os dados e verifica se não existe no arquivo
void codigo(){
	
    //Abre o arquivo 
	FILE* publicacao = fopen(publicacao_arq,"rb");
	
	int encontrou;
	int tamanho;
	int aux;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(38,10);
	puts(codigo1);
	barrinha(38,11,47);
	
	do{
		encontrou = FALSE;
		
		textcolor(GREENWATER);
		gotoxy(38 + strlen(codigo1),10);
		setbuf(stdin, NULL);
		getString(codigoPublicacao);
		tamanho = strlen(codigoPublicacao);
		aux = verificarNumeros(codigoPublicacao,20);
	
		if(codigoPublicacao[0] == '\0'){
	        gotoxy(38 + strlen(codigo1),13);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),13);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(1000);
		}
		if(tamanho > 20){
			gotoxy(38 + strlen(codigo1),10);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),10);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(aux == 0){
			gotoxy(38 + strlen(codigo1),10);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),10);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(publicacao != NULL){
			
			rewind(publicacao);
			while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
				if(strcmp(publicar.codigo,codigoPublicacao) == 0){
					encontrou = TRUE;
				}
			}
		}
		
		if(encontrou == TRUE){
			gotoxy(38 + strlen(codigo1),10);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),10);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
				
	    gotoxy(38 + strlen(codigo1),10);
	    printf("                                            ");
	        
	}while(codigoPublicacao[0] == '\0' || tamanho > 20 || aux == 0 || encontrou == TRUE);
	
	fclose(publicacao);
	
	//Troca a Cor se Preenchido Corretamente
	if(matriculaUsuario[0] != ESC){
		
		textcolor(BRIGHTWHITE);
		gotoxy(38,10);
		puts(codigo1);
		gotoxy(38 + strlen(codigo1),10);
		setbuf(stdin, NULL);
		puts(codigoPublicacao);
		barrinha(38,11,47);
	}
}

void inclusaoPublicacao(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	int op;
	int op1;
	int op3;
	int tecla;
	int tamanho = 0;
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("INCLUS%cO",199);
	
	//Entrada de dados
	textcolor(BRIGHTWHITE);
	gotoxy(38,13);
	puts(titulo);
	barrinha(38,14,47);
	
	textcolor(BRIGHTWHITE);
	gotoxy(38,16);
	puts(autor);
	barrinha(38,17,47);

	//Código
	codigo();
	if(codigoPublicacao[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}
	
	//Título
	verificacaoChar(38,13,titulo,publicar.titulo,50,BRIGHTWHITE);
	
	if(codigoPublicacao[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}
	
	//Autor
	verificacaoChar(38,16,autor,publicar.autor,100,BRIGHTWHITE);
	
	if(publicar.autor[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}
	
	strcpy(publicar.codigo,codigoPublicacao);
	
	//Interagindo com o usuario
	
	textcolor(GREENWATER);
	gotoxy(45,21);
	printf("DESEJA SALVAR OS DADOS DA INCLUS%cO?",199);
	op = sim_nao(51,23);
	
	if(op == 1){
		
		//Abre o arquivo 
		FILE* publicacao = fopen(publicacao_arq,"ab");
		
		//Verifica se o arquivo realmente foi criado
		if(publicacao == NULL){
			quadrado(4,4,116,30,GREENWATER);
			textcolor(LIGHTRED);
			gotoxy(49,14);
			printf("ERRO AO SALVAR ARQUIVO");
			gotoxy(45,15);
			printf("PRESSIONE ENTER PARA CONTINUAR");
			gotoxy(1,1);
			getchar();
			system("cls");
			cadastroPublicacao();
		}
		
		//Se não ele escreve os dados no arquivo
		fwrite(&publicar,sizeof(Publicacao),1,publicacao);
		
		//E por fim, fecha o arquivo
		fclose(publicacao);
		
		textcolor(GREENWATER);
		gotoxy(45,21);
		printf("                                         ");
		gotoxy(56,21);
		printf("NOVA INCLUS%cO?",199);
		op1 = sim_nao(51,23);
		
		if(op1 == 1){
			system("cls");
			inclusaoPublicacao();
		}
		else
			system("CLS");
			cadastroPublicacao();
	}
	else
		system("CLS");
		cadastroPublicacao();
}

void consultaPublicacao(){
	
	int y = 6;
	int tecla;
	int cont = 0;
	
	//Abre o arquivo 
	FILE* publicacao = fopen(publicacao_arq,"rb");
	
	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(publicacao == NULL){ 
	
		quadrado(4,4,116,30,GREENWATER);
		criar_caixinha(46,3,30,2);
		textcolor(BRIGHTWHITE);
		gotoxy(58,4);
		printf("CONSULTA");
		
		textcolor(LIGHTRED);
		gotoxy(51,15);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(46,16);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		cadastroPublicacao();
	}
	
	
	//Faz a verificação de quantos cadastros tem no arquivo
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		cont++;
	}
	
	//Fecha o arquivo
	fclose(publicacao);
	
	if(cont <= 4){
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,35);
		criar_caixinha(4,3,116,31);
		
		textcolor(GREENWATER);
		gotoxy(43,32);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
		
	}else{
		int aux = cont * 8 + 2;
		
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,aux - 1);
		criar_caixinha(3,3,116,aux - 5);
		
		textcolor(GREENWATER);
		gotoxy(43,aux - 4);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
		
	}
	criar_caixinha(46,2,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,3);
	printf("CONSULTA");
	
	//Reabre o arquivo em modo de leitura binária
	publicacao = fopen(publicacao_arq,"rb");
	
	//Verifica se o arquivo existe, caso não, exibi uma mensagem de erro
	if(publicacao == NULL){
		
		quadrado(4,4,116,30,GREENWATER);
		textcolor(LIGHTRED);
		gotoxy(49,14);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(45,15);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		cadastroPublicacao();
	}
	
	//Caso não tenha nenhum erro ele exibe o que tem no arquivo
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		
		textcolor(GREENWATER);
		criar_caixinha(38,y,45,4);
		
		y+=1;
			
		gotoxy(39,y++);
		textcolor(BRIGHTWHITE);
		setbuf(stdin, NULL);
		printf("CODIGO: ");
		puts(publicar.codigo);
			
		gotoxy(39,y++);
		printf("TITULO: ");
		puts(publicar.titulo);
			
		gotoxy(39,y++);
		printf("AUTOR: ");
		puts(publicar.autor);
		
		y+=2;

	}	
	
	gotoxy(1,1);
	tecla = getch();
	
	//fecha o arquivo
	fclose(publicacao);
	system("CLS");
	cadastroPublicacao();
}

void menuAlterarPublicacao(){
	
	int tecla;
	int op = 1;
	int op2;
	int aux1;
	int aux2;
	int aux3;
	
	reescreverAlteracaoPublic(GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
	
	do{
		tecla = getch();
		
		if(tecla == BAIXO){
			op++;
		}
		
		if(tecla == CIMA){
			op--;
		}
		
		if(tecla == ESC){
			system("cls");
			cadastroUsuario();
		}
		
		if(tecla == TAB){
			FILE* publicacaoaux = fopen(publicacao_arqaux,"ab");
			FILE* publicacao = fopen(publicacao_arq,"rb");
			rewind(publicacao);
			
			if(publicacao == NULL || publicacaoaux == NULL){
				quadrado(3,3,117,30,LIGHTBLUE);
				textcolor(LIGHTRED);
				gotoxy(49,14);
				printf("ERRO AO SALVAR ARQUIVO");
				gotoxy(45,15);
				printf("PRESSIONE ENTER PARA CONTINUAR");
				gotoxy(1,1);
				getchar();
				system("cls");
				cadastroPublicacao();
			}
			fwrite(&publicar,sizeof(Publicacao),1,publicacaoaux);
				while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
					if(strcmp(codigoPublicacao,publicar.codigo) != 0){
						fwrite(&publicar,sizeof(Publicacao),1,publicacaoaux);
				}
			}
			
			fclose(publicacao);
			fclose(publicacaoaux);
			
			remove(publicacao_arq);
			rename(publicacao_arqaux,publicacao_arq);
			
			gotoxy(44,21);
			printf("                                       ");
			textcolor(GREENWATER);
			gotoxy(56,21);
			printf("NOVA ALTERA%c%cO?",128,199);
			op2 = sim_nao(51,23);// Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe 
			
			if(op2 == 1){
				alteracaoPublicacao();
			}
			else{
				system("CLS");
				cadastroPublicacao();
			}
		}
		
		switch(op){
			
			case 0:
				op = 3;
				reescreverAlteracaoPublic(BRIGHTWHITE,BRIGHTWHITE,GREENWATER);
				break;
			case 1:
				reescreverAlteracaoPublic(GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
				break;
			case 2:
				reescreverAlteracaoPublic(BRIGHTWHITE,GREENWATER,BRIGHTWHITE);
				break;
			case 3:
				reescreverAlteracaoPublic(BRIGHTWHITE,BRIGHTWHITE,GREENWATER);
				break;
			case 4:
				op = 1;
				reescreverAlteracaoPublic(GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
				break;	
		
		}
		
	}while(tecla != ENTER || tecla == ESC);
	
	switch(op){
		case 1:
			reescreverAlteracaoPublic(LIGHTYELLOW,BRIGHTWHITE,BRIGHTWHITE);
			gotoxy(38 + strlen(codigo1),11);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(codigo1),11);
				getString(publicar.codigo);
				aux1 = verificarNumeros(publicar.codigo,20);
	
				if(publicar.codigo[0] == '\0'){
			       	gotoxy(38 + strlen(codigo1),11);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(codigo1),11);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(codigo1),11);
		        	printf("                                            ");
				}
				
				if(aux1 == 0 ){
					gotoxy(38 + strlen(codigo1),11);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(codigo1),11);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(codigo1),11);
		        	printf("                                            ");
				}
				
				if(strlen(publicar.codigo) > 20){
					gotoxy(38 + strlen(codigo1),11);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(codigo1),11);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(codigo1),11);
		        	printf("                                            ");
				}	
			        
			}while(publicar.codigo[0] == '\0' || aux1 == 0 || strlen(publicar.codigo) > 20);
			
			if(publicar.codigo[0] == ESC){
				system("cls");
				cadastroPublicacao();
			}
			menuAlterarPublicacao();
			break;
			
		case 2:
			reescreverAlteracaoPublic(BRIGHTWHITE,LIGHTYELLOW,BRIGHTWHITE);
			gotoxy(38 + strlen(titulo),14);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(titulo),14);
				getString(publicar.titulo);
				aux2 = verificarLetra(publicar.titulo,50);
	
				if(publicar.titulo[0] == '\0'){
			       	gotoxy(38 + strlen(titulo),14);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(titulo),14);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(titulo),14);
		        	printf("                                            ");
				}
				
				if(aux2 == 0){
					gotoxy(38 + strlen(titulo),14);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(titulo),14);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(titulo),14);
		        	printf("                                            ");
				}
				
				if(strlen(publicar.titulo) > 50){
					gotoxy(38 + strlen(titulo),14);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(titulo),14);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(titulo),14);
		        	printf("                                            ");
				}	
			        
			}while(publicar.titulo[0] == '\0' || aux2 == 0 || strlen(publicar.titulo) > 50);
			
			if(publicar.titulo[0] == ESC){
				system("cls");
				cadastroPublicacao();
			}
			menuAlterarPublicacao();
			break;
			
		case 3:
			reescreverAlteracaoPublic(BRIGHTWHITE,BRIGHTWHITE,LIGHTYELLOW);
			gotoxy(38 + strlen(autor),17);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(autor),17);
				getString(publicar.autor);
				aux3 = verificarLetra(publicar.autor,100);
	
				if(publicar.autor[0] == '\0'){
			       	gotoxy(38 + strlen(autor),17);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(autor),17);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(1000);
					gotoxy(38 + strlen(autor),17);
		        	printf("                                            ");
				}
				
				if(aux3 == 0){
					gotoxy(38 + strlen(autor),17);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(autor),17);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(autor),17);
		        	printf("                                            ");
				}	
			        
			    if(strlen(publicar.autor) > 100){
			    	gotoxy(38 + strlen(autor),17);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(autor),17);
					printf("INV%cLIDO",181);
					Sleep(1000);
					gotoxy(38 + strlen(autor),17);
		        	printf("                                            ");
				}
			}while(publicar.autor[0] == '\0' || aux3 == 0 || strlen(publicar.autor) > 100);
			
			if(publicar.autor[0] == ESC){
				system("cls");
				cadastroPublicacao();
			}
			menuAlterarPublicacao();
			break;
	}
}

void alteracaoPublicacao(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("ALTERA%c%cO",128,199);
	
	//Abre o arquivo em modo de leitura binária
	FILE* publicacao = fopen(publicacao_arq,"rb");
	
	int y = 10;
	int op;
	int op1;
	int encontrou = FALSE;
	int tecla;

	textcolor(GREENWATER);
	gotoxy(44,9);
	printf("INFORME O CODIGO QUE DESEJA ALTERAR");
	textcolor(BRIGHTWHITE);
	gotoxy(44,11);
	printf("CODIGO: ");
	setbuf(stdin, NULL);
	gotoxy(52,11);
	getString(codigoPublicacao);
	if(codigoPublicacao[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}
	setbuf(stdin, NULL);
	
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		if(strcmp(publicar.codigo,codigoPublicacao) == 0){
			encontrou = TRUE;
			break;
		}
	}
	
	fclose(publicacao);
	
	//NAO ENCONTROU
	if(! encontrou){
		textcolor(LIGHTRED);
		gotoxy(50,16);
		printf("CODIGO N%cO ENCONTRADO",199);
		gotoxy(35,17);
		printf("PRESSIONE QUALQUER TECLA PARA INSIRA OS DADOS NOVAMENTE!");
		gotoxy(1,1);
		tecla = getch();
		if(tecla == ESC){
			system("cls");
			cadastroPublicacao();
		}
		system("cls");
		alteracaoPublicacao();

	}
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("ALTERA%c%cO",128,199);
	
	gotoxy(39,y++);
	textcolor(BRIGHTWHITE);
	setbuf(stdin, NULL);
	printf("CODIGO: ");
	puts(publicar.codigo);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("TITULO: ");
	puts(publicar.titulo);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("AUTOR: ");
	puts(publicar.autor);
	barrinha(39,y++,45);
	
	textcolor(GREENWATER);
	gotoxy(51,19);
	printf("DESEJA ALTERAR OS DADOS?\n");
	op = sim_nao(51,21); // Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe 
	
	if(op == 1){ // op recebe 1 e indica que ele escolheu sim
		quadrado(4,4,116,30,GREENWATER);
	
		criar_caixinha(46,3,30,2);
		textcolor(BRIGHTWHITE);
		gotoxy(58,4);
		printf("ALTERA%c%cO",128,199);
		
		textcolor(GREENWATER);
		gotoxy(53,8);
		printf("INSIRA OS NOVOS DADOS\n");
		
		menuAlterarPublicacao();
	}
	else
		system("CLS");
		cadastroPublicacao();
}

void exclusaoPublicacao(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("EXCLUS%cO",199);
	
	int y = 10;
	int encontrou = FALSE;
	char codigo[20];
	int op;
	int op2;
	int tecla;
	
	FILE* publicacao = fopen(publicacao_arq,"rb");
	
	textcolor(GREENWATER);
	gotoxy(43,9);
	printf("INFORME O CODIGO QUE DESEJA EXCLUIR");
	textcolor(BRIGHTWHITE);
	gotoxy(43,11);
	printf("CODIGO: ");
	setbuf(stdin, NULL);
	gotoxy(51,11);
	getString(codigo);
	if(codigo[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}
	setbuf(stdin, NULL);
	
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		if(strcmp(publicar.codigo,codigo)==0){
			encontrou = TRUE;
			break;
		}
	}
	
	fclose(publicacao);
	setbuf(stdin, NULL);
	
	//NAO ENCONTROU
	if(!encontrou){
		textcolor(LIGHTRED);
		gotoxy(50,16);
		printf("CODIGO N%cO ENCONTRADO",199);
		gotoxy(35,17);
		printf("PRESSIONE QUALQUER TECLA PARA INSIRA OS DADOS NOVAMENTE!");
		gotoxy(1,1);
		tecla = getch();
		if(tecla == ESC){
			system("cls");
			cadastroPublicacao();
		}
		system("cls");
		exclusaoPublicacao();
	}
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(46,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(58,4);
	printf("EXCLUS%cO",199);

	gotoxy(39,y++);
	textcolor(BRIGHTWHITE);
	setbuf(stdin, NULL);
	printf("CODIGO: ");
	puts(publicar.codigo);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("TITULO: ");
	puts(publicar.titulo);
	barrinha(39,y++,45);
	
	gotoxy(39,y++);
	printf("AUTOR: ");
	puts(publicar.autor);
	barrinha(39,y++,45);
		
	textcolor(GREENWATER);
	gotoxy(51,19);
	printf("DESEJA EXCLUIR OS DADOS?\n");
	op = sim_nao(51,21); // Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe 
	
	if(op == 1){ // op recebe 1 e indica que ele escolheu sim
		FILE* publicacaoaux = fopen(publicacao_arqaux,"ab");
		publicacao = fopen(publicacao_arq,"rb");
		
	
	if(publicacao == NULL || publicacaoaux == NULL){
		quadrado(4,4,116,30,GREENWATER);
		textcolor(LIGHTRED);
		gotoxy(49,14);
		printf("ERRO AO SALVAR ARQUIVO");
		gotoxy(45,15);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		cadastroPublicacao();
	}
	else{
		while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
			if(strcmp(codigo, publicar.codigo) != 0){
				fwrite(&publicar,sizeof(Publicacao),1,publicacaoaux);
			}
		}
	}
	
	fclose(publicacao);
	fclose(publicacaoaux);
	
	remove(publicacao_arq);
	rename(publicacao_arqaux,publicacao_arq);
	
	gotoxy(51,19);
	printf("                           ");
	textcolor(GREENWATER);
	gotoxy(56,19);
	printf("NOVA EXCLUS%cO?",199);
	op2 = sim_nao(51,21); // Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe 
	
	
	if(op2 == 1){
		exclusaoPublicacao();
	}
	else{
		system("CLS");
		cadastroPublicacao();
		}
	}
	else{
		system("CLS");
		cadastroPublicacao();
	}
}

//Função que exibe as opções da movimentção 
void movimentacao(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(45,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(55,4);
	printf("MOVIMENTA%c%cO",128,199);
	
	int tecla;
	int op = 1;
	
	reescreverMovimentacao(GREENWATER,BRIGHTWHITE);
	
	do{
		tecla = getch();
		
		if(tecla == BAIXO){
			op++;
		}
		if(tecla == CIMA){
			op--;
		}
		if(tecla == ESC){
			system("cls");
			menu();
		}
		
		switch(op){
			case 0:
				op = 2;
				reescreverMovimentacao(BRIGHTWHITE,GREENWATER);
				break;
				
			case 1:
				reescreverMovimentacao(GREENWATER,BRIGHTWHITE);
				break;
				
			case 2:
				reescreverMovimentacao(BRIGHTWHITE,GREENWATER);
				break;
				
			case 3:
				op = 1;
				reescreverMovimentacao(GREENWATER,BRIGHTWHITE);
				break;
		}
	}while(tecla != ENTER);
	
	switch(op){
		case 1:
			emprestimoPublicacao();
			break;
			
		case 2:
			devolucao();
			break;
	}
}

//Função que lê os dados e verifica se não existe no arquivo
/*void Identificador(){
	
	FILE* emprestimo = fopen(emprestimo_arq,"rb");
	
	int encontrou;
	int tamanho;
	int aux;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(37,16);
	puts(id);
	barrinha(37,17,47);
	
	do{
		encontrou = FALSE;
		
		textcolor(GREENWATER);
		gotoxy(37 + strlen(id),16);
		setbuf(stdin, NULL);
		getString(identificar);
		tamanho = strlen(identificar);
		aux = verificarNumeros(identificar,50);
	
		if(identificar[0] == '\0'){
	        gotoxy(37 + strlen(id),16);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(37 + strlen(id),16);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(1000);
		}
		if(tamanho > 13){
			gotoxy(37 + strlen(id),16);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(37 + strlen(id),16);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(aux == 0){
			gotoxy(37 + strlen(id),16);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(37 + strlen(id),16);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(emprestimo != NULL){
			
			rewind(emprestimo);
			while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
				if(strcmp(emprestar.identificador,identificar) == 0){
					encontrou = TRUE;
				}
			}
		}
		if(encontrou == TRUE){
			gotoxy(37 + strlen(id),16);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(37 + strlen(id),16);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
				
	    gotoxy(37 + strlen(id),16);
	    printf("                                            ");
	        
	}while(identificar[0] == '\0' || tamanho > 13 || aux == 0 || encontrou == TRUE);
	
	fclose(emprestimo);
	
	//Troca a Cor se Preenchido Corretamente
	if(identificar[0] != ESC){
		
		textcolor(BRIGHTWHITE);
		gotoxy(37,16);
		puts(id);
		gotoxy(37 + strlen(id),16);
		setbuf(stdin, NULL);
		puts(identificar);
		barrinha(37,17,47);
	}
}*/

//livro
void livro2(){
	
	textcolor(BRIGHTWHITE);
	/*gotoxy(15,17); printf("       .--.           .---.        .-.");
    gotoxy(15,18); printf("   .---|--|   .-.     | S |  .---. |~|    .--.");
    gotoxy(15,19); printf(".--|===| B|---|_|--.__| T |--|:::| |~|-==-|==|---.");
    gotoxy(15,20); printf("|%c%c|NT2| O|===| |~~|%c%c| O |--|   |_|~|CATS|  |___|-.",37,37,37,37);
    gotoxy(15,21); printf("|  |   | O|===| |==|  | R |  |:::|=| |    |GB|---|=|");
    gotoxy(15,22); printf("|  |   | K|   |_|__|  | E |__|   | | |    |  |___| |");
    gotoxy(15,23); printf("|~~|===|--|===|~|~~|%c%c|~~~|--|:::|=|~|----|==|---|=|",37,37);
    gotoxy(15,24); printf("^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'");
    */
	gotoxy(15,17); printf("           .--.                   .---.");
	gotoxy(15,18); printf("       .---|__|           .-.     |~~~|");
	gotoxy(15,19); printf("    .--|===|--|_          |_|     |~~~|--.");
	gotoxy(15,20); printf("    |  |===|  |'%c     .---!~|  .--|   |--|",92);
	gotoxy(15,21); printf("    |%c%c|   |  |.'%c    |===| |--|%c%c|   |  |",37,37,92,37,37);
	gotoxy(15,22); printf("    |%c%c|   |  |%c.'%c   |   | |__|  |   |  |",37,37,92,92);
	gotoxy(15,23); printf("   _|  |   |  | %c  %c  |===| |==|  |   |  |_",92,92);
	gotoxy(15,24); printf("  / |  |   |__|  %c.'%c |   |_|__|  |~~~|__| %c",92,92,92);
	gotoxy(15,25); printf(" /  |  |===|--|   %c.'%c|===|~|--|%c%c|~~~|--|  %c",92,92,37,37,92);
	gotoxy(15,26); printf("/   ^--^---'--^    `-'`---^-^--^--^---'--'   %c",92);
	gotoxy(15,27); printf("'=============================================`");
}

//Funcao que gera o numero de tombo do livro emprestado
void numeroTombo(){
	
	FILE* emprestimo = fopen(emprestimo_arq,"rb");
	
	srand(time(NULL));//semente para gerar os números aleatórios
	
	int encontrou = FALSE;
	
    numero  = (rand() % 500)+1;
	
	if(emprestimo != NULL){
		while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
			if(numero == emprestar.numeroTombo){
				encontrou = TRUE;
				break;
			}
		}
	}
	
	if(encontrou == TRUE){
		numeroTombo();
	}
	
	fclose(emprestimo);
}

//Função responsavel pelo emprestimo de publicacao
void emprestimoPublicacao(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	int op;
	int tecla;
	int encontrou = FALSE;
	char cod[20];
	
	criar_caixinha(44,3,32,2);
	textcolor(BRIGHTWHITE);
	gotoxy(50,4);
	printf("EMPRESTIMO DE PUBLICA%c%cO",128,199);
	
	FILE* publicacao = fopen(publicacao_arq,"rb");

	textcolor(GREENWATER);
	gotoxy(35,9);
	printf("INFORME O C%cDIGO DA PUBLICA%c%cO QUE DESEJA EMPRESTAR",224,128,199);
	
	//Entrada de dados
			
	//Código
	verificacaoInt(38,13,codigo1,emprestar.codigo,20,BRIGHTWHITE);
	if(emprestar.codigo[0] == ESC){
		system("cls");
		movimentacao();
	}
	
	strcpy(cod,emprestar.codigo);
	
	numeroTombo();
	
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		if(strcmp(cod,publicar.codigo) == 0){
			strcpy(emprestar.autor,publicar.autor);
			strcpy(emprestar.titulo,publicar.titulo);
				encontrou = TRUE;
				break;
		}
	}
		
	fclose(publicacao);
	
	if(! encontrou){
		textcolor(LIGHTRED);
		gotoxy(49,22);
		printf("PUBLICA%c%cO INDISPON%cVEL",128,199,214);
		gotoxy(34,23);
		printf("PRESSIONE QUALQUER TECLA PARA INSIRA OS DADOS NOVAMENTE!");
		gotoxy(1,1);
		tecla = getch();
		if(tecla == ESC){
			system("cls");
			movimentacao();
		}
		system("cls");
		emprestimoPublicacao();
	}
	
	//Le os dados do usuario que deseja emprestar a publicacao
	textcolor(GREENWATER);
	gotoxy(50,22);
	printf("PUBLICA%c%cO DISPON%cVEL",128,199,214);
	gotoxy(42,23);
	printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR");
	gotoxy(1,1);
	tecla = getch();
	if(tecla == ESC){
		system("cls");
		movimentacao();
	}
	
	dadosUsuario();
	
	publicacao = fopen(publicacao_arq,"rb");
	
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		if(strcmp(cod,publicar.codigo) == 0){
		
			quadrado(4,4,116,30,GREENWATER);	
			criar_caixinha(44,3,32,2);
			textcolor(BRIGHTWHITE);
			gotoxy(50,4);
			printf("EMPRESTIMO DE PUBLICA%c%cO",128,199);
			
			gotoxy(38,9);
			textcolor(BRIGHTWHITE);
			setbuf(stdin, NULL);
			printf("CODIGO: ");
			puts(publicar.codigo);
			barrinha(38,10,47);
				
			gotoxy(38,12);
			printf("TITULO: ");
			puts(publicar.titulo);
			barrinha(38,13,47);
				
			gotoxy(38,15);
			printf("AUTOR: ");
			puts(publicar.autor);
			barrinha(38,16,47);
			
			break;
		}
	}
	
	fclose(publicacao);
	
	emprestar.numeroTombo = numero;
	strcpy(emprestar.codigo,cod);
	
	textcolor(GREENWATER);
	gotoxy(46,21);
	printf("DESEJA EMPRESTAR A PUBLICA%c%cO?",128,199);
	op = sim_nao(49,23);
	
	if(op == 1){
		
	FILE* emprestimo = fopen(emprestimo_arq,"ab");
	
	if(emprestimo == NULL){
		quadrado(4,4,116,30,GREENWATER);
		textcolor(LIGHTRED);
		gotoxy(49,14);
		printf("ERRO AO SALVAR ARQUIVO");
		gotoxy(45,15);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		movimentacao();
	}
	
		emprestar.situacao = EMPRESTADO;
		
		fwrite(&emprestar,sizeof(Emprestimo),1,emprestimo);
		
		fclose(emprestimo);
		
		gotoxy(43,21);
		printf("                                                      ");
		gotoxy(43,22);
		printf("                                                      ");
		gotoxy(43,23);
		printf("                                                      ");
		gotoxy(43,24);
		printf("                                                      ");
		gotoxy(43,25);
		printf("                                                      ");
		gotoxy(1,1);
		
		
		for(int i = 0; i < 3; i++){
			Sleep(450);
			gotoxy(1,1);
			textcolor(LIGHTGREEN);
			criar_caixinha(43,21,36,2);
			gotoxy(46,22);
			printf("EMPRESTIMO EFETUADO COM SUCESSO!");
			gotoxy(1,1);
			Sleep(450);
			gotoxy(43,21);
			printf("                                                      ");
			gotoxy(1,1);
			gotoxy(43,22);
			printf("                                                      ");
			gotoxy(1,1);
			gotoxy(43,23);
			printf("                                                      ");
			gotoxy(1,1);
			
		}
	}
	
	
	system("cls");
	movimentacao();
}

void matriculaEmprestimo(){
	
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	
	int encontrou;
	int tamanho;
	int aux;
	
	//Campo
	textcolor(GREENWATER);
	gotoxy(38,16);
	puts(campo2);
	barrinha(38,17,47);
	
	do{
		encontrou = FALSE;
		
		textcolor(GREENWATER);
		gotoxy(38 + strlen(campo2),16);
		setbuf(stdin, NULL);
		getString(emprestarMatricula);
		tamanho = strlen(emprestarMatricula);
		aux = verificarNumeros(emprestarMatricula,12);
	
		if(emprestarMatricula[0] == '\0'){
	        gotoxy(38 + strlen(campo2),16);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),16);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(1000);
		}
		if(tamanho > 12){
			gotoxy(38 + strlen(campo2),16);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),16);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(aux == 0){
			gotoxy(38 + strlen(campo2),16);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),16);
			printf("INV%cLIDO",181);
			Sleep(1000);
		}
		if(cadastrar != NULL){
			
			rewind(cadastrar);
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(emprestarMatricula,cadastro.matricula) == 0){
					encontrou = TRUE;
				}
			}
		}
		
		if(!encontrou){
			gotoxy(38 + strlen(campo2),16);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),16);
			printf("USU%cRIO N%cO ENCONTRADO",181,199);
			Sleep(1000);
		}
				
	    gotoxy(38 + strlen(campo2),16);
	    printf("                                            ");
	        
	}while(emprestarMatricula[0] == '\0' || tamanho > 12 || aux == 0 || encontrou != TRUE);
	
	fclose(cadastrar);
	
	//Troca a Cor se Preenchido Corretamente
	if(emprestarMatricula[0] != ESC){
		
		textcolor(BRIGHTWHITE);
		gotoxy(38,16);
		puts(campo2);
		gotoxy(38 + strlen(campo2),16);
		setbuf(stdin, NULL);
		puts(emprestarMatricula);
		barrinha(38,17,47);
	}
}

void dadosUsuario(){
	
	int tecla;
	int encontrou = FALSE;
	
	textcolor(GREENWATER);
	gotoxy(35,9);
	printf("                                                     ");
	gotoxy(50,22);
	printf("                                                      ");
	gotoxy(42,23);
	printf("                                                         ");
	gotoxy(51,9);
	printf("INFORME SUA MATRICULA");
	
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	
	//Matricula
	matriculaEmprestimo();
	if(emprestarMatricula[0] == ESC){
		system("cls");
		consulta_de_acervo();
	}
	
	strcpy(emprestarMatricula,emprestar.matricula);
	
	for(int i = 0; i < 3; i++){
		
		Sleep(450);
		gotoxy(1,1);
		textcolor(LIGHTGREEN);
		criar_caixinha(49,23,24,2);
		gotoxy(52,24);
		printf("PUBLICA%c%cO DISPON%cVEL",128,199,214);
		gotoxy(1,1);
		Sleep(450);
		gotoxy(49,23);
		printf("                                                      ");
		gotoxy(1,1);
		gotoxy(49,24);
		printf("                                                      ");
		gotoxy(1,1);
		gotoxy(49,25);
		printf("                                                      ");
		gotoxy(1,1);
	
	}
	
}

//Função que efetua a devolucacao de determinada publicação
void devolucao(){
	
	int y = 7;
	int tecla;
	int encontrar = FALSE;
	int encontrou = FALSE;
	int op;
	
	FILE* emprestimo = fopen(emprestimo_arq,"rb");
	
	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(emprestimo == NULL){ 
	
		quadrado(4,4,116,30,GREENWATER);
		
		criar_caixinha(44,3,32,2);
		textcolor(BRIGHTWHITE);
		gotoxy(50,4);
		printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);
		
		textcolor(LIGHTRED);
		gotoxy(51,15);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(46,16);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		menu();
	}
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(44,3,32,2);
	textcolor(BRIGHTWHITE);
	gotoxy(50,4);
	printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);
	
	textcolor(GREENWATER);
	gotoxy(38,9);
	printf("INFORME SUA MATRICULA E O C%cDIGO DA PUBLICA%c%cO",224,128,199);
	
	//Entrada de dados
	textcolor(BRIGHTWHITE);
	gotoxy(38,16);
	puts(codigo1);
	barrinha(38,17,47);
	
	//Matricula
	verificacaoInt(38,13,campo2,devolver.matricula,12,BRIGHTWHITE);
	if(devolver.matricula[0] == ESC){
		system("cls");
		movimentacao();
	}
	
	//Codigo
	verificacaoInt(38,16,codigo1,devolver.codigo,20,BRIGHTWHITE);
	if(devolver.codigo[0] == ESC){
		system("cls");
		movimentacao();
	}
	
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
		if(strcmp(devolver.matricula,emprestar.matricula) == 0){
			if(strcmp(devolver.codigo,emprestar.codigo) == 0){
				devolver.numeroTombo = emprestar.numeroTombo;
				encontrou = TRUE;
				break;
			}
		}
	}

	if(!encontrou){
		textcolor(LIGHTRED);
		gotoxy(52,22);
		printf("DADOS N%cO ENCONTRADOS",199);
		gotoxy(34,23);
		printf("PRESSIONE QUALQUER TECLA PARA INSIRA OS DADOS NOVAMENTE!");
		gotoxy(1,1);
		tecla = getch();
		if(tecla == ESC){
			system("cls");
			movimentacao();
		}
		system("cls");
		devolucao();
	}
	
	rewind(emprestimo);
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
		if(devolver.numeroTombo == emprestar.numeroTombo){
			
			quadrado(4,4,116,30,GREENWATER);	
			criar_caixinha(44,3,32,2);
			textcolor(BRIGHTWHITE);
			gotoxy(50,4);
			printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);
			
			gotoxy(38,9);
			textcolor(BRIGHTWHITE);
			setbuf(stdin, NULL);
			printf("CODIGO: ");
			puts(emprestar.codigo);
			barrinha(38,10,47);
				
			gotoxy(38,12);
			printf("TITULO: ");
			puts(emprestar.titulo);
			barrinha(38,13,47);
				
			gotoxy(38,15);
			printf("AUTOR: ");
			puts(emprestar.autor);
			barrinha(38,16,47);
			
			break;
		}
	}
	
	fclose(emprestimo);
	
	textcolor(GREENWATER);
	gotoxy(47,20);
	printf("DESEJA DEVOLVER A PUBLICA%c%cO?",128,199);
	op = sim_nao(50,22);
	
	if(op == 1){
				
		FILE* emprestimoaux = fopen(emprestimo_arqaux,"ab");
		emprestimo = fopen(emprestimo_arq,"rb");
		
		while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
			if(devolver.numeroTombo == emprestar.numeroTombo){
				emprestar.situacao = DEVOLVIDO;
				fwrite(&emprestar,sizeof(Emprestimo),1,emprestimoaux);
			}
		}
		
		rewind(emprestimo);
		while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
			if(devolver.numeroTombo != emprestar.numeroTombo){
				fwrite(&emprestar,sizeof(Emprestimo),1,emprestimoaux);
			}
		}
		                        
		fclose(emprestimo);
		fclose(emprestimoaux);
		
		remove(emprestimo_arq);
		rename(emprestimo_arqaux,emprestimo_arq);
		
	}
	
	system("cls");
	movimentacao();
	
}

//Função que possibilita o usuario verificar seus emprestimos, devoluções e publicações
void consulta_de_acervo(){
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(45,3,30,2);
	textcolor(BRIGHTWHITE);
	gotoxy(52,4);
	printf("CONSULTA DE ACERVO");	
	int tecla;
	int op = 1;
	
	reescreverAcervo(GREENWATER,BRIGHTWHITE);
	
	do{
		tecla = getch();
		
		if(tecla == BAIXO){
			op++;
		}
		if(tecla == CIMA){
			op--;
		}
		if(tecla == ESC){
			system("cls");
			menu();
		}
		
		switch(op){
			case 0:
				op = 2;
				reescreverAcervo(BRIGHTWHITE,GREENWATER);
				break;
				
			case 1:
				reescreverAcervo(GREENWATER,BRIGHTWHITE);
				break;
				
			case 2:
				reescreverAcervo(BRIGHTWHITE,GREENWATER);
				break;
				
			case 3:
				op = 1;
				reescreverAcervo(GREENWATER,BRIGHTWHITE);
				break;
		}
	}while(tecla != ENTER);
	
	switch(op){
		case 1:
			acervoUsuario();
			break;
			
		case 2:
			consultarAcervo();
			break;
	}
}

int opcoes(){
	
	int tecla;
	int op = 2;
	
	reescreverCarteira(GREENWATER,LIGHTGREEN,32,28);
	
	do{
		tecla = getch();
		
		if(tecla == ESQUERDA){
			op++;
		}
		if(tecla == DIREITA){
			op--;
		}
		if(tecla == ESC){
			system("cls");
			consulta_de_acervo();
		}
		
		switch(op){
			case 0:
				op = 2;
				reescreverCarteira(GREENWATER,LIGHTGREEN,32,28);
				break;
					
			case 1:
				reescreverCarteira(LIGHTRED,GREENWATER,32,28);
				break;
				
			case 2:
				reescreverCarteira(GREENWATER,LIGHTGREEN,32,28);
				break;
			case 3:
				op = 1;
				reescreverCarteira(LIGHTRED,GREENWATER,32,28);
				break;
		}
	}while(tecla != 13);
	
	return op;
}

void carteiraUsuario(char nome[], char matricula[], char curso[], char cpf[], char rg[]){
	
	textcolor(GREENWATER);
	criar_caixinha(32,8,55,16);
	
	textcolor(LIGHTRED);
	gotoxy(35,10);
	printf("%c",223);
	gotoxy(36,10);
	textcolor(LIGHTGREEN);
	printf(" %c %c",223,223);
	
	gotoxy(35,11);
	printf("%c %c",223,223);
	gotoxy(35,12);
	printf("%c %c %c",223,223,223);
	gotoxy(35,13);
	printf("%c %c",223,223);
	
	textcolor(GREENWATER);
	gotoxy(44,10);
	printf("INSTITUTO FEDERAL DE");
	gotoxy(44,11);
	printf("EDUCACAO, CIENCIA E TECNOLOGIA");
	gotoxy(44,12);
	printf("DO AMAZONAS");
	
	textcolor(GREENWATER);
	criar_caixinha(77,9,8,5);
	gotoxy(79,10);
	printf("~~   ~~");
	gotoxy(80,11);
	printf("@   @");
	gotoxy(82,12);
	printf("^");
	gotoxy(81,13);
	printf("===");
	
	textcolor(LIGHTRED);
	gotoxy(52,14);
	printf("DADOS DE USUARIO");
	
	textcolor(GREENWATER);
	criar_caixinha(34,15,51,2);
	textcolor(GREENWATER);
	gotoxy(36,16);
	puts(campo1);
	textcolor(WHITE);
	gotoxy(42,16);
	puts(nome);
	
	textcolor(GREENWATER);
	criar_caixinha(34,18,25,2);
	gotoxy(36,19);
	puts(campo2);
	textcolor(WHITE);
	gotoxy(47,19);
	puts(matricula);
	
	textcolor(GREENWATER);
	criar_caixinha(66,18,19,2);
	gotoxy(68,19);
	puts(campo5);
	textcolor(WHITE);
	gotoxy(75,19);
	puts(curso);
	
	textcolor(GREENWATER);
	criar_caixinha(34,21,17,2);
	gotoxy(36,22);
	puts(campo3);
	textcolor(WHITE);
	gotoxy(41,22);
	puts(cpf);

	textcolor(GREENWATER);
	criar_caixinha(55,21,13,2);
	gotoxy(57,22);
	printf("RG:");
	textcolor(WHITE);
	gotoxy(61,22);
	puts(rg);
	
	textcolor(GREENWATER);
	criar_caixinha(72,21,13,2);
	gotoxy(74,22);
	printf("UNIDADE:");
	textcolor(WHITE);
	gotoxy(83,22);
	printf("CMC");
	
	gotoxy(1,1);
}

void acervoUsuario(){
	
	int y = 7;
	int cont = 0;
	int tecla;
	int op;
	int encontrou = FALSE;
	char matriculaE[13];
	
	//Declaração dos arquivo 
	FILE* emprestimo = fopen(emprestimo_arq,"rb");
	
	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(emprestimo == NULL){ 
	
		quadrado(4,4,116,30,GREENWATER);
		
		criar_caixinha(44,3,32,2);
		textcolor(BRIGHTWHITE);
		gotoxy(52,4);
		printf("CONSULTA DE USU%cRIO",181);
	
		textcolor(LIGHTRED);
		gotoxy(51,15);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(46,16);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		menu();
	}
	
	quadrado(4,4,116,30,GREENWATER);
	
	criar_caixinha(44,3,32,2);
	textcolor(BRIGHTWHITE);
	gotoxy(52,4);
	printf("CARTEIRA DE USU%cRIO",181);
	
	textcolor(GREENWATER);
	gotoxy(43,9);
	printf("INFORME SUA MATRICULA PARA CONSULTA");
	
	textcolor(BRIGHTWHITE);
	gotoxy(43,11);
	printf("MATRICULA: ");
	setbuf(stdin, NULL);
	
	gotoxy(54,11);
	getString(matriculaE);
	
	if(matriculaE[0] == ESC){
		system("cls");
		consulta_de_acervo();
	}
	setbuf(stdin, NULL);
	
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
		if(strcmp(emprestar.matricula,matriculaE) == 0){
			encontrou = TRUE;
			break;
		}
	}
	
	fclose(emprestimo);
	
	if(!encontrou){
	
		textcolor(LIGHTRED);
		gotoxy(50,16);
		printf("MATRICULA N%cO ENCONTRADA\n",199);
		gotoxy(43,17);
		printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR");
		gotoxy(1,1);
		tecla = getch();
		system("cls");
		consulta_de_acervo();
	}
		
	emprestimo = fopen(emprestimo_arq,"rb");
	
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
		carteiraUsuario(emprestar.nome,emprestar.matricula,emprestar.curso,emprestar.cpf,emprestar.rg);
		break;
	}

	op = opcoes();
	system("cls");
	
	if(op == 2){
		
		quadrado(4,4,116,30,GREENWATER);
	
		criar_caixinha(44,3,32,2);
		textcolor(WHITE);
		gotoxy(51,4);
		printf("CONSULTA DE EMPRESTIMO");
	
		rewind(emprestimo);
		while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
				if(strcmp(matriculaE,emprestar.matricula ) == 0){
					switch(emprestar.situacao){
						
						case EMPRESTADO:
							
							textcolor(LIGHTYELLOW);
							criar_caixinha(37,y,45,4);
							
							y+=1;
								
							gotoxy(39,y++);
							textcolor(BRIGHTWHITE);
							setbuf(stdin, NULL);
							printf("CODIGO: ");
							puts(emprestar.codigo);
								
							gotoxy(39,y++);
							printf("TITULO: ");
							puts(emprestar.titulo);
								
							gotoxy(39,y++);
							printf("AUTOR: ");
							puts(emprestar.autor);
								
							y+=2;
							break;
							
						case DEVOLVIDO:
							
							textcolor(LIGHTGREEN);
							criar_caixinha(37,y,45,4);
							
							y+=1;
								
							gotoxy(39,y++);
							textcolor(BRIGHTWHITE);
							setbuf(stdin, NULL);
							printf("CODIGO: ");
							puts(emprestar.codigo);
								
							gotoxy(39,y++);
							printf("TITULO: ");
							puts(emprestar.titulo);
								
							gotoxy(39,y++);
							printf("AUTOR: ");
							puts(emprestar.autor);
								
							y+=2;
							break;
						
					}
				}
			}
			
			gotoxy(6,32);
			textcolor(LIGHTGREEN);
			printf("%c DEVOLVIDO",254);
			gotoxy(6,33);
			textcolor(LIGHTYELLOW);
			printf("%c EMPRESTADO",254);
			
			gotoxy(1,1);
			tecla = getch();
			
		}
		
		//fecha o arquivo
		fclose(emprestimo);
		system("CLS");
		consulta_de_acervo();
}
	
	

	

//Função que exibe as publicações emprestadas por todos os usuários
void consultarAcervo(){
		
	int y = 7;
	int tecla;
	int cont = 0;
	
	//Abre o arquivo
	FILE* emprestimo = fopen(emprestimo_arq,"rb");
	
	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(emprestimo == NULL){ 
	
		quadrado(4,4,116,30,GREENWATER);
		
		criar_caixinha(44,3,32,2);
		textcolor(BRIGHTWHITE);
		gotoxy(51,4);
		printf("CONSULTA DE PUBLICA%c%cO",128,199);
		
		textcolor(LIGHTRED);
		gotoxy(51,15);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(46,16);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		consulta_de_acervo();
	}
	
	
	//Faz a verificação de quantos cadastros tem no arquivo
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
		cont++;
	}
	
	//Fecha o arquivo
	fclose(emprestimo);
	
	if(cont <= 4){
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,35);
		criar_caixinha(4,3,116,31);
		
		textcolor(GREENWATER);
		gotoxy(43,32);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
		
	}else{
		int aux = cont * 8 + 2;
		
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,aux);
		criar_caixinha(3,3,116,aux - 4);
		
		textcolor(GREENWATER);
		gotoxy(43,aux - 3);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
	}
	
	criar_caixinha(44,2,32,2);
	textcolor(BRIGHTWHITE);
	gotoxy(51,3);
	printf("CONSULTA DE PUBLICA%c%cO",128,199);
	
	//Reabre o arquivo em modo de leitura binária
	emprestimo = fopen(emprestimo_arq,"rb");
	
	//Verifica se o arquivo existe, caso não, exibi uma mensagem de erro
	if(emprestimo == NULL){
		
		quadrado(4,4,116,30,GREENWATER);
		textcolor(LIGHTRED);
		gotoxy(49,14);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(45,15);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		consulta_de_acervo();
	}
	
	//Caso não tenha nenhum erro ele exibe o que tem no arquivo
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
		switch(emprestar.situacao){	
			
			case EMPRESTADO:
			
				textcolor(LIGHTYELLOW);
				criar_caixinha(38,y,45,5);
				
				y+=1;
				
				textcolor(BRIGHTWHITE);
				gotoxy(39,y++);
				setbuf(stdin, NULL);
				printf("USUARIO: ");
				puts(emprestar.nome);
				
				gotoxy(39,y++);
				printf("CODIGO: ");
				puts(emprestar.codigo);
					
				gotoxy(39,y++);
				printf("TITULO: ");
				puts(emprestar.titulo);
					
				gotoxy(39,y++);
				printf("AUTOR: ");
				puts(emprestar.autor);
					
				y+=2;
				break;
				
			case DEVOLVIDO:
				
				textcolor(LIGHTGREEN);
				criar_caixinha(38,y,45,5);
				
				y+=1;
					
				textcolor(BRIGHTWHITE);
				gotoxy(39,y++);
				setbuf(stdin, NULL);
				printf("USUARIO: ");
				puts(emprestar.nome);
				
				gotoxy(39,y++);
				printf("CODIGO: ");
				puts(emprestar.codigo);
					
				gotoxy(39,y++);
				printf("TITULO: ");
				puts(emprestar.titulo);
					
				gotoxy(39,y++);
				printf("AUTOR: ");
				puts(emprestar.autor);
					
				y+=2;
				break;
			
		}
	}
	
	gotoxy(1,1);
	tecla = getch();
	
	//fecha o arquivo
	fclose(emprestimo);
	system("CLS");
	consulta_de_acervo();
	
}

int main(){
	SetConsoleTitle("Controle de Biblioteca");
	Titulo();
	menu();
	return 0;
}
