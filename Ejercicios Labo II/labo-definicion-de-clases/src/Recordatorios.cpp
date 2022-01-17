// Franco Flores 302/20

#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    // Para ejercicio 9
    bool operator==(Fecha o);
    //Para ejercicio 10
    void incrementar_dia();

  private:
    //Completar miembros internos
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {}

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

//Ejercicio 9

bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}

void Fecha::incrementar_dia() {
    if ( dia_ < dias_en_mes(mes_) ){
        dia_++;
    }else{
        dia_= 1;
        mes_++;
    }
}

// Ejercicio 11, 12

// Clase Horario
class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();

    bool operator==(Horario o);
    bool operator<(Horario o);

private:
    int hora_;
    int min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min){}

uint Horario::hora() {
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool igual_min = this->min() == o.min();
    return igual_hora && igual_min;
}


ostream& operator<<(ostream& os, Horario h) {
    os << h.hora()<< ":"<< h.min() ;
    return os;
}

bool Horario::operator<(Horario o) {
    bool menor_hora = this->hora() < o.hora();
    bool igual_hora = this->hora() == o.hora();
    bool menor_min = this->min() < o.min();

    if (menor_hora){
        return true;
    }else{
        if (igual_hora){
            return menor_min;
        }else{
            return false;
        }
    }
}

// Ejercicio 13

// Clase Recordatorio
class Recordatorio{
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    Fecha fecha();
    Horario horario();
    string mensaje();

private:
    Fecha fecha_;
    Horario horario_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje) : fecha_(fecha), horario_(horario), mensaje_(mensaje){}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return horario_;
}

string Recordatorio::mensaje() {
    return mensaje_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje()<< " @ "<< r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

// Clase Agenda
class Agenda{
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio r);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha hoy_;
    list<Recordatorio> lista_;
    list<Recordatorio> otro_dia_;

};

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio r) {
    if (r.fecha() == hoy_) {
        if (r.horario() < lista_.front().horario() || lista_.size() == 0){
            lista_.push_front(r);
        }else{
            Recordatorio aux = lista_.front();
            lista_.pop_front();
            agregar_recordatorio(r);
            lista_.push_front(aux);
        }
    }else{
        otro_dia_.push_back(r);
    }
}

void Agenda::incrementar_dia() {
    list<Recordatorio> aux = otro_dia_;
    lista_.clear();
    otro_dia_.clear();
    hoy_.incrementar_dia();
    for (Recordatorio r : aux) {
        agregar_recordatorio(r);
    }
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    return lista_;
}

Fecha Agenda::hoy() {
    return hoy_;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << "\n";
    os << "=====" << "\n";
    for(Recordatorio r : a.recordatorios_de_hoy()){
        os << r << "\n";
    }
    return os;
}