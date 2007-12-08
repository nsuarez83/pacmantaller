///////////////////////////////////////////////////////////
//  Modelo.h
//  Implementation of the Class Modelo
//  Created on:      21-Nov-2007 23:40:20
///////////////////////////////////////////////////////////

#if !defined(EA_C452893E_00CB_470e_BB7D_F33E91B1347A__INCLUDED_)
#define EA_C452893E_00CB_470e_BB7D_F33E91B1347A__INCLUDED_

#include <list>
#include <queue>
#include <string>
#include "Elemento.h"
#include "Operacion.h"
#include "Jugador.h"
#include "AppSettings.h"
#include "Mapa.h"
#include "Mundo.h"
#include "Config.h"
#include "StartJugador.h"
#include "XmlParser.h"
#include "CasaFantasmas.h"
#include "Bonus.h"
#include "SalidaPacMan.h"

using std::string;

class Operacion;

typedef std::list<Elemento*> tListElementos; 
typedef std::queue<Operacion*> tQueueOperacion;
typedef std::list<Jugador*> tListJugadores;
typedef std::list<Jugador*>::iterator itListJugadores;
typedef std::list<Elemento*>::iterator itListElementos;
typedef bool* pBool;

/**
 * Clase que se controla el ciclo de vida del juego, aplicando diferentes
 * operaciones.
 */
class Modelo: public Thread
{

public:
	static Modelo* getInstance();
	static void setInstance(pBool finalizoJuego,pBool cerroServidor);
	virtual ~Modelo();

	void agregarOperacion(Operacion* operacion);
	tListElementos* GetElementos();
	Mapa* GetMapa();
	Mundo* GetMundo();
	tListJugadores& GetJugadores();
	int GetPuntuacion()const;
	void main();
	void notify();
	void SetElementos(tListElementos& elementos);
	void SetMapa(Mapa* mapa);
	void SetMundo(Mundo* mundo);
	void SetJugadores(tListJugadores& jugadores);
	void SetPuntuacion( int puntuacion );
	void seFinalizoElJuego(bool finalizo){*finalizoJuego=finalizo;};
	bool seFinalizoElJuego(){return *finalizoJuego;};
	void liberarStartJugadores();
	void liberarNivel();
	void SetSalidaPacMan(SalidaPacMan& salidaPacMan);
	void SetCasaFantasmas(CasaFantasmas& casaFantasmas);
	SalidaPacMan* getSalidaPacMan(){return &salidaPacMan;} 
	CasaFantasmas* getCasaFantasmas(){return &casa;}
	
	/**
	 * Determina se termino el nivel o no
	 */
	bool seFinalizoElNivel(){return finalizoNivel;};
	/**
	 * Setea el comiezo o el fin del nivel.
	 */
	void seFinalizoElNivel(bool finalizo){finalizoNivel=finalizo;};
	
	Operacion* getOperacion();
	Operacion* desacolar();
	void esperarRecibirOperaciones();
	
	/* Eventos */
	Evento& getRecibiOperacionEvent(){return this->recibiOperacionEvent;};
	Evento& getEsperarMinJugadoresEvent(){return this->esperarMinJugadoresEvent;};
protected:
	Modelo();
	Modelo(pBool finalizoJuego,pBool cerroServidor);
	Modelo(const Modelo&);
	Modelo& operator= (const Modelo&);
	
private:
	static Modelo* pModelo;
	/**
	 * Salida del pacman.
	 */
	SalidaPacMan salidaPacMan;
	/**
	 * Casa de los fantasmas posicion
	 */
	CasaFantasmas casa;
	/**
	 * Evento que determina si hay que empezar el juego.
	 */
	Evento esperarMinJugadoresEvent;
	/**
	 * Evento que determina si recibio una operacion
	 */
	Evento recibiOperacionEvent;
	/**
	 * Desacola una operacion de la cola y la ejecuta.
	 */
	void ejecutarOperaciones();
	/**
	 * Lista de elementos del mapa.
	 */
	tListElementos elementos;
	/**
	 * Mundo que se esta jugando actualmente.
	 */
	Mundo *mundo;
	/**
	 * Nivel que se esta jugando actualmente.
	 */
	Mapa *mapa;
	/**
	 * Lista de operacion que se ejecutan sobre el modelo
	 */
	tQueueOperacion operaciones;
	/**
	 * Lista de jugadores pueden ser PacMan o Fantasma
	 */
	tListJugadores jugadores;
	/**
	 * Indica si el nivel ha finalizado o no
	 */
	bool finalizoNivel;
	/**
	 * Indica si el juego ha finalizado o no
	 */
	pBool finalizoJuego;
	/**
	 * Indica si el servidor termino o no.
	 */
	pBool cerroServidor;
	/**
	 * Puntuacion del pacman
	 */
	int puntuacion;

};
#endif // !defined(EA_C452893E_00CB_470e_BB7D_F33E91B1347A__INCLUDED_)
