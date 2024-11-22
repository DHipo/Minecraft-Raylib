#pragma once

#include "raylib.h"
#include <iostream>

class Cube : public Entity {
public:
	Cube(Vector3 position, Vector3 size, Color color = DARKGRAY){
		m_position = position;
		m_size = size;
		m_color = color;
	}

	void draw() override {
		DrawCubeWiresV(m_position, m_size, BLACK);
		DrawCubeV(m_position, m_size, m_color);
	}

	void update() override {
		return;
	}
};
