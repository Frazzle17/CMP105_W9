#pragma once
#include "Framework/GameObject.h"
class Ball:public GameObject
{
public:
	Ball();
	~Ball();

	virtual void update(float dt);
};

