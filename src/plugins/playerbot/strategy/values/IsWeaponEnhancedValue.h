#pragma once
#include "../Value.h"

namespace ai
{
    class IsMainhandEnhancedValue : public BoolCalculatedValue, public Qualified
	{
	public:
        IsMainhandEnhancedValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        virtual bool Calculate()
        {
            Item* weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
            if (!weapon)
                return true;
            else return (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0);
        }
    };

    class IsOffhandEnhancedValue : public BoolCalculatedValue, public Qualified
	{
	public:
        IsOffhandEnhancedValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        virtual bool Calculate()
        {
            Item* weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if (!weapon)
                return true;
            else return (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0);
        }
    };
}
