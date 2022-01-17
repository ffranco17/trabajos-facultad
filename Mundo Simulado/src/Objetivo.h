#ifndef OBJETIVO_H
#define OBJETIVO_H

#include "Tipos.h"

class Objetivo {
  public:
    
    Objetivo();

    Objetivo(Color  objeto, Color  receptaculo);

    const Color& objeto() const;
    const Color& receptaculo() const;

    bool operator==(const Objetivo& o) const;
    bool operator<(const Objetivo& o)const;

  private:
    Color _objeto;
    Color _receptaculo;
};

#endif
