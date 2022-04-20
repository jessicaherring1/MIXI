import processing.sound.*;
AudioIn input;
Amplitude loudness;
Waveform waveform;

float sizeMin = 0;    // Set Min for Sound Size
float sizeMax = 350;  // Set Max for Sound Size
float soundSize = 0;  // Current Sound Size
int samples = 100;    // Number of Audio Wave Samples

// Initialize Audio Input
void initAudio(){
  input = new AudioIn(this, 0);
  input.start();
  loudness = new Amplitude(this);
  loudness.input(input);
}

// Get Audio Loudness
void getLoud(){
  float inputLevel = map(mouseY, 0, height, 1.0, 0.0);
  input.amp(inputLevel);
  float volume = loudness.analyze();
  soundSize = int(map(volume, 0, 0.5, sizeMin, sizeMax));
  // Do Something
}

// Get Audio Waves
void getWave(){
  waveform.analyze();
  for(int i = 0; i < samples; i++){
    // Do something
  }
}
