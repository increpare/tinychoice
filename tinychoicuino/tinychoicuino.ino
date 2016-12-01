#include <Arduboy2.h>
#include "generated.h"

// make an instance of arduboy used for many functions
Arduboy2 arduboy;

char buffer[MAX_STR_LEN];

size_t currentVerb=0;
size_t currentPage=0;
byte yoffset=0;


// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  Serial.begin(9600);
  // initiate arduboy instance
  arduboy.boot();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(10);
  render();
}


void render(){
// first we clear our screen to black
  arduboy.clear();

  word lines = pgm_read_word_near(textlinecounts+currentPage);
  char linestoshow = 6;
  if (lines<linestoshow){
    linestoshow=lines;
  }
  const char* const * text = pgm_read_word_near(texts+currentPage);
  for (int i=0;i<linestoshow;i++){
    strcpy_P(buffer, (char*)pgm_read_word(&text[i+yoffset])); // Necessary casts and dereferencing, just copy.
    arduboy.setCursor( 0,i*9);
    arduboy.print(buffer);
  }

  arduboy.fillRect(0,64-10,128,1,WHITE);

  word verbcount = pgm_read_word_near(verbcounts+currentPage);
  if (verbcount>0){
    const char* const * verblist = pgm_read_word_near(verblists+currentPage);
    strcpy_P(buffer, (char*)pgm_read_word(&verblist[currentVerb])); // Necessary casts and dereferencing, just copy.
    byte verb_length = strlen(buffer);

    char xoffset = 128/2-verb_length*6/2;
    arduboy.setCursor( xoffset,64-8);
    arduboy.print(buffer);
  }

  word h = 54;
  word linesPerPage = 6;

  if (lines>linesPerPage){    
    word scrollBarSize = (h*linesPerPage)/lines;
    word maxOffset = lines-6;
    word maxScrollbarY = 53-scrollBarSize;
    arduboy.fillRect(128-2,(maxScrollbarY*yoffset)/maxOffset,2,scrollBarSize,WHITE);
  }

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}

bool nothingHappened(){
  return !(
          arduboy.pressed(UP_BUTTON) ||
          arduboy.pressed(DOWN_BUTTON) ||
          arduboy.justPressed(LEFT_BUTTON) ||
          arduboy.justPressed(RIGHT_BUTTON) ||
          arduboy.justPressed(A_BUTTON) ||
          arduboy.justPressed(B_BUTTON) //||
          // arduboy.justReleased(UP_BUTTON) ||
          // arduboy.justReleased(DOWN_BUTTON) ||
          // arduboy.justReleased(LEFT_BUTTON) ||
          // arduboy.justReleased(RIGHT_BUTTON) ||
          // arduboy.justReleased(A_BUTTON) ||
          // arduboy.justReleased(B_BUTTON)
          );
}

void reset(){
  currentPage=0;
  currentVerb=0;
  yoffset=0;
}

void pressAction(){
  const word* const targetlist = pgm_read_word_near(verbtargetlists+currentPage);
  const word verbtarget = pgm_read_word_near(targetlist+currentVerb);

  Serial.print("going from ");
  Serial.print(currentPage);
  Serial.print(" to ");
  Serial.print(verbtarget);
  Serial.println(".");
  currentPage=verbtarget;
  currentVerb=0;
  yoffset=0;
}

// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  arduboy.pollButtons();

  if (nothingHappened()){
    return;
  }

  bool change=false;
  if (arduboy.pressed(UP_BUTTON)){
    if (yoffset>0){
      yoffset--;
      change=true;
    }
  }
  if (arduboy.pressed(DOWN_BUTTON)){
    word lines = pgm_read_word_near(textlinecounts+currentPage);
    word maxoffset = lines-6;
    if (yoffset<maxoffset){
      yoffset++;
      change=true;
    } 
  }
  if (arduboy.justPressed(LEFT_BUTTON)){
    if (currentVerb>0){
      currentVerb--;
      change=true;
    }
  }
  if (arduboy.justPressed(RIGHT_BUTTON)){
    word verbcount = pgm_read_word_near(verbcounts+currentPage);
    if (currentVerb<verbcount-1){
      currentVerb++;
      change=true;
    }
  }
  if (
    (arduboy.pressed(A_BUTTON)&&arduboy.justPressed(B_BUTTON))||
    (arduboy.pressed(B_BUTTON)&&arduboy.justPressed(A_BUTTON)))
    {
      reset();
      change=true;
    }
  else if (arduboy.justPressed(A_BUTTON)||arduboy.justPressed(B_BUTTON)){
    pressAction();
    change=true;
  }
  if (change){
    render();
  }
}