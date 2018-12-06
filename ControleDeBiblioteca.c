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

//Define utilizada para saber quem esta utilizando o sistema e printar na tela
#define USUARIO 1
#define FUNCIONARIO 2

//Cores utilizadas na funcao TEXTCOLOR
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

//Valores das teclas
#define CIMA 72
#define BAIXO 80
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define TAB 9
#define ESQUERDA 75
#define DIREITA 77

//Codigo Ascii que forma o quadrado
#define CANTO1 218
#define CANTO2 191
#define CANTO3 192
#define CANTO4 217

#define CIMA1 196
#define LADO 179

#define CANTO5 201
#define CANTO6 187
#define CANTO7 200
#define CANTO8 188

#define LADO1 186
#define LADO2 205

//Codigo Ascii que faz um cubo
#define BLOCO_DE_CORES 219


//Estrutura de Cadastro de Usuario
typedef struct Cadastro{
	char cpf[12];
	char nome[100];
	char curso[12];
	char matricula[13];
	char identidade[9];
	char senha[20];

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

//Estrutura de Cadastro de funcionario
typedef struct Funcionnario{
	char nome[100];
	char matricula[13];
	char senha[20];

}Funcionario;

//Variaveis Globais
Cadastro cadastro; //variavel que recebe os dados do cadastro
Publicacao publicar; //variavel que recebe os dados da publicacao
Emprestimo emprestar; //variavel que recebe os dados do emprestimo
Devolucao devolver; //variavel que recebe os dados da devolucacao
Funcionario funcionario;

int exibir = 0;
int numero; //variavel responsavel por armazenar temporariamente o numero que é gerado a cada emprestimo
char salvar[] = "SALVAR";
char proximo1[] = "PROXIMO";
char campo1[] = "NOME: "; //variavel utilizada para printar o campo nome
char campo2[] = "MATRICULA: "; //variavel utilizada para printar o campo matricula
char campo3[] = "CPF: "; //variavel utilizada para printar o campo cpf
char campo4[] = "IDENTIDADE: "; //variavel utilizada para printar o campo identidade
char campo5[] = "CURSO: "; //variavel utilizada para printar o campo curso
char autor[] = "AUTOR: "; //variavel utilizada para printar o campo autor
char titulo[] = "TITULO: "; //variavel utilizada para printar o campo titulo
char codigo1[] = "CODIGO: "; //variavel utilizada para printar o campo codigo
char dataEmprestimo[] = "DATA DE EMPRESTIMO: "; //variavel utilizada para printar o campo data de emprestimo
char senha1[] = "SENHA: ";
char senha2[20];
char novasenha[] = "NOVA SENNHA: ";
char senhaAtual[] = "SENHA ATUAL: ";
char confSenha[] = "CONFIRMAR SENHA: ";
char matriculaMenu[13];  //variavel responsavel de receber a matricula informada pelo usuario no menu de entrada
char matriculaA[13]; //variavel responsavel de receber a matricula informada pelo usuario na alteracao
char matriculaUsuario[13]; //variavel responsavel de receber a matricula informada pelo usuario no cadastro
char codigoPublicacao[20]; //variavel responsavel de receber o codigo de publicacao informada pelo usuario no cadastro
char emprestarMatricula[13]; //variavel responsavel de receber a matricula informada pelo usuario no emprestimo
char emprestarCodigo[20];  //variavel responsavel de receber o codigo informada pelo usuario no emprestimo
char senhaUsuario[7];
char confirmarSenha[7]; //variavel responsavel de receber a confirmacao da senha informada pelo usuario no cadastro
char cadastrar_arq[] = "./cadastrar.dat"; //variavel responsavel por armazenar o diretorio do arquivo de cadastro
char cadastrar_arqaux[] = "./cadastraraux.dat"; //variavel responsavel por armazenar o diretorio do arquivo de cadastro auxiliar
char publicacao_arq[] = "./publicacao.dat";  //variavel responsavel por armazenar o diretorio do arquivo de cadastro de publicacao
char publicacao_arqaux[] = "./publicacaoaux.dat" ;  //variavel responsavel por armazenar o diretorio do arquivo de cadastro de publicacao auxiliar
char emprestimo_arq[] = "./emprestimo.dat";  //variavel responsavel por armazenar o diretorio do arquivo de emprestimo
char emprestimo_arqaux[] = "./emprestimoaux.dat";  //variavel responsavel por armazenar o diretorio do arquivo de emprestimo
char funcionario_arq[] = "./funcionario.dat";  //variavel responsavel por armazenar o diretorio do arquivo de funcinario

//Prototipos das Funcoes
void gotoxy(int,int);
void textcolor (int );
void espacamento(int,char);
void barras(int,int,int,int,char);
void barrinha(int,int,int);
void criar_caixinha(int,int,int,int,int,int,int,int,int,int);
void quadrado(int);
void quad();
void Titulo();
void livro();
void carregando();
void reescreverMenu(int,int,int,int);
void reescreverCadastro(int,int,int,int);
void reescreverAlteracao(int,int,int,int,int);
void reescreverAlteracaoPublic(int,int,int);
void reescreverMovimentacao(int,int);
void reescreverAcervo(int,int);
void reescreverSimNao(int,int,int,int);
void reescreverCarteira(int,int,int,int);
void reescreverProx(int,int,int,int,char[]);
void reescreverUsuario(int,int,int,int,int);
void menu();
void login();
int matriculaLogin();
void senhaLogin();
void funcionario1();
void usuario();
void alterarSenha();
void publicacoes_usuario();
void senha(char[],char[],int,int);
void senhaconfirmar(char[],char[],char[],int,int);
void cadastroUsuario();
void matricula();
void SenhaAtual();
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
void codigoEmprestimo();
void matriculaEmprestimo();
void dadosUsuario();
void devolucao();
void consultarAcervo();
void carteiraUsuario(char[],char[],char[],char[],char[]);
void acervoUsuario();
void consulta_de_acervo();
void relatorios();
int sim_nao(int,int,int,int);
int opcoes();
int proximo(char[]);
int opUsuario();
int verificarNumeros(char[],int);
int verificarLetra(char[],int);
int validarCPF(char[]);
void verificarCPF(int,int,char[],char[],int);
void verificacaoChar(int,int,char[],char[],int,int);
void verificacaoInt(int,int,char[],char[],int,int);
void converter(char[]);
void getString(char[]);
void getSenha(char[]);

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
void criar_caixinha(int x, int y, int larg, int alt, int canto1, int canto2, int canto3, int canto4, int lado, int cima){

    gotoxy(x,y);
    printf("%c", canto1); espacamento(larg, cima); printf("%c\n", canto2);

    barras(alt, larg, x, y, lado);

    gotoxy(x, alt + y);
    printf("%c",canto3); espacamento(larg, cima); printf("%c\n", canto4);
}

//Função para Criar o Quadrado Externo
void quadrado(int cor){

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

	criar_caixinha(4,5,116,29,218,191,192,217,179,196);

	if(exibir == USUARIO){

		FILE* cadastrar = fopen(cadastrar_arq,"rb");

		textcolor(GREENWATER);
		gotoxy(6,33);
		printf("USU%cRIO: ",181);
		textcolor(BRIGHTWHITE);
		rewind(cadastrar);
		while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
			if(strcmp(matriculaMenu,cadastro.matricula) == 0){
				gotoxy(15,33);
				converter(cadastro.nome);
			}
		}

		fclose(cadastrar);
	}

	if(exibir == FUNCIONARIO){

		textcolor(GREENWATER);
		gotoxy(6,33);
		printf("FUNCIONARIO: ",181);
		textcolor(BRIGHTWHITE);
		converter(funcionario.nome);

	}

	textcolor(GREENWATER);

	gotoxy(114,32);
	printf("%d:%d",lt.tm_hour,lt.tm_min);
	gotoxy(111,33);
	printf("0%d/%d/%d",lt.tm_mday,lt.tm_mon,lt.tm_year + 1900);

	criar_caixinha(4,2,9,2,218,191,192,217,179,196);
	gotoxy(7,3);
	printf("<< ESC");

	textcolor(GREENWATER);
	criar_caixinha(111,2,9,2,218,191,192,217,179,196);
	gotoxy(113,3);
	printf("ENTER >>");

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

	gotoxy(17,5+3);  printf("    __________________________________________   _________________________________________");
	gotoxy(17,6+3);  printf(".-/|                                          %c /                                         |%c-.",92,92);
	gotoxy(17,7+3);  printf("||||                                           |                                          ||||");
	gotoxy(17,8+3);  printf("||||                                           |                                          ||||");
	gotoxy(17,9+3);  printf("||||                                           |                                          ||||");
	gotoxy(17,10+3); printf("||||                                           |                                          ||||");
	gotoxy(17,11+3); printf("||||                                           |                                          ||||");
	gotoxy(17,12+3); printf("||||                                           |                                          ||||");
	gotoxy(17,13+3); printf("||||                                           |                                          ||||");
	gotoxy(17,14+3); printf("||||                                           |                                          ||||",92,92,92,92,92,92,92);
	gotoxy(17,15+3); printf("||||                                           |                                          ||||");
	gotoxy(17,16+3); printf("||||                                           |                                          ||||",92,92,92,92,92,92,92);
	gotoxy(17,17+3); printf("||||                                           |                                          ||||");
	gotoxy(17,18+3); printf("||||                                           |                                          ||||");
	gotoxy(17,19+3); printf("||||                                           |                                          ||||");
	gotoxy(17,20+3); printf("||||                                           |                                          ||||");
	gotoxy(17,21+3); printf("||||                                           |                                          ||||");
	gotoxy(17,22+3); printf("||||                                           |                                          ||||");
	gotoxy(17,23+3); printf("||||                                           |                                          ||||");
	gotoxy(17,24+3); printf("||/===========================================%c|/==========================================%c||",92,92);
	gotoxy(17,25+3);printf("`--------------------------------------------~___~------------------------------------------''");

	textcolor(BRIGHTWHITE);

    gotoxy(23,12+3); printf("88888b.                     888           .d8888b.  888                           ");
    gotoxy(23,13+3); printf("888   88b                    888          d88P  Y88b 888                           ");
    gotoxy(23,14+3); printf("888  .88P                    888          Y88b.      888                           ");
    gotoxy(23,15+3); printf("8888888K.   .d88b.   .d88b.  888  888      'Y888b.   888888 .d88b.  888d888 .d88b. ");
    gotoxy(23,16+3); printf("888   Y88b d88  88b d88  88b 888 .88P         'Y88b. 888   d88''88b 888P'  d8P  Y8b");
    gotoxy(23,17+3); printf("888    888 888  888 888  888 888888K            '888 888   888  888 888    88888888");
    gotoxy(23,18+3); printf("888   d88P Y88..88P Y88..88P 888 '88b     Y88b  d88P Y88b. Y88..88P 888    Y8b.    ");
    gotoxy(23,19+3); printf("8888888P'   'Y88P'   'Y88P'  888  888      'Y8888P'   'Y888 'Y88P'  888     'Y8888 ");


	textcolor(GREENWATER);

	gotoxy(64,12+3); printf("|");
	gotoxy(64,13+3); printf("|");
	gotoxy(64,14+3); printf("|");
	gotoxy(64,15+3); printf("|");
	gotoxy(64,16+3); printf("|");
	gotoxy(64,17+3); printf("|");
	gotoxy(64,18+3); printf("|");
	gotoxy(64,19+3); printf("|");

	gotoxy(1,1);

}

//Função de Printar o Titulo na Tela Inicial
void Titulo(){

	textcolor(GREENWATER);

	criar_caixinha(1,1,122,35,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);
	criar_caixinha(4,4,116,30,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);

	gotoxy(111,32);
	printf("         ");
	gotoxy(108,33);
	printf("             ");
	livro();

	carregando();
	system("cls");
}

//Função de Printar na Tela Carregado
void carregando(){

	int i;

	textcolor(GREENWATER);

	criar_caixinha(30,30,64,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

	for(i=31;i<96;i++){ //Um for para poder o bloco de cores ir passando pelo meio da caixinha
		textcolor(GREENBLUE);
		gotoxy(i,31);
		printf("%c",BLOCO_DE_CORES);
		gotoxy(1,1);
		Sleep(50);
	}
}

//Função que Trocar as Cores das Opções do Menu Principal a Cada Opção Selecionada
void reescreverMenu(int cor1, int cor2, int cor3, int cor4){

	textcolor(cor1);
	criar_caixinha(44,10,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(51,11);
	printf("CADASTRO DE USU%cRIOS",181);

	textcolor(cor2);
	criar_caixinha(44,13,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(50,14);
	printf("CADASTRO DE PUBLICA%c%cES",128,229);

	textcolor(cor3);
	criar_caixinha(44,16,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(55,17);
	printf("MOVIMENTA%c%cO",128,199);

	textcolor(cor4);
	criar_caixinha(44,19,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(52,20);
	printf("CONSULTA DE ACERVO");

    gotoxy(1,1);
}

//Função que Trocar as Cores das Opcoes do Menu de Cadastro a Cada Opção Selecionada
void reescreverCadastro(int cor1, int cor2, int cor3, int cor4){

	textcolor(cor1);
	criar_caixinha(47,10,26,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(57,11);
	printf("INCLUS%cO",199);

	textcolor(cor2);
	criar_caixinha(47,13,26,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(57,14);
	printf("CONSULTA");

	textcolor(cor3);
	criar_caixinha(47,16,26,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(57,17);
	printf("ALTERA%c%cO",128,199);

	textcolor(cor4);
	criar_caixinha(47,19,26,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(57,20);
	printf("EXCLUS%cO",199);

    gotoxy(1,1);
}

//Função que Trocar as Cores das Opções do Emprestimo e Devolução de Publicacao a Cada Opção Selecionada
void reescreverMovimentacao(int cor1, int cor2){

	textcolor(cor1);
	criar_caixinha(44,10,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(49,11);
	printf("EMPRESTIMO DE PUBLICA%c%cO",128,199);

	textcolor(cor2);
	criar_caixinha(44,13,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(49,14);
	printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);

	gotoxy(1,1);
}

//Função que Trocar as Cores das Opções de Consulta de Arcevo eConsulta de Usuário a Cada Opção Selecionada
void reescreverAcervo(int cor1, int cor2){

	textcolor(cor1);
	criar_caixinha(47,10,26,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(52,11);
	printf("CARTEIRA DE USU%cRIO",181);

	textcolor(cor2);
	criar_caixinha(47,13,26,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(50,14);
	printf("CONSULTA DE MOVIMENTA%c%cO",128,199);

	gotoxy(1,1);
}

//Função que reescreve os campos da alteracão, e troca de cor se o usuario selecionar alterar
void reescreverAlteracao(int cor1,int cor2, int cor3, int cor4, int cor5){

	textcolor(cor1);
	gotoxy(38,11);
	puts(campo1);
	barrinha(38,12,47);

	textcolor(cor2);
	gotoxy(38,14);
	puts(campo2);
	barrinha(38,15,47);

	textcolor(cor3);
	gotoxy(38,17);
	puts(campo3);
	barrinha(38,18,47);

	textcolor(cor4);
	gotoxy(38,20);
	puts(campo4);
	barrinha(38,21,47);

	textcolor(cor5);
	gotoxy(38,23);
	puts(campo5);
	barrinha(38,24,47);

	gotoxy(1,1);
}

//Função que reescreve os campos da alteracão, e troca de cor se o usuario selecionar alterar
void reescreverAlteracaoPublic(int cor1,int cor2, int cor3){

	textcolor(cor1);
	gotoxy(38,12);
	puts(codigo1);
	barrinha(38,13,47);

	textcolor(cor2);
	gotoxy(38,15);
	puts(titulo);
	barrinha(38,16,47);

	textcolor(cor3);
	gotoxy(38,18);
	puts(autor);
	barrinha(38,19,47);

	gotoxy(1,1);
}

//Função que reescreve os campos das opções SIM e NÃO, e troca as cores conforme o usuario seleciona as opções
void reescreverSimNao(int cor1, int cor2,int x, int y){

	textcolor(cor1);
	criar_caixinha(x,y,6,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x+3,y+1);
	printf("SIM");

	textcolor(cor2);
	criar_caixinha(x+15,y,6,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x+18,y+1);
	printf("N%cO",199);

	gotoxy(1,1);
}

void reescreverUsuario(int cor1, int cor2, int cor3, int x, int y){

	textcolor(cor1);
	criar_caixinha(x,y,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x + 7,y + 1);
	printf("CARTEIRA DE USU%cRIO",181);

	textcolor(cor2);
	criar_caixinha(x,y + 3,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x + 6,y + 4);
	printf("CONSULTAR PUBLICA%c%cES",128,229);

	textcolor(cor3);
	criar_caixinha(x,y + 6,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x + 10,y + 7);
	printf("ALTERAR SENHA",128,229);
	gotoxy(1,1);
}

//Funcao que reescreve os campos de CANCELAR e PROXIMO e troca as cores conforme o usuario seleciona as opcoes
void reescreverProx(int cor1, int cor2,int x, int y, char campo[]){

	textcolor(cor1);
	criar_caixinha(x+29,y,8,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x+31,y+1);
	puts(campo);

	textcolor(cor2);
	criar_caixinha(x,y,9,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x+2,y+1);
	printf("CANCELAR");

	gotoxy(1,1);
}

//Função que reescreve os campos das opções RETORNAR e CONSULTAR EMPRESTIMO, e troca as cores conforme o usuario seleciona as opções
void reescreverCarteira(int cor1, int cor2,int x, int y){

	textcolor(cor1);
	criar_caixinha(x,y,21,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x+8,y+1);
	printf("RETORNAR");

	textcolor(cor2);
	criar_caixinha(x+32,y,23,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(x+35,y+1);
	printf("CONSULTAR EMPRESTIMO");

	gotoxy(1,1);
}

int proximo(char campo[]){

	int tecla;
	int op = 1;

	reescreverProx(LIGHTGREEN,GREENWATER,42,24,campo);

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
				reescreverProx(GREENWATER,LIGHTRED,42,24,campo);
				break;

			case 1:
				reescreverProx(LIGHTGREEN,GREENWATER,42,24,campo);
				break;

			case 2:
				reescreverProx(GREENWATER,LIGHTRED,42,24,campo);
				break;
			case 3:
				op = 1;
				reescreverProx(LIGHTGREEN,GREENWATER,42,24,campo);
				break;
		}
	}while(tecla != 13);

	return op;

}

//Função do SIM e NÃO
int sim_nao(int x, int y, int cor1, int cor2){

	int tecla;
	int op = 1;

	reescreverSimNao(cor1,BRIGHTWHITE,x,y);

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
				reescreverSimNao(BRIGHTWHITE,cor2,x,y);
				break;

			case 1:
				reescreverSimNao(cor1,BRIGHTWHITE,x,y);
				break;

			case 2:
				reescreverSimNao(BRIGHTWHITE,cor2,x,y);
				break;
			case 3:
				op = 1;
				reescreverSimNao(cor1,BRIGHTWHITE,x,y);
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
    Sleep(4000);

}

//Função do Menu Principal
void menu(){

	int op = 1;
	int op1;
	int tecla1;

	quadrado(GREENWATER);

	textcolor(GREENWATER);
	criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(55,5);
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

			textcolor(GREENWATER);
			gotoxy(51,24);
			printf("DESEJA REALMENTE SAIR?");

			op1 = sim_nao(50,26,LIGHTRED,LIGHTGREEN);

			if(op1 == 1){
				system("cls");
				login();
			}
			else{
				system("cls");
				menu();
			}
		}

        if(tecla1 == BAIXO || tecla1 == CIMA){
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

int matriculaLogin(){
    FILE* cadastrar = fopen(cadastrar_arq,"rb");
	FILE* administrador = fopen(funcionario_arq,"rb");

	int encontrouf;
	int encontrou;
	int tamanho;
	int aux;

	//Campo
	textcolor(GREENWATER);
	gotoxy(38,14);
	puts(campo2);
	barrinha(38,15,47);

	do{
		encontrouf = FALSE;
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(campo2),14);
		setbuf(stdin, NULL);
		getString(matriculaMenu);
		tamanho = strlen(matriculaMenu);
		aux = verificarNumeros(matriculaMenu,14);

		if(matriculaMenu[0] == '\0'){
	        gotoxy(38 + strlen(campo2),14);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),14);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(600);
		}
		if(tamanho > 12){
			gotoxy(38 + strlen(campo2),14);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),14);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
		if(aux == 0){
			gotoxy(38 + strlen(campo2),14);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),14);
			printf("APENAS NUMERO!");
			Sleep(600);
		}
		if(matriculaMenu[0] == ESC){
			return;
		}
		if(matriculaMenu[0] != '\0' && aux != 0){

            if(cadastrar != NULL){

                rewind(cadastrar);
                while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
                    if(strcmp(cadastro.matricula,matriculaMenu) == 0){
                        encontrou = 1;
                    }
                }
            }

            if(administrador != NULL){

                rewind(administrador);
                while(fread(&funcionario,sizeof(Funcionario),1,administrador)){
                    if(strcmp(funcionario.matricula,matriculaMenu) == 0){
                        encontrou = 2;
                        break;
                    }
                }
            }

            if(encontrou == 0){
                gotoxy(38 + strlen(campo2),14);
                printf("                                        ");
                textcolor(LIGHTRED);
                gotoxy(38 + strlen(campo2),14);
                printf("MATRICULA N%cO ENCONTRADA",199);
                Sleep(800);
            }
		}

	    gotoxy(38 + strlen(campo2),14);
	    printf("                                            ");

	}while(matriculaMenu[0] == '\0' || tamanho > 12 || aux == 0 || encontrou == 0);

	fclose(cadastrar);
	fclose(administrador);

	//Troca a Cor se Preenchido Corretamente
	if(matriculaMenu[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,14);
		puts(campo2);
		gotoxy(38 + strlen(campo2),14);
		setbuf(stdin, NULL);
		puts(matriculaMenu);
		barrinha(38,15,47);
	}

	return encontrou;
}

void senhaLogin(){

    FILE* cadastrar = fopen(cadastrar_arq,"rb");
	FILE* administrador = fopen(funcionario_arq,"rb");

	int encontrouf;
	int encontrou;
	int tamanho;
	int aux;
	int i;

	//Campo
	textcolor(GREENWATER);
	gotoxy(38,17);
	puts(senha1);
	barrinha(38,18,47);

	do{
		encontrouf = FALSE;
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(senha1),17);
		setbuf(stdin, NULL);
		getSenha(senha2);
		tamanho = strlen(senha2);

		if(senha2[0] == '\0'){
	        gotoxy(38 + strlen(senha1),17);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(senha1),17);
			printf("CAMPO OBRIGAT%cRIO!",224);
			gotoxy(1,1);
			Sleep(700);
		}
		if(tamanho > 20){
			gotoxy(38 + strlen(senha1),17);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(senha1),17);
			printf("INV%cLIDO",181);
			gotoxy(1,1);
			Sleep(700);
		}
		if(senha2[0] == ESC){
			return;
		}
		if(senha2[0] != '\0' && aux != 0){

            if(cadastrar != NULL){

                rewind(cadastrar);
                while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
                    if(strcmp(cadastro.senha,senha2) == 0){
                        encontrou = 1;
                    }
                }
            }

            if(administrador != NULL){

                rewind(administrador);
                while(fread(&funcionario,sizeof(Funcionario),1,administrador)){
                    if(strcmp(funcionario.senha,senha2) == 0){
                        encontrou = 2;
                        break;
                    }
                }
            }

            if(encontrou == 0){
                gotoxy(38 + strlen(senha1),17);
                printf("                                        ");
                textcolor(LIGHTRED);
                gotoxy(38 + strlen(senha1),17);
                printf("SENHA INV%cLIDA",181);
                Sleep(800);
            }
		}

	    gotoxy(38 + strlen(senha1),17);
	    printf("                                            ");

	}while(senha2[0] == '\0' || tamanho > 20 || encontrou == 0);

	fclose(cadastrar);
	fclose(administrador);

	//Troca a Cor se Preenchido Corretamente
	if(senha2[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,17);
		puts(senha1);

		gotoxy(38 + strlen(senha1),17);
		for(i = 0; i < tamanho; i++){
			printf("*");
		}
		barrinha(38,18,47);
	}
}

void login(){

	int op1;
	int tecla;
	int encontrou = 0;

	quadrado(GREENWATER);

	FILE* administrador = fopen(funcionario_arq,"rb");

	gotoxy(6,33);
	printf("                                             ");

	if(administrador == NULL){

		textcolor(GREENWATER);
		criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(51,5);
		printf("CADASTRO DE FUNCION%cRIO",181);

		funcionario1();

		system("cls");
		login();

	}

	fclose(administrador);

	if(administrador != NULL){

		textcolor(GREENWATER);
		criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(51,5);
		printf("CONTROLE DE BIBLIOTECA");

		textcolor(GREENWATER);
		gotoxy(45,10);
		printf("INFORME A MATRICULA E SUA SENHA");

		//Entrada
		textcolor(BRIGHTWHITE);
		gotoxy(38,17);
		puts(senha1);
		barrinha(38,18,47);

		textcolor(BRIGHTWHITE);
		criar_caixinha(75,19,7,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		gotoxy(77,20);
		printf("ENTRAR");

		encontrou = matriculaLogin();
		if(matriculaMenu[0] == ESC){

			gotoxy(75,19);
			printf("                            ");
			gotoxy(75,20);
			printf("                             ");
			gotoxy(75,21);
			printf("                             ");
			textcolor(GREENWATER);
			gotoxy(51,22);
			printf("DESEJA REALMENTE SAIR?");

			op1 = sim_nao(50,24,LIGHTRED,LIGHTGREEN);

			if(op1 == 1){
				system("cls");
				finalizado();
				system("cls");
				exit(0);
			}
			else{
				system("cls");
				login();
			}
		}

		textcolor(GREENWATER);
		senhaLogin();
		if(senha2[0] == ESC){

			gotoxy(75,19);
			printf("                            ");
			gotoxy(75,20);
			printf("                             ");
			gotoxy(75,21);
			printf("                             ");
			textcolor(GREENWATER);
			gotoxy(51,22);
			printf("DESEJA REALMENTE SAIR?");

			op1 = sim_nao(50,24,LIGHTRED,LIGHTGREEN);

			if(op1 == 1){
				system("cls");
				finalizado();
			}
			else{
				system("cls");
				login();
			}
		}

		textcolor(GREENWATER);
		criar_caixinha(75,19,7,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		gotoxy(77,20);
		printf("ENTRAR");
		gotoxy(1,1);

		do{
            tecla = getch();

            if(tecla == ESC){

                system("cls");
                login();
            }

		}while(tecla != ENTER);

		if(tecla == ENTER){
			if(encontrou == 1){

				system("cls");
				exibir = USUARIO;
				usuario();

			}
			if(encontrou == 2){

				system("cls");
				exibir = FUNCIONARIO;
				menu();
            }
        }
    }
}

void SenhaAtual(){

	FILE* cadastrar = fopen(cadastrar_arq,"rb");

	int i;
	int encontrou;
	int tamanho;
	char senhaatual[7];

	//Campo
	textcolor(GREENWATER);
	gotoxy(38,11);
	puts(senhaAtual);
	barrinha(38,12,47);

	do{
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(senhaAtual),11);
		setbuf(stdin, NULL);
		getSenha(senhaatual);
		tamanho = strlen(senhaatual);

		if(senhaatual[0] == '\0'){
	        gotoxy(38 + strlen(senhaAtual),11);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(senhaAtual),11);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(500);
		}
		if(tamanho > 20){
			gotoxy(38 + strlen(senhaAtual),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(senhaAtual),11);
			printf("INV%cLIDO",181);
			Sleep(500);
		}
		if(senhaatual[0] == ESC){
			system("cls");
			usuario();
		}

		if(cadastrar != NULL){

			rewind(cadastrar);
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(cadastro.matricula,matriculaMenu) == 0){
					if(strcmp(cadastro.senha,senhaatual) == 0){
						encontrou = TRUE;
					}
				}
			}
		}
		if(encontrou != TRUE){
			gotoxy(38 + strlen(senhaAtual),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(senhaAtual),11);
			printf("SENHA INCORRETA");
			Sleep(500);
		}

	    gotoxy(38 + strlen(senhaAtual),11);
	    printf("                                            ");

	}while(senhaatual[0] == '\0' || tamanho > 20 || encontrou != TRUE);

	fclose(cadastrar);

	//Troca a Cor se Preenchido Corretamente
	if(senhaatual[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,11);
		puts(senhaAtual);

		gotoxy(38 + strlen(senhaAtual),11);
		for(i = 0; i < tamanho; i++){
			printf("*");
		}

		barrinha(38,12,47);
	}
}

void carteira_usuario(){

	//abrindo o arquivo em modo de leitura binaria
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	FILE* emprestimo = fopen(emprestimo_arq,"rb");

	int op1;
	int y = 8;
	int tecla;

	quadrado(GREENWATER);
	criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(52,5);
	printf("CARTEIRA DE USU%cRIO",181);

	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		if(strcmp(matriculaMenu,cadastro.matricula) == 0){
			carteiraUsuario(cadastro.nome,cadastro.matricula,cadastro.curso,cadastro.cpf,cadastro.identidade);
			break;
		}
	}

	fclose(cadastrar);

	op1 = opcoes();
	system("cls");

	if(op1 == 2){

	quadrado(GREENWATER);

	criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(51,5);
	printf("CONSULTA DE EMPRESTIMO");

	gotoxy(6,33);
	printf("                                         ");

	if(emprestimo == NULL){

		textcolor(LIGHTRED);
		gotoxy(50,20);
		printf("NENHUM EMPRESTIMO EFETUADO");
		gotoxy(1,1);
		Sleep(2000);
		system("cls");
		usuario();
	}

	rewind(emprestimo);
	while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
			if(strcmp(matriculaMenu,emprestar.matricula ) == 0){
				switch(emprestar.situacao){

					case EMPRESTADO:

						textcolor(LIGHTYELLOW);
						criar_caixinha(37,y,45,4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
						criar_caixinha(37,y,45,4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
		printf("                                         ");
		gotoxy(6,33);
		textcolor(LIGHTYELLOW);
		printf("%c EMPRESTADO",254);

		gotoxy(1,1);
		tecla = getch();

	}

	//fecha o arquivo
	fclose(emprestimo);
	system("CLS");
	usuario();

}

void publicacao_usuario(){

	int y = 6;
	int tecla;
	int cont = 0;

	//Abre o arquivo
	FILE* publicacao = fopen(publicacao_arq,"rb");

	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(publicacao == NULL){

		quadrado(GREENWATER);
		criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(51,5);
		printf("CONSULTA DE PUBLICA%c%cO",128,199);

		textcolor(LIGHTRED);
		gotoxy(51,18);
		printf("ERRO AO ABRIR ARQUIVO");
		gotoxy(46,19);
		printf("PRESSIONE ENTER PARA CONTINUAR");
		gotoxy(1,1);
		getchar();
		system("cls");
		usuario();
	}


	//Faz a verificação de quantos cadastros tem no arquivo
	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		cont++;
	}

		//Fecha o arquivo
		fclose(publicacao);

		if(cont <= 4){
			textcolor(GREENWATER);
			criar_caixinha(1,1,122,35,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			criar_caixinha(4,3,116,31,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

			textcolor(GREENWATER);
			gotoxy(43,32);
			printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");

		}else{
			int aux = cont * 8 + 2;

			textcolor(GREENWATER);
			criar_caixinha(1,1,122,aux - 1,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			criar_caixinha(3,3,116,aux - 5,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

			textcolor(GREENWATER);
			gotoxy(43,aux - 4);
			printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");

		}
		criar_caixinha(46,2,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(51,3);
		printf("CONSULTA DE PUBLICA%c%cO",128,199);

		//Reabre o arquivo em modo de leitura binária
		publicacao = fopen(publicacao_arq,"rb");

		//Verifica se o arquivo existe, caso não, exibi uma mensagem de erro
		if(publicacao == NULL){

			quadrado(GREENWATER);
			textcolor(LIGHTRED);
			gotoxy(49,15);
			printf("ERRO AO ABRIR ARQUIVO");
			gotoxy(45,16);
			printf("PRESSIONE ENTER PARA CONTINUAR");
			gotoxy(1,1);
			getchar();
			system("cls");
			usuario();
		}

		//Caso não tenha nenhum erro ele exibe o que tem no arquivo
		while(fread(&publicar,sizeof(Publicacao),1,publicacao)){

			textcolor(GREENWATER);
			criar_caixinha(38,y,45,4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
		usuario();
}

void alterarSenha(){

	quadrado(GREENWATER);

	int i;
	int op2;
	int op3;
	char confirirmarUsuario[7];

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("ALTERA%c%cO",128,199);

	textcolor(GREENWATER);
	gotoxy(53,8);
	printf("INSIRA A NOVO SENHA\n");

	textcolor(BRIGHTWHITE);
	gotoxy(38,14);
	puts(novasenha);
	barrinha(38,15,47);

	textcolor(BRIGHTWHITE);
	gotoxy(38,17);
	puts(confSenha);
	barrinha(38,18,47);

	//Senha Atual
	SenhaAtual();

	//Senha
	senha(novasenha,cadastro.senha,38,14);
	if(cadastro.senha[0] == ESC){

		system("cls");
		usuario();
	}

	//Confirmacao da senha
	senhaconfirmar(confirirmarUsuario,cadastro.senha,novasenha,38,17);
	if(cadastro.senha[0] == ESC){
		system("cls");
		usuario();
	}

	textcolor(GREENWATER);
	gotoxy(50,21);
	printf("DESEJA ALTERAR A SENHA?\n");

	op2 = sim_nao(49,23,LIGHTGREEN,LIGHTRED);


	if(op2 == 1){

		FILE* cadastraraux = fopen(cadastrar_arqaux,"ab");
		FILE* cadastrar = fopen(cadastrar_arq,"rb");

		if(cadastrar == NULL || cadastraraux == NULL){
			quadrado(GREENWATER);
			textcolor(LIGHTRED);
			gotoxy(49,16);
			printf("ERRO AO SALVAR ARQUIVO");
			gotoxy(45,17);
			printf("PRESSIONE ENTER PARA CONTINUAR");
			gotoxy(1,1);
			getchar();
			system("cls");
			usuario();
		}
		else{
			rewind(cadastrar);
			fwrite(&cadastro,sizeof(Cadastro),1,cadastraraux);
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(matriculaMenu, cadastro.matricula) != 0){
					fwrite(&cadastro,sizeof(Cadastro),1,cadastraraux);
				}
			}
		}

		fclose(cadastrar);
		fclose(cadastraraux);

		remove(cadastrar_arq);
		rename(cadastrar_arqaux,cadastrar_arq);

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

		for(i = 0; i < 3; i++){
			Sleep(450);
			gotoxy(1,1);
			textcolor(LIGHTGREEN);
			criar_caixinha(43,22,36,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			gotoxy(47,23);
			printf("ALTERA%c%cO EFETUADA COM SUCESSO!",128,199);
			gotoxy(1,1);
			Sleep(450);
			gotoxy(43,22);
			printf("                                                      ");
			gotoxy(43,23);
			printf("                                                      ");
			gotoxy(43,24);
			printf("                                                      ");
			gotoxy(1,1);

		}

		system("cls");
		login();

	}
	else{

		system("cls");
		usuario();
	}
}
void usuario(){

	quadrado(GREENWATER);

	int op;

	textcolor(GREENWATER);
	criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(55,5);
	printf("MENU PRINCIPAL");

	op = opUsuario();
	system("cls");

	if(op == 1){
		carteira_usuario();
	}

	if(op == 2){

		publicacao_usuario();
	}

	if(op == 3){

		alterarSenha();
	}
}

int opUsuario(){

	int tecla;
	int op = 1;
	int op1;

	reescreverUsuario(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,45,10);

	do{
		tecla = getch();

		if(tecla == BAIXO){
			op++;
		}
		if(tecla == CIMA){
			op--;
		}
		if(tecla == ESC){

			textcolor(GREENWATER);
			gotoxy(51,23);
			printf("DESEJA REALMENTE SAIR?");

			op1 = sim_nao(50,25,LIGHTRED,LIGHTGREEN);

			if(op1 == 1){
				system("cls");
				login();
			}
			else{
				system("cls");
				usuario();
			}

		}

		switch(op){
			case 0:
				op = 3;
				reescreverUsuario(BRIGHTWHITE,BRIGHTWHITE,GREENWATER,45,10);
				break;

			case 1:
				reescreverUsuario(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,45,10);
				break;

			case 2:
				reescreverUsuario(BRIGHTWHITE,GREENWATER,BRIGHTWHITE,45,10);
				break;
			case 3:
				reescreverUsuario(BRIGHTWHITE,BRIGHTWHITE,GREENWATER,45,10);
				break;
			case 4:
				op = 1;
				reescreverUsuario(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,45,10);
				break;

		}

	}while(tecla != 13);

	return op;
}

void funcionario1(){

	FILE* administrador = fopen(funcionario_arq,"ab");

	char confirmarFuncionario[7];

	textcolor(BRIGHTWHITE);
	gotoxy(38,14);
	puts(campo2);
	barrinha(38,15,47);

	textcolor(BRIGHTWHITE);
	gotoxy(38,17);
	puts(senha1);
	barrinha(38,18,47);

	textcolor(BRIGHTWHITE);
	gotoxy(38,20);
	puts(confSenha);
	barrinha(38,21,47);

	//Nome
	verificacaoChar(38,11,campo1,funcionario.nome,100,BRIGHTWHITE);

	//Matricula
	verificacaoInt(38,14,campo2,funcionario.matricula,12,BRIGHTWHITE);

	//Senha
	senha(senha1,funcionario.senha,38,17);

	//Confirmacao da senha
	senhaconfirmar(confirmarFuncionario,funcionario.senha,senha1,38,20);

	fwrite(&funcionario,sizeof(Funcionario),1,administrador);

	fclose(administrador);

}

//Função que Exibe as Opções do Cadastro de Usuário
void cadastroUsuario(){

	int op = 1;
	int tecla;

	quadrado(GREENWATER);

	textcolor(GREENWATER);
	criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(51,5);
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
        if(tecla == BAIXO || tecla == CIMA){
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
        //digito 1
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
        //digito 2

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
			cpf = validarCPF(var);

			if(var[0] == '\0'){
		        gotoxy(x + strlen(campo),y);
		        printf("                                       ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("CAMPO OBRIGAT%cRIO!",224);
				Sleep(1000);
			}
			if(cpf == 0){
				gotoxy(x + strlen(campo),y);
		        printf("                                       ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("INV%cLIDO",181);
				Sleep(1000);
			}

	        gotoxy(x + strlen(campo),y);
	        printf("                                           ");

	}while(var[0] == '\0' || cpf  == 0);

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
            gotoxy(1,1);
			Sleep(700);
		}

		if(aux == 0){
			gotoxy(x + strlen(campo),y);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("APENAS LETRA");
        	gotoxy(1,1);
			Sleep(700);
		}
		if(tamanho > tam){
			gotoxy(x + strlen(campo),y);
		    printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("INV%cLIDO",181);
        	gotoxy(1,1);
			Sleep(700);
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
                gotoxy(1,1);
				Sleep(700);
			}
			if(aux == 0){
				gotoxy(x + strlen(campo),y);
		        printf("                                        ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("APENAS NUMERO!");
				gotoxy(1,1);
				Sleep(700);
			}
			if(tamanho > tam){
				gotoxy(x + strlen(campo),y);
		        printf("                                        ");
				textcolor(LIGHTRED);
				gotoxy(x + strlen(campo),y);
				printf("INV%cLIDO",181);
                gotoxy(1,1);
				Sleep(700);
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

//Função que converte letra minuscula em Maiuscula
void converter(char var[]){

	int i;

	for(i = 0; i < strlen(var); i++){

		var[i] = toupper(var[i]);
		printf("%c",var[i]);
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
	FILE* administrador = fopen(funcionario_arq,"rb");

	int encontrouf;
	int encontrou;
	int tamanho;
	int aux;

	//Campo
	textcolor(GREENWATER);
	gotoxy(38,11);
	puts(campo2);
	barrinha(38,12,47);

	do{
		encontrouf = FALSE;
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(campo2),11);
		setbuf(stdin, NULL);
		getString(matriculaUsuario);
		tamanho = strlen(matriculaUsuario);
		aux = verificarNumeros(matriculaUsuario,11);

		if(matriculaUsuario[0] == '\0'){
	        gotoxy(38 + strlen(campo2),11);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),11);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(600);
		}
		if(tamanho > 12){
			gotoxy(38 + strlen(campo2),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),11);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
		if(aux == 0){
			gotoxy(38 + strlen(campo2),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),11);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
		if(matriculaUsuario[0] == ESC){
			system("cls");
			cadastroUsuario();
		}
		if(cadastrar != NULL){

			rewind(cadastrar);
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(cadastro.matricula,matriculaUsuario) == 0){
					encontrou = TRUE;
				}
			}
		}

		if(administrador != NULL){

			rewind(administrador);
			while(fread(&funcionario,sizeof(Funcionario),1,administrador)){
				if(strcmp(funcionario.matricula,matriculaUsuario) == 0){
					encontrouf = 2;
					break;
				}
			}
		}

		if(encontrou == TRUE || encontrouf ==2){
			gotoxy(38 + strlen(campo2),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),11);
			printf("MATRICULA JA CADASTRADA");
			Sleep(600);
		}

	    gotoxy(38 + strlen(campo2),11);
	    printf("                                            ");

	}while(matriculaUsuario[0] == '\0' || tamanho > 12 || aux == 0 || encontrou == TRUE || encontrouf == 2);

	fclose(cadastrar);
	fclose(administrador);

	//Troca a Cor se Preenchido Corretamente
	if(matriculaUsuario[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,11);
		puts(campo2);
		gotoxy(38 + strlen(campo2),11);
		setbuf(stdin, NULL);
		puts(matriculaUsuario);
		barrinha(38,12,47);
	}
}

void inclusaoUsuario(){

	quadrado(GREENWATER);

	int aux;
	int op;
	int op1;
	int tecla;
	int op3;
	char nomeUsuario[100];
	char cpf[12];
	char curso[12];
	char rg[9];

	textcolor(GREENWATER);
	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("INCLUS%cO",199);

	//Entrada de dados

	textcolor(BRIGHTWHITE);
	gotoxy(38,14);
	puts(campo3);
	barrinha(38,15,47);

	textcolor(BRIGHTWHITE);
	gotoxy(38,17);
	puts(campo4);
	barrinha(38,18,47);

	textcolor(BRIGHTWHITE);
	gotoxy(38,20);
	puts(campo5);
	barrinha(38,21,47);

	reescreverProx(GREY,GREY,42,24,proximo1);

	//Nome
	verificacaoChar(38,11,campo1,nomeUsuario,100,BRIGHTWHITE);

	if(nomeUsuario[0] == ESC){
		system("cls");
		cadastroUsuario();
	}

	//CPF
	verificarCPF(38,14,campo3,cpf,BRIGHTWHITE);

	//Identidade
	verificacaoInt(38,17,campo4,rg,8,BRIGHTWHITE);

	if(cadastro.identidade[0] == ESC){
		system("cls");
		cadastroUsuario();
	}

	//Curso
	verificacaoChar(38,20,campo5,curso,11,BRIGHTWHITE);

	if(cadastro.curso[0] == ESC){
		system("cls");
		cadastroUsuario();
	}

	aux = proximo(proximo1);

	if(aux == 1){

		quadrado(GREENWATER);

		textcolor(GREENWATER);
		criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(58,5);
		printf("INCLUS%cO",199);

		textcolor(BRIGHTWHITE);
		gotoxy(38,14);
		puts(senha1);
		barrinha(38,15,47);

		textcolor(BRIGHTWHITE);
		gotoxy(38,17);
		puts(confSenha);
		barrinha(38,18,47);

		reescreverProx(GREY,GREY,42,24,salvar);

		//Matricula
		matricula();

		if(matriculaUsuario[0] == ESC){
			system("cls");
			cadastroUsuario();
		}


		//Senha
		senha(senha1,senhaUsuario,38,14);
		if(senhaUsuario[0] == ESC){
			system("cls");
			cadastroUsuario();
		}

		//Confirmacao da senha
		senhaconfirmar(confirmarSenha,senhaUsuario,senha1,38,17);
		if(confirmarSenha[0] == ESC){
			system("cls");
			cadastroUsuario();
		}
	}

	if(aux == 2){
		system("cls");
		cadastroUsuario();
	}



	//Interagindo com o usuario

	op = proximo(salvar);

	if(op == 1){

        strcpy(cadastro.matricula,matriculaUsuario);
        strcpy(cadastro.senha,senhaUsuario);
        strcpy(cadastro.nome,nomeUsuario);
        strcpy(cadastro.cpf,cpf);
        strcpy(cadastro.curso,curso);
        strcpy(cadastro.identidade,rg);
		//abrir o arquivo
		FILE* cadastrar = fopen(cadastrar_arq,"ab");

		//verificar se o arquivo foi criado
		if(cadastrar == NULL){
			quadrado(GREENWATER);
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
		gotoxy(40,24);
		printf("                                                         ");
		gotoxy(40,25);
		printf("                                                         ");
		gotoxy(40,26);
		printf("                                                         ");
		gotoxy(55,23);
		printf("NOVA INCLUS%cO?",199);
		op1 = sim_nao(49,25,LIGHTGREEN,LIGHTRED);

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

		quadrado(GREENWATER);
		criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(58,5);
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
		criar_caixinha(1,1,122,34,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		criar_caixinha(4,3,116,30,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

		textcolor(GREENWATER);
		gotoxy(43,31);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");

	}else{
		int aux = cont * 9 + 5;

		textcolor(GREENWATER);
		criar_caixinha(1,1,122,aux,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		criar_caixinha(3,3,116,aux - 4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

		textcolor(GREENWATER);
		gotoxy(43,aux - 3);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
	}

	criar_caixinha(46,2,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,3);
	printf("CONSULTA");


	cadastrar = fopen(cadastrar_arq,"rb");

	//Caso não tenha nenhum erro ele exibe o que tem no arquivo
	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){

		textcolor(GREENWATER);
		criar_caixinha(38,y,45,6,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
	int tecla1;
	int salvar1 = 1;
	int op = 1;
	int op2;
	int aux1;
	int aux2;
	int cpf;
	int aux4;
	int aux5;

	reescreverAlteracao(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
	reescreverProx(GREY,GREY,42,27,salvar);

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
        if(tecla == BAIXO || tecla == CIMA){
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

                    reescreverAlteracao(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
                    reescreverProx(LIGHTGREEN,GREENWATER,42,27,salvar);

                    do{
                        tecla1 = getch();

                        if(tecla1 == ESQUERDA){
                            salvar1++;
                        }
                        if(tecla1 == DIREITA){
                            salvar1--;
                        }
                        if(tecla1 == CIMA){
                            menuAlteracao();
                        }
                        if(tecla1 == BAIXO){
                            menuAlteracao();
                        }

                        switch(salvar1){
                            case 0:
                                salvar1 = 2;
                                reescreverProx(GREENWATER,LIGHTRED,42,27,salvar);
                                break;

                            case 1:
                                reescreverProx(LIGHTGREEN,GREENWATER,42,27,salvar);
                                break;

                            case 2:
                                reescreverProx(GREENWATER,LIGHTRED,42,27,salvar);
                                break;
                            case 3:
                                salvar1 = 1;
                                reescreverProx(LIGHTGREEN,GREENWATER,42,27,salvar);
                                break;
                        }
                    }while(tecla1 != 13);

                    if(salvar1 == 1){

                        FILE* cadastrar = fopen(cadastrar_arq,"rb");
                        FILE* cadastraraux = fopen(cadastrar_arqaux,"ab");
                        rewind(cadastrar);

                        if(cadastrar == NULL || cadastraraux == NULL){
                            quadrado(GREENWATER);
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
                        gotoxy(40,27);
                        printf("                                                   ");
                        gotoxy(40,28);
                        printf("                                                   ");
                        gotoxy(40,29);
                        printf("                                                   ");
                        gotoxy(55,27);
                        printf("NOVA ALTERA%c%cO?",128,199);
                        op2 = sim_nao(50,29,LIGHTGREEN,LIGHTRED);

                        if(op2 == 1){
                            system("CLS");
                            alteracaoUsuario();
                        }
                        else{
                            system("CLS");
                            cadastroUsuario();
                        }
                            break;
                    }
                    if(salvar1 == 2){
                        system("cls");
                        alteracaoUsuario();
                    }

                    break;

                case 7:
                    op = 1;
                    reescreverAlteracao(GREENWATER,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
                    break;
            }
        }

	}while(tecla != ENTER || tecla == ESC);

	switch(op){
		case 1:
			reescreverAlteracao(LIGHTYELLOW,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
			gotoxy(38 + strlen(campo1),11);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo1),11);
				getString(cadastro.nome);
				aux1 = verificarLetra(cadastro.nome,100);

				if(cadastro.nome[0] == '\0'){
			       	gotoxy(38 + strlen(campo1),12);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo1),12);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(campo1),12);
		        	printf("                                            ");
				}

				if(aux1 == 0 ){
					gotoxy(38 + strlen(campo1),12);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo1),12);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo1),12);
		        	printf("                                            ");
				}

				if(strlen(cadastro.nome) > 100){
					gotoxy(38 + strlen(campo1),12);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo1),12);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo1),12);
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
			gotoxy(38 + strlen(campo2),14);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo2),14);
				getString(cadastro.matricula);
				aux2 = verificarNumeros(cadastro.matricula,12);

				if(cadastro.matricula[0] == '\0'){
			       	gotoxy(38 + strlen(campo2),14);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo2),14);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(campo2),14);
		        	printf("                                            ");
				}

				if(aux2 == 0){
					gotoxy(38 + strlen(campo2),14);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo2),14);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo2),14);
		        	printf("                                            ");
				}

				if(strlen(cadastro.matricula) > 12){
					gotoxy(38 + strlen(campo2),14);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo2),14);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo2),14);
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
			gotoxy(38 + strlen(campo3),17);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo3),17);
				getString(cadastro.cpf);
				cpf = validarCPF(cadastro.cpf);

				if(cadastro.cpf[0] == '\0'){
			        gotoxy(38 + strlen(campo3),17);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo3),17);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(campo3),17);
		        	printf("                                           ");
				}

				if(cpf == 0){
					gotoxy(38 + strlen(campo3),17);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo3),17);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo3),17);
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
			gotoxy(38 + strlen(campo4),20);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo4),20);
				getString(cadastro.identidade);
				aux4 = verificarNumeros(cadastro.identidade,8);

				if(cadastro.identidade[0] == '\0'){
			       	gotoxy(38 + strlen(campo4),20);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo4),20);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(campo4),20);
		        	printf("                                            ");
				}

				if(aux4 == 0){
					gotoxy(38 + strlen(campo4),20);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo4),20);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo4),20);
		        	printf("                                            ");
				}

				if(strlen(cadastro.identidade) > 8){
					gotoxy(38 + strlen(campo4),20);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo4),20);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo4),20);
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
			gotoxy(38 + strlen(campo5),23);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(campo5),23);
				getString(cadastro.curso);
				aux5 = verificarLetra(cadastro.curso,11);

				if(cadastro.curso[0] == '\0'){
			       	gotoxy(38 + strlen(campo5),23);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo5),23);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(campo5),23);
		        	printf("                                            ");
				}

				if(aux5 == 0){
					gotoxy(38 + strlen(campo5),23);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo5),23);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo5),23);
		        	printf("                                            ");
				}

				if(strlen(cadastro.curso) > 11){
					gotoxy(38 + strlen(campo5),23);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(campo5),23);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(campo5),23);
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

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("ALTERA%c%cO",128,199);

	FILE* cadastrar = fopen(cadastrar_arq,"rb");

	int op;
	int op1;
	int op2;
	int op3;
	int y = 10;
	int tecla;
	int encontrou = FALSE;
	char confiSenha[7];


	textcolor(GREENWATER);
	criar_caixinha(35,16,50,2,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);
	gotoxy(43,15);
	printf("INFORME A MATRICULA QUE DESEJA ALTERAR");
	gotoxy(37,17);
	textcolor(BRIGHTWHITE);
	printf("MATRICULA: ");
	setbuf(stdin, NULL);
	gotoxy(48,17);
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
		gotoxy(49,20);
		printf("MATRICULA N%cO ENCONTRADA\n",199);
		gotoxy(35,21);
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


	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,218,191,192,217,179,196);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
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
	op = sim_nao(51,y+=2,LIGHTGREEN,LIGHTRED);

	if(op == 1){
		quadrado(GREENWATER);

		criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(58,5);
		printf("ALTERA%c%cO",128,199);

		textcolor(GREENWATER);
		gotoxy(53,8);
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

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("EXCLUS%cO",199);

	int y = 9;
	int encontrou = FALSE;
	char matricula[13];
	int op;
	int op2;
	int tecla;

	FILE* cadastrar = fopen(cadastrar_arq,"rb");

	textcolor(GREENWATER);
	criar_caixinha(35,16,50,2,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);
	gotoxy(43,15);
	printf("INFORME A MATRICULA QUE DESEJA EXCLUIR");
	gotoxy(37,17);
	textcolor(BRIGHTWHITE);
	printf("MATRICULA: ");
	setbuf(stdin, NULL);
	gotoxy(48,17);
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
		gotoxy(50,20);
		printf("MATRICULA N%cO ENCONTRADA\n",199);
		gotoxy(35,21);
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

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
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
	op = sim_nao(51,y+=2,LIGHTRED,LIGHTGREEN);

	if(op == 1){

		FILE* cadastraraux = fopen(cadastrar_arqaux,"ab");
		cadastrar = fopen(cadastrar_arq, "rb");


		if(cadastrar == NULL || cadastraraux == NULL){
			quadrado(GREENWATER);
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
		gotoxy(51,21);
		printf("                                ");
		gotoxy(56,21);
		printf("NOVA EXCLUS%cO?",199);
		op2 = sim_nao(51,23,LIGHTRED,LIGHTGREEN);

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

	quadrado(GREENWATER);

	int tecla;
	int op = 1;

	textcolor(GREENWATER);
	criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(51,5);
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
        if(tecla == BAIXO || tecla == CIMA){
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
	gotoxy(38,11);
	puts(codigo1);
	barrinha(38,12,47);

	do{
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(codigo1),11);
		setbuf(stdin, NULL);
		getString(codigoPublicacao);
		tamanho = strlen(codigoPublicacao);
		aux = verificarNumeros(codigoPublicacao,20);

		if(codigoPublicacao[0] == '\0'){
	        gotoxy(38 + strlen(codigo1),11);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),11);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(700);
		}
		if(tamanho > 20){
			gotoxy(38 + strlen(codigo1),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),11);
			printf("INV%cLIDO",181);
			Sleep(700);
		}
		if(aux == 0){
			gotoxy(38 + strlen(codigo1),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),11);
			printf("APENAS NUMERO");
        	gotoxy(1,1);
			Sleep(700);
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
			gotoxy(38 + strlen(codigo1),11);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),11);
			printf("CODIGO JA CADASTRDO");
        	gotoxy(1,1);
			Sleep(700);
		}

	    gotoxy(38 + strlen(codigo1),11);
	    printf("                                            ");

	}while(codigoPublicacao[0] == '\0' || tamanho > 20 || aux == 0 || encontrou == TRUE);

	fclose(publicacao);

	//Troca a Cor se Preenchido Corretamente
	if(matriculaUsuario[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,11);
		puts(codigo1);
		gotoxy(38 + strlen(codigo1),11);
		setbuf(stdin, NULL);
		puts(codigoPublicacao);
		barrinha(38,12,47);
	}
}

void inclusaoPublicacao(){

	quadrado(GREENWATER);

	int op;
	int op1;
	int op3;
	int tecla;
	int tamanho = 0;

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("INCLUS%cO",199);

	//Entrada de dados
	textcolor(BRIGHTWHITE);
	gotoxy(38,14);
	puts(titulo);
	barrinha(38,15,47);

	textcolor(BRIGHTWHITE);
	gotoxy(38,17);
	puts(autor);
	barrinha(38,18,47);

	//Código
	codigo();
	if(codigoPublicacao[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}

	//Título
	verificacaoChar(38,14,titulo,publicar.titulo,50,BRIGHTWHITE);

	if(codigoPublicacao[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}

	//Autor
	verificacaoChar(38,17,autor,publicar.autor,100,BRIGHTWHITE);

	if(publicar.autor[0] == ESC){
		system("cls");
		cadastroPublicacao();
	}

	strcpy(publicar.codigo,codigoPublicacao);

	//Interagindo com o usuario
	op = proximo(salvar);

	if(op == 1){

		//Abre o arquivo
		FILE* publicacao = fopen(publicacao_arq,"ab");

		//Verifica se o arquivo realmente foi criado
		if(publicacao == NULL){
			quadrado(GREENWATER);
			textcolor(LIGHTRED);
			gotoxy(49,15);
			printf("ERRO AO SALVAR ARQUIVO");
			gotoxy(45,16);
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
		gotoxy(40,24);
		printf("                                                         ");
		gotoxy(40,25);
		printf("                                                         ");
		gotoxy(40,26);
		printf("                                                         ");
		gotoxy(56,22);
		printf("NOVA INCLUS%cO?",199);
		op1 = sim_nao(51,24,LIGHTGREEN,LIGHTRED);

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

		quadrado(GREENWATER);
		criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(58,5);
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
		criar_caixinha(1,1,122,35,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		criar_caixinha(4,3,116,31,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

		textcolor(GREENWATER);
		gotoxy(43,32);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");

	}else{
		int aux = cont * 8 + 2;

		textcolor(GREENWATER);
		criar_caixinha(1,1,122,aux - 1,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		criar_caixinha(3,3,116,aux - 5,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

		textcolor(GREENWATER);
		gotoxy(43,aux - 4);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");

	}
	criar_caixinha(46,2,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,3);
	printf("CONSULTA");

	//Reabre o arquivo em modo de leitura binária
	publicacao = fopen(publicacao_arq,"rb");

	//Verifica se o arquivo existe, caso não, exibi uma mensagem de erro
	if(publicacao == NULL){

		quadrado(GREENWATER);
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
		criar_caixinha(38,y,45,4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
	int tecla1;
	int salvar1 = 1;
	int op = 1;
	int op2;
	int aux1;
	int aux2;
	int aux3;

	reescreverAlteracaoPublic(GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
	reescreverProx(GREY,GREY,42,22,salvar);

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
			cadastroPublicacao();
		}
        if(tecla == BAIXO || tecla == CIMA){
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

                    reescreverAlteracaoPublic(BRIGHTWHITE,BRIGHTWHITE,BRIGHTWHITE);
                    reescreverProx(LIGHTGREEN,GREENWATER,42,22,salvar);

                    do{
                        tecla1 = getch();

                        if(tecla1 == ESQUERDA){
                            salvar1++;
                        }
                        if(tecla1 == DIREITA){
                            salvar1--;
                        }
                        if(tecla1 == CIMA){
                            menuAlterarPublicacao();
                        }
                        if(tecla1 == BAIXO){
                            menuAlterarPublicacao();
                        }

                        switch(salvar1){
                            case 0:
                                salvar1 = 2;
                                reescreverProx(GREENWATER,LIGHTRED,42,22,salvar);
                                break;

                            case 1:
                                reescreverProx(LIGHTGREEN,GREENWATER,42,22,salvar);
                                break;

                            case 2:
                                reescreverProx(GREENWATER,LIGHTRED,42,22,salvar);
                                break;
                            case 3:
                                salvar1 = 1;
                                reescreverProx(LIGHTGREEN,GREENWATER,42,22,salvar);
                                break;
                        }
                    }while(tecla1 != 13);

                    if(salvar1 == 1){

                        FILE* publicacaoaux = fopen(publicacao_arqaux,"ab");
                        FILE* publicacao = fopen(publicacao_arq,"rb");
                        rewind(publicacao);

                        if(publicacao == NULL || publicacaoaux == NULL){
                            quadrado(GREENWATER);
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

                        gotoxy(40,22);
                        printf("                                                         ");
                        gotoxy(40,23);
                        printf("                                                         ");
                        gotoxy(40,24);
                        printf("                                                          ");
                        textcolor(GREENWATER);
                        gotoxy(56,22);
                        printf("NOVA ALTERA%c%cO?",128,199);
                        op2 = sim_nao(51,24,LIGHTGREEN,LIGHTRED);// Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe

                        if(op2 == 1){
                            alteracaoPublicacao();
                        }
                        else{
                            system("CLS");
                            cadastroPublicacao();
                        }
                    }
                    if(salvar1 == 2){
                        system("cls");
                        alteracaoPublicacao();
                    }
                    break;

                case 5:
                    op = 1;
                    reescreverAlteracaoPublic(GREENWATER,BRIGHTWHITE,BRIGHTWHITE);
                    break;

            }
        }

	}while(tecla != ENTER || tecla == ESC);

	switch(op){
		case 1:
			reescreverAlteracaoPublic(LIGHTYELLOW,BRIGHTWHITE,BRIGHTWHITE);
			gotoxy(38 + strlen(codigo1),12);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(codigo1),12);
				getString(publicar.codigo);
				aux1 = verificarNumeros(publicar.codigo,20);

				if(publicar.codigo[0] == '\0'){
			       	gotoxy(38 + strlen(codigo1),12);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(codigo1),12);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(codigo1),12);
		        	printf("                                            ");
				}

				if(aux1 == 0 ){
					gotoxy(38 + strlen(codigo1),12);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(codigo1),12);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(codigo1),12);
		        	printf("                                            ");
				}

				if(strlen(publicar.codigo) > 20){
					gotoxy(38 + strlen(codigo1),12);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(codigo1),12);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(codigo1),12);
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
			gotoxy(38 + strlen(titulo),15);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(titulo),15);
				getString(publicar.titulo);
				aux2 = verificarLetra(publicar.titulo,50);

				if(publicar.titulo[0] == '\0'){
			       	gotoxy(38 + strlen(titulo),15);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(titulo),15);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(titulo),15);
		        	printf("                                            ");
				}

				if(aux2 == 0){
					gotoxy(38 + strlen(titulo),15);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(titulo),15);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(titulo),15);
		        	printf("                                            ");
				}

				if(strlen(publicar.titulo) > 50){
					gotoxy(38 + strlen(titulo),15);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(titulo),15);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(titulo),15);
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
			gotoxy(38 + strlen(autor),18);
			printf("                                           ");
			do{
				textcolor(LIGHTYELLOW);
				gotoxy(38 + strlen(autor),18);
				getString(publicar.autor);
				aux3 = verificarLetra(publicar.autor,100);

				if(publicar.autor[0] == '\0'){
			       	gotoxy(38 + strlen(autor),18);
			        printf("                                       ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(autor),18);
					printf("CAMPO OBRIGAT%cRIO!",224);
					Sleep(500);
					gotoxy(38 + strlen(autor),18);
		        	printf("                                            ");
				}

				if(aux3 == 0){
					gotoxy(38 + strlen(autor),18);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(autor),18);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(autor),18);
		        	printf("                                            ");
				}

			    if(strlen(publicar.autor) > 100){
			    	gotoxy(38 + strlen(autor),18);
			        printf("                                        ");
					textcolor(LIGHTRED);
					gotoxy(38 + strlen(autor),18);
					printf("INV%cLIDO",181);
					Sleep(500);
					gotoxy(38 + strlen(autor),18);
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

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("ALTERA%c%cO",128,199);

	//Abre o arquivo em modo de leitura binária
	FILE* publicacao = fopen(publicacao_arq,"rb");

	int y = 11;
	int op;
	int op1;
	int encontrou = FALSE;
	int tecla;

	textcolor(GREENWATER);
	criar_caixinha(35,16,50,2,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);
	gotoxy(44,15);
	printf("INFORME O CODIGO QUE DESEJA ALTERAR");
	gotoxy(37,17);
	textcolor(BRIGHTWHITE);
	printf("CODIGO: ");
	setbuf(stdin, NULL);
	gotoxy(45,17);
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
		gotoxy(50,20);
		printf("CODIGO N%cO ENCONTRADO",199);
		gotoxy(34,21);
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

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
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
	op = sim_nao(51,21,LIGHTGREEN,LIGHTRED); // Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe

	if(op == 1){ // op recebe 1 e indica que ele escolheu sim
		quadrado(GREENWATER);

		criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(58,5);
		printf("ALTERA%c%cO",128,199);

		textcolor(GREENWATER);
		gotoxy(53,9);
		printf("INSIRA OS NOVOS DADOS\n");

		menuAlterarPublicacao();
	}
	else
		system("CLS");
		cadastroPublicacao();
}

void exclusaoPublicacao(){

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
	printf("EXCLUS%cO",199);

	int y = 11;
	int encontrou = FALSE;
	char codigo[20];
	int op;
	int op2;
	int tecla;

	FILE* publicacao = fopen(publicacao_arq,"rb");

	textcolor(GREENWATER);
	criar_caixinha(35,16,50,2,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);
	gotoxy(44,15);
	printf("INFORME O CODIGO QUE DESEJA EXCLUIR");
	gotoxy(37,17);
	textcolor(BRIGHTWHITE);
	printf("CODIGO: ");
	setbuf(stdin, NULL);
	gotoxy(45,17);
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
		gotoxy(50,20);
		printf("CODIGO N%cO ENCONTRADO",199);
		gotoxy(35,21);
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

	quadrado(GREENWATER);

	criar_caixinha(46,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(58,5);
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
	gotoxy(51,20);
	printf("DESEJA EXCLUIR OS DADOS?\n");
	op = sim_nao(51,22,LIGHTRED,LIGHTGREEN); // Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe

	if(op == 1){ // op recebe 1 e indica que ele escolheu sim
		FILE* publicacaoaux = fopen(publicacao_arqaux,"ab");
		publicacao = fopen(publicacao_arq,"rb");


	if(publicacao == NULL || publicacaoaux == NULL){
		quadrado(GREENWATER);
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

	gotoxy(51,20);
	printf("                           ");
	textcolor(GREENWATER);
	gotoxy(56,20);
	printf("NOVA EXCLUS%cO?",199);
	op2 = sim_nao(51,22,LIGHTRED,LIGHTGREEN); // Variavel op recebe a função sim e nao que mostra a opção que o usuario escolhe


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

	quadrado(GREENWATER);

	textcolor(GREENWATER);
	criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(55,5);
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
        if(tecla == BAIXO || tecla == CIMA){
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

	quadrado(GREENWATER);

	int i;
	int op;
	int tecla;
	int encontrou = FALSE;
	char cod[20];

	criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(50,5);
	printf("EMPRESTIMO DE PUBLICA%c%cO",128,199);

	FILE* publicacao = fopen(publicacao_arq,"rb");

	textcolor(GREENWATER);
	gotoxy(33,10);
	printf("INFORME O C%cDIGO DA PUBLICA%c%cO E A MATR%cCULA DO USU%cRIO",224,128,199,214,181);

	//Entrada de dados

	textcolor(BRIGHTWHITE);
	gotoxy(38,17);
	puts(campo2);
	barrinha(38,18,47);

	//Código
	codigoEmprestimo();

	numeroTombo();

	dadosUsuario();

	while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
		if(strcmp(emprestarCodigo,publicar.codigo) == 0){
            strcpy(emprestar.autor,publicar.autor);
            strcpy(emprestar.titulo,publicar.titulo);

			quadrado(GREENWATER);
			criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			textcolor(BRIGHTWHITE);
			gotoxy(50,5);
			printf("EMPRESTIMO DE PUBLICA%c%cO",128,199);

			gotoxy(38,10);
			textcolor(BRIGHTWHITE);
			setbuf(stdin, NULL);
			printf("CODIGO: ");
			puts(publicar.codigo);
			barrinha(38,11,47);

			gotoxy(38,13);
			printf("TITULO: ");
			puts(publicar.titulo);
			barrinha(38,14,47);

			gotoxy(38,16);
			printf("AUTOR: ");
			puts(publicar.autor);
			barrinha(38,17,47);

			break;
		}
	}

	fclose(publicacao);

	emprestar.numeroTombo = numero;
    strcpy(emprestar.codigo,emprestarCodigo);

	textcolor(GREENWATER);
	gotoxy(46,23);
	printf("DESEJA EMPRESTAR A PUBLICA%c%cO?",128,199);
	op = sim_nao(49,25,LIGHTGREEN,LIGHTRED);

	if(op == 1){

	FILE* emprestimo = fopen(emprestimo_arq,"ab");

	if(emprestimo == NULL){
		quadrado(GREENWATER);
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

		gotoxy(43,23);
		printf("                                                      ");
		gotoxy(43,24);
		printf("                                                      ");
		gotoxy(43,25);
		printf("                                                      ");
		gotoxy(43,26);
		printf("                                                      ");
		gotoxy(43,27);
		printf("                                                      ");
		gotoxy(1,1);

		for(i = 0; i < 3; i++){
			Sleep(450);
			gotoxy(1,1);
			textcolor(LIGHTGREEN);
			criar_caixinha(43,23,36,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			gotoxy(46,24);
			printf("EMPRESTIMO EFETUADO COM SUCESSO!");
			gotoxy(1,1);
			Sleep(450);
			gotoxy(43,23);
			printf("                                                      ");
			gotoxy(43,24);
			printf("                                                      ");
			gotoxy(43,25);
			printf("                                                      ");
			gotoxy(1,1);

		}
	}


	system("cls");
	movimentacao();
}

//Funca responsavel por ler o codigo informado no emprestimo e verificar se existe no arquivo
void codigoEmprestimo(){

	FILE* publicacao = fopen(publicacao_arq,"rb");

	int encontrou;
	int tamanho;
	int aux;

	//Campo
	textcolor(GREENWATER);
	gotoxy(38,14);
	puts(codigo1);
	barrinha(38,15,47);

	do{
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(codigo1),14);
		setbuf(stdin, NULL);
		getString(emprestarCodigo);
		tamanho = strlen(emprestarCodigo);
		aux = verificarNumeros(emprestarCodigo,12);

		if(emprestarCodigo[0] == '\0'){
	        gotoxy(38 + strlen(codigo1),14);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),14);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(500);
		}
		if(tamanho > 20){
			gotoxy(38 + strlen(codigo1),14);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),14);
			printf("INV%cLIDO",181);
			Sleep(500);
		}
		if(aux == 0){
			gotoxy(38 + strlen(codigo1),14);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),14);
			printf("INV%cLIDO",181);
			Sleep(500);
		}
		if(publicacao != NULL){

			rewind(publicacao);
			while(fread(&publicar,sizeof(Publicacao),1,publicacao)){
				if(strcmp(emprestarCodigo, publicar.codigo) == 0){
					encontrou = TRUE;
					break;
				}
			}
		}
		if(emprestarCodigo[0] == ESC){
			system("cls");
			movimentacao();
		}
		if(!encontrou){
			gotoxy(38 + strlen(codigo1),14);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(codigo1),14);
			printf("PUBLICA%c%cO N%cO ENCONTRADO",128,199,199);
			Sleep(500);
		}
		if(emprestarCodigo[0] == ESC){
			system("cls");
			movimentacao();
		}

	    gotoxy(38 + strlen(codigo1),14);
	    printf("                                            ");

	}while(emprestarCodigo[0] == '\0' || tamanho > 20 || aux == 0 || encontrou != TRUE);

	fclose(publicacao);

	//Troca a Cor se Preenchido Corretamente
	if(emprestarCodigo[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,14);
		puts(codigo1);
		gotoxy(38 + strlen(codigo1),14);
		setbuf(stdin, NULL);
		puts(emprestarCodigo);
		barrinha(38,15,47);
	}
}

void getSenha(char var[]){

    int i;
	int tecla;
	int pos = 0;
	int aux = TRUE;

	var[0] = '\0';

	do{
		tecla = getch();

        if(tecla == TAB){
            if(aux == FALSE){
                aux = TRUE;
            }
            else{
                aux = FALSE;
            }
        }

        if(aux == TRUE){
            if(isprint(tecla)){
                var[pos] = tecla;
                var[pos + 1] = '\0';
                pos++;
                printf("%c",42);
            }
        }
		if(aux == FALSE){
            if(isprint(tecla)){
                var[pos] = tecla;
                var[pos + 1] = '\0';
                pos++;
                printf("%c",tecla);
            }
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

void senha(char campo[], char senha[], int x, int y){

	int i;
	int tamanho;

	//Campo
	textcolor(GREENWATER);
	gotoxy(x,y);
	puts(campo);
	barrinha(x,y+1,47);

	do{

		gotoxy(x + strlen(campo),y);
		printf("                                            ");

		textcolor(GREENWATER);
		gotoxy(x + strlen(campo),y);
		setbuf(stdin, NULL);
		getSenha(senha);
		tamanho = strlen(senha);

		if(senha[0] == '\0'){
	        gotoxy(x + strlen(campo),y);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(600);
		}
		if(tamanho > 20){
			gotoxy(x + strlen(campo),y);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(campo),y);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
		if(senhaUsuario[0] == ESC){
			return;
		}
	    gotoxy(x + strlen(campo),y);
	    printf("                                            ");


	}while(senha[0] == '\0' || tamanho > 20);

	//Troca a Cor se Preenchido Corretamente
	if(senha[0] != ESC){

		textcolor(BRIGHTWHITE);

		gotoxy(x,y);
		puts(campo);

		gotoxy(x + strlen(campo),y);
		for(i = 0; i < tamanho; i++){
			printf("*");
		}

		barrinha(38,15,47);
	}
}

void senhaconfirmar(char confirmar[], char senha3[], char senha4[], int x, int y){

	int tamanho;
	int aux;
	int encontrou;
	int i;

	//Campo
	textcolor(BRIGHTWHITE);
	barrinha(x,y - 2,47);
	textcolor(GREENWATER);
	gotoxy(x,y);
	puts(confSenha);
	barrinha(x,y+1,47);

	do{

		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(x,y);
		puts(confSenha);
		barrinha(x,y+1,47);
		gotoxy(x + strlen(confSenha),y);
		setbuf(stdin, NULL);

		getSenha(confirmar);
		tamanho = strlen(confirmar);

		if(confirmar[0] == '\0'){
	        gotoxy(x + strlen(confSenha),y);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(confSenha),y);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(600);
		}
		if(tamanho > 20){
			gotoxy(x + strlen(confSenha),y);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(x + strlen(confSenha),y);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
        if(confirmar[0] == ESC){
            return;
        }
		if(strcmp(confirmar,senha3) != 0){

			gotoxy(x + strlen(confSenha),y);
	        printf("                                        ");

			textcolor(LIGHTRED);
			gotoxy(x + strlen(confSenha),y);
			printf("SENHA INV%cLIDA",181);

			gotoxy(x + strlen(senha4),y-3);
			printf("SENHA INV%cLIDA",181);
			gotoxy(1,1);
			Sleep(1000);

			gotoxy(x + strlen(confSenha),y);
	    	printf("                                            ");

	    	textcolor(BRIGHTWHITE);
			gotoxy(x,y);
			puts(confSenha);
			barrinha(x,y+1,47);

			senha(senha4,senha3,x,y - 3);

			encontrou = TRUE;
		}

	    gotoxy(x + strlen(confSenha),y);
	    printf("                                            ");

	}while(senha1[0] == '\0' || tamanho > 20 || encontrou == TRUE );

	//Troca a Cor se Preenchido Corretamente
	if(confirmar[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(x,y);
		puts(confSenha);
		gotoxy(x + strlen(confSenha),y);
		setbuf(stdin, NULL);
		for(i = 0; i < tamanho; i++){
			printf("*");
		}
		barrinha(38,18,47);
	}

}

//Funcao responsavel por ler a matricula informmda no emprestimo e verificar se existe no arquivo
void matriculaEmprestimo(){

	FILE* cadastrar = fopen(cadastrar_arq,"rb");

	int encontrou;
	int tamanho;
	int aux;

	//Campo
	textcolor(GREENWATER);
	gotoxy(38,17);
	puts(campo2);
	barrinha(38,18,47);

	do{
		encontrou = FALSE;

		textcolor(GREENWATER);
		gotoxy(38 + strlen(campo2),17);
		setbuf(stdin, NULL);
		getString(emprestarMatricula);
		tamanho = strlen(emprestarMatricula);
		aux = verificarNumeros(emprestarMatricula,12);

		if(emprestarMatricula[0] == '\0'){
	        gotoxy(38 + strlen(campo2),17);
	        printf("                                       ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),17);
			printf("CAMPO OBRIGAT%cRIO!",224);
			Sleep(600);
		}
		if(tamanho > 12){
			gotoxy(38 + strlen(campo2),17);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),17);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
		if(aux == 0){
			gotoxy(38 + strlen(campo2),17);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),17);
			printf("INV%cLIDO",181);
			Sleep(600);
		}
		if(cadastrar != NULL){

			rewind(cadastrar);
			while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
				if(strcmp(emprestarMatricula,cadastro.matricula) == 0){
					strcpy(emprestar.nome,cadastro.nome);
					strcpy(emprestar.cpf,cadastro.cpf);
					strcpy(emprestar.rg,cadastro.identidade);
					strcpy(emprestar.curso,cadastro.curso);
					encontrou = TRUE;
				}
			}
		}
		if(!encontrou){
			gotoxy(38 + strlen(campo2),17);
	        printf("                                        ");
			textcolor(LIGHTRED);
			gotoxy(38 + strlen(campo2),17);
			printf("USU%cRIO N%cO ENCONTRADO",181,199);
			Sleep(600);
		}
		if(emprestarMatricula[0] == ESC){
			system("cls");
			movimentacao();
		}

	    gotoxy(38 + strlen(campo2),17);
	    printf("                                            ");

	}while(emprestarMatricula[0] == '\0' || tamanho > 12 || aux == 0 || encontrou != TRUE);

	fclose(cadastrar);

	//Troca a Cor se Preenchido Corretamente
	if(emprestarMatricula[0] != ESC){

		textcolor(BRIGHTWHITE);
		gotoxy(38,17);
		puts(campo2);
		gotoxy(38 + strlen(campo2),17);
		setbuf(stdin, NULL);
		puts(emprestarMatricula);
		barrinha(38,18,47);
	}
}

void dadosUsuario(){

	int i;
	int tecla;
	int encontrou = FALSE;

	//Matricula
	matriculaEmprestimo();

	if(emprestarMatricula[0] == ESC){
		system("cls");
		consulta_de_acervo();
	}

	strcpy(emprestar.matricula,emprestarMatricula);

	for(i = 0; i < 3; i++){

		Sleep(450);
		gotoxy(1,1);
		textcolor(LIGHTGREEN);
		criar_caixinha(49,24,24,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		gotoxy(52,25);
		printf("PUBLICA%c%cO DISPON%cVEL",128,199,214);
		gotoxy(1,1);
		Sleep(450);
		gotoxy(49,24);
		printf("                                                      ");
		gotoxy(1,1);
		gotoxy(49,25);
		printf("                                                     ");
		gotoxy(1,1);
		gotoxy(49,26);
		printf("                                                     ");
		gotoxy(1,1);

	}

}

//Função que efetua a devolucacao de determinada publicação
void devolucao(){

	int i;
	int y = 7;
	int tecla;
	int encontrar = FALSE;
	int encontrou = FALSE;
	int op;

	FILE* emprestimo = fopen(emprestimo_arq,"rb");

	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(emprestimo == NULL){

		quadrado(GREENWATER);

		criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(50,5);
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

	quadrado(GREENWATER);

	criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(50,5);
	printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);

	textcolor(GREENWATER);
	gotoxy(38,10);
	printf("INFORME SUA MATRICULA E O C%cDIGO DA PUBLICA%c%cO",224,128,199);

	//Entrada de dados
	textcolor(BRIGHTWHITE);
	gotoxy(38,17);
	puts(campo2);
	barrinha(38,18,47);

	//Codigo
	verificacaoInt(38,14,codigo1,devolver.codigo,20,BRIGHTWHITE);
	if(devolver.codigo[0] == ESC){
		system("cls");
		movimentacao();
	}
	
	//Matricula
	verificacaoInt(38,17,campo2,devolver.matricula,12,BRIGHTWHITE);
	if(devolver.matricula[0] == ESC){
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

			quadrado(GREENWATER);
			criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			textcolor(BRIGHTWHITE);
			gotoxy(50,5);
			printf("DEVOLU%c%cO DE PUBLICA%c%cO",128,199,128,199);

			gotoxy(38,10);
			textcolor(BRIGHTWHITE);
			setbuf(stdin, NULL);
			printf("CODIGO: ");
			puts(emprestar.codigo);
			barrinha(38,11,47);

			gotoxy(38,13);
			printf("TITULO: ");
			puts(emprestar.titulo);
			barrinha(38,14,47);

			gotoxy(38,16);
			printf("AUTOR: ");
			puts(emprestar.autor);
			barrinha(38,17,47);

			break;
		}
	}

	fclose(emprestimo);

	textcolor(GREENWATER);
	gotoxy(47,21);
	printf("DESEJA DEVOLVER A PUBLICA%c%cO?",128,199);
	op = sim_nao(50,23,LIGHTGREEN,LIGHTRED);

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

		for(i = 0; i < 3; i++){
			Sleep(450);
			gotoxy(1,1);
			textcolor(LIGHTGREEN);
			criar_caixinha(43,23,36,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
			gotoxy(47,24);
			printf("DEVOLU%c%cO EFETUADO COM SUCESSO!",128,199);
			gotoxy(1,1);
			Sleep(450);
			gotoxy(43,23);
			printf("                                                      ");
			gotoxy(43,24);
			printf("                                                      ");
			gotoxy(43,25);
			printf("                                                      ");
			gotoxy(1,1);

		}

	}

	system("cls");
	movimentacao();

}

//Função que possibilita o usuario verificar seus emprestimos, devoluções e publicações
void consulta_de_acervo(){

	quadrado(GREENWATER);

	textcolor(GREENWATER);
	criar_caixinha(45,4,30,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(52,5);
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
        if(tecla == BAIXO || tecla == CIMA){
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

	reescreverCarteira(GREENWATER,LIGHTGREEN,32,29);

	do{
		tecla = getch();

		if(tecla == ESQUERDA){
			op++;
		}
		if(tecla == DIREITA){
			op--;
		}
		if(tecla == ESC){

			if(exibir == USUARIO){

				system("cls");
				usuario();
			}

			if(exibir == FUNCIONARIO){

				system("cls");
				consulta_de_acervo();
			}
		}

		switch(op){
			case 0:
				op = 2;
				reescreverCarteira(GREENWATER,LIGHTGREEN,32,29);
				break;

			case 1:
				reescreverCarteira(LIGHTRED,GREENWATER,32,29);
				break;

			case 2:
				reescreverCarteira(GREENWATER,LIGHTGREEN,32,29);
				break;
			case 3:
				op = 1;
				reescreverCarteira(LIGHTRED,GREENWATER,32,29);
				break;
		}
	}while(tecla != 13);

	return op;
}

void carteiraUsuario(char nome[], char matricula[], char curso[], char cpf[], char rg[]){

	textcolor(GREENWATER);
	criar_caixinha(32,9,55,16,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

	textcolor(LIGHTRED);
	gotoxy(35,11);
	printf("%c",223);
	gotoxy(36,11);
	textcolor(LIGHTGREEN);
	printf(" %c %c",223,223);

	gotoxy(35,12);
	printf("%c %c",223,223);
	gotoxy(35,13);
	printf("%c %c %c",223,223,223);
	gotoxy(35,14);
	printf("%c %c",223,223);

	textcolor(GREENWATER);
	gotoxy(44,11);
	printf("INSTITUTO FEDERAL DE");
	gotoxy(44,12);
	printf("EDUCACAO, CIENCIA E TECNOLOGIA");
	gotoxy(44,13);
	printf("DO AMAZONAS");

	textcolor(GREENWATER);
	criar_caixinha(77,10,8,5,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(79,11);
	printf("~~   ~~");
	gotoxy(80,12);
	printf("@   @");
	gotoxy(82,13);
	printf("^");
	gotoxy(81,14);
	printf("===");

	textcolor(LIGHTRED);
	gotoxy(52,15);
	printf("DADOS DE USUARIO");

	textcolor(GREENWATER);
	criar_caixinha(34,16,51,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(GREENWATER);
	gotoxy(36,17);
	puts(campo1);
	textcolor(WHITE);
	gotoxy(42,17);
	converter(nome);

	textcolor(GREENWATER);
	criar_caixinha(34,19,25,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(36,20);
	puts(campo2);
	textcolor(WHITE);
	gotoxy(47,20);
	puts(matricula);

	textcolor(GREENWATER);
	criar_caixinha(66,19,19,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(68,20);
	puts(campo5);
	textcolor(WHITE);
	gotoxy(75,20);
	converter(curso);

	textcolor(GREENWATER);
	criar_caixinha(34,22,17,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(36,23);
	puts(campo3);
	textcolor(WHITE);
	gotoxy(41,23);
	puts(cpf);

	textcolor(GREENWATER);
	criar_caixinha(55,22,13,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(57,23);
	printf("RG:");
	textcolor(WHITE);
	gotoxy(61,23);
	puts(rg);

	textcolor(GREENWATER);
	criar_caixinha(72,22,13,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	gotoxy(74,23);
	printf("UNIDADE:");
	textcolor(WHITE);
	gotoxy(83,23);
	printf("CMC");

	gotoxy(1,1);
}

void acervoUsuario(){

	int y = 8;
	int cont = 0;
	int tecla;
	int op;
	int encontrou = FALSE;
	int encontrouC = FALSE;
	char matriculaE[13];

	//Declaração dos arquivo
	FILE* cadastrar = fopen(cadastrar_arq,"rb");
	FILE* emprestimo = fopen(emprestimo_arq,"rb");

	//Verifica se exixte alguma coisa no arquivo. Se não o programa exibe uma mensagem de erro
	if(emprestimo == NULL && cadastrar == NULL){

		quadrado(GREENWATER);

		criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(52,5);
		printf("CARTEIRA DE USU%cRIO",181);

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

	quadrado(GREENWATER);

	criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(52,5);
	printf("CARTEIRA DE USU%cRIO",181);

	textcolor(GREENWATER);
	criar_caixinha(35,16,50,2,CANTO5,CANTO6,CANTO7,CANTO8,LADO1,LADO2);
	gotoxy(43,15);
	printf("INFORME SUA MATRICULA PARA CONSULTA");

	gotoxy(37,17);
	textcolor(BRIGHTWHITE);
	printf("MATRICULA: ");

	setbuf(stdin, NULL);
	gotoxy(48,17);
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

	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		if(strcmp(matriculaE,cadastro.matricula) == 0){
			encontrouC = TRUE;
			break;
		}
	}

	fclose(cadastrar);
	fclose(emprestimo);

	if(!encontrou && !encontrouC){

		textcolor(LIGHTRED);
		gotoxy(50,18);
		printf("MATRICULA N%cO ENCONTRADA\n",199);
		gotoxy(43,19);
		printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR");
		gotoxy(1,1);
		tecla = getch();
		system("cls");
		consulta_de_acervo();
	}

	emprestimo = fopen(emprestimo_arq,"rb");
	cadastrar = fopen(cadastrar_arq,"rb");

	while(fread(&cadastro,sizeof(Cadastro),1,cadastrar)){
		if(strcmp(matriculaE,cadastro.matricula) == 0){
			carteiraUsuario(cadastro.nome,cadastro.matricula,cadastro.curso,cadastro.cpf,cadastro.identidade);
			break;
		}
	}

	fclose(cadastrar);

	op = opcoes();
	system("cls");

	if(op == 2){

		quadrado(GREENWATER);

		criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(51,5);
		printf("CONSULTA DE EMPRESTIMO");

		gotoxy(6,33);
		printf("                                         ");

		rewind(emprestimo);
		while(fread(&emprestar,sizeof(Emprestimo),1,emprestimo)){
				if(strcmp(matriculaE,emprestar.matricula ) == 0 && encontrouC == TRUE){
					switch(emprestar.situacao){

						case EMPRESTADO:

							textcolor(LIGHTYELLOW);
							criar_caixinha(37,y,45,4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
							criar_caixinha(37,y,45,4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
			printf("                                         ");
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

		quadrado(GREENWATER);

		criar_caixinha(44,4,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		textcolor(BRIGHTWHITE);
		gotoxy(49,5);
		printf("CONSULTA DE MOVIMENTA%c%cO",128,199);

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

	if(cont < 4){
		textcolor(GREENWATER);
		criar_caixinha(1,1,122,35,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		criar_caixinha(4,3,116,31,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

		textcolor(GREENWATER);
		gotoxy(43,32);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
		
		gotoxy(6,32);
		textcolor(LIGHTGREEN);
		printf("%c DEVOLVIDO",254);
		gotoxy(6,33);
		textcolor(LIGHTYELLOW);
		printf("%c EMPRESTADO",254);

	}else{
		int aux = cont * 9 + 3;

		textcolor(GREENWATER);
		criar_caixinha(1,1,122,aux,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
		criar_caixinha(3,3,116,aux - 4,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

		textcolor(GREENWATER);
		gotoxy(43,aux - 3);
		printf("PRESSIONE QUALQUER TECLA PARA RETORNAR");
		
		gotoxy(6,aux-3);
		textcolor(LIGHTGREEN);
		printf("%c DEVOLVIDO",254);
		gotoxy(6,33);
		printf("                                         ");
		gotoxy(6,aux - 2);
		textcolor(LIGHTYELLOW);
		printf("%c EMPRESTADO",254);
	}
	
	textcolor(GREENWATER);
	criar_caixinha(44,2,32,2,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);
	textcolor(BRIGHTWHITE);
	gotoxy(49,3);
	printf("CONSULTA DE MOVIMENTA%c%cO",128,199);

	//Reabre o arquivo em modo de leitura binária
	emprestimo = fopen(emprestimo_arq,"rb");

	//Verifica se o arquivo existe, caso não, exibi uma mensagem de erro
	if(emprestimo == NULL){

		quadrado(GREENWATER);
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
				criar_caixinha(38,y,45,5,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
				criar_caixinha(38,y,45,5,CANTO1,CANTO2,CANTO3,CANTO4,LADO,CIMA1);

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
	//Titulo();
	login();
	return 0;
}
