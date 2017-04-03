
#include "Sample.h"

namespace Sample
{
	Texture *PowerUp::s_pTexture = nullptr;
	Texture *PowerUp::s_pGlowTexture = nullptr;

	PowerUp::PowerUp()
	{
		SetCollisionRadius(1);
	}

	void PowerUp::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			TranslatePosition(m_velocity);
		}

		GameObject::Update(pGameTime);
	}

	void PowerUp::Draw(const GameTime *pGameTime)
	{
		float alpha = ((sin(pGameTime->GetTotalTime() * 4) + 1) / 8) + 0.75f;
		Color c = Color::Orange * alpha;

		GetSpriteBatch()->Draw(s_pGlowTexture, GetPosition(), c, s_pTexture->GetSize() / 2, Vector2::One / 2);
		GetSpriteBatch()->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetSize() / 2, Vector2::One / 2);
	}

	void PowerUp::Activate(const Vector2 position)
	{
		m_velocity = Vector2::GetRandom(true);

		GameObject::Activate();
		SetPosition(position);
	}

	PowerUp *PowerUp::Resolve(GameObject *pGameObject1, GameObject *pGameObject2)
	{
		if (pGameObject1->HasMask(POWER_UP)) return static_cast<PowerUp *>(pGameObject1);
		if (pGameObject2->HasMask(POWER_UP)) return static_cast<PowerUp *>(pGameObject2);
	}
}