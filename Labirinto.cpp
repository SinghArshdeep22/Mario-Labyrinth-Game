#include <string>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
using namespace std;

// Function Declaration
void menu();
void won_message();
void create_display();
void coordinate(float &x, float &y);
int coin_collection(float &x, float &y);
void movement_finale(float &x, float &y);
void movement_iniziale(float &x, float &y);
void prevent_movement_top(float &x, float &y, float &speed);
void prevent_movement_left(float &x, float &y, float &speed);
void prevent_movement_right(float &x, float &y, float &speed);
void prevent_movement_bottom(float &x, float &y, float &speed);

// Screen-Dimensions: 16x10
const int screen_width = 1696;
const int screen_height = 1040;

// Contatore
int conta=0;

// Audio Setup
ALLEGRO_SAMPLE *sample = NULL;
ALLEGRO_SAMPLE *coin_sound = NULL;
ALLEGRO_SAMPLE *pipe_sound = NULL;
ALLEGRO_SAMPLE *victory_sound = NULL;
ALLEGRO_SAMPLE *mamma_mia_sound = NULL;

// Image Setup
ALLEGRO_BITMAP *door = NULL;
ALLEGRO_BITMAP *door1= NULL;
ALLEGRO_BITMAP *logo = NULL;
ALLEGRO_BITMAP *mario = NULL;
ALLEGRO_BITMAP *bitmap = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *background2 = NULL;
ALLEGRO_BITMAP *coin1 = NULL;
ALLEGRO_BITMAP *coin2 = NULL;
ALLEGRO_BITMAP *coin3 = NULL;
ALLEGRO_BITMAP *coin4 = NULL;
ALLEGRO_BITMAP *coin5 = NULL;
ALLEGRO_BITMAP *coin6 = NULL;
ALLEGRO_BITMAP *coin7 = NULL;
ALLEGRO_BITMAP *coin8 = NULL;
ALLEGRO_BITMAP *coin9 = NULL;
ALLEGRO_BITMAP *coin10 = NULL;
ALLEGRO_BITMAP *coin11 = NULL;
ALLEGRO_BITMAP *coin12 = NULL;
ALLEGRO_BITMAP *coin13 = NULL;
ALLEGRO_BITMAP *coin14 = NULL;
ALLEGRO_BITMAP *coin15 = NULL;
ALLEGRO_BITMAP *coin16 = NULL;
ALLEGRO_BITMAP *coin17 = NULL;
ALLEGRO_BITMAP *coin18 = NULL;
ALLEGRO_BITMAP *cover_coin = NULL;

// Conditionals 
int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,c10=0,c11=0,c12=0,c13,c14=0,c15=0,c16=0,c17=0,c18=0,c19=0,c20=0,c21=0;

// Font Setup
ALLEGRO_FONT* score_board_txt = NULL;
ALLEGRO_FONT* won_message_txt = NULL;

// MAIN
int main() {
	
	// Initialize Allegro
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *queue;
	// Create Display
	al_init();
	// Audio 
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);
	// Image
	al_init_image_addon();
	// Font 
	al_init_font_addon();
	al_init_ttf_addon();
	// Display
	display = al_create_display(screen_width, screen_height);
    queue = al_create_event_queue();
	
	// Initialize Allegro
	al_install_keyboard();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	
	// Load Images 
	door = al_load_bitmap("Img/door1.png");				// DOOR  -> 106x208
	door1 = al_load_bitmap("Img/door2.png");			// DOOR  -> 106x208
	logo = al_load_bitmap("Img/logo.png");				// LOGO	 -> 1280x600
	bitmap = al_load_bitmap("Img/wall.png"); 			// WALL  -> 103x104
	mario = al_load_bitmap("Img/mario.png");			// MARIO -> 106x104
	background = al_load_bitmap("Img/back1.jpg");		// BACK	 -> 1669x1040
	background2 = al_load_bitmap("Img/back2.png");		// BACK2 -> 667x374
	coin1 = al_load_bitmap("Img/Coins/coin1.png");		// COIN  -> 60x58
	coin2 = al_load_bitmap("Img/Coins/coin2.png");	
	coin3 = al_load_bitmap("Img/Coins/coin3.png");
	coin4 = al_load_bitmap("Img/Coins/coin4.png");	
	coin5 = al_load_bitmap("Img/Coins/coin5.png");	
	coin6 = al_load_bitmap("Img/Coins/coin6.png");	
	coin7 = al_load_bitmap("Img/Coins/coin7.png");	
	coin8 = al_load_bitmap("Img/Coins/coin8.png");	
	coin9 = al_load_bitmap("Img/Coins/coin9.png");	
	coin10 = al_load_bitmap("Img/Coins/coin10.png");	
	coin11 = al_load_bitmap("Img/Coins/coin11.png");
	coin12 = al_load_bitmap("Img/Coins/coin12.png");		
	coin13 = al_load_bitmap("Img/Coins/coin13.png");		
	coin14 = al_load_bitmap("Img/Coins/coin14.png");		
	coin15 = al_load_bitmap("Img/Coins/coin15.png");		
	coin16 = al_load_bitmap("Img/Coins/coin16.png");			
	coin17 = al_load_bitmap("Img/Coins/coin17.png");			
	coin18 = al_load_bitmap("Img/Coins/coin18.png");			
	cover_coin = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	// Load Audio 
	sample = al_load_sample("Audio/mario.wav");
	coin_sound = al_load_sample("Audio/coin_sound.wav");
	pipe_sound = al_load_sample("Audio/pipe_sound.wav");
	victory_sound = al_load_sample("Audio/victory_sound.wav");
	mamma_mia_sound = al_load_sample("Audio/mamma.wav");
	// Load Font
	score_board_txt = al_load_font("Font/SuperMario256.ttf", 40, 0);
	won_message_txt = al_load_font("Font/SuperMario256.ttf", 250, 0);
	// Controll Image/Audio/Font
	assert(score_board_txt != NULL);
	assert(won_message_txt != NULL);
	assert(mamma_mia_sound != NULL);
	assert(victory_sound != NULL);
	assert(background2 != NULL);
	assert(pipe_sound != NULL);
	assert(background != NULL);
	assert(coin_sound != NULL);
	assert(bitmap != NULL);
	assert(sample != NULL);
	assert(mario != NULL);
	assert(logo != NULL);
	assert(door != NULL);
	// Create Menu
	menu();
	// Create Map
	create_display();
	// Width-Height
	int width = al_get_display_width(display);
	int height = al_get_display_height(display);
	// Draw Mario
	float x=106, y=0;
	// Variables
    float speed = 1;
    bool run = true;
	bool keys[4] = { false, false, false, false };
	// Initial Animation
	movement_iniziale(x,y);
	// RUN
	while(run){
	// Reload Map
	create_display();
	// Mario
	al_draw_bitmap(mario, x, y, 0);
	// Coin Collection
	coin_collection(x,y);
	// Score Board
	int score = conta;
	char scoreText[18];
	sprintf(scoreText, "Score is %d", score);
	al_draw_text(score_board_txt, al_map_rgb(255, 255, 255), 1500, 52, ALLEGRO_ALIGN_RIGHT, scoreText);
	// Win Message
	if(conta == 18){
		won_message();
		movement_finale(x,y);
	}
	
	al_flip_display();
	
	ALLEGRO_EVENT event;
	if (!al_is_event_queue_empty(queue)) {
	al_wait_for_event(queue, &event);
	switch (event.type) {
	case ALLEGRO_EVENT_KEY_DOWN:
	switch (event.keyboard.keycode) {
	case ALLEGRO_KEY_UP:
	keys[0] = true;
	break;
	
	case ALLEGRO_KEY_DOWN:
	keys[1] = true;
	break;
	
	case ALLEGRO_KEY_LEFT:
	keys[2] = true;
	break;
	
	case ALLEGRO_KEY_RIGHT:
	keys[3] = true;
	break;
	
	case ALLEGRO_KEY_ESCAPE:
	run = false;
	
	break;
	default:
	break;
	}
	break;
	
	case ALLEGRO_EVENT_KEY_UP:
	switch (event.keyboard.keycode) {
	case ALLEGRO_KEY_UP:
	keys[0] = false;
	
	break;
	
	case ALLEGRO_KEY_DOWN:
	keys[1] = false;
	
	break;
	
	case ALLEGRO_KEY_LEFT:
	keys[2] = false;
	
	break;
	
	case ALLEGRO_KEY_RIGHT:
	keys[3] = false;
	
	break;
	default:
	break;
	}
	break;
	
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
	
	run = false;
	
	break;
	default:
	break;
	}
	}
	// KEYS
	if (keys[0]) {
		// Coordinate X Y
		coordinate(x,y);
		// Function BOTTOM
		prevent_movement_top(x,y,speed);
	}
	if (keys[1]) {
		// Coordinate X Y
		coordinate(x,y);
		// Function TOP
		prevent_movement_bottom(x,y,speed);
}
	if (keys[2]) {
		// Coordinate X Y
		coordinate(x,y);
		// Function LEFT
		prevent_movement_left(x,y,speed);
	}
	if (keys[3]) {
		// Coordinate X Y
		coordinate(x,y);
		// Function RIGHT
		prevent_movement_right(x,y,speed);
	}
	}
	// Close Display
	ALLEGRO_EVENT event;
	if (!al_is_event_queue_empty(queue)) {
	al_wait_for_event(queue, &event);
	if (event.type == ALLEGRO_EVENT_KEY_UP ||
	event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	run = false;
	}
	
	// Cleanup
	al_destroy_font(score_board_txt);
	al_destroy_font(won_message_txt);
	al_destroy_sample(sample);
	al_destroy_sample(coin_sound);
	al_destroy_sample(pipe_sound);
	al_destroy_sample(victory_sound);
	al_destroy_sample(mamma_mia_sound);
	al_uninstall_keyboard();
	al_destroy_bitmap(bitmap);
	al_destroy_bitmap(mario);
	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_destroy_bitmap(background2);
    return 0;
}
// Function Definition
void menu(){
	al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	al_clear_to_color(al_map_rgba_f(1, 0.8, 0, 1));
	al_draw_bitmap(background2, 501, 666, 0);
	al_draw_bitmap(logo, 195, 80, 0);
	al_flip_display();
	al_rest(5.0);
}
void won_message(){
	// TXT
	al_draw_text(won_message_txt, al_map_rgb(255, 255, 255), screen_width/2, 900/2, ALLEGRO_ALIGN_CENTER, "You Won!");
	// Victory Sound
	al_play_sample(victory_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}
void create_display(){
    // Back (al_draw_bitmap(background, 0, 0, 0);)
    al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	// Coordinate
	float x=0;
	float y=0;
    // TOP-LEFT/BOTTOM-LEFT
    for(int i=0; i<10; i++){
    al_draw_bitmap(bitmap, x, y, 0);
	al_draw_bitmap(bitmap, x, y, 0);
	y+=104;
	}
	// LEFT-TOP/RIGHT-TOP
	x=212;
	y=0;
	for(int i=0; i<16; i++){
		al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	// TOP-RIGHT/BOTTOM-RIGHT
	x=1590;
	y=0;
	for(int i=0; i<10; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		y+=104;
	}
	// LEFT-BOTTOM/RIGHT-BOTTOM
	x=0;
	y=936;
	for(int i=0; i<14; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	
	// OBSTACLE
	// First 1
	x=530;
	y=104;
	for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		y+=104;
	}
	// First 2
	x=106;
	y=624;
	for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	// First 3
	x=954;
	y=104;
	for(int i=0; i<3; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		y+=104;
	}
	// First 4
	x=848;
	y=728;
	for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		y+=104;
	}
	// First 5
	x=1060;
	y=520;
	for(int i=0; i<4; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		y+=104;
	}
	// First 6 13*2
	x=1378;
	y=208;
	for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	// First 7 12*7
	x=1272;
	y=728;
	for(int i=0; i<3; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	// Secondary 1
	x=212;
	y=312;
	for(int i=0; i<4; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	
	// Secondary 2
	x=636;
	y=312;
	for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		x+=106;
	}
	// Secondary 3 11*3
	x=1166;
	y=312;
	for(int i=0; i<3; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
		al_draw_bitmap(bitmap, x, y, 0);
		y+=104;
	}
	// Third 1
	x=742;
	y=416;
	    for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
	al_draw_bitmap(bitmap, x, y, 0);
	y+=104;
	}
	// Third 2
	x=636;
	y=520;
	    for(int i=0; i<3; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
	al_draw_bitmap(bitmap, x, y, 0);
	y+=104;
	}
	// Third 3
	x=424;
	y=416;
	    for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
	al_draw_bitmap(bitmap, x, y, 0);
	y+=104;
	}
	// Third 4
	al_draw_bitmap(bitmap, 212, 208, 0);
	// Third 5 9*5
	al_draw_bitmap(bitmap, 954, 520, 0);
	// Third 6 2*4
	al_draw_bitmap(bitmap, 212, 416, 0);
	// Third 7 4*7
	x=424;
	y=728;
	    for(int i=0; i<2; i++){
	    al_draw_bitmap(bitmap, x, y, 0);
	al_draw_bitmap(bitmap, x, y, 0);
	x+=106;
	}
	// Third 8 12*5
	x=1272;
	y=520;
	for(int i=0; i<2; i++){
	al_draw_bitmap(bitmap, x, y, 0);
	al_draw_bitmap(bitmap, x, y, 0);
	x+=106;
	}
	
}
void prevent_movement_left(float &x, float &y, float &speed){
	// 1
    if (x==80 && y>=0 && y<=530) {
        x=80;
        cout << x;
    } 
    else if (x==80 && y>=710 && y<=850) {
        x=80;
        cout << x;
    }
    // 3
    else if (x==295 && y>=120 && y<=216) {
        x=295;
        cout << x;
    }
    else if (x==295 && y>=408 && y<=511) {
        x=295;
        cout << x;
    }
    // 4
    else if (x==295 && y>=530 && y<=710) {
        x=295;
        cout << x;
    }
    // 6
    else if (x==610 && y>=94 && y<=230) {
        x=610;
        cout << x;
    }
    // 6
    else if (x==507 && y>=408 && y<=610) {
        x=507;
        cout << x;
    }
    // 7
    else if (x==717 && y>=530 && y<=815) {
        x=717;
        cout << x;
    }
    // 8
    else if (x==822 && y>=218 && y<=600) {
        x=822;
        cout << x;
    }
    // 9
    else if (x==930 && y>=642 && y<=850) {
        x=930;
        cout << x;
    }
    // 10
    else if (x==1037 && y>=94 && y<=403) {
        x=1037;
        cout << x;
    }
    // 11
    else if (x==1140 && y>=530 && y<=850) {
        x=1140;
        cout << x;
    }
    // 12
    else if (x==1247 && y>=218 && y<=425) {
        x=1247;
        cout << x;
    }
    // 14
    else if (x==1458 && y>=425 && y<=600) {
        x=1458;
        cout << x;
    }
    else if (x==1458 && y>=850 && y<=1000) {
        x=1458;
        cout << x;
    }
    // ELSE 
	else {
        x -= speed;
        cout << x;
    }
}
void prevent_movement_right(float &x, float &y, float &speed){
	// 3
    if (x==133 && y>=0 && y<=93) {
        x=133;
        cout << x;
    }
    else if (x==133 && y>=120 && y<=506) {
        x=133;
        cout << x;
    }
    // 5
    else if (x==345 && y>=403 && y<=600) {
        x=345;
        cout << x;
    }
    else if (x==345 && y>=642 && y<=828) {
        x=345;
        cout << x;
    }
    // 6 
    else if (x==448 && y>=94 && y<=218) {
        x=448;
        cout << x;
    }
    // 7
    else if (x==557 && y>=430 && y<=828) {
        x=557;
        cout << x;
    }
    // 8
    else if (x==663 && y>=321 && y<=508) {
        x=663;
        cout << x;
    }
    // 9
    else if (x==766 && y>=638 && y<=850) {
        x=766;
        cout << x;
    }
    // 10
    else if (x==874 && y>=0 && y<=405) {
        x=874;
        cout << x;
    }
    else if (x==874 && y>=422 && y<=600) {
        x=874;
        cout << x;
    }
    // 11
    else if (x==978 && y>=600 && y<=850) {
        x=978;
        cout << x;
    }
    // 12
    else if (x==1086 && y>=218 && y<=510) {
        x=1086;
        cout << x;
    }
    // 13
    else if (x==1188 && y>=633 && y<=821) {
        x=1188;
        cout << x;
    }
    // 14 
    else if (x==1294 && y>=111 && y<=300) {
        x=1294;
        cout << x;
    }
    // 15
    else if (x==1510 && y>=0 && y<=1000) {
        x=1510;
        cout << x;
    }
    // ELSE
	else {
        x += speed;
        cout << x;
    }
}
void prevent_movement_top(float &x, float &y, float &speed){
	// 2
    if (y==95 && x>=130 && x<=1510) {
        y=95;
        cout << y;
    }
    // 3
    else if (y==300 && x>=1294 && x<=1510) {
        y=300;
        cout << y;
    }
    else if (y==511 && x>=133 && x<=295) {
        y=511;
        cout << y;
    }
    // 4
    else if (y==408 && x>=133 && x<=822) {
        y=408;
        cout << y;
    }
    else if (y==408 && x>=874 && x<=1037) {
        y=408;
        cout << y;
    }
    // 6
    else if (y==615 && x>=345 && x<=513) {
        y=615;
        cout << y;
    }
    else if (y==615 && x>=874 && x<=1458) {
        y=615;
        cout << y;
    }
    // 7
    else if (y==717 && x>=0 && x<=295) {
        y=717;
        cout << y;
    }
    // 8
    else if (y==824 && x>=345 && x<=717) {
        y=824;
        cout << y;
    }
    else if (y==824 && x>=1188 && x<=1510) {
        y=824;
        cout << y;
    }
    // ELSE
	else {
        y -= speed;
        cout << y;
    }
}
void prevent_movement_bottom(float &x, float &y, float &speed){
	// 4
    if (y==215 && x>=295 && x<=822) {
        y=215;
        cout << y;
    }
    else if(y==215 && x>=1086 && x<=1247) {
        y=215;
        cout << y;
	}
    // 3
	else if(y==112 && x>=130 && x<=295) {
        y=112;
        cout << y;
	}
	else if(y==112 && x>=1294 && x<=1510) {
        y=112;
        cout << y;
	}
	// 6
    else if(y==422 && x>=554 && x<=663) {
        y=422;
        cout << y;
	}
	else if(y==422 && x>=874 && x<=1458) {
        y=422;
        cout << y;
	}
	// 7
    else if(y==522 && x>=0 && x<=295) {
        y=522;
        cout << y;
	}
	// 8
    else if(y==634 && x>=345 && x<=557) {
        y=634;
        cout << y;
	}
	else if(y==634 && x>=766 && x<=930) {
        y=634;
        cout << y;
	}
	else if(y==634 && x>=1188 && x<=1510) {
        y=634;
        cout << y;
	}
	// 10
    else if(y==833 && x>=0 && x<=1458) {
        y=833;
        cout << y;
	}
    // ELSE
	else {
        y += speed;
        cout << y;
    }
}
void coordinate(float &x, float &y){
	cout << "X: "<<x<<endl;
	cout << "Y: "<<y<<endl;
	cout << "\t";
}
int coin_collection(float &x, float &y){
	// Coins Position Formula -> (106*(n-1))+26 o (104*(n-1))+26
	// 2.5
	al_draw_bitmap(coin1, 132, 442, 0);
	// 3.2
    al_draw_bitmap(coin2, 238, 130, 0);
    // 3.9
    al_draw_bitmap(coin3, 238, 858, 0);
    // 4.5
    al_draw_bitmap(coin4, 344, 442, 0);
    // 5.3
    al_draw_bitmap(coin5, 450, 234, 0);
    // 6.7
    al_draw_bitmap(coin6, 556, 650, 0);
    // 7.3
    al_draw_bitmap(coin7, 662, 234, 0);
    // 7.5
    al_draw_bitmap(coin8, 662, 442, 0);
    // 7.9
    al_draw_bitmap(coin9, 662, 858, 0);
    // 9.2
    al_draw_bitmap(coin10, 874, 130, 0);
    // 9.6
    al_draw_bitmap(coin11, 874, 546, 0);
    // 10.9
    al_draw_bitmap(coin12, 980, 858, 0);
    // 11.2
    al_draw_bitmap(coin13, 1086, 130, 0);
    // 11.5
    al_draw_bitmap(coin14, 1086, 442, 0);
    // 12.9
    al_draw_bitmap(coin15, 1192, 858, 0);
    // 13.4
    al_draw_bitmap(coin16, 1298, 338, 0);
    // 15.2
    al_draw_bitmap(coin17, 1510, 130, 0);
    // 15.7
    al_draw_bitmap(coin18, 1510, 650, 0);
    // DOOR
    al_draw_bitmap(door, 1442, 936, 0);
    al_draw_bitmap(door1, 64, -40, 0);
    
    // Coin Covering | Counting
    // Coin1
    if (c1==0) {
    	if ((x>=78 && x<=192) && (y>=384 && y<=500)){
	  	coin1 = al_load_bitmap("Img/Coins/cover_coin1.png");
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL); 
	  	conta++;
	  	c1=1;
		  }
	}
	// Coin2
	if (c2==0) {
    	if ((x>=178 && x<=298) && (y>=72 && y<=188)){
	  	coin2 = al_load_bitmap("Img/Coins/cover_coin1.png");
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL); 
	  	conta++;
	  	c2=1;
		  }
	}
	// Coin3
	if (c3==0) {
    	if ((x>=178 && x<=298) && (y>=800 && y<=916)){
	  	coin3 = al_load_bitmap("Img/Coins/cover_coin1.png");
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL); 
	  	conta++;
	  	c3=1;
		  }
	}
	// Coin4
	if (c4==0) {
    	if ((x>=287 && x<=407) && (y>=384 && y<=500)){
	  	coin4 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c4=1;
		}
	}
	// Coin5
	if (c5==0) {
    	if ((x>=390 && x<=510) && (y>=176 && y<=292)){
	  	coin5 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c5=1;
		}
	}
	// Coin6
	if (c6==0) {
    	if ((x>=496 && x<=616) && (y>=592 && y<=708)){
	  	coin6 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c6=1;
		}
	}
	// Coin7
	if (c7==0) {
    	if ((x>=602 && x<=722) && (y>=176 && y<=292)){
	  	coin7 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c7=1;
		}
	}
	// Coin8
	if (c8==0) {
    	if ((x>=602 && x<=722) && (y>=384 && y<=500)){
	  	coin8 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c8=1;
		}
	}
	// Coin9
	if (c9==0) {
    	if ((x>=602 && x<=722) && (y>=800 && y<=916)){
	  	coin9 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c9=1;
		}
	}
	// Coin10
	if (c10==0) {
    	if ((x>=814 && x<=934) && (y>=72 && y<=188)){
	  	coin10 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c10=1;
		}
	}
	// Coin11
	if (c11==0) {
    	if ((x>=814 && x<=934) && (y>=488 && y<=604)){
	  	coin11 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c11=1;
		}
	}
	// Coin12
	if (c12==0) {
    	if ((x>=920 && x<=1040) && (y>=800 && y<=916)){
	  	coin12 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c12=1;
		}
	}
	// Coin13
	if (c13==0) {
    	if ((x>=1026 && x<=1146) && (y>=72 && y<=188)){
	  	coin13 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c13=1;
		}
	}
	// Coin14
	if (c14==0) {
    	if ((x>=1026 && x<=1146) && (y>=384 && y<=500)){
	  	coin14 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c14=1;
		}
	}
	// Coin15
	if (c15==0) {
    	if ((x>=1132 && x<=1252) && (y>=800 && y<=916)){
	  	coin15 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c15=1;
		}
	}
	// Coin16
	if (c16==0) {
    	if ((x>=1238 && x<=1358) && (y>=280 && y<=396)){
	  	coin16 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c16=1;
		}
	}
	// Coin17
	if (c17==0) {
    	if ((x>=1450 && x<=1570) && (y>=72 && y<=188)){
	  	coin17 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c17=1;
		}
	}
	// Coin18
	if (c18==0) {
    	if ((x>=1450 && x<=1570) && (y>=592 && y<=708)){
	  	coin18 = al_load_bitmap("Img/Coins/cover_coin1.png"); 
	  	al_play_sample(coin_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	conta++;
	  	c18=1;
		}
	}
	// Pipe Sound
    if (c19==0) {
    	if((x=106)&&(x=104)){
    	al_play_sample(pipe_sound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	  	c19=1;
		}
	}
    // Point
	return conta;
}
void movement_iniziale(float &x, float &y){
	while (y!=104) {
    	al_draw_bitmap(mario, x, y+=0.5, 0);
    	al_flip_display();
  	}
  	x=106;
  	y=104;
}
void movement_finale(float &x, float &y){
    if ((x>=1140 && x<=1188) && (y>=824 && y<=833)){
    	// First Animation
    	while (x!=1480) {
    	al_draw_bitmap(mario, x+=0.5, y, 0);
    	al_flip_display();
  		}
  		// Second Animation
  		if(x==1480){
  			while (y!=1040) {
    		al_draw_bitmap(mario, x, y+=0.5, 0);
    		al_flip_display();
			}
		}
	}
}
// SINGH ARSHDEEP -3IA 
