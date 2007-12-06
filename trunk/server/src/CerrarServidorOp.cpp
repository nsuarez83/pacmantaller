#include "CerrarServidorOp.h"

CerrarServidorOp::CerrarServidorOp()
{
}

bool CerrarServidorOp::ejecutar()
{
	std::cout<< "SE CERRO EL SERVIDOR...\n";
	//Crear mensaje stop
	
	//Enviar mensaje stop a todos los jugadores
	std::cout<<"Enviar mensaje QUIT\n";
	Quit *quit = new Quit;
	Modelo *modelo = Modelo::getInstance();
	tListJugadores jugadores =  modelo->GetJugadores();
	tListJugadores::iterator it;
	for( it=jugadores.begin(); it != jugadores.end() ; it++ )
	{
		(*it)->GetSocket()->enviar( quit->Serialize(), quit->getSize() );
	}
	//Finalizar el juego.
	modelo->seFinalizoElJuego(true);
	modelo->seFinalizoElNivel(true);
	
	return false;
}

