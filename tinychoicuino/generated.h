
// Save as a .ino file and upload from the Arduino IDE to play on your arduboy.

// Made with www.tinychoice.net :)

#define MAX_STR_LEN 30
const PROGMEM word sectionCount = 5;
const PROGMEM word textlinecounts[] = { 8, 2, 4, 2, 6 };
const PROGMEM word verbcounts[] = { 2, 2, 0, 2, 0 };
const PROGMEM char text_0_0[]="You stand between a";
const PROGMEM char text_0_1[]="field of sheep and a";
const PROGMEM char text_0_2[]="field of cows.";
const PROGMEM char text_0_3[]="";
const PROGMEM char text_0_4[]="You wonder what the";
const PROGMEM char text_0_5[]="cows are up to, but";
const PROGMEM char text_0_6[]="you can't figure it";
const PROGMEM char text_0_7[]="out.";
const PROGMEM char * const(text_0[]) = { text_0_0, text_0_1, text_0_2, text_0_3, text_0_4, text_0_5, text_0_6, text_0_7 };
const PROGMEM char text_1_0[]="Cows are rolling";
const PROGMEM char text_1_1[]="about.";
const PROGMEM char * const(text_1[]) = { text_1_0, text_1_1 };
const PROGMEM char text_2_0[]="You roll around for a";
const PROGMEM char text_2_1[]="bit, but you don't";
const PROGMEM char text_2_2[]="feel that you really";
const PROGMEM char text_2_3[]="fit in here.";
const PROGMEM char * const(text_2[]) = { text_2_0, text_2_1, text_2_2, text_2_3 };
const PROGMEM char text_3_0[]="Sheep are jumping up";
const PROGMEM char text_3_1[]="and down";
const PROGMEM char * const(text_3[]) = { text_3_0, text_3_1 };
const PROGMEM char text_4_0[]="You jump up and down,";
const PROGMEM char text_4_1[]="just like the sheep,";
const PROGMEM char text_4_2[]="but however hard and";
const PROGMEM char text_4_3[]="long you try they";
const PROGMEM char text_4_4[]="still look at you";
const PROGMEM char text_4_5[]="differently.";
const PROGMEM char * const(text_4[]) = { text_4_0, text_4_1, text_4_2, text_4_3, text_4_4, text_4_5 };
const PROGMEM char * const(* const (texts[])) = { text_0, text_1, text_2, text_3, text_4 };
const PROGMEM char verb_0_0[]="  Go to the cows >";
const PROGMEM char verb_0_1[]="< Go to the sheep  ";
const PROGMEM char * const(verblist_0[]) = { verb_0_0, verb_0_1 };
const PROGMEM char verb_1_0[]=" Roll with the cows>";
const PROGMEM char verb_1_1[]="< Leave this place  ";
const PROGMEM char * const(verblist_1[]) = { verb_1_0, verb_1_1 };
const PROGMEM char * const(verblist_2[]) = {  };
const PROGMEM char verb_3_0[]=" Jump with the sheep>";
const PROGMEM char verb_3_1[]="< Leave this place  ";
const PROGMEM char * const(verblist_3[]) = { verb_3_0, verb_3_1 };
const PROGMEM char * const(verblist_4[]) = {  };
const PROGMEM char * const(* const (verblists[])) = { verblist_0, verblist_1, verblist_2, verblist_3, verblist_4 };
const PROGMEM word verbtargetlist_0[] = { 1, 3 };
const PROGMEM word verbtargetlist_1[] = { 2, 0 };
const PROGMEM word verbtargetlist_2[] = {  };
const PROGMEM word verbtargetlist_3[] = { 4, 0 };
const PROGMEM word verbtargetlist_4[] = {  };
const PROGMEM word *const (verbtargetlists[]) = { verbtargetlist_0, verbtargetlist_1, verbtargetlist_2, verbtargetlist_3, verbtargetlist_4 };