#include <iostream>

/**
 * clase encargada de servir como interfaz entre objetos
*/
class IPersonalCocina {
public:
    virtual void cocinar() = 0;
};

/**
 * Clase que representa el objeto real del programa. 
 * Hereda de la interfaz IPersonalCocina.
 * Sobreescribe el método cocinar() de la interfaz.
*/
class Chef : public IPersonalCocina {
    void cocinar() override {
        std::cout << "Se ha cocinado" << std::endl;
    }
};

/**
 * Clase que representa el objeto proxy. 
 * Hereda de la interfaz IPersonalCocina.
 * Sobreescribe el método cocinar() de la interfaz.
*/
class ProxyChef : public IPersonalCocina {
private:
    // referencia hacia el objeto real
    IPersonalCocina* chefReal;
    int _aniosDeExperiencia;

public:
    // contructor del proxy
    ProxyChef(int experiencia) : chefReal(new Chef()), _aniosDeExperiencia(experiencia) {}
    // destructor del proxy. MUY NECESARIO PARA ELIMINAR EL OBJETO REAL Y NO DEJARLO FLOTANDO EN MEMORIA DE FORMA OBSOLETA.
    ~ProxyChef() {
        delete chefReal;
    }

    // dependiendo de los años de experiencia, el proxy llama al objeto real o no
    void cocinar() {
        if(_aniosDeExperiencia > 10) {
            chefReal->cocinar();
        }
        else {
            std::cout << "Este chef no tiene suficiente experiencia para cocinar acá" << std::endl;
        }
    }
};

int main() {
    // crear proxy y decirle que ejecute una accion
    IPersonalCocina* chef = new ProxyChef(10);
    chef->cocinar();
    delete chef;

    // crear proxy y decirle que ejecute una accion
    chef = new ProxyChef(20);
    chef->cocinar();
    delete chef;
}