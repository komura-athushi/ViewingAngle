#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{

}

Wall::~Wall()
{

}

bool Wall::Start()
{
	m_modelRender.Init("Assets/modelData/wall.tkm");
	m_modelRender.SetPosition(Vector3(0.0f,0.0f,100.0f));
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	m_physicsStaticObject.GetbtCollisionObject()->setUserIndex(enCollisionAttr_Wall);
	return true;
}

void Wall::Udpate()
{

}

void Wall::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}