import processing.video.*;
import javax.imageio.*;
import java.awt.image.*; 
import java.net.*;
import java.io.*;

int clientPort = 9100; 
DatagramSocket ds; 

void initBroadcast(){
  try {
    ds = new DatagramSocket();
  } catch (SocketException e) {
    e.printStackTrace();
  }
  frameRate(30);
}

// Broadcast Image
void broadcast() {

  BufferedImage bimg = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB );
  loadPixels();
  bimg.setRGB( 0, 0, width, height, pixels, 0, width);

  ByteArrayOutputStream baStream  = new ByteArrayOutputStream();
  BufferedOutputStream bos    = new BufferedOutputStream(baStream);

  try {
    ImageIO.write(bimg, "jpg", bos);
  } 
  catch (IOException e) {
    e.printStackTrace();
  }

  byte[] packet = baStream.toByteArray();

  try {
    ds.send(new DatagramPacket(packet,packet.length, InetAddress.getByName(ipAddress),clientPort));
  } 
  catch (Exception e) {
    e.printStackTrace();
  }
}
