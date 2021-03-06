#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	//	1)	carregar spritesheet
	//		este m�todo recebe como parametro:
	//			1 - um nome qualquer para o spritesheet
	//			2 - o caminho para a imagem
	//			3 - o n�mero de animacoes
	//			4 - o n�mero de frames da maior animacao
	recursos.carregarSpriteSheet("player", "dados/imagens/sprite_sheet.png", 5, 4);

	//	setar numero de frames na primeira animacao (porque � um n�mero diferente) 
	recursos.getSpriteSheet("player")->setNumFramesAnimacao(0, 1);	//	anim 0, frames = 1


	//	2)	inicializar personagem (setar spritesheet, posicao e velocidade)
	per.setSpriteSheet("player");		//	passando o nome dado ao spritesheet!
	per.setPos(res_x/2, res_y/2);		//	bem no meio da tela
	per.setVel(0.4);
}

void Jogo::finalizar()
{
	//	6)	descarregar tudo (SpriteSheets, Fontes e Sons)
	recursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!teclado.soltou[TECLA_ESC] && !aplicacao.sair)
	{
		uniIniciarFrame();

		//	3)	animar o personagem
		per.animar();

		//	4)	mover o personagem
		if(teclado.segurando[TECLA_DIR])
			per.moverDir();
		else if(teclado.segurando[TECLA_ESQ])
			per.moverEsq();
		else if(teclado.segurando[TECLA_CIMA])
			per.moverCima();
		else if(teclado.segurando[TECLA_BAIXO])
			per.moverBaixo();
		else 
			per.ficarParado();

		//	5)	desenhar o personagem
		per.desenhar();


		uniTerminarFrame();
	}
}