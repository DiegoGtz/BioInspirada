//Practica 04 Bioinspirada CS-UNSA
// DiegoGTZ - Brayan 


//Encontrar la función matemática que se ajuste al conjunto de 10 ejemplos:

// Entrada - Salida  
// 0 -  0
// 0.1 - 0.005
// 0.2 - 0.02
// 0.3 - 0.045 
// 0.4 - 0.08
// 0.5 - 0.125
// 0.6 - 0.18
// 0.7 - 0.245 
// 0.8 - 0.32 
// 0.9 - 0.405
// Variable :  X 
// Terminales : -5 .... + 5 
// Conjunto de funciones  : +, - , *, %, /. 
// Error cuadratico medio 
// utiliza reproduccion  y mutacion 

// Librerias
#include <iostream>
#include <cmath>
#include <vector> 
#include <string>

using namespace std; 
// Def. Variables  

typedef vector<string> Variables;  // x,y,z,
typedef vector<double> Constantes; // 1,2,3,4 .. 
typedef vector<string> Funciones; // +,-,*,/.
typedef vector<double> datos;  // datos de entrada y salida 
typedef tuple<vector<double>,double> Aptitud; // <Entrada, Salida> 


// variables programacion Genetica 


#define FUN 0 // Funcion + - ... 
#define VAR 1 // Variable 
#define CONS 3  // constante 

class Arbol_PG
{   
public:
    class Nodo
    {
    public:

        Nodo(){}
        Nodo(int estado, double constante){
            this->estado = estado; 
            this->constante = constante;
            hijos[0] = hijos[1] = NULL;
        }
        Nodo(int estado, string varIaBleoRfuncion ){
            this->estado            = estado; 
            this->varIaBleoRfuncion = varIaBleoRfuncion;
            hijos[0] = hijos[1] = NULL;
        }
        void DeleteNodo(){
			if(hijos[0] != nullptr) hijos[0]->DeleteNodo();
			if(hijos[1] != nullptr) hijos[1]->DeleteNodo();
		    delete hijos[0];
			delete hijos[1];           
        }
    public:
  		Nodo * hijos[2];
		int estado;
		double constante;
		string varIaBleoRfuncion;  

    };
//Funciones
public:
    Arbol_PG(){} // no inicia nada
    Arbol_PG(Variables var , Constantes cons, Funciones fun);
    Arbol_PG(Arbol_PG* tree);

    Aptitud fitness(datos entradas, datos salida);

    void DeleteTree(){
        root->DeleteNodo();
        delete root;
    }
    void print(){
        cout<<"|" << root->varIaBleoRfuncion<<"|";
        for ( int  i = 0; i < 2 ; i++)
        {
            cout<<"|"<<root->hijos[i]->varIaBleoRfuncion<<"|";
            for (int j = 0; j < 2; j++)
            {
                if(root->hijos[i]->hijos[j]->estado == VAR)
                {cout<<"|x|";}
                else cout<<root->hijos[i]->hijos[j]->constante<<"|"; 
            }
            cout<<"|";
        }
        cout<<error<<endl;
        
    }
// variables 
public: 
    Nodo * root;
    Variables varables; 
    Constantes constantes;
    Funciones funciones;
    double error;
};





class ProgramacionGenetica
{
private:
    // Variables
	int nroiNdividuos;
	int nroiteraciones;
	float probAreproducCion;
	float probAcruzamieNto;
	int puntoCruz;
	float probAmutacion;

    // Funciones 

    void Poblacion_Inicial(Variables var, Constantes cons, Funciones fun );

public:
    ProgramacionGenetica(int numIndiv, int numIter,float probRepro, float probCruza, float probMuta);
};

ProgramacionGenetica::ProgramacionGenetica(int numIndiv, int numIter,float probRepro, float probCruza, float probMuta)
{
    this->nroiNdividuos     = numIndiv;
    this->nroiteraciones    = numIter;
    this->probAreproducCion = probRepro;
    this->probAcruzamieNto  = probCruza;
    this->probAmutacion     = probMuta;

}

void ProgramacionGenetica::Poblacion_Inicial(Variables var, Constantes cons, Funciones fun )
{
    cout<< "\t Generando Poblacion Inicial "<< endl ; 

}




int main()
{   
    Variables variable = {"x"};
    Funciones funciones = {"+","-","*","/"}; 
    Constantes constantes  = {-5,-4,-3,-2,-1,0,1,2,3,4,5};

    datos input  = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};// datos de entrada
    datos output = {0, 0.005, 0.02, 0.045, 0.08, 0.125, 0.18, 0.245, 0.32, 0.405}; // datos de salida esperados 

    float Prob_Reproduccion = 0.2;  //  20%
    float Prob_Cruzamiento = 0.8;  //   80% 
    float Prob_Mutacion = 0.2;     //   20 % 

    int Num_individuos  = 8;       // numero de individuos 
    int Num_Iteraciones = 100 ;     // numero de Iteraciones



    
    cout<< "Practica de Programacion Geneica"  ; 



    return 0;
}


