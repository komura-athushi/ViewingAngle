#pragma once

class Player;

class Enemy :public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	void Rotation();
	void SearchPlayer();
	ModelRender				m_modelRender;
	Quaternion				m_rotation;
	Vector3					m_position = Vector3(0.0f, 0.0f, -100.0f);
	Vector3					m_forward;
	Player*					m_player = nullptr;
	bool					m_isSearchPlayer = false;
	FontRender				m_fontRender;
	SphereCollider			m_sphereCollider;							//コライダー。
	RigidBody				m_rigidBody;						//剛体。		
};

