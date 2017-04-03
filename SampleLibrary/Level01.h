
#pragma once

namespace Sample
{
	class Level01 : public Level
	{

	public:

		Level01();
		virtual ~Level01() { }

		virtual void LoadContent();

		virtual void Update(const GameTime *pGameTime);

	private:

		float m_POWERUPTEST = 1;

	};
}