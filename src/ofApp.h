#pragma once

#include "ofMain.h"
#include "ofxOsc.h" //you will need to work out how to include ofxOSC in a project

#define HOST "192.168.0.102" //this are the correct ip for the mad hatter
#define PORT 7000 //this is the correct port for him too

//--------------------------------------------------------
class ofApp : public ofBaseApp {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofxOscSender sender;
    ofxOscReceiver receiver;
    
    vector<int> x;
    vector<int> y;
    
};

