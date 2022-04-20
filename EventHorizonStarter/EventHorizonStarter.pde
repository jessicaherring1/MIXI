// Event Horizon Starter
// Zane Cochran
// 27 March 2022

boolean isBroadcast = false;       // Toggles Visualization On/Off
String ipAddress = "10.40.4.115";  // Event Horizon IP Address
float whichColor = 0;

ArrayList<Fire> fireworks = new ArrayList();
final float G = 0.04;

int randX;
int randY;

void setup() {
  size(480, 480);
  initBroadcast();
  initAudio();
}

void draw() {
  background(0);
  getLoud();

  noStroke();
  background(0);
  for (int i = 0; i < fireworks.size(); i++) {
    fireworks.get(i).update();
    fireworks.get(i).draw();
  }

  randX = (int)random(width);
  randY = (int)random(height);
  // circle(mouseX, mouseY, 50);
  if (soundSize>100) {
  makeFire();
  println(soundSize);
  }
  broadcast();
}

void makeFire() {
  //fireworks.clear();
  color c = color(random(50, 255), random(50, 255), random(50, 255));
    int numFires =(int)map(soundSize, 0, 350, 4, 1000);//(int)random(4, 1000);
    for (int i=0; i<numFires; i++) {
      float r = random(0, TWO_PI);
      float R = random(0, 2);
      fireworks.add(new Fire(randX, randY, R*sin(r), R*cos(r), c));
      //fireworks.add(new Fire(mouseX, mouseY, R*sin(r), R*cos(r), c));
    }
  //circle(mouseX, mouseY, 50);

  /*
  for(int j=0; j<soundSize; j++){
   
   color c = color(random(50, 255), random(50, 255), random(50, 255));
   int numFires = (int)random(4, 1000);
   for (int i=0; i<numFires; i++) {
   float r = random(0, TWO_PI);
   float R = random(0, 2);
   fireworks.add(new Fire(mouseX, mouseY, R*sin(r), R*cos(r), c));
   }
   }*/

  /*
  colorMode(HSB, 255);
   fill(whichColor, 255, 255);
   ellipse(width/2, height/2, soundSize, soundSize);
   //getWave();
   if (soundSize >100) {
   whichColor= random(255);
   }
   if (isBroadcast) {
   broadcast();
   }*/
}
