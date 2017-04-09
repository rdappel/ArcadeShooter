
#include "Sample.h"

namespace Sample
{

	Texture *Missile::s_pTexture;

	Missile::Missile()
	{
		SetSpeed(400);
		SetDamage(3);
		Deactivate();
		SetCollisionRadius(15);
		SetRange(140);
		SetTarget();
		SetTargetingDelay(0.5f);


		//m_pAnimation = new Animation(2);
		//m_pAnimation->Play(true);
	}

	void Missile::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			//m_pAnimation->Update(pGameTime);

			if (m_currentTargetingDelay > 0) m_currentTargetingDelay -= pGameTime->GetTimeElapsed();

			if (GetTarget() && !GetTarget()->IsActive()) SetTarget();

			if (!GetTarget() && m_currentTargetingDelay <= 0)
			{
				Vector2 seek = GetPosition() + m_targetingOffset;
				SetTarget(GetCurrentLevel()->GetClosestObject<ShooterLibrary::EnemyShip>(seek, m_range));
			}

			if (GetTarget())
			{
				Vector2 targetDirection = m_pTarget->GetPosition() - GetPosition();
				targetDirection.Normalize();

				float dot = targetDirection.DotProduct(m_direction.Left());
				float turn = m_turnSpeed * pGameTime->GetTimeElapsed();

				m_angle += (dot > 0) ? turn : -turn;
				m_direction.Set(cos(m_angle), sin(m_angle));

				// remove jitter
				float newDot = targetDirection.DotProduct(m_direction.Left());
				if (newDot * dot < 0)
				{
					m_direction = targetDirection;
					m_angle = atan2f(m_direction.Y, m_direction.X);
				}
			}
			
			Projectile::Update(pGameTime);

			//if (IsActive())
			//{
			//	m_pEmitter->SetOutput(1);
			//	m_pEmitter->SetPosition(m_position + (m_direction * -18));
			//	m_pEmitter->Update(pGameTime);
			//}
		}
	}

	void Missile::Draw(const GameTime *pGameTime)
	{
		if (s_pTexture)
		{
			/*
			int index = m_pAnimation->GetCurrentFrame();
			int sw = 70;
			int sh = 15;
			int sx = index % (70 / sw);
			int sy = index / (70 / sw);
			int dx = (int)m_position.X;
			int dy = (int)m_position.Y;
			ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

			al_draw_tinted_scaled_rotated_bitmap_region(
				s_pTexture, sw * sx, sh * sy, sw, sh, color,
				sw / 2, sh / 2, dx, dy, 1, 1, m_angle, 0);*/
		}
	}

	void Missile::Activate(const Vector2 &position, bool wasShotByPlayer)
	{
		GameObject::Activate();

		m_currentTargetingDelay = m_targetingDelaySeconds;
		SetTarget();

		Projectile::Activate(position, wasShotByPlayer);

		if (wasShotByPlayer)
		{
			SetDirection(-Vector2::UnitY);
			SetAngle(-2 * Math::PI);
		}

		m_targetingOffset = m_direction * 50;
	}
}
