///////////////////////////////////////////////////////////
//  Fantasma.cpp
//  Implementation of the Class Fantasma
//  Created on:      21-Nov-2007 23:40:19
///////////////////////////////////////////////////////////

#include "Fantasma.h"


Fantasma::Fantasma(){

}



Fantasma::~Fantasma(){

}





/**
 * Velocidad del personaje
 */
int Fantasma::GetVelocidad(){

	return velocidad;
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
