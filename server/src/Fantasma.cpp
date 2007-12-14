///////////////////////////////////////////////////////////
//  Fantasma.cpp
//  Implementation of the Class Fantasma
//  Created on:      21-Nov-2007 23:40:19
///////////////////////////////////////////////////////////

#include "Fantasma.h"


Fantasma::Fantasma(){
	this->visible=true;
}

Fantasma::Fantasma(Posicion& posicion):Personaje(posicion){
	this->visible=true;
}

Fantasma::~Fantasma(){

}

/**
 * Identificador del rol de personaje
 */
int Fantasma::GetRol()const{

	return Fantasma::FANTASMA_TYPE;
}

/**
 * Velocidad del personaje
 */
int Fantasma::GetVelocidad(){

	return velocidadInicial;
}


/**
 * Determina si el fantasma esta en estado invisible que ocurre cuando un pacman
 * en estado powerUp como el fantasma. Cuando el mismo se encuentra invisible no
 * puede volver entrar en juego hasta que no haya pasado por la casa.
 */
bool Fantasma::IsVisible(){

	return visible;
}


/**
 * Determina si el fantasma esta en estado invisible que ocurre cuando un pacman
 * en estado powerUp como el fantasma. Cuando el mismo se encuentra invisible no
 * puede volver entrar en juego hasta que no haya pasado por la casa.
 */
void Fantasma::SetVisible(bool visible){

	visible = visible;
}

bool Fantasma::operator==( int tipo )const
{
	return tipo == FANTASMA_TYPE;
}

/**
 * El radio da una idea del volumen del personaje, y usa para detectar colisiones.
 */
int Fantasma::getRadio()const
{
	return Fantasma::radio;
}
