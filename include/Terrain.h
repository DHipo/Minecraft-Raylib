#pragma once

#include "raylib.h"
#include "Chunk.h"
#include "Entity.h"
#include <vector>

class Terrain : public Entity {
public:
	Terrain(){
		m_chunks.push_back(new Chunk({0,0}));
	}

	void draw() override {
		for(Chunk* chunk : m_chunks)
			chunk->draw();
	}

	void update() override {return;}

	void generateNewChunk() {
		m_chunks.push_back(new Chunk({(float)m_chunks.size() * 16 * 2,0}));
	}
private:
	std::vector<Chunk*> m_chunks;
};
