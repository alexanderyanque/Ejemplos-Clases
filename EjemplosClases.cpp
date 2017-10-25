#include <iostream>
using namespace std;

class Clase {
    protected:
      int secreto;                  //solo puede ser modificada por si misma
    private:
        int ultrasecreto;           //nadie excepto la misma clase puede accesar a este dato
    public:
      int numero;                   //a menos que la herencia este declarada como protected o private, numero es accesible por todos
      Clase(int x,int y,int z):numero(x),ultrasecreto(z),secreto(y){}
      void imprime(int x){
      cout<<x;return;}
};

class Clasedos :protected Clase{       //como esta en protected Clasedos no puede accesar a funciones como imprime.
    public:
    int numerodos;
    Clasedos(int x,int y,int a,int b):Clase(x,a,b),numerodos(y){}   //
    int getsecreto(){
    return secreto;}

};

class Clasetres :private   Clase{     //como es private, tiene acceso a nada de Clase
    public:
        int numerotres;
      Clasetres(int x,int y,int a,int b):numerotres(y),Clase(x,a,b){}   //
      int getsecreto(){
    return secreto;}
};

class Clasecuatro :public   Clase{     //como es private, tiene acceso a nada de Clase
    public:
        int numerocuatro;
      Clasecuatro(int x,int y,int a,int b):numerocuatro(y),Clase(x,a,b){}   //
      int getsecreto(){
    return secreto;}
};
//si en lugar de private o protected hubiera puesto public, clasedos y clasetres hubieran tenido acceso a todas las funciones/variables de clase

int main(){
    Clasetres a(3,4,1,5);
    Clasecuatro b(1,8,6,1);
    //a.imprime(5);    no corre por que Clasetres esta en protected y tiene 0 acceso
    cout<<a.getsecreto()<<endl;//por eso con esta funcion si se puede pedir, mas no modificar una variable de Clase
    b.imprime(5);
    return 0;
}
