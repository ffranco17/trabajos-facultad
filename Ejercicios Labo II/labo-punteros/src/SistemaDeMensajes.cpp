#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    /*ConexionJugador c = ConexionJugador(ip);
    ConexionJugador* p = &c; //esto esta mal ya que al salir de la funcion, se pierde este dato
    _conns[id] = p; //hay que usar New, new arma una casa, el puntero me da la direccion de esa casa
     */

    if (registrado(id)) {
        delete _conns[id];
        _conns[id] = new ConexionJugador(ip);
    } else {
        _conns[id] = new ConexionJugador(ip);
    }
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    if(registrado(id)) {
        _conns[id]->enviarMensaje(mensaje);
    }
}

string SistemaDeMensajes::ipJugador(int id) const {
    if (registrado(id)) {
        _conns[id]->ip();
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (registrado(id)){
        delete _conns[id];
        _conns[id] = nullptr;
    }
}

SistemaDeMensajes:: ~SistemaDeMensajes() {
    for (ConexionJugador* c : _conns) {
        delete c;
    }
/*
    for (Proxy* p: _proxys) {
        delete p;
    }*/


}

Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    _proxys[id] = new Proxy(_conns[id]);
    return _proxys[id];
}