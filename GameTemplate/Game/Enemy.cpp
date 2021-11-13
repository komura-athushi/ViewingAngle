#include "stdafx.h"
#include "Enemy.h"

#include "Player.h"



Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

bool Enemy::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetScale(Vector3::One * 2.0f);
	m_player = FindGO<Player>("player");

	//スフィアコライダーを初期化。
	m_sphereCollider.Create(1.0f);

	return true;
}

void Enemy::Update()
{
	Rotation();
	SearchPlayer();

	m_modelRender.Update();
}

void Enemy::Rotation()
{
	m_rotation.AddRotationDegY(1.0f);
	m_modelRender.SetRotation(m_rotation);

	Vector3 diff = m_player->GetPosition() - m_position;
}

//衝突したときに呼ばれる関数オブジェクト(壁用)
struct SweepResultWall :public btCollisionWorld::ConvexResultCallback
{
	bool isHit = false;						//衝突フラグ。

	virtual	btScalar	addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace)
	{
		//壁とぶつかってなかったら。
		if (convexResult.m_hitCollisionObject->getUserIndex() != enCollisionAttr_Wall) {
			//衝突したのは壁ではない。
			return 0.0f;
		}

		//壁とぶつかったら。
		//フラグをtrueに。
		isHit = true;
		return 0.0f;
	}
};

void Enemy::SearchPlayer()
{
	m_isSearchPlayer = false;

	m_forward = Vector3::AxisZ;
	m_rotation.Apply(m_forward);

	Vector3 playerPosition = m_player->GetPosition();
	Vector3 diff = playerPosition - m_position;

	diff.Normalize();
	float angle = acosf(diff.Dot(m_forward));
	//プレイヤーが視界内に居なかったら。
	if (Math::PI * 0.35f <= fabsf(angle))
	{
		//プレイヤーは見つかっていない。
		return;
	}

	btTransform start, end;
	start.setIdentity();
	end.setIdentity();
	//始点はエネミーの座標。
	start.setOrigin(btVector3(m_position.x, m_position.y + 70.0f, m_position.z));
	//終点はプレイヤーの座標。
	end.setOrigin(btVector3(playerPosition.x, playerPosition.y + 70.0f, playerPosition.z));

	SweepResultWall callback;
	//コライダーを始点から終点まで動かして。
	//衝突するかどうかを調べる。
	PhysicsWorld::GetInstance()->ConvexSweepTest((const btConvexShape*)m_sphereCollider.GetBody(), start, end, callback);
	//壁と衝突した！
	if (callback.isHit == true)
	{
		//プレイヤーは見つかっていない。
		return;
	}

	//壁と衝突してない！！
	//プレイヤー見つけたフラグをtrueに。
	m_isSearchPlayer = true;
}

void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);

	if (m_isSearchPlayer == false)
	{
		m_fontRender.SetText(L"見つからない・・・");
	}
	else
	{
		m_fontRender.SetText(L"見つけた！");
	}
	m_fontRender.Draw(rc);
}