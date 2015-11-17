#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sender.setup(HOST, PORT); //host and port for the sender are defined in the header file
    
    receiver.setup(12345); //listen for messages on port 12345
    
    
    
    


    
}

//--------------------------------------------------------------
void ofApp::update(){
    while (receiver.hasWaitingMessages())
    {
        ofxOscMessage m;
        receiver.getNextMessage(m);
        //
        //        cout << m.getAddress() + "\n";
        //        cout <<  m.getArgAsString(0) + "\n";
        //        cout << ofToString(m.getArgAsFloat(1),5) + "\n";
        //        cout << ofToString(m.getArgAsInt(2)) + "\n\n";
        
        /*
         
         the_march_hare
         The Mad Hatter has been expecting you.
         Are you with a friend ?
         Well don't be rude. Introduce them to me as well
         So are you coming in ?
         Send me a message addressed /send_the_key and I will send you back /some_coordinates.
         These will draw out the door code - I'll leave it to you to work out how to draw them.
         Don't forget to bring a present.
         It is the Mad hatter's unbirthday after all.
         
         
         */
        
        if(receiver.getNextMessage(m));
        {
            // cout << m.getAddress() << "\n" << m.getArgAsString(0) << endl;
            if(m.getAddress() == "/some_coordinates") // use if statements to listen for specific addresses
            {
                cout << m.getAddress() << endl;
                cout << m.getArgAsInt32(0) << endl;
                x.push_back(m.getArgAsInt32(0));
                cout << m.getArgAsInt32(1) << endl;
                y.push_back(m.getArgAsInt32(1));
                //now do something specific
                //                cout << m.getAddress() << "\n" << m.getArgAsString(0) << endl;
            }
            else
            {
                
                //otherwise just print the message and all it's arguments
                
                cout << m.getAddress() << endl;
                
                for(int i = 0; i < m.getNumArgs(); i++)
                {
                    if(m.getArgTypeName(i) == "s") //detect and print string arguments
                    {
                        cout << m.getArgAsString(i) << endl;
                    }
                    else if (m.getArgTypeName(i) == "i") //detect and print int arguments
                    {
                        cout << m.getArgAsInt(i) << endl;
                    }
                    
                    //hmm I wonder how you could print float arguments ?!
                }
            }
        }
    }
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    
    if (x.size() > 0) {
    
    ofSetColor(255);
    
    for (int i = 0; i < x.size(); i++) {
        ofDrawCircle(x[i], y[i], 2,2);
    }
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    // send message
    ofxOscMessage m;
    m.setAddress("/send_the_key");
//    m.addStringArg("jbowe021, tpins001");
//    m.addFloatArg(0.00001);
//    m.addInt32Arg(8128);
    sender.sendMessage(m);
    
    cout << "sent" << endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

