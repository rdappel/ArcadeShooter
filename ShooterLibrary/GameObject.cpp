
#include "ShooterLibrary.h"

namespace ShooterLibrary
{
	int GameObject::s_count = 0;
	Level *GameObject::s_pCurrentLevel = nullptr;

	GameObject::GameObject()
	{
		m_index = s_count;
		s_count++;

		m_isActive = false;
		m_collisionRadius = 0;
	}

	void GameObject::Update(const GameTime *pGameTime)
	{
		if (IsActive() && s_pCurrentLevel)
		{
			s_pCurrentLevel->UpdateSectorPosition(this);
		}
	}

	Vector2 GameObject::GetHalfDimensions() const
	{
		return Vector2(m_collisionRadius, m_collisionRadius);
	}

	void GameObject::SetPosition(const float x, const float y)
	{
		m_previousPosition = m_position;
		m_position.Set(x, y);
	}

	void GameObject::SetPosition(const Vector2 &position)
	{
		SetPosition(position.X, position.Y);
	}

	void GameObject::TranslatePosition(const float x, const float y)
	{
		SetPosition(m_position.X + x, m_position.Y + y);
	}

	void GameObject::TranslatePosition(const Vector2 &offset)
	{
		TranslatePosition(offset.X, offset.Y);
	}
}