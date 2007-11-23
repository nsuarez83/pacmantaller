///////////////////////////////////////////////////////////
//  ConnectionManager.h
//  Implementation of the Class ConnectionManager
//  Created on:      21-Nov-2007 23:40:18
///////////////////////////////////////////////////////////

#if !defined(EA_9FD9E414_BBDB_43e0_8CD7_CFB519785B5B__INCLUDED_)
#define EA_9FD9E414_BBDB_43e0_8CD7_CFB519785B5B__INCLUDED_

#include "Pool.h"
#include "Jugador.h"

class ConnectionManager
{

public:
	static ConnectionManager* getInstance();
	Pool* pool;
	int maxJugadores;
	
	void agregarJugador(Jugador jugador);
	void enviarMensajes();
	Pool GetJugadores();
	void quitarJugador();
	void SetJugadores(Pool newVal);

private:
	Pool jugadores;
    static ConnectionManager* pConnectionManager;

protected:
	ConnectionManager(int maxJugadores=10);
    ConnectionManager(const ConnectionManager&);
    ConnectionManager& operator= (const ConnectionManager&);

};
#endif // !defined(EA_9FD9E414_BBDB_43e0_8CD7_CFB519785B5B__INCLUDED_)
