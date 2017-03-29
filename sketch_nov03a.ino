//binary clock design. time is represented as binary lights corresponding to the powers of two.
//11/3/14

int a, currHour = 0, currMinute = 0, b = 0, c = 0;

void setup(){
  //make all the applicable pins OUTPUT
 for(int i = 0; i<9; i++){
   pinMode(i, OUTPUT);
 }
}



void loop(){
 
  //check if its time for the 1 hour and 1 minute pins to be toggled. if so, do so. (this should be done using BwoDelay, maybe in a method call.)
    //if it was toggled off, do loop. these pins' bools are always true.
      //for(all pins beyond the first):
       //set bool to false
       //if parent's bool is true
         //toggle this guy 
         //if this causes it to toggle off, 
           //set its bool to true.  
   
  a = millis(); 
     
  if(a - b >= 60000){
    minutes();
    b = a;
  }
  if(a - c >= 3600000){
    hours();
    c = a;
  } 
}

void hours(){
 toggle(0);
 currHour++;
 if(currHour == 12){
   turnOff(0, 3);
   currHour = 0;
   return;
 }
 for(int i = 1; i<=3; i++){
   if(isOff(i-1)){
     toggle(i);
   }
 } 
}

void minutes(){
 toggle(4);
 currMinute++;
 if(currMinute == 12){
   turnOff(4, 9);
   currHour = 0;
   return;
 }
 for(int i = 5; i<=9; i++){
   if(isOff(i-1)){
     toggle(i);
   }
 } 
}

void turnOff(int starter, int ender){
  for(int i = starter; i <= ender; i++){
    digitalWrite(i, LOW);
  }
}

boolean isOff(int x){
  return !digitalRead(x);
}

void toggle(int x){
  digitalWrite(x, !digitalRead(x));
}
