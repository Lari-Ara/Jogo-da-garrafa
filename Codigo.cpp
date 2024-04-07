#define ledVerde 2
#define ledAmarelo 3
#define ledVermelho 4

int garrafa3L = 0;
int garrafa5L = 0;
int troca = 0;

void setup(){
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
  Serial.println("Digite um numero");
}

void loop(){  
  
 
  if (Serial.available() > 0){
    
    int num = Serial.parseInt(SKIP_ALL, '\n'); 
     Serial.print("Numero digitado ");
     Serial.println(num);
    if(garrafa3L == 0 && garrafa5L == 0){
    	Serial.println("Garrafas vazias");
    }
    switch(num){	
    	case 1:
      	 garrafa3L = 3;
      	 break;
      	case 2:
         garrafa5L = 5;
         break;
        case 3:
         // garrafa5L = garrafa5L + garrafa3L;
         garrafa5L += garrafa3L;
         garrafa3L = 0;
      	 if(garrafa5L > 5){
            garrafa3L = garrafa5L - 5;
         	garrafa5L = 5;
      	 }
         break;
        case 22: 
         garrafa3L += garrafa5L;
         garrafa5L = 0;
     	 if(garrafa3L > 3){
            garrafa5L = garrafa3L - 3;
         	garrafa3L = 3;
      	 }
		 break;
      	case 7:
         garrafa3L = 0;
         garrafa5L = 0;
         break;
        case 26:
         garrafa3L = 0;
         break;
        case 17:
         garrafa5L = 0;
         break;
      	default:
         Serial.println("Seu numero digitado nao e valido");
         break;
    }
    
    Serial.print("A garrafa3L tem: ");
    Serial.println(garrafa3L);
    Serial.print("A garrafa5L tem: ");
    Serial.println(garrafa5L);
    Serial.println("--------------------------");
    
    
    if(garrafa3L <= 3 && garrafa5L != 4){
    	digitalWrite(ledAmarelo, HIGH);
    }
    if(garrafa5L <= 5 && garrafa5L != 4){
        digitalWrite(ledVermelho, HIGH);
    }
    if(garrafa5L == 4){
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledAmarelo, LOW);
    }
  
  }
 }
    
    
