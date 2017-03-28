#pragma once

#include "ShooterLibrary.h"
#include "SampleLevel.h"

class SamplePlayerShip : public PlayerShip
{

public:

	SamplePlayerShip();
	virtual ~SamplePlayerShip() { }

	virtual void Fire();

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void SetSampleLevel(SampleLevel *pLevel) { m_pLevel = pLevel; }

	virtual void SetThrusterAnimation(Animation *pAnimation) { m_pThrusterAnimation = pAnimation; }

	virtual bool CanFire() const { return (m_coolDownTime <= 0); }

protected:

	//virtual float GetSpeed() const { return PlayerShip::GetSpeed(); }

	virtual float GetResponsiveness() const;


private:

	SampleLevel *m_pLevel;

	Animation *m_pThrusterAnimation;

	float m_coolDownTime;

};