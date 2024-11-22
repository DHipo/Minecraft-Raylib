#pragma once

#include "raylib.h"
#include "Cube.h"
#include "Entity.h"
#include <vector>

class Chunk : public Entity {
public:
	Chunk(Vector2 _position, Vector2 _size = {16,16}) {
		m_size = _size;
		m_position = _position;

		for (int z = 0; z < m_size.y; z++){
			for (int x = 0; x < m_size.x; x++)
				m_cubes.push_back(
					new Cube({ x * 2.f + m_position.x, 0.f, z * 2.f + m_position.y}, {2.f,2.f,2.f})
					);
		}
	}

	void draw() override {
		for (int y = 0; y < m_size.y; y++)
			for (int x = 0; x < m_size.x; x++)
				m_cubes[x + y * m_size.x]->draw();

	}
	void update() override {return;}

private:
	Vector2 m_size = {16, 16};
	Vector2 m_position = {0,0};
	std::vector<Cube*> m_cubes;
};
