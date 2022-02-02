
/*                '888 88888888888 888888888',8888'
					88 888888888888 8888888',8888'
					 8 8888             ,8',8888'
		  ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
		  /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
		 / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
		/ /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
		\_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
	  ============== 8 8888 ===== ,8',8888' ===============
					88 8888      ,8',8888888888888
				   ,88 8888     ,8',888888888888888,

						   ファイナル ゼロ

			   Guardian FZ © 2017 - Shuriken Studios LLC          */

#include "GuardianFinalZero.h"

namespace GuardianFinalZero
{
	Missile::Missile()
	{
		SetSpeed(350);
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
			pSpriteBatch->Draw(m_pAnimation, GetPosition(), Color::White, center, Vector2::ONE * 0.75f, m_angle);
		}
	}


	void Missile::Activate(const Vector2 &position, bool wasShotByPlayer)
	{
		ResetTargetingDelay();
		SetTarget();

		Projectile::Activate(position, wasShotByPlayer);

		if (wasShotByPlayer)
		{
			SetDirection(-Vector2::UNIT_Y);
			SetAngle(-0.5f * Math::PI);
		}

		m_targetingOffset = GetDirection() * 50;
		Vector2 emitterPosition = GetPosition() - GetDirection() * 18;
		m_pEmitter->SetPosition(emitterPosition);
	}
}
