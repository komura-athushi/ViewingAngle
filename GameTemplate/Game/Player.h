#pragma once
class Player: public IGameObject 
{
public:
	Player();
	~Player();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc);
	const Vector3& GetPosition() const
	{
		return m_position;
	}
private:
	/// <summary>
	/// ˆÚ“®ˆ—B
	/// </summary>
	void Move();
	Vector3						m_position;
	Vector3						m_moveSpeed = Vector3::Zero;
	ModelRender					m_modelRender;
	CharacterController			m_characterController;
};

