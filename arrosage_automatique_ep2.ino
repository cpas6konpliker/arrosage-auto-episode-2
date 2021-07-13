void setup() {
  pinMode(A0,INPUT); //initialisation du port analogique A0 (capteur d'humidité pour la zone 1) en mode lecture
  pinMode(A1,INPUT); //initialisation du port analogique A1 (capteur d'humidité pour la zone 2) en mode lecture
  pinMode(A2,INPUT); //initialisation du port analogique A2 (potentiomètre pour la zone 1) en mode lecture
  pinMode(A3,INPUT); //initialisation du port analogique A2 (potentiomètre pour la zone 2) en mode lecture
  pinMode(7,OUTPUT); //initialisation du port numérique 7 (LED de la zone 2) en mode écriture
  pinMode(8,OUTPUT); //initialisation du port numérique 8 (LED de la zone 1) en mode écriture
}

void loop() {
  
  while(1) {
      
      if(analogRead(A0) < (1023 - analogRead(A2))){ //On compare le capteur zone 1 au potentiomètre qui lui est associé, et si le premiere est inférieur au deuxième, on execute la ligne suivante
          digitalWrite(8,1); //On allume la LED de la zone 1
      }
      if(analogRead(A1) < (1023 - analogRead(A3))){ //On compare le capteur zone 2 au potentiomètre qui lui est associé, et si le premiere est inférieur au deuxième, on execute la ligne suivante
          digitalWrite(7,1); //On allume la LED de la zone 2
      }

      delay(1000); //On attends 1 seconde
      
      digitalWrite(8,0); //On éteinds la LED de la zone 1
      digitalWrite(7,0); //On éteinds la LED de la zone 2
      
      delay(1000); //On attends de nouveau 1 seconde

  } //On repart au début de la boucle

}
