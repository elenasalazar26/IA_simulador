#include "../include/entorno.hpp"

int entorno::numero_col() {
  return malla_.size();
}
int entorno::numero_filas() {
  return malla_[0].size();
}
pair <int, int> entorno::get_pos_inicial() {
  return puntoInicial_;
}
pair <int, int> entorno::get_pos_final() {
  return puntoFinal_;
}
void entorno::set_pos_inicial(int x, int y){
  puntoInicial_.first = x;
  puntoInicial_.second = y;
  posi_coche(x, y);
}

void entorno::set_pos_final(int x, int y){
  puntoFinal_.first = x;
  puntoFinal_.second = y;
}

void entorno::posi_coche(int x, int y) {
  coche_.set_x(x);
  coche_.set_y(y);
}

void entorno::set_ocupada(int x, int y) {
  malla_[x][y].ocupar();
}

void entorno::mostrar_malla() {
  for (int i = 0; i < malla_.size(); i++) {
    for (int j = 0; j < malla_[i].size(); j++) {
      if (coche_.get_x() == i && coche_.get_y() == j) {
        cout << "|C|";
      } else if (puntoFinal_.first == i && puntoFinal_.second == j) {
        cout << "|E|";
      } else if (puntoInicial_.first == i && puntoInicial_.second == j){
       cout << "|S|";
      } else {
         cout << malla_[i][j];
      }
     } 
    cout << endl;
  }
}

int entorno::distancia_linea_recta(int x, int y) {
  int distancia = 0;
  while (x != puntoFinal_.first && y != puntoFinal_.second) {
    if (x < puntoFinal_.first)
      x++;
    else
      x--;
    if (y < puntoFinal_.second)
      y++;
    else
      y--;
    distancia++;
  }
  if (x != puntoFinal_.first) {
    while (x != puntoFinal_.first) {
      if (x < puntoFinal_.first)
        x++;
      else
        x--;
      distancia++;
    }
  } else if (y != puntoFinal_.second) {
      if (y < puntoFinal_.second)
        y++;
      else
        y--;
      distancia++;
  }
  return distancia;
}

void entorno::siguiente_posicion() {

}