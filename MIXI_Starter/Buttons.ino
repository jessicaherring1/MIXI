// Button/Potontiometer Functions

// Initialize Buttons
void initButtons(){
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

// Check Buttons
/*void checkButtons(){
  for (int i = 0; i < numButtons; i++)  {
    buttons[i].update();
    if (buttons[i].rose() ) {
      buttonStates[i] = !buttonStates[i];
    }
  }
}*/

// Check Pots
void checkPots(){
  for (int i = 0; i < numPots; i++){
    potStates[i] = analogRead(potPins[i]);
  }
}

void potStuff(){
  /*for (int i = 0; i < numPots; i++){
    if
  }*/
}
