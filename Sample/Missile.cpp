
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

					        Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

namespace Sample
{
	Missile::Missile()
	{
		SetSpeed(320);
		SetDamage(3);
		SetTurnSpeed(Math::PI);
		Deactivate();
		SetCollisionRadius(15);
		SetRange(200);
	}


	void Missile::Update(const GameTime *pGameTime)
	{
		if (IsActive())
		{
			m_pAnimation->Update(pGameTime);
			m_targetingDelayFrames--;

			if (GetTarget() && !GetTarget()->IsActive())
			{
				SetTarget();
			}

			if (!GetTarget() && m_targetingDelayFrames <= 0)
			{
				Vector2 seek = GetPosition() + m_targetingOffset;
				SetTarget(GetCurrentLevel()->GetClosestObject<ShooterLibrary::EnemyShip>(seek, m_range));
				ResetTargetingDelay();
			}

			if (GetTarget())
			{
				Vector2 targetDirection = m_pTarget->GetPosition() - GetPosition();
				targetDirection.Normalize();

				float dot = targetDirection.DotProduct(GetDirection().Left());
				float turn = m_turnSpeed * pGameTime->GetTimeElapsed();

				m_angle += (dot > 0) ? turn : -turn;
				SetDirection(Vector2(cos(m_angle), sin(m_angle)));

				// remove jitter
				float newDot = targetDirection.DotProduct(GetDirection().Left());
				if (newDot * dot < 0)
				{
					SetDirection(targetDirection);
					m_angle = atan2f(GetDirection().Y, GetDirection().X);
				}
			}
			
			Projectile::Update(pGameTime);
			
			if (IsActive() && m_pEmitter)
			{
				m_pEmitter->SetOutput(1);
				m_pEmitter->SetPosition(GetPosition() - GetDirection() * 18);
				m_pEmitter->Update(pGameTime);
			}
		}
	}


	void Missile::Draw(SpriteBatch *pSpriteBatch)
	{
		if (m_pAnimation)
		{
			Vector2 center = m_pAnimation->GetFrame(0)->GetCenter();
			pSpriteBatch->Draw(m_pAnimation, GetPosition(), Color::White, center, Vector2::One * 0.75f, m_angle);
		}
	}


	void Missile::Activate(const Vector2 &position, bool wasShotByPlayer)
	{
		ResetTargetingDelay();
		SetTarget();

		Projectile::Activate(position, wasShotByPlayer);

		if (wasShotByPlayer)
		{
			SetDirection(-Vector2::UnitY);
			SetAngle(-0.5f * Math::PI);
		}

		m_targetingOffset = GetDirection() * 50;
		Vector2 emitterPosition = GetPosition() - GetDirection() * 18;
		m_pEmitter->SetPosition(emitterPosition);
	}
}
