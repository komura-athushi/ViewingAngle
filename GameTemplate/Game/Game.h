#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Background;
class Wall;
class Enemy;

class Game : public IGameObject
{
public:
	Game() {}
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	Player*					m_player = nullptr;
	GameCamera*				m_gameCamera = nullptr;
	Background*				m_background = nullptr;
	SkyCube*				m_skyCube = nullptr;
	Wall*					m_wall = nullptr;
	Enemy*					m_enemy = nullptr;
};

