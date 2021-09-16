#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstring>

///prototipos
void cargarMateria();

void mostrarMaterias();

bool grabarEnDisco(Materia);

bool borrarMateria();

int buscarMateria(int nroMateria);

int subMenu();

int buscarNombre(char nombre);

bool modificarNombre();

bool modificarCantidadAlumnos();


///desarrollo de las funciones globales

int buscarMateria(int nroMateria){
    Materia reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getNroMateria()==nroMateria){
            return pos;
        }
        pos++;
    }
    return -1;
}

void cargarMateria(){
    Materia reg;
    reg.Cargar();
    if(reg.grabarEnDisco()==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
}

void mostrarMaterias(){
    Materia obj;
    int i=0;
    while(obj.leerDeDisco(i++)){
        if(obj.getCantidadAlumnos()>100){
            obj.Mostrar();
            cout<<endl;
        }
    }
    /*FILE *pMateria;
    Materia obj;
    int i;
    pMateria=fopen("materias.dat", "rb");

    if(pMateria==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj,sizeof obj,1, pMateria)==1){
       obj.Mostrar();
       cout<<endl;
    }
    /*i=fread(obj,sizeof(Materia),8, pMateria);

    cout<<"VALOR DEVUELTO: "<<i<<endl;
    fclose(pMateria);

    for(i=0;i<5;i++){
        obj[i].Mostrar();
        cout<<endl;
    }*/
}

bool grabarEnDisco(Materia obj){
    FILE *pMateria;

    pMateria=fopen("materias.dat", "ab");

    if(pMateria==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fwrite(&obj,sizeof(Materia),1, pMateria);
    fclose(pMateria);
    return true;
}

bool borrarMateria(){
    int nroMateria, pos;
    Materia reg;
    cout<<"INGRESAR NUMERO DE MATERIA A ELIMINAR: ";
    cin>>nroMateria;
    pos=buscarMateria(nroMateria);
    if(pos==-1){
        cout<<"NO EXISTE UNA MATERIA CON ESE NUMERO"<<endl;
        system("pause");
        return false;
    }
    reg.leerDeDisco(pos);

    reg.setActivo(false);
    if(reg.modificarEnDisco(pos)==true){
        return true;
    }
    else{
        return false;
    }
}

int buscarNombre(char *nombreMateria){
    Materia reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(strcmp(reg.getNombreMateria(),nombreMateria)==0){
            return pos;
        }
        pos++;
    }
    return -1;

}

bool modificarNombre(){
    int  pos;
    char nombreMateria[40];
    Materia reg;
    cout<<"INGRESAR EL NOMBRE DE MATERIA A MODIFICAR: ";
    cin.ignore();
    cin.getline(nombreMateria,40);
    pos=buscarNombre(nombreMateria);
    if(pos==-1){
        cout<<"NO EXISTE UNA MATERIA CON ESE NOMBRE"<<endl;
        system("pause");
        return false;
    }
    reg.leerDeDisco(pos);
    cout<<"INGRESAR EL NUEVO NOMBRE: ";
    cin.getline(nombreMateria,40);
    reg.setNombreMateria(nombreMateria);
    if(reg.modificarEnDisco(pos)==true){
        return true;
    }
    else{
        return false;
    }
}

 bool modificarCantidadAlumnos(){
    int nroMateria,alumno, pos;
    Materia reg;
    cout<<"INGRESAR NUMERO DE MATERIA DONDE DESEA CAMBIAR LA CANTIDAD DE ALUMNOS: ";
    cin>>nroMateria;
    pos=buscarMateria(nroMateria);
    if(pos==-1){
        cout<<"NO EXISTE UNA MATERIA CON ESE NUMERO"<<endl;
        system("pause");
        return false;
    }
    reg.leerDeDisco(pos);
    cout<<"INGRESAR LA NUEVA CANTIDAD DE ALUMNOS: ";
    cin>>alumno;
    reg.setCantidadAlumnos(alumno);

    if(reg.modificarEnDisco(pos)==true){
        return true;
    }
    else{
        return false;
    }
}



int subMenu(){
       int opc;
    while(true){
        system("cls");
        cout << "1. MODIFICAR EL NOMBRE DE MATERIA" << endl;
        cout << "2. MODIFICAR LA CANTIDAD DE ALUMNOS" << endl;
        cout << "3. MODIFICAR CANTIDAD DE DOCENTES)" << endl;
        cout << "4. BUSCAR POR NUMERO DE MATERIA" << endl;
        cout << "5. BUSCAR POR NOMBRE DE MATERIA" << endl;
        cout << "0. REGRESAR AL MENU ANTERIOR" << endl;
        cout << "----------------" << endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: modificarNombre();
                    break;
            case 2: modificarCantidadAlumnos();
                    break;
            case 3:
                    break;
            case 4: subMenu();
                    break;
            case 5:subMenu();
                    break;
            case 0: return 0;
                    break;
            default:cout<<"OPCION INCORRECTA. INGRESE NUEVAMENTE"<<endl;
                  break;

        }
        system("pause");
    }


}


#endif // FUNCIONES_H_INCLUDED
