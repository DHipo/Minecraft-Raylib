#pragma once

#include "raylib.h"
#include "Terrain.h"
#include <vector>

class Game {
public:
	Game() = default;

	void addEntity(Entity& _entity){
		m_entities.push_back(&_entity);
	}
	
	void addEntity(Entity* _entity){
		m_entities.push_back(_entity);
	}

	Terrain& getTerrain() { return m_terrain;}
	std::vector<Entity*>& getEntities() {return m_entities;}

private:
	std::vector<Entity*> m_entities;
	Terrain m_terrain;
};
