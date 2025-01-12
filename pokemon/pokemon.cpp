#include <iostream>
using namespace std;

class Pokemon {
protected: // Accessible dins de la classe i les seves derivades
    int hp;
    int atk;
    int def;
    string nombre;
    const int debilidad = 20; // Aquest valor és constant

public:
    // Constructor per defecte
    Pokemon() : hp(0), atk(0), def(0), nombre("") {}

    // Constructor amb paràmetres
   // Els primers paràmetres són els que es reben de fora i després s’especifica on va cada paràmetre
    Pokemon(int _hp, int _atk, int _def, const string& _nombre)
        : hp(_hp), atk(_atk), def(_def), nombre(_nombre) {}

    // Mètodes per establir i obtenir valors
    void setHp(int hp) { this->hp = hp; }
    int getHp() const { return hp; }

    void setAtk(int atk) { this->atk = atk; }
    int getAtk() const { return atk; }

    void setDef(int def) { this->def = def; }
    int getDef() const { return def; }

    void setNombre(const string& nombre) { this->nombre = nombre; }
    string getNombre() const { return nombre; }

    int getDebilidad() const { return debilidad; }

    // Mètode per mostrar informació del Pokémon
    // La paraula const declara que es tracta d’un valor que no es pot modificar
    // virtual ens indica que mostrarà dades d’una classe de la qual deriva aquesta
    virtual void mostrarInfo() const {
        cout << "Nom: " << nombre << "\n"
            << "HP: " << hp << "\n"
            << "Atac: " << atk << "\n"
            << "Defensa: " << def << endl;
    }
};

class CartaTipoFuego : public Pokemon {
private:
    const string tipo = "Foc";
    const string debilidadTipo = "Aigua"; // Dèbil contra tipus Aigua
    string habilidad;

public:
    CartaTipoFuego(int _hp, int atk, int def, const string& nombre, const string& habilidad)
        : Pokemon(_hp, atk, def, nombre), habilidad(habilidad) {}

    void mostrarInfo() const override {
        // El mètode mostrarInfo és "overridden" per proporcionar una implementació específica
        // per a la classe derivada CartaTipoFuego. Això sobrescriu el comportament de la classe base
        // i permet mostrar informació addicional relacionada amb la classe derivada.
        cout << "[Carta de Tipus " << tipo << "]" << endl;
        Pokemon::mostrarInfo();
        cout << "Tipus: " << tipo << "\n";
        cout << "Debil contra: " << debilidadTipo << " (+" << getDebilidad() << " dany extra)\n";
        cout << "Habilitat: " << habilidad << "\n";
    }
};

class CartaTipoAgua : public Pokemon {
private:
    const string tipo = "Aigua";
    const string debilidadTipo = "Electric"; // Dèbil contra tipus Elèctric
    string habilidad;

public:
    CartaTipoAgua(int hp, int atk, int def, const string& nombre, const string& habilidad)
        : Pokemon(hp, atk, def, nombre), habilidad(habilidad) {}

    void mostrarInfo() const override {
        // El mètode mostrarInfo és "overridden" per proporcionar una implementació específica
        // per a la classe derivada CartaTipoAgua. Això sobrescriu el comportament de la classe base
        // i permet mostrar informació addicional relacionada amb la classe derivada.
        cout << "[Carta de Tipus " << tipo << "]" << endl;
        Pokemon::mostrarInfo();
        cout << "Tipus: " << tipo << "\n";
        cout << "Debil contra: " << debilidadTipo << " (+" << getDebilidad() << " dany extra)\n";
        cout << "Habilitat: " << habilidad << "\n";
    }
};

class CartaTipoPlanta : public Pokemon {
private:
    const string tipo = "Planta";
    const string debilidadTipo = "Fuego"; // Dèbil contra tipus Fuego
    string habilidad;


public:
    CartaTipoPlanta(int hp, int atk, int def, const string& nombre, const string& habilidad)
        : Pokemon(hp, atk, def, nombre), habilidad(habilidad) {}


    void mostrarInfo() const override {
        cout << "[Carta de Tipo " << tipo << "]" << endl;
        Pokemon::mostrarInfo();
        cout << "Tipo: " << tipo << "\n";
        cout << "Debil contra: " << debilidadTipo << " (+" << getDebilidad() << " dany extra)\n";
        cout << "Habilitat: " << habilidad << "\n";
    }
};

class CartaTipoElectric : public Pokemon {
private:
    const string tipo = "Electric";
    const string debilidadTipo = "Pedra"; // Dèbil contra tipus Pedra
    string habilidad;


public:
    CartaTipoElectric(int hp, int atk, int def, const string& nombre, const string& habilidad)
        : Pokemon(hp, atk, def, nombre), habilidad(habilidad) {}


    void mostrarInfo() const override {
        cout << "[Carta de Tipo " << tipo << "]" << endl;
        Pokemon::mostrarInfo();
        cout << "Tipo: " << tipo << "\n";
        cout << "Debil contra: " << debilidadTipo << " (+" << getDebilidad() << " dany extra)\n";
        cout << "Habilitat: " << habilidad << "\n";
    }
};

class CartaTipoPedra : public Pokemon {
private:
    const string tipo = "Pedra";
    const string debilidadTipo = "Aigua";  // Debilidad contra Agua, por ejemplo
    string habilidad;

public:
    CartaTipoPedra(int hp, int atk, int def, const string& nombre, const string& habilidad)
        : Pokemon(hp, atk, def, nombre), habilidad(habilidad) {}

    void mostrarInfo() const override {
        cout << "[Carta de Tipus " << tipo << "]" << endl;
        Pokemon::mostrarInfo();
        cout << "Tipus: " << tipo << "\n";
        cout << "Debil contra: " << debilidadTipo << " (+" << getDebilidad() << " dany extra)\n";
        cout << "Habilitat: " << habilidad << "\n";
    }
};

// Definició de la Linked List
class Baraja {
private:
    struct Node {
        Pokemon* carta;
        Node* next;
    };

    Node* head;

public:
    Baraja() : head(nullptr) {}

    // Mètode per afegir una carta a la baralla
    void afegirCarta(Pokemon* carta) {
        Node* newNode = new Node;
        newNode->carta = carta;
        newNode->next = head;
        head = newNode;
    }

    // Mètode per mostrar tota la baralla
    void mostrarBaraja() const {
        Node* current = head;
        while (current != nullptr) {
            current->carta->mostrarInfo();
            cout << "--------------------" << endl;
            current = current->next;
        }
    }

    // Destructor per netejar la memòria
    ~Baraja() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp->carta; // Elimina el Pokémon
            delete temp; // Elimina el node
        }
    }
};

int main() {
    // Crear algunes cartes de Pokémon
    CartaTipoFuego* cartaFuego = new CartaTipoFuego(100, 50, 30, "Charizard", "Llamarada");
    CartaTipoAgua* cartaAgua = new CartaTipoAgua(90, 40, 40, "Blastoise", "Hidrobomba");
    CartaTipoPlanta* cartaPlanta = new CartaTipoPlanta(110, 30, 50, "Venusaur", "Energibola");
    CartaTipoElectric* cartaElectric = new CartaTipoElectric(70, 60, 20, "Pikachu", "Bola Voltio");
    CartaTipoPedra* cartaPiedra = new CartaTipoPedra(140, 50, 70, "Onix", "Roca Afilada");

    // Crear la baralla i afegir les cartes
    Baraja baraja;
    baraja.afegirCarta(cartaFuego);
    baraja.afegirCarta(cartaAgua);
    baraja.afegirCarta(cartaPlanta);
    baraja.afegirCarta(cartaElectric);
    baraja.afegirCarta(cartaPiedra);

    // Mostrar la baralla
    baraja.mostrarBaraja();

    // La memòria es neteja automàticament al final del programa
    return 0;
}
