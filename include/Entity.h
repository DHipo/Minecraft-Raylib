#pragma once

#include "raylib.h"
#include <string>

class Entity {
public:
	Entity() = default;

	virtual void draw(){return;};
	virtual void update(){return;};

protected:
	Vector3 m_position;
	Vector3 m_size = {2.f, 2.f, 2.f};
	Color m_color;
};
