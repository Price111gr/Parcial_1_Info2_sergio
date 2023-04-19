#include <iostream>
#include <fstream>
#include <istream>

void imprimirmate(char ***Materias, int Num);
void liberador(char ***Materias, int Num);
bool comparechars(char*** s1, char s2, int Num);


using namespace std;

int main(void)
{
    /////////Declaracion e inicializacion de Variables///////

    ofstream Archivo;//Variable para escribir el txt.
    char ***Materias=nullptr; // Arreglo dinamico con ptr
    int Num=0;//Numero de materias;
    char documento[11];//Numero de documento

    int dia = 0, hora = 0;
    char eleccion = ' ';
    char ***horario = nullptr;




    ///////////////Recepcion de datos por teclado////////////

    cout<<"ingrese su numero de documento: ";
    cin>>documento;

    cout<<"ingrese el numero de materias: ";
    cin>>Num;
    //////////////// Matriz dinamica de Datos///////////////

    Materias = new char**[Num];
    char Materia[8], Materia_aux[1];

    for(int i=0; i<Num; i++){
        Materias[i]=new char*[6];

        Materias[i][0] = new char[8];
        cout<<"Ingrese el codigo de la materia ["<<i+1<<"] : ";
        cin>>Materia;

        //if(comparechars(Materias, Materia, Num)==true){

        //}

        //while(){
        //        for(int j = 0; j<=Num; j++){
        //            Materia_aux[1]= *Materias[i][0];
        //            if(Materias[i][0]!=Materia){
        //                cout<<"esta ya"<<endl;
        //            }
        //            else{
        //                cout<<"no esta"<<endl;
        //            }
        //        }
        //}



        Materias[i][0]=Materia;

        cout<<endl;
        Materias[i][1] = new char[25];
        cout<<"Ingrese el nombre de la materia : ";
        cin>>Materias[i][1];
        cout<<endl;
        Materias[i][2] = new char[3];
        cout<<"Ingrese Horas de clase teorica : ";
        cin>>Materias[i][2];
        cout<<endl;
        Materias[i][3] = new char[3];
        cout<<"Ingrese Horas de clase practica: ";
        cin>>Materias[i][3];
        cout<<endl;
        Materias[i][4] = new char[3];
        cout<<"Ingrese el numero de creditos de la materia: ";
        cin>>Materias[i][4];
        cout<<endl;
    }

    ////////////////////Imprimir Datos///////////////////////

    imprimirmate(Materias, Num);
    liberador(Materias, Num);

}












bool Comparar(char** Materias, char cad[], int c){
    for(int i = 1; i < c-1; i++){
        if(Materias[i][0]==Materias[i+1][0] || Materias[i][0]==Materias[i-1][0]){
            return true;
        }
    }
    return false;
}

void imprimirmate(char ***Materias, int Num){
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 25; c++) {
                cout<<Materias[a][b][c];
                if (Materias[a][b][c]=='\0') break;
            }
            cout<<" | ";
        }
        cout<<endl;
    }
}

void liberador(char ***Materias, int Num){

    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            delete[] Materias[a];
        }
    }
    delete[] Materias;
    Materias=nullptr;
}

bool comparechars(char*** s1, char s2, int Num) {
    for (int i = 0; i < Num; i++) {

        if (*s1[i][0] == s2) {
            return true;
        }

    }
    return false;
}







