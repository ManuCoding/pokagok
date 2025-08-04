#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>

#define BG_COLOR     CLITERAL(Color){ 20, 24, 36, 255 }
#define BORDER_COLOR CLITERAL(Color){ 244, 233, 244, 255 }
#define TEXT_COLOR   CLITERAL(Color){ 244, 233, 244, 255 }
#define BAR_HEIGHT   100

typedef struct {
	bool hide_bar;
	int bar_tab;
} Pokagok;

static int winw,winh,apptop;

void draw_bar(int bar_tab) {
	switch(bar_tab) {
		case 0:
			DrawText("Main section woo",0,20,20,TEXT_COLOR);
			break;
		case 1:
			DrawText("Secret section shhhhhhhh",0,20,20,TEXT_COLOR);
			break;
		default:
			char buf[256];
			snprintf(buf,256,"??? Bar state is %d",bar_tab);
			DrawText(buf,winw/2-MeasureText(buf,40)/2,40,40,TEXT_COLOR);
			sprintf(buf,"Click on the bar to set it back to normal ¯\\_(-v-)_/¯");
			DrawText(buf,winw/2-MeasureText(buf,20)/2,80,20,TEXT_COLOR);
	}
	DrawRectangle(0,BAR_HEIGHT-2,winw,2,BORDER_COLOR);
}

int main() {
	InitWindow(1600,900,"Pokagok Studio");
	SetTargetFPS(60);
	Pokagok app={0};
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BG_COLOR);
		winw=GetRenderWidth();
		winh=GetRenderHeight();
		apptop=0;
		if(!app.hide_bar) {
			draw_bar(app.bar_tab);
			apptop+=BAR_HEIGHT;
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
