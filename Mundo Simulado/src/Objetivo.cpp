#include "Objetivo.h"

#include <utility>

Objetivo::Objetivo() = default;

Objetivo::Objetivo(Color objeto, Color receptaculo) : _objeto(objeto), _receptaculo(receptaculo){}

const Color &Objetivo::objeto() const {
    return _objeto;
}

const Color &Objetivo::receptaculo() const {
    return _receptaculo;
}

bool Objetivo::operator==(const Objetivo& o) const {
    return o.receptaculo() == _receptaculo && o.objeto() == _objeto;
}

bool Objetivo::operator<(const Objetivo &o) const {
    return true;
}
