
/*   .oooooo..o       .o.       ooo        ooooo ooooooooo.   ooooo        oooooooooooo
	d8P'    `Y8      .888.      `88.       .888' `888   `Y88. `888'        `888'     `8
	Y88bo.          .8"888.      888b     d'888   888   .d88'  888          888
	 `"Y8888o.     .8' `888.     8 Y88. .P  888   888ooo88P'   888          888oooo8
		 `"Y88b   .88ooo8888.    8  `888'   888   888          888          888    "
	oo     .d8P  .8'     `888.   8    Y     888   888          888       o  888       o
	8""88888P'  o88o     o8888o o8o        o888o o888o        o888ooooood8 o888ooooood8

							Sample © 2017 - Shuriken Studios LLC                          */

#include "Sample.h"

using ShooterLibrary::Projectile;

namespace Sample
{

	PlayerShip::PlayerShip(const uint8_t playerIndex)
		: ShooterLibrary::PlayerShip(playerIndex)
	{
		SetSpeed(450);
		m_isAIControlled = false;

		Color colors[4] = { Color::Red, Color::DarkGreen, Color::Purple, Color::Yellow };
		m_color = colors[playerIndex];

		for (int i = 0; i < 3; i++) m_thrusterOffset[i] = Vector2::Zero;
		m_thrusterScale = 1;
	}


	void PlayerShip::LoadContent(ResourceManager *pResourceManager)
	{
		std::string shipPath;
		std::string colorPath;

		Blaster *pBlaster = (Blaster *)GetWeapon(0);

		switch (GetPlayerIndex())
		{
		//case 1:
		//	shipPath = "Animations\\PlayerShip02.anim";
		//	colorPath = "Animations\\PlayerShip02_Color.anim";
		//	pBlaster->SetCooldownSeconds(0.67);
		//	m_thrusterOffset[0] = Vector2(-2, 16);
		//	SetSpeed(400);
		//	break;
		//case 2:
		//	shipPath = "Animations\\PlayerShip03.anim";
		//	colorPath = "Animations\\PlayerShip03_Color.anim";
		//	m_thrusterOffset[0] = Vector2(-10, 3);
		//	m_thrusterOffset[1] = Vector2(  7, 3);
		//	m_thrusterScale = 0.5f;
		//	pBlaster->SetCooldownSeconds(0.43);
		//	SetSpeed(510);
		//	break;
		case 3:
			shipPath = "Animations\\PlayerShip04.anim";
			colorPath = "Animations\\PlayerShip04_Color.anim";
			m_thrusterOffset[0] = Vector2(-10, 6);
			m_thrusterOffset[1] = Vector2(  7, 6);
			m_thrusterScale = 0.8f;
			pBlaster->SetCooldownSeconds(0.56);
			GetWeapon(0)->Dectivate();
			GetWeapon(1)->Activate();
			GetWeapon(2)->Activate();
			SetSpeed(480);
			break;
		default:
			shipPath = "Animations\\PlayerShip01.anim";
			colorPath = "Animations\\PlayerShip01_Color.anim";
			m_thrusterOffset[0] = Vector2(-2, 14);
			pBlaster->SetCooldownSeconds(0.61);
			SetSpeed(450);
		}

		m_pAnimation = pResourceManager->Load<Animation>(shipPath);
		m_pAnimation->SetTexture(pResourceManager->Load<Texture>("Textures\\PlayerShips.png"));
		m_pAnimation->Stop();
		m_pAnimation->SetCurrentFrame(1);

		m_pColorAnimation = pResourceManager->Load<Animation>(colorPath);
		m_pColorAnimation->SetTexture(pResourceManager->Load<Texture>("Textures\\PlayerShips.png"));
		m_pColorAnimation->Stop();
		m_pColorAnimation->SetCurrentFrame(1);

		m_pThrusterAnimation = pResourceManager->Load<Animation>("Animations\\Thruster.anim");
		m_pThrusterAnimation->SetTexture(pResourceManager->Load<Texture>("Textures\\Thruster01.png"));
		m_pThrusterAnimation->Play();
	}


	void PlayerShip::Initialize(Level *pLevel)
	{
		m_pLevel = pLevel;
		float spacing = Game::GetScreenWidth() / (pLevel->GetPlayerCount() + 1);
		float x = (GetPlayerIndex() + 1) * spacing;
		float y = Game::GetScreenHeight() + 100;
		SetPosition(x, y);
		SetAITarget(Vector2(x, y - 300));
	}


	void PlayerShip::HandleInput(const InputState *pInput)
	{
		if (!m_isAIControlled) ShooterLibrary::PlayerShip::HandleInput(pInput);
	}


	void PlayerShip::Update(const GameTime *pGameTime)
	{
		if (m_pThrusterAnimation) m_pThrusterAnimation->Update(pGameTime);

		if (m_isAIControlled)
		{
			Vector2 targetBefore = m_targetPosition - GetPosition();
			targetBefore.Normalize();

			SetDesiredDirection(targetBefore);
			ShooterLibrary::PlayerShip::Update(pGameTime);

			Vector2 targetAfter = m_targetPosition - GetPosition();
			targetAfter.Normalize();

			if (targetBefore.DotProduct(targetAfter) <= 0)
			{
				SetPosition(m_targetPosition);
				m_isAIControlled = false;
				ConfineToScreen();
			}
		}
		else
		{
			ShooterLibrary::PlayerShip::Update(pGameTime);
		}

		int frame = 1;
		if (GetDesiredDirection().X > 0) frame++;
		if (GetDesiredDirection().X < 0) frame--;

		m_pAnimation->SetCurrentFrame(frame);
		m_pColorAnimation->SetCurrentFrame(frame);
	}


	void PlayerShip::Draw(SpriteBatch *pSpriteBatch)
	{
		Vector2 origin(m_pThrusterAnimation->GetCurrentFrame()->Width / 2, 0);
		for (int i = 0; i < 3; i++)
		{
			if (m_thrusterOffset[i].IsZero()) break;
			Vector2 position = GetPosition() + m_thrusterOffset[i];
			pSpriteBatch->Draw(m_pThrusterAnimation, position, Color::White, origin, Vector2::One * m_thrusterScale, 0, 0.001 * GetPlayerIndex());
		}

		Region frame = *(m_pAnimation->GetCurrentFrame());
		frame.X = 0;
		frame.Y = 0;
		pSpriteBatch->Draw(m_pColorAnimation, GetPosition(), m_color, frame.GetCenter(), Vector2::One * m_scale, 0, 0.98 + 0.001 * GetPlayerIndex());
		pSpriteBatch->Draw(m_pAnimation, GetPosition(), Color::White, frame.GetCenter(), Vector2::One * m_scale, 0, 0.99 + 0.001 * GetPlayerIndex());

	}


	void PlayerShip::Hit(const float damage)
	{
		ShooterLibrary::PlayerShip::Hit(damage);

		if (!IsActive())
		{
			Level *pLevel = (Level *)GetCurrentLevel();
			pLevel->SpawnExplosion(GetPosition(), 1);
		}
	}


	Vector2 PlayerShip::GetHalfDimensions() const
	{
		Region frame = *(m_pAnimation->GetCurrentFrame());
		frame.X = 0;
		frame.Y = 0;
		return frame.GetCenter() * m_scale;
	}

}