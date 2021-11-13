#include "stdafx.h"
#include "Game.h"

#include "Player.h"
#include "GameCamera.h"
#include "Background.h"
#include "Wall.h"
#include "Enemy.h"

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	DeleteGO(m_background);
	DeleteGO(m_wall);
}

bool Game::Start()
{
	m_player = NewGO<Player>(0, "player");
	m_gameCamera = NewGO<GameCamera>(0, "gameCamera");
	m_background = NewGO<Background>(0, "background");
	m_wall = NewGO<Wall>(0, "wall");
	m_enemy = NewGO<Enemy>(0, "enemy");

	m_skyCube = NewGO<SkyCube>(0, "skycube");
	m_skyCube->SetScale(Vector3::One * 200.0f);
	m_skyCube->SetType(enSkyCubeType_Night);
	return true;
}

void Game::Update()
{

}

void Game::Render(RenderContext& rc)
{

}