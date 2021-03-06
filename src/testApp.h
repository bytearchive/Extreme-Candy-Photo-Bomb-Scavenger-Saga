#pragma once

//ON IPHONE NOTE INCLUDE THIS BEFORE ANYTHING ELSE

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofxOpenALSoundPlayer.h"
#include "ofxCenteredTrueTypeFont.h"
#include "candy.h"
#include "shooter.h"
#include "scorepop.h"
#include "ofxEasyRetina.h"
#include "ofxiOSEAGLView+retinaPatch.h"
#include "ofxGameCenter.h"
#include "ofxOpenCv.h"
#include "explode.h"

//warning video player doesn't currently work - use live video only
#define _USE_LIVE_VIDEO

class testApp : public ofxiPhoneApp{
	
	public:
		
		void setup();
		void update();
		void draw();
        void exit();
    
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);
	
        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        void grabImage();
        void randomLevel();
        int highscore();
        bool hitTest(Candy candy, Bullet bullet);
    
        static bool matched(Candy &candy);
        static bool done(Bullet &bullet);
        static bool popped(ScorePop &scorepop);
        static bool hanging(Candy &c);
        static bool exploded(Explode &e);
    
        void checkHangers(Candy &c);
        void findMatchingColors(Candy &c);
        //bool removeHangers(Candy &c);
        bool tooManyCandies();
        bool zappedAllCandies();
    
    
        void play();
        vector<int> getAmmo();
    
        NSUserDefaults *player;

        ofVideoGrabber vidGrabber;
        ofxOpenALSoundPlayer wand;
        ofxOpenALSoundPlayer firingWand;
        ofxOpenALSoundPlayer cauldron;
        ofxOpenALSoundPlayer candySounds[7];
        ofxOpenALSoundPlayer startSound;
        ofxOpenALSoundPlayer randomTaunt[5];
        ofxOpenALSoundPlayer introSound;
        ofxOpenALSoundPlayer soundtrack;
        ofxOpenALSoundPlayer hurrySound;
        ofxOpenALSoundPlayer rememberSound;
        ofxOpenALSoundPlayer candyFallingSound;
        ofxCvColorImage	colorImg;
        ofxCenteredTrueTypeFont messageText;
        ofxCenteredTrueTypeFont scoreText;
        ofxCenteredTrueTypeFont scoreTextBig;
        Shooter shooter;
    
        float capW;
        float capH;
        float startTime;
        float endTime;
        float nextTaunt;
        int candiesCollected;
        int score;
        int gameState;
        bool bLearnPhoto;
        bool highscoreAchieved;
        bool createGrid;
        bool playing;
        bool hurryUpPlayed;
        bool candyFalling;
        ofImage highscoreImage;
        ofImage candyImages[3][7];
        ofImage bulletImages[3];
        ofImage gameOverImage;
        ofImage cauldronMask;
        ofImage hourglassImage;
        ofImage scoreBarImage;
        ofImage themeImage;
        ofImage starImage;
        string leaderboardName;         //ID name of your leaderboard for your app

        vector <Candy> candies;
        vector<ScorePop> scorePops;
        vector<Explode> candyFall;
        ofxEasyRetina retina;
        ofxGameCenter gameCenter;

        //
    
};
