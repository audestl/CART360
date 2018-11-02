/**********************ETUDE 2 CART 360 2017*******************************
 * WELCOME! 
 * THE PURPOSE OF THIS EXERCISE IS TO DESIGN A VERY SIMPLE KEYBOARD (5 KEYS)
 * WHICH ALLOWS YOU TO PLAY LIVE, RECORD, AND PLAYBACK SINGLE NOTES (NO CHORDS). 
 * THERE WILL BE A BUTTON WHICH WHEN PRESSED WILL TAKE THE USER TO THE NEXT MODE:
 * THERE ARE 5 POSSIBLE MODES
 * 0 ==  reset    ==   led off == also resets
 * 1 ==  live     ==   led BLUE
 * 2 ==  record   ==   led RED
 * 3 ==  play     ==   led GREEN
 * 4 ==  looper   ==   led PURPLE
 * 
 * ADDITIONALLY - WHEN THE USER CHANGES MODE, 
 * THE RGB LED WILL CHANGE COLOR (ACCORDING TO THE SPECIFICATIONS)

 * PLEASE FOLLOW THE INSTRUCTIONS IN THE COMMENTS:
 * DO NOT ADD ANY MORE FUNCTION DEFINITIONS 
 * ONLY IMPLEMENT THE FUNCTION DEFINITIONS SUPPLIED
 * THERE IS NO NEED TO ADD ANY NEW VARIABLES OR CONSTANTS
 * PROVIDE COMMENTS FOR ANY OF THE CODE IMPLEMENTED
 * GOOD LUCK!
 */
/**** CONSTANTS ********************************************************/
#include "pitches.h"
#define BUTTON_MODE_PIN 2 // Button to change the mode

// constants for RGB LED
#define LED_PIN_R 9 // R PIN
#define LED_PIN_G 6 // G PIN
#define LED_PIN_B 5 // B PIN

// constant for note in (button-resistor ladder on breadboard)
# define NOTE_IN_PIN A0

//constant for max number of notes in array
#define MAX_NOTES 16

// a constant for duration
const int duration = 200;

// constant for pin to output for buzzer 
#define BUZZER_PIN 3 // PWM



/******** VARIABLES *****************************************************/
// counter for how many notes we have
int countNotes = 0;
int mode = 0; // start at off
// array to hold the notes played (for record/play mode)
int notes [MAX_NOTES]; 
int prev=LOW;
int bs=LOW;
int pprev=HIGH;
int counter=0;

/*************************************************************************/


/**********************SETUP() DO NOT CHANGE*******************************/
// Declare pin mode for the single digital input
void setup()
{
  pinMode(BUTTON_MODE_PIN, INPUT);
   Serial.begin(9600);
}

/**********************LOOP() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change the loop - it establishes the flow of the program
 * We call here 3 functions repeatedly:
 * 1: chooseMode(): this function will determine the mode that your program is in 
 * based on if the button (linked to the BUTTON_MODE_PIN) was pressed
 * 2: setRGB(): will set the color of the RGB LED based on the value of the mode variable
 * 3: selectMode(): will determine which function to call based on the value of the mode variable

**************************************************************************/
void loop()
{
  chooseMode();
  setRGB();
  selectMode();
}
/******************CHOOSEMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Read the value from the Button (linked to the BUTTON_MODE_PIN) and 
 * if is being pressed then change the mode variable.
 * REMEMBER:
 * mode == 0 is reset 
 * mode == 1 is live
 * mode == 2 is record
 * mode == 3 is play
 * mode == 4 is loopMode
 * Every time the user presses the button, the program will go to the next mode,
 * once it reaches 4, it should go back to mode == 0. 
 * (i.e. if mode ==2 and we press, then mode ==3) ...
**************************************************************************/
void chooseMode(){ // previous mode
        prev=LOW;
         
        bs = digitalRead(BUTTON_MODE_PIN); 
        if(mode !=5){
          
                 if (bs != prev ) { 
                                    mode++;
                                    delay(300);
                                  } 
                else{
                      prev = bs;
                    }
        }
        
        else
        {
          mode=0;
          }
        }

/******************SETRGB(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Depending on the value of the mode variable:
 * if the mode is 0 - RGB LED IS OFF
 * if the mode is 1 - RGB LED IS BLUE
 * if mode is 2 - RGB LED IS RED
 * if mode is 3 - RGB LED IS GREEN
 * if mode is 4 - RGB LED iS PURPLE
 * YOU MUST USE A SWITCH CASE CONSTRUCT (NOT A SERIES OF IF / ELSE STATEMENTS
**************************************************************************/
void setRGB()
{
  int i= mode;
  switch(i){
  case 0: {
    analogWrite(LED_PIN_G, 0);
    analogWrite(LED_PIN_R, 0);
    analogWrite(LED_PIN_B, 0);
    break;
    }
  case 1:{
    analogWrite(LED_PIN_G, 0);
    analogWrite(LED_PIN_R, 0);
    analogWrite(LED_PIN_B, 255);
    break;
    }
  case 2:{
    analogWrite(LED_PIN_G, 0);
    analogWrite(LED_PIN_R, 255);
    analogWrite(LED_PIN_B, 0);
    break;
    }
  case 3:{
    analogWrite(LED_PIN_G, 255);
    analogWrite(LED_PIN_R, 0);
    analogWrite(LED_PIN_B, 0);
    break;
    }
  case 4:{
    analogWrite(LED_PIN_G, 0);
    analogWrite(LED_PIN_R, 100);
    analogWrite(LED_PIN_B, 100);
    break;
    }
 
  } 
}
/**********************SELECTMODE() DO NOT CHANGE *******************************

******************************************************************************/
void selectMode()
{
  if(mode == 0) { 
    reset();
  }
  else if(mode == 1) {
    live();
  }
  else if(mode == 2) {
   record();
  }
  
  else if(mode == 3) {
    play();
  }
   
   else if(mode == 4) {
    looper();
  }
}
/******************RESET(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function should ensure that any notes recorded are no longer available
**************************************************************************/
void reset()
{ 
 for(int i=0; i<MAX_NOTES; i++)
  { 
    notes [i] =0;
    int k = notes [i]; 
   
    }
     delay(200);
}
  


/******************LIVE(): IMPLEMENT **************************************

**************************************************************************/
void live() // NOISE AND PEAK VALUE PROBABLY NEED TO BE HANDLE
{  long myNote;
    
    if(analogRead(HIGH))
    { 
      
        myNote = analogRead(NOTE_IN_PIN);
       tone(BUZZER_PIN, getNote(myNote),200);
      }
      else
      {
        analogRead(LOW);
        }
      
       

}
/******************RECORD(): IMPLEMENT **********************************

**************************************************************************/
void record(){
  
      /*
        long key, myNote;
        long i =0 ;
        bs = digitalRead(BUTTON_MODE_PIN);  
      
             
               for(i=0; i<MAX_NOTES; i++)
              {

         
                if(analogRead(HIGH)){
                 
                myNote=analogRead(NOTE_IN_PIN);
                key=getNote(myNote);
                   delay(200);
                tone(BUZZER_PIN,key,200);
               
                notes[i] = key;
                }
                else
                {
                  analogRead(LOW);
                  }
                
                 
                            
                                    
              if (bs!=prev )
              {
                     
                   
                   selectMode();
                   analogRead(LOW);
                       
                    
                   } 
                
               
              
                 
               */     
                
              
              
         
      
  
 }
      

/******************PLAY(): IMPLEMENT ************************************

**************************************************************************/
void play(){
long n,t;
long i=0;
  bs = digitalRead(BUTTON_MODE_PIN);
  
    if( i<= counter){
     
     
      n = notes [i];
      t=getNote(n);
      tone(BUZZER_PIN,t,200);
      delay(400);
      i++;
      
      if(bs!=prev)
                   {
                    selectMode();
                    analogRead(LOW);
                  
                    }

    } 
}
/******************LOOPMODE(): IMPLEMENT *********************************

**************************************************************************/
void looper()
{
  //IMPLEMENT
}
/******************GETNOTE(): Convert to pitches *********************************

**************************************************************************/
int getNote(int noteValue)
{  
  if(noteValue <= 100 && noteValue>=30 )
  {
    return NOTE_C5;
    }
  else if(noteValue > 100 && noteValue <=400)
  {
    return NOTE_D5;
    }
     else if(noteValue > 400 && noteValue <=800)
  {
    return NOTE_E5;
    }
     else if(noteValue > 800 && noteValue <=980)
  {
    return NOTE_F5;
    }
     else if(noteValue > 980)
  {
    return NOTE_G5;
    }
    else
    {
      return 0;}
    

  }

/**************************************************************************/
