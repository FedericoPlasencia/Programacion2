#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;



class Materia{
    private:///propiedades van en la parte privada de la clase
        ///Encapsulamiento
        int nroMateria;
        char nombreMateria[40];
        int cantAlumnos;
        int cantDocentes;
        bool activo;
    public:///desarrollo de los métodos. Funciones de la clase
        Materia(int nM=0, const char *nombre="nada", int ca=0, int cd=0){
            nroMateria=nM;
            strcpy(nombreMateria,nombre);
            cantAlumnos=ca;
            cantDocentes=cd;
        }
        ~Materia(){
      //      cout<<"SE MURIO EL OBJETO. VIVA EL OBJETO!!!"<<endl;
        }
        void Cargar(){
            int nro;
            cout<<"NUMERO DE MATERIA: ";
            cin>>nro;
            setNroMateria(nro);
            cout<<"NOMBRE DE MATERIA: ";
            cin.ignore();
            cin.getline(nombreMateria,35);
            cout<<"CANTIDAD DE ALUMNOS: ";
            cin>>this->cantAlumnos;
            cout<<"CANTIDAD DE DOCENTES: ";
            cin>>cantDocentes;
            activo=true;
        }
        void Mostrar();
        ///sets() para asignar valor a cada propiedad
        void setNroMateria(int nm){if(nm>=0)nroMateria=nm;}
        void setNombreMateria(const char *nm){strcpy(nombreMateria,nm);}
        void setCantidadAlumnos(int cantAlu) {cantAlumnos=cantAlu;}

        void setActivo(bool valor){activo=valor;}

        ///gets() para que desde fuera de la clase se conozca el valor de cada propiedad.
        int getNroMateria(){return nroMateria;}
        char *getNombreMateria(){return nombreMateria;}

        int getCantidadAlumnos(){return cantAlumnos;}
        int getCantidadDocentes(){return cantDocentes;}

        bool grabarEnDisco(){
            FILE *pMateria;
            pMateria=fopen("materias.dat", "ab");
            if(pMateria==NULL){
                cout<<"ERROR DE ARCHIVO"<<endl;
                return false;
            }
            bool escribio=fwrite(this,sizeof(Materia),1, pMateria);
            fclose(pMateria);
            return escribio;
        }
        bool leerDeDisco(int pos){
            FILE *pMateria;
            pMateria=fopen("materias.dat", "rb");
            if(pMateria==NULL){
                cout<<"ERROR DE ARCHIVO"<<endl;
                return false;
            }
            fseek(pMateria,sizeof(Materia)*pos,0);
            bool leyo=fread(this,sizeof(Materia),1, pMateria);
            fclose(pMateria);
            return leyo;
        }
        bool modificarEnDisco(int pos){
            FILE *pMateria;
            pMateria=fopen("materias.dat", "rb+");///le agrega al modo lo que le falta
            if(pMateria==NULL){
                cout<<"ERROR DE ARCHIVO"<<endl;
                return false;
            }
            fseek(pMateria,sizeof(Materia)*pos,0);
            bool escribio=fwrite(this,sizeof(Materia),1, pMateria);
            fclose(pMateria);
            return escribio;

        }

};



#include "funciones.h"

void Materia::Mostrar(){
       // if(activo==true){
            cout<<"NUMERO DE MATERIA: ";
            cout<<this->nroMateria<<endl;
            cout<<"NOMBRE DE MATERIA: ";
            cout<<nombreMateria<<endl;
            cout<<"CANTIDAD DE ALUMNOS: ";
            cout<<cantAlumnos<<endl;
            cout<<"CANTIDAD DE DOCENTES: ";
            cout<<cantDocentes<<endl<<endl;
    //    }
}




int main(){
    int opc;
    while(true){
        system("cls");
        cout << "1. CARGAR DATOS MATERIAS" << endl;
        cout << "2. MOSTRAR DATOS MATERIAS" << endl;
        cout << "3. ELIMINAR MATERIA (BAJA LOGICA)" << endl;
        cout << "4. OTRAS FUNCIONES" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "----------------" << endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarMateria();
                    break;
            case 2: mostrarMaterias();
                    break;
            case 3: borrarMateria();
                    break;
            case 4: subMenu();
                    break;
            case 0: return 0;
                    break;
            default:cout<<"OPCION INCORRECTA. INGRESE NUEVAMENTE"<<endl;
                  break;

        }
        system("pause");
    }
    return 0;
}
