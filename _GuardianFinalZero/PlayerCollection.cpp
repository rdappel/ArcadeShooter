
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
    PlayerCollection::PlayerCollection()
    {
        for (uint8_t i = 0; i < MAX_PLAYERS; i++) m_pPlayerShips[i] = nullptr;
        InitializeShip(0);
    }

    void PlayerCollection::HandleInput(const InputState* pInput)
    {
        int8_t playerIndex = -1;
        if (pInput->IsNewButtonPress(Button::START, playerIndex))
        {
            if (playerIndex >= 0 && !m_pPlayerShips[playerIndex])
            {
                InitializeShip(playerIndex);
            }
        }
    }

    void PlayerCollection::InitializeShip(uint8_t index)
    {
        PlayerShip* pShip = new PlayerShip(index);


        Blaster* pBlaster = new Blaster(true);
        pBlaster->SetTriggerType(TriggerType::SECONDARY);
        /*
        TriggerType *t0 = new TriggerType(0);
        TriggerType *t1 = new TriggerType(1);
        TriggerType *t2 = new TriggerType(2);
*/
        pShip->AttachWeapon(pBlaster, Vector2(0, 0));

        m_pPlayerShips[index] = pShip;
    }
}