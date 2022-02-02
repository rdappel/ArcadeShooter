
#pragma once

namespace GuardianFinalZero
{
	class AIController : public ShipController
	{

	public:

		AIController() { }
		AIController(Ship* pShip) : ShipController(pShip) { }
		virtual ~AIController() { }

		virtual void Update(const GameTime* pGameTime) { }

	};
}