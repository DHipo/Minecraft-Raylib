#pragma once

#include "raylib.h"
#include "Entity.h"
#include "Game.h"
#include "Terrain.h"
#include <string>
#include <vector>

#define DEFAULT_WINDOW_SIZE {1280,720}
#define WINDOW_TITLE "MinecraftProject"

struct WindowInfo {
	Vector2 size;
	std::string title;
};

class App {
public:
	App() = default;

	void run();
	void handleEvents();
	void init();
	void update();
	void render();


private:
	void createEntities();

	bool running = true;	
	Camera camera = {0};
	WindowInfo window = {DEFAULT_WINDOW_SIZE, WINDOW_TITLE};
	Game game;
};
