#include <iostream>
#include <vector>
#include <fstream>
#include <string> 

using namespace std;

// returns month number with letter month format
string mesAnum(string mes){
    if (mes == "Jan"){
        return "01";
    } else if (mes == "Feb"){
        return "02";
    } else if (mes == "Mar"){
        return "03";
    } else if (mes == "Apr"){
        return "04";
    } else if (mes == "May"){
        return "05";
    } else if (mes == "Jun"){
        return "06";
    } else if (mes == "Jul"){
        return "07";
    } else if (mes == "Aug"){
        return "08";
    } else if (mes == "Sep"){
        return "09";
    } else if (mes == "Oct"){
        return "10";
    } else if (mes == "Nov"){
        return "11";
    } else if (mes == "Dec"){
        return "12";
    }
    return "ENTRADA INVALIDA";
}

void imprimir(vector< vector<string> > bitacoraAcomodada ) {
    for( int i = 0 ; i < bitacoraAcomodada.size() -1 ; i++){
        cout << bitacoraAcomodada[i][0] << " " << bitacoraAcomodada[i][1] << " " << bitacoraAcomodada[i][2] << ":" << bitacoraAcomodada[i][3] << ":" << bitacoraAcomodada[i][4] << " " << bitacoraAcomodada[i][5] << " " << bitacoraAcomodada[i][6] <<endl;
    }
}

void imprimir(vector< vector< vector <string> > > bitacoraDiaria){
    for(int i = 0; i < bitacoraDiaria.size(); i++){
        if (bitacoraDiaria[i].size() > 1){
            cout << i << endl;
            for(int j = 0; j < bitacoraDiaria[i].size() ; j ++){
                cout << bitacoraDiaria[i][j][0] << " " << bitacoraDiaria[i][j][1] << endl;
            }
        }
    }

}
void separar(vector<string> &bitacora,vector< vector<string> > &bitacoraAcomodada ) {
  string space_delimiter = " ";
  vector<string> valores;
  size_t pos = 0;
  for(int j = 0;j<bitacora.size();j++){
    
    for (int i = 0; i < 2;i++){
        pos = bitacora[j].find(space_delimiter);
        valores.push_back(bitacora[j].substr(0, pos));
        bitacora[j].erase(0, pos + space_delimiter.length());
    }
    space_delimiter = ":";
    for (int i = 2; i < 4;i++){
        pos = bitacora[j].find(space_delimiter);
        valores.push_back(bitacora[j].substr(0, pos));
        bitacora[j].erase(0, pos + space_delimiter.length());
    }
    space_delimiter = " ";
    for (int i = 4; i < 6;i++){
        pos = bitacora[j].find(space_delimiter);
        valores.push_back(bitacora[j].substr(0, pos));
        bitacora[j].erase(0, pos + space_delimiter.length());
    }
    valores.push_back(bitacora[j]);
    if (stoi(valores[1]) < 10){
        valores[1] = "0" + valores[1];
    }
    valores.push_back(mesAnum(valores[0]) + valores[1] + valores[2] + valores[3] + valores[4]);
    bitacoraAcomodada.push_back(valores);
    valores.clear();
    //cout << bitacoraAcomodada;
  }
}

// reads file and stores in vector
void leerArchivo(string nombreArchivo,vector<string> &bitacora){
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
      bitacora.push_back(linea);
    }
}

void bubbleSort(vector< vector<string> > &bitacoraAcomodada){
  for(int i = 0; i < bitacoraAcomodada.size() - 1; i++ ){
    for (int j = 0; j < bitacoraAcomodada.size() -i -1;j++){
          if(stoi(bitacoraAcomodada[j][7])  > stoi(bitacoraAcomodada[j+1][7])){
              swap(bitacoraAcomodada[j],bitacoraAcomodada[j+1]);
          }
      }
  }
}

void sort(vector< vector< vector <string> > > &bitacoraDiaria, string fecha){
  for(int i = 0; i < bitacoraDiaria[stoi(fecha)].size() - 1; i++ ){
    for (int j = 0; j < bitacoraDiaria[stoi(fecha)].size() -i -1;j++){
          if(stoi(bitacoraDiaria[stoi(fecha)][j][1])  < stoi(bitacoraDiaria[stoi(fecha)][j+1][1])){
              swap(bitacoraDiaria[stoi(fecha)][j],bitacoraDiaria[stoi(fecha)][j+1]);
          }
      }
  }
}


void filtro(vector< vector<string> > &bitacoraAcomodada){

  string dia, mes, hora, minuto, segundo;
  string diaF, mesF, horaF, minutoF, segundoF;
  
  cout<<"Siempre usar un 0 al inicio siempre que sea un solo digito Ejemplo: 05 \n\n";

  cout<<"DESDE que fecha quiere visualzar\n";
  cout<<"Ingrese el mes: ";
  cin>>mes;
  cout<<"Ingrese el dia: ";
  cin>>dia;
  cout<<"Ingrese el hora: ";
  cin>>hora;
  cout<<"Ingrese el minuto: ";
  cin>>minuto;
  cout<<"Ingrese el segundo: ";
  cin>>segundo;
  cout<<endl;
  cout<<"HASTA que fecha quiere visualzar\n";
  cout<<"\nIngrese el mes: ";
  cin>>mesF;
  cout<<"Ingrese el dia: ";
  cin>>diaF;
  cout<<"Ingrese el hora: ";
  cin>>horaF;
  cout<<"Ingrese el minuto: ";
  cin>>minutoF;
  cout<<"Ingrese el segundo: ";
  cin>>segundoF;
  
  string inicio = mes + dia + hora + minuto + segundo;
  string fin = mesF + diaF + horaF + minutoF + segundoF;

  cout<< "INICIO Registros del " << mes << "/" << dia << " " << hora <<":" << minuto << ":" << segundo << " al " << mesF << "/" << diaF << " " << horaF <<":" << minutoF << ":" << segundoF << endl;
  for (int i = 0; i < bitacoraAcomodada.size(); i ++){
      if (stoi(bitacoraAcomodada[i][7]) > stoi(inicio) && stoi(bitacoraAcomodada[i][7]) < stoi(fin)){
          cout << bitacoraAcomodada[i][0] << " " << bitacoraAcomodada[i][1] << " " << bitacoraAcomodada[i][2] << ":" << bitacoraAcomodada[i][3] << ":" << bitacoraAcomodada[i][4] << " " << bitacoraAcomodada[i][5] << " " << bitacoraAcomodada[i][6] <<endl;
      }
  }
    cout<< "FIN Registros del " << mes << "/" << dia << " " << hora <<":" << minuto << ":" << segundo << " al " << mesF << "/" << diaF << " " << horaF <<":" << minutoF << ":" << segundoF << endl;

}

void filtro(vector< vector< vector <string> > > &bitacoraDiaria){

  string dia, mes;
  string diaF, mesF;
  
  cout<<"Siempre usar un 0 al inicio siempre que sea un solo digito Ejemplo: 05 \n\n";

  cout<<"DESDE que fecha quiere visualzar\n";
  cout<<"Ingrese el mes: ";
  cin>>mes;
  cout<<"Ingrese el dia: ";
  cin>>dia;
  cout<<endl;
  cout<<"HASTA que fecha quiere visualzar\n";
  cout<<"\nIngrese el mes: ";
  cin>>mesF;
  cout<<"Ingrese el dia: ";
  cin>>diaF;
  
  string inicio = mes + dia;
  string fin = mesF + diaF;

  cout<< "INICIO Registros del " << mes << "/" << dia << " al " << mesF << "/" << diaF << endl;
  for(int i = stoi(inicio); i < stoi(fin) +1; i++){
        if (bitacoraDiaria[i].size() > 1 ){
            string dia = to_string((i - i%100) /100) + "/" + to_string(i%100);
            cout << dia << endl;
            for(int j = 0; j < bitacoraDiaria[i].size() ; j ++){
                cout << bitacoraDiaria[i][j][0] << " Accesos:" << bitacoraDiaria[i][j][1] << endl;
            }
        }
    }
  cout<< "FIN Registros del " << mes << "/" << dia << " al " << mesF << "/" << diaF << endl;

}

void archivo(vector< vector<string> > &bitacoraAcomodada){
        ofstream file;
        file.open("bitacoraOrdenada.txt");
        
        for (int i = 0; i < bitacoraAcomodada.size(); i ++){
          file << bitacoraAcomodada[i][0] << " " << bitacoraAcomodada[i][1] << " " << bitacoraAcomodada[i][2] << ":" << bitacoraAcomodada[i][3] << ":" << bitacoraAcomodada[i][4] << " " << bitacoraAcomodada[i][5] << " " << bitacoraAcomodada[i][6] <<endl;
          
        }
        file.close();
}

void insertarIp(vector<string> valor, vector< vector< vector <string> > > &bitacoraDiaria, string fecha){
    bool anadido = false;
    for( int i = 0; i < bitacoraDiaria[stoi(fecha)].size() ; i ++ ){
        if (bitacoraDiaria[stoi(fecha)][i][0] == valor[0]){
            bitacoraDiaria[stoi(fecha)][i][1] = to_string(stoi(bitacoraDiaria[stoi(fecha)][i][1]) +1 );
            anadido = true;
            sort(bitacoraDiaria, fecha);
        } 
    }
    if (!anadido){
        bitacoraDiaria[stoi(fecha)].push_back(valor);
    }
}

vector< vector< vector <string> > >  porDia(vector< vector<string> > bitacoraAcomodada){
    vector< vector< vector <string> > > bitacoraDiaria(1231);
    vector<string> valor;
    for( int i = 0; i < bitacoraAcomodada.size(); i++){
        string fecha = mesAnum(bitacoraAcomodada[i][0]) + bitacoraAcomodada[i][1];
        valor.push_back(bitacoraAcomodada[i][5]);
        valor.push_back("1");
        insertarIp(valor,bitacoraDiaria, fecha);
        valor.clear();
    }
    return bitacoraDiaria;
}


int main(){
  vector<string> bitacoratxt;
  vector< vector<string> > bitacoraAcomodada;
  vector< vector< vector <string> > > bitacoraDiaria(1231);
  leerArchivo("bitacora.txt", bitacoratxt);
  cout<<"------"<<endl;
  cout << "Sistema de busqueda en la bitacora" << endl;
  separar(bitacoratxt, bitacoraAcomodada);
  cout<<"------"<<endl;
  cout << "Por favor espere un momento..." << endl;
  bubbleSort(bitacoraAcomodada);
  cout << "Listo!" << endl;
  // filtro(bitacoraAcomodada);
  bitacoraDiaria = porDia(bitacoraAcomodada);
  filtro(bitacoraDiaria);
  archivo(bitacoraAcomodada);
  return 0;
}