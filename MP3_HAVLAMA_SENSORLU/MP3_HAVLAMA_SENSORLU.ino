
/*
  TEKNO_KANGAL TEKNOLOJI EGITIM SETI
 	MP3_HAVLAMA_SENSORLU
  HAZIRLAYAN: ÖMER KARABUYA
  Elektronikyardim.com
*/
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial KANGAL_MP3(12, 11); // RX, TX
#define HAREKET_SENSORU 13 // HC-SR501 PIR HAREKET SENSORU PINI
#define LEDPIN1 3 // LED PINI KIRMIZI
#define LEDPIN2 2 // LED PINI BEYAZ
#define LEDPIN3 5 // LED PINI KIRMIZI
#define LEDPIN4 6 // LED PINI BEYAZ
#define LEDPIN5 7 // LED PINI KIRMIZI
#define LEDPIN6 8 // LED PINI BEYAZ
#define IKAZ 4 // DEVRELI IKAZ VERICI PINI

int HAREKET_DURUMU = 0;
int DURUM1 = 0;
int DURUM2 = 1;
//
void setup () {
  pinMode(HAREKET_SENSORU, INPUT);
  pinMode(IKAZ, OUTPUT);
  digitalWrite(IKAZ, LOW);
  pinMode(LEDPIN1, OUTPUT);
  digitalWrite(LEDPIN1, LOW);
  pinMode(LEDPIN2, OUTPUT);
  digitalWrite(LEDPIN2, LOW);
  pinMode(LEDPIN3, OUTPUT);
  digitalWrite(LEDPIN3, LOW);
  pinMode(LEDPIN4, OUTPUT);
  digitalWrite(LEDPIN4, LOW);
  pinMode(LEDPIN5, OUTPUT);
  digitalWrite(LEDPIN5, LOW);
  pinMode(LEDPIN6, OUTPUT);
  digitalWrite(LEDPIN6, LOW);

  Serial.begin (9600);
  KANGAL_MP3.begin (9600);

  mp3_set_serial (KANGAL_MP3);	//set softwareSerial for DFPlayer-mini mp3 module
  delay(100);  //wait 100ms for mp3 module to set volume
  mp3_set_volume (30);
  delay(3000);  
}


//
void loop () {
//  Serial.println(digitalRead(HAREKET_SENSORU))	;
  if ((digitalRead(HAREKET_SENSORU) == HIGH ) && ( HAREKET_DURUMU == 0 ) )
  {
    HAREKET_DURUMU = 1;
    Serial.println("Havlama sesi");
      delay(100);  //wait 100ms for mp3 module to set volume
  mp3_set_volume (30);
  delay(100);  
    mp3_play (1);
 delay(100); 
  }

  if ((digitalRead(HAREKET_SENSORU) == LOW ) && ( HAREKET_DURUMU == 1 ) )
  {
    HAREKET_DURUMU = 0;
    Serial.println("Ses kapatıldı");
    mp3_stop();
  digitalWrite(LEDPIN1, LOW);
  digitalWrite(LEDPIN2, LOW);
  digitalWrite(LEDPIN3, LOW);
  digitalWrite(LEDPIN4, LOW);
  digitalWrite(LEDPIN5, LOW);
  digitalWrite(LEDPIN6, LOW);
   digitalWrite(IKAZ,LOW);
  }


if ( HAREKET_DURUMU == 1 ) 
{
  DURUM1 = !DURUM1;
  DURUM2 = !DURUM2;
  digitalWrite(LEDPIN1, DURUM1);
  digitalWrite(LEDPIN2, DURUM2);
  digitalWrite(LEDPIN3, DURUM1);
  digitalWrite(LEDPIN4, DURUM2);
  digitalWrite(LEDPIN5, DURUM1);
  digitalWrite(LEDPIN6, DURUM2);
    //digitalWrite(IKAZ,DURUM1);
}



  delay(100);
}

/*
 * 
 * DIGER MP3 KOMUTLARI
   mp3_play ();		//start play
   mp3_play (5);	//play "mp3/0005.mp3"
   mp3_next ();		//play next
   mp3_prev ();		//play previous
   mp3_set_volume (uint16_t volume);	//0~30
   mp3_set_EQ ();	//0~5
   mp3_pause ();
   mp3_stop ();
   void mp3_get_state (); 	//send get state command
   void mp3_get_volume ();
   void mp3_get_u_sum ();
   void mp3_get_tf_sum ();
   void mp3_get_flash_sum ();
   void mp3_get_tf_current ();
   void mp3_get_u_current ();
   void mp3_get_flash_current ();
   void mp3_single_loop (boolean state);	//set single loop
   void mp3_DAC (boolean state);
   void mp3_random_play ();
*/

