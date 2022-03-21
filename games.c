#include <stdio.h>

int menu() {
  printf("\n\n======================\n     <<<MENU>>>\n1 - JOGO DAS PERGUNTAS\n2 - ADIVINHE O NUMERO\n3 - OLHO DE COBRA\n4 - SAIR\n\nDIGITE: ");

  char opcao;
  scanf(" %c", &opcao);

  if (opcao == '1') {
    jogarPerguntas();
  } else if (opcao == '2') {
    jogarAdivinhe();
  } else if (opcao == '3') {
    jogarOlhoCobra();
  } else if (opcao == '4') {
    funcaoSair();
  }

  return 0;
}

int jogarPerguntas() {
  
  char altCorreta, altUsuario;

  printf("\n\n=============================\n\t<<JOGO DAS PERGUNTAS>>\n-Serao 3 perguntas.\n");

  //PERGUNTA 1
  altCorreta = '2';
  
  printf("\nQuantos anos apos o seu descobrimento o Brasil se tornou independente?");
  printf("\n[1] 321 anos\n[2] 322 anos\n[3] 323 anos");
  
  printf("\nDigite o numero da alternativa: ");
  scanf(" %c", &altUsuario);

  //CONFERINDO RESPOSTA 1
  
  if (altUsuario == altCorreta) {
    printf("<<Parabens! Voce acertou essa pergunta>>\n");
  } else {
    printf("<<Alternativa errada. A resposta correta era %c>>\n", altCorreta);
  }

  //PERGUNTA 2

  altCorreta = '2';
  
  printf("\nQual desses jogadores venceu o premio de melhor jogador do mundo primeiro?");
  printf("\n[1] Ronaldo\n[2] Romario\n[3] Rivaldo");
  
  printf("\nDigite o numero da alternativa: ");
  scanf(" %c", &altUsuario);

  //CONFERINDO RESPOSTA 2
  
  if (altUsuario == altCorreta) {
    printf("<<Parabens! Voce acertou essa pergunta>>\n");
  } else {
    printf("<<Alternativa errada. A resposta correta era %c>>\n", altCorreta);
  }

  //PERGUNTA 3

  altCorreta = '3';
  
  printf("\nQual dessas empresas e a mais valiosa atualmente?");
  printf("\n[1] Amazon\n[2] Alphabet(Google)\n[3] Microsoft");
  
  printf("\nDigite o numero da alternativa: ");
  scanf(" %c", &altUsuario);

  //CONFERINDO RESPOSTA 3
  
  if (altUsuario == altCorreta) {
    printf("<<Parabens! Voce acertou essa pergunta>>\n");
  } else {
    printf("<<Alternativa errada. A resposta correta era %c>>\n", altCorreta);
  }

  //JOGAR DE NOVO
  char respostaJogarNovamente;
  
	printf("\n\n\n  --Deseja jogar de novo?--\n[1 = SIM; 2 = VOLTAR AO MENU]\nDigite: ");
	fflush(stdin);
	scanf(" %c", &respostaJogarNovamente);
	
	if(respostaJogarNovamente == '1'){
		jogarPerguntas();
	} else {
		menu();
  }
  
}



int jogarAdivinhe() {
	// NUMERO SORTEADO, NUM USUARIO, NUM TENTATIVAS
	int numRand, numUser;
	int t = 0;
	
	//SORTEIO
	srand(time(NULL));
	numRand = rand() % 1001;
  //CONTROLE PRINTAR NUMERO SORTEADO *TIRAR NO FIM*
	//printf("CONTROLE:%d", numRand);

  //PRINT FORMATACAO
	printf("\n\n=============================\n\t<<ADIVINHE O NUMERO>>\n-Os numeros vao de 0 a 1000.\n");
  
	//USUARIO TENTA ACERTAR VALIDA E/OU DIMINUE TENTATIVAS
	while (t <= 5) {
    // VERIFICA SE O USUARIO JA ATINGIU O LIMITE DE TENTATIVAS E DA FEEDBACK A ELE
    if (t == 5) {
			printf("\n\n  -Voce PERDEU\nO numero era %d.", numRand);
			t++;
			break;
		}
    printf("\nTENTATIVAS RESTANTES: %d\n", 5-t);
		printf("Digite um numero: ");
		scanf("%d", &numUser);
		if(numUser == numRand) {
			printf("\nPARABENS! Voce acertou!");
			break;
		} else if (numUser < numRand){
			printf("\nTente um numero maior\n");
			t++;
		} else if (numUser > numRand) {
			printf("\nTente um numero menor\n");
			t++;
    }
	}
  
	//JOGAR DE NOVO
  char respostaJogarNovamente;
  
	printf("\n\n\n  --Deseja jogar de novo?--\n[1 = SIM; 2 = VOLTAR AO MENU]\nDigite: ");
	fflush(stdin);
	scanf(" %c", &respostaJogarNovamente);
	
	if(respostaJogarNovamente == '1'){
		jogarAdivinhe();
	} else {
		menu();
	}

  return 0;
}

int jogarOlhoCobra() {
	//ATRIBUINDO REFERENCIA PRA RAND
	srand(time(NULL));
	
	//FORMATACAO
	printf("\n\n=============================\n  <<OLHO DE COBRA>>\n-Sao necessarios 2 jogadores\nQuem fizer 50 pontos primeiro vence\n");
	printf("REGRAS: Sao necessarios 2 jogadores\nQuem fizer 50 pontos primeiro vence\n");
	printf("\nSao necessarios 2 jogadores\nQuem fizer 50 pontos primeiro vence\nO computador vai jogar dois dados\nA soma dos valores vai para a pontuacao do jogador\nO jogador pode escolher jogar os dados novamente ou finalizar seu turno.\n");
	printf("Se jogar de novo, os novos valores tambem sao somados a pontuacao\nPorem o jogador tem dois riscos:\n--Se em um dado cair o valor 1, o jogador perde todos os pontos acumulado no turno.\n--Caso caiam dois dados 1, o jogador perde todos os pontos que ganhou durante o jogo.\n\n");
	
	//DECLARACAO NOMES E PONTOS DOS JOGADORES
	char nomeJogador1[50];
	char nomeJogador2[50];
	int pontosJogador1 = 0;
	int pontosJogador2 = 0;
	
	printf("Primeiro jogador: ");
	scanf(" %s", &nomeJogador1);
	printf("Segundo jogador: ");
	scanf(" %s", &nomeJogador2);
	
	//SORTEIO DO JOGADOR INICIAL
	int jogadorSorteado;
	jogadorSorteado = (rand() % 2) + 1;
	
	//INVERTENDO OS JOGADORES SE O JOGADOR 2 TIVER QUE COMECAR PRIMEIRO
	char auxiliarTroca[50];
	if (jogadorSorteado == 2) {
		strcpy(auxiliarTroca, nomeJogador1);
		strcpy(nomeJogador1, nomeJogador2);
		strcpy(nomeJogador2, auxiliarTroca);
	}
	
	//CONTROLE DE TROCA -- REMOVER DEPOIS
	//printf("CONTROLE: %s, %s, %d", nomeJogador1, nomeJogador2, jogadorSorteado);
	
	//CONTROLE DE TURNO
	int turno = 1;
	//CRIACAO DOS DADOS E DA PONTUACAO DO TURNO
	int dado1, dado2;
	int pontuacaoTurno = 0;
	//CONTROLE DE RISCO
	int tomarRisco;
	
	//ENTRANDO NO TURNO
	while(pontosJogador1 < 50 && pontosJogador2 < 50) {
		
		//"JOGANDO" OS DADOS
		dado1 = (rand() % 6) + 1;
		dado2 = (rand() % 6) + 1;
		pontuacaoTurno = dado1 + dado2;
		
		//VERIFICANDO TURNO
		if (turno % 2 == 1) {
			printf("\n======================\n%s!\n", nomeJogador1);
		} else {
			printf("\n======================\n%s!\n", nomeJogador2);
		}
		
		//APRESENTANDO VALOR DOS DADOS AO USUARIO E PERGUNTANDO SE QUER JOGAR DE NOVO
		printf("\nDado 1: %d\nDado 2: %d\nSerao adicionados %d pontos\nDeseja jogar de novo? [1 - SIM, 2 - NAO]\nDigite: ", dado1, dado2, pontuacaoTurno);
		scanf(" %d", &tomarRisco);
		
		if (tomarRisco == 1) {
			//NOVOS DADOS
			dado1 = (rand() % 6) + 1;
			dado2 = (rand() % 6) + 1;
			//CHECA 2 ZEROS
			if (dado1 == 1 && dado2 == 1) {
				printf("\n\nDado 1: %d\nDado 2: %d\nVoce perdeu todos os seus pontos do jogo\n", dado1, dado2);
				if (turno % 2 == 1) {
					pontosJogador1 = 0;
				} else {
					pontosJogador2 = 0;
				}
			} else if (dado1 == 1 || dado2 == 1) { //CHECA 1 ZERO
				printf("\n\nDado 1: %d\nDado 2: %d\nVoce perdeu seus pontos do turno\n", dado1, dado2);
				pontuacaoTurno = 0;
			} else { //ADICIONA NORMAL
				pontuacaoTurno = pontuacaoTurno + dado1 + dado2;
				printf("\nDado 1: %d\nDado 2: %d\nSerao adicionados %d", dado1, dado2, pontuacaoTurno);
			}
		}
		
		//RESUMO PRO USUARIO
		if (turno % 2 == 1) {
			pontosJogador1 = pontosJogador1 + pontuacaoTurno;
			printf("\n<<Pontuacao ganha na jogada: %d>>\n<<Sua pontuacao total: %d>>", pontuacaoTurno, pontosJogador1);
		} else {
			pontosJogador2 = pontosJogador2 + pontuacaoTurno;
			printf("\n<<Pontuacao ganha na jogada: %d>>\n<<Sua pontuacao total: %d>>", pontuacaoTurno, pontosJogador2);
		}
		
		//CHECA VITORIA
		if (pontosJogador1 >= 50) {
			printf("\n--------------------------------------\n%s VENCEU O JOGO COM %d PONTOS>>\n--------------------------------------", nomeJogador1, pontosJogador1);
		} else if (pontosJogador2 >= 50) {
			printf("\n--------------------------------------\n%s VENCEU O JOGO COM %d PONTOS>>\n--------------------------------------", nomeJogador2, pontosJogador2);
		}
		
		//PASSA PRO PROXIMO JOGADOR
		turno++;
	}
	//JOGAR DE NOVO
	char respostaJogarNovamente;
  
	printf("\n\n\n  --Deseja jogar de novo?--\n[1 = SIM; 2 = VOLTAR AO MENU]\nDigite: ");
	fflush(stdin);
	scanf(" %c", &respostaJogarNovamente);
	
	if(respostaJogarNovamente == '1'){
	jogarOlhoCobra();
	} else {
	menu();
	}	
}



int funcaoSair() {
  printf("\nFIM!");
  return 0;
}


//MAIN
int main() {
    menu();
    return 0;
}