
//***5 Channel IR Sensor Connection***//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//*****************// 



// Declaraçôes para os enviar para centro de controle
const int controller_moveForward = 13;
const int controller_turnRight = 12;
const int controller_turnLeft = 11;

const int range_sensor = 1;

String direcao = "u";

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo informações dos sensores");

  //Declarando as entradas dos sensores seguidor de linhas
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  //Declarando os controlles para controle de direção do ADV (comunicação entre informação e controle)
  pinMode(controller_turnRight, OUTPUT);
  pinMode(controller_turnLeft, OUTPUT);
  pinMode(controller_moveForward, OUTPUT);

  
  
}
// -- STRAT VOID LOOP --
void loop() {
  
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  
/*--------------------------------------------------------------------
 * LÓGICA PARA O ROBÔ SEGUIR A LINHA  
 * 
 * -------------------------------------------------------------------*/


  // Se todos os sensores centrais, conseguirem detectar a linha, e a variavel de controle false, então mover o robo para frente
  if (s3 < range_sensor)
  //s3 < 100 && s1 > 100 && s2 > 100 && s4 > 100 && s5 > 100
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_turnRight, LOW );
        digitalWrite(controller_turnLeft,  LOW );
    //---
    digitalWrite(controller_moveForward, HIGH); //Mover para frente
    direcao = "f";
  }

  

  // Se um dos sensores da esquerda indentificar a linha, então firar para a direita
  if (s2 < range_sensor)
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnRight,  LOW );
    //---
    digitalWrite(controller_turnLeft, HIGH); //Viara para Esquerda
    direcao = "e";
  }

  if (s4 < range_sensor )
  {
        //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnLeft,  LOW );
    //---
    digitalWrite(controller_turnRight, HIGH); //Virar para Direita
    direcao = "d";
 
  }

}
// -- END VOID LOOP --
