#pragma once

#include "../Action.h"

namespace ai
{
	class UseItemAction : public Action {
	public:
		UseItemAction(PlayerbotAI* ai, string name = "use", bool selfOnly = false) : Action(ai, name), selfOnly(selfOnly) {}

    public:
        virtual bool Execute(Event event);
        virtual bool isPossible();
        bool setTargetMainhand();
        bool setTargetOffhand();
    private:
        bool UseItemAuto(Item* item);
        bool UseItemOnGameObject(Item* item, ObjectGuid go);
        bool UseItemOnItem(Item* item, Item* itemTarget);
        bool UseItem(Item* item, ObjectGuid go, Item* itemTarget);
        bool UseGameObject(ObjectGuid guid);
        bool SocketItem(Item* item, Item* gem, bool replace = false);
    private:
        bool selfOnly;
        Item* actionTarget;
    };

    class UseSpellItemAction : public UseItemAction {
    public:
        UseSpellItemAction(PlayerbotAI* ai, string name, bool selfOnly = false) : UseItemAction(ai, name, selfOnly) {}

    public:
        virtual bool isUseful();
    };

    class UseHealingPotion : public UseItemAction {
    public:
        UseHealingPotion(PlayerbotAI* ai) : UseItemAction(ai, "healing potion") {}
        virtual bool isUseful() { return AI_VALUE2(bool, "combat", "self target"); }
    };

    class UseManaPotion : public UseItemAction
    {
    public:
        UseManaPotion(PlayerbotAI* ai) : UseItemAction(ai, "mana potion") {}
        virtual bool isUseful() { return AI_VALUE2(bool, "combat", "self target"); }
    };

    class UseInstantPoisonMainHand : public UseItemAction
    {
    public:
        UseInstantPoisonMainHand(PlayerbotAI* ai) : UseItemAction(ai, "instant poison") {setTargetMainhand();}
    };

    class UseInstantPoisonOffHand : public UseItemAction
    {
    public:
        UseInstantPoisonOffHand(PlayerbotAI* ai) : UseItemAction(ai, "instant poison") {setTargetOffhand();}
    };

    class UseDeadlyPoisonMainHand : public UseItemAction
    {
    public:
        UseDeadlyPoisonMainHand(PlayerbotAI* ai) : UseItemAction(ai, "deadly poison") {setTargetMainhand();}
    };

    class UseDeadlyPoisonOffHand : public UseItemAction
    {
    public:
        UseDeadlyPoisonOffHand(PlayerbotAI* ai) : UseItemAction(ai, "deadly poison") {setTargetOffhand();}
    };

    class UseWoundPoisonMainHand : public UseItemAction
    {
    public:
        UseWoundPoisonMainHand(PlayerbotAI* ai) : UseItemAction(ai, "wound poison") {setTargetMainhand();}
    };

    class UseWoundPoisonOffHand : public UseItemAction
    {
    public:
        UseWoundPoisonOffHand(PlayerbotAI* ai) : UseItemAction(ai, "wound poison") {setTargetOffhand();}
    };

    class UseCripplingPoisonMainHand : public UseItemAction
    {
    public:
        UseCripplingPoisonMainHand(PlayerbotAI* ai) : UseItemAction(ai, "crippling poison") {setTargetMainhand();}
    };

    class UseCripplingPoisonOffHand : public UseItemAction
    {
    public:
        UseCripplingPoisonOffHand(PlayerbotAI* ai) : UseItemAction(ai, "crippling poison") {setTargetOffhand();}
    };

    class UseMindNumbingPoisonMainHand : public UseItemAction
    {
    public:
        UseMindNumbingPoisonMainHand(PlayerbotAI* ai) : UseItemAction(ai, "mind-numbing poison") {setTargetMainhand();}
    };

    class UseMindNumbingPoisonOffHand : public UseItemAction
    {
    public:
        UseMindNumbingPoisonOffHand(PlayerbotAI* ai) : UseItemAction(ai, "mind-numbing poison") {setTargetOffhand();}
    };

}
