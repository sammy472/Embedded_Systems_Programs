 #include<Servo.h>
Servo servoH;//pour la commande  du servo horizontale
Servo servoV;//pour la commande du servo verticale 
//pin des servomoteur vertical et horizontal
int pinservoH = 11;
int pinservoV = 10;

int valeurLDRHG=1024;// LDRHG:LDR Haut à Gauche 
int valeurLDRHD=1024;//LDRHD: LDR Haut à Droite
int valeurLDRBG=1024;//LDRBG:LDR Bas à gauche
int valeurLDRBD=1024;//LDRBD: LDR Bas à Droite
 //on initialise la valeur des angles des servomoteurs
int anglehorizontal=1;
int anglevertical=1;
//on définit les limites(max et min) d'angles que les servomoteurs ne doivent pas franchir
int anglemax=175;
int anglemin=10;
float pas=1;//on définit un pas d'incrémentation des angles des servomoteurs
//pins des photoresistances
int pinLDRHG = A1;
int pinLDRHD = A2;
int pinLDRBG = A3;
int pinLDRBD = A4;

int attente=5;//pour le delai
void setup(){
 //connection serie pour l'affichage sur le moniteur
 Serial.begin(9600);
 //les differents servomoteurs sont branchés à leurs pins de commande respectifs
    servoH.attach(pinservoH);
    servoV.attach(pinservoV);
 servoH.write(anglehorizontal);
 servoV.write(anglevertical);
 //on oriente les pins des servomoteurs en sortie
   pinMode(pinservoH,OUTPUT);
   pinMode(pinservoV,OUTPUT);
 //on met les pins des servomoteurs en niveau haut
     digitalWrite(pinservoH,HIGH);
     digitalWrite(pinservoV,HIGH);
 //on oriente les pins des LDR en entrée
       pinMode(pinLDRHG,INPUT);
       pinMode(pinLDRHD,INPUT);
       pinMode(pinLDRBG,INPUT);
       pinMode(pinLDRBD,INPUT);

 }
void loop() {
  //récupération des valeurs fournis par les photoresistances
    valeurLDRHG=analogRead( pinLDRHG);
    valeurLDRHD=analogRead( pinLDRHD);
    valeurLDRBG=analogRead( pinLDRBG);
    valeurLDRBD=analogRead( pinLDRBD);
    
    //Serial.println(valeurLDRBG);
    //après obtention des valeurs des photoresistances on va calculer les valeurs moyennes
    float moyhaut=float((valeurLDRHG+valeurLDRHD)/2);
    float moybas=float((valeurLDRBG+valeurLDRBD)/2);
    float moygauche=float((valeurLDRHG+valeurLDRBG)/2);
    float moydroite=float((valeurLDRHD+valeurLDRBD)/2);
    //on compare la valeur moyenne des LDR haut et bas pour ajuster la position des panneaux
     if(TopGreater){
      TournerVersBas();
     }
      
        
       else if(ButtomGreater(moyhaut,moybas)){
          TournerVersHaut();
         }
    
       else {
            servoH.write(anglehorizontal);
         }
       //on compare la valeur moyenne des LDR droite et gauche pour ajuster la position des panneaux
       if(RightGreater(moydroite,moygauche)){
           TournerVersGauche();
           }
          
       else if(LeftGreater(moygauche,moydroite)){
            TournerVersDroite();
           }
          
      else{
            servoV.write(anglevertical);
        }

        //Le Reste
        //LeReste();

       }
/*=============================================================
===============================================================
===============================================================
===============================================================
===============================================================*/
//Les fonctions pour manipuler le panneau solaire

 bool TopGreater(float moyhaut  ,float moybas){
  return moyhaut > moybas;
  }

  void TournerVersBas(){
          while(anglehorizontal<anglemax){
         anglehorizontal += pas;
         servoH.write(anglehorizontal);
         Serial.println("vers le bas");
         delay(attente);
        }
  }
 bool ButtomGreater(float a ,float b){
  return a < b;
  }
 void TournerVersHaut(){
   while(anglehorizontal>anglemin){
              anglehorizontal -= pas;
              servoH.write(anglehorizontal);
              Serial.println("vers le haut");
              delay(attente);
           }
 }

 bool LeftGreater(float a ,float b){
  return a > b;
 }

 void TournerVersDroite(){
              while(anglevertical>anglemin){
              anglevertical -= pas;
              servoV.write(anglevertical);
              Serial.println("vers la droite");
              delay(attente);            
             }
 }

bool RightGreater(float a ,float b){
  return a > b;
 }
 void TournerVersGauche(){
   while(anglevertical<anglemax){
              anglevertical += pas;
              servoV.write(anglevertical);
              Serial.println("vers la gauche");
              delay(attente);             
            }
 }

/*
 void LeReste(){
     if(moyhaut==moybas){
      servoH.write(anglehorizontal);
     }
     else if(moygauche==moydroite){
     servoV.write(anglevertical);
     }
     else if(moyhaut==moybas==moygauche==moydroite){
      servoV.write(anglevertical);
      servoH.write(anglehorizontal);
      Serial.println("au milieu");
     }
     Serial.println("angle vertical=");
     Serial.println(anglevertical);
     Serial.println("angle horizontal=");
     Serial.println(anglehorizontal);
     if(moyhaut>moybas)
        Serial.println("moyhaut");
     else if (moyhaut>moybas)
         Serial.println("moybas");
     else if(moydroite>moygauche)
        Serial.println("moydroite");
     else if(moydroite<moygauche)
        Serial.println("moygauche");
 }
 */




       
        
