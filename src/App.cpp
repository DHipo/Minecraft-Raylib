#include "../include/App.h"

void App::run() {
	
	while(running){
		handleEvents();
		update();

		render();
	}

	CloseWindow();        // Close window and OpenGL context
}

void App::createEntities()
{
	game.addEntity(new Cube({.0f, .0f, .0f}, {2.f, 2.f, 2.f}));
}

void App::init() {
	InitWindow(window.size.x, window.size.y, window.title.c_str());
	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    DisableCursor();                    // Limit cursor to relative movement inside the window

	createEntities();
}

void App::handleEvents(){
	if (WindowShouldClose()) running = false;
    if (IsKeyPressed('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
}

void App::update(){
	UpdateCamera(&camera, CAMERA_FREE);
}

void App::render(){
	BeginDrawing();
		ClearBackground(RAYWHITE);
	
		//Draw entities
		BeginMode3D(camera);
			for (Entity* e : game.getEntities())
				e->draw();
			DrawGrid(10, 10.f);
		EndMode3D();

		//Draw text
		DrawRectangle( 10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
		DrawRectangleLines( 10, 10, 320, 93, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);

	EndDrawing();
}
