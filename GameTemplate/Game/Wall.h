#pragma once
class Wall : public IGameObject
{
public:
	Wall();
	~Wall();
	bool Start();
	void Udpate();
	void Render(RenderContext& rc);
private:
	ModelRender					m_modelRender;
	PhysicsStaticObject			m_physicsStaticObject;
};

