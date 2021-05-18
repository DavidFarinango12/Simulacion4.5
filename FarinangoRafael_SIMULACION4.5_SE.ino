/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * CODIGO 18: USO DE TIMER 2
 * OBJETIVO: REALIZAR UN RELOJ CON ESTE TIMER
 * NOMBRE: RAFAEL FARINANGO
 * FUNCIONES:       MsTimer2::set(1000,flash);
 *                  MsTimer2::start();
 *                  MsTimer2::start(stop);
 */

#include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int segundos = 0;
int minutos = 0;
int horas = 0;


void setup() {
  lcd.begin(16,2);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
}


void loop() {
  // put your main code here, to run repeatedly:

}


void reloj(){
  if(segundos < 60){
    segundos++;
  }
  else{
    segundos = 0;
    if(minutos < 60){
      minutos++;
    }
    else{
      minutos = 0;
       if(horas < 24)
          horas++;
       else
          horas = 0;
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
}
