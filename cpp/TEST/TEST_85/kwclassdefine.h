#ifndef KW_CLASS_DEFINE_HPP
#define KW_CLASS_DEFINE_HPP

#include <string>
namespace KWFrame
{
class AccumulatedSignIn
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RewardData();
    static const std::string& ObjectType();
    static const std::string& ObjectValue();
};

class AccumulatedSignInGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& WitchShow();
    static const std::string& ActivePrama();
};

class ActiveControl
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ActiveType();
    static const std::string& ActiveTypePrama();
    static const std::string& ShowConditionType();
    static const std::string& ShowCondition();
    static const std::string& UnlockConditionType();
    static const std::string& UnlockCondition();
    static const std::string& ExecuteConditionType();
    static const std::string& ExecuteCondition();
    static const std::string& EndConditionType();
    static const std::string& EndCondition();
    static const std::string& CloseConditionType();
    static const std::string& CloseCondition();
    static const std::string& ChangeMark();
};

class ActiveMission
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& UnlockCondition();
    static const std::string& ObjectType();
    static const std::string& ObjectValue();
    static const std::string& ActiveValue();
    static const std::string& Skip();
};

class AttrData
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& BasicFight();
    static const std::string& MagicHue();
    static const std::string& Hp();
    static const std::string& Attack();
    static const std::string& Defence();
    static const std::string& Speed();
    static const std::string& Crit();
    static const std::string& CritDmg();
    static const std::string& Hit();
    static const std::string& Resist();
    static const std::string& HurtFluctuation();
};

class AttrGrowth
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& AttrGrowth1();
    static const std::string& AttrGrowth2();
    static const std::string& AttrGrowth3();
    static const std::string& AttrGrowth4();
    static const std::string& AttrGrowth5();
    static const std::string& AttrGrowth6();
    static const std::string& AttrGrowth7();
    static const std::string& AttrGrowth8();
    static const std::string& AttrGrowth9();
    static const std::string& AttrGrowth10();
    static const std::string& AttrGrowth11();
};

class BTLBattle
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Label();
    static const std::string& Scene();
    static const std::string& Feature();
    static const std::string& MemberNum();
    static const std::string& JoinCondition();
    static const std::string& NpcData();
    static const std::string& Operable();
    static const std::string& BanWitches();
    static const std::string& BanSkills();
    static const std::string& EnemyData();
    static const std::string& Fight();
    static const std::string& FightFix();
    static const std::string& WinCondition();
    static const std::string& LoseCondition();
    static const std::string& StarCondition();
    static const std::string& MaxRound();
    static const std::string& ClashReward();
    static const std::string& BattleSetData();
    static const std::string& BattleTrigger();
    static const std::string& TriggerDisposable();
    static const std::string& MercenarySwitch();
    static const std::string& FieldSkill();
    static const std::string& WitchFieldSkill();
};

class BTLBeyondThreshold
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Reduce();
    static const std::string& ReduceRate();
};

class BTLBuff
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Gain();
    static const std::string& Type();
    static const std::string& SubType();
    static const std::string& MaxNum();
    static const std::string& Weight();
    static const std::string& Event();
    static const std::string& EffectType();
    static const std::string& Rate();
    static const std::string& LazyEffects();
    static const std::string& Time();
    static const std::string& Level();
    static const std::string& Effects();
};

class BTLCond
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& Data();
};

class BTLEffect
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Source();
    static const std::string& Type();
    static const std::string& TypeData();
    static const std::string& HitRateType();
    static const std::string& HitRate();
};

class BTLEvent
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& Data();
};

class BTLSkill
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RelationSkill();
    static const std::string& AffiliateSkill();
    static const std::string& Type();
    static const std::string& Event();
    static const std::string& Condition();
    static const std::string& CastChance();
    static const std::string& TargetCamp();
    static const std::string& TargetNumberType();
    static const std::string& TargetNumberData();
    static const std::string& MainTargetAi();
    static const std::string& AdditionalTargetAi();
    static const std::string& GuaranteeCrit();
    static const std::string& Effects();
    static const std::string& Rate();
    static const std::string& DirectorId();
    static const std::string& UnlockConditions();
    static const std::string& UnlockMartial();
    static const std::string& UnlockCost();
    static const std::string& NextSkill();
    static const std::string& CurLv();
    static const std::string& MaxLv();
    static const std::string& BasicFight();
    static const std::string& Cd();
    static const std::string& Cost();
    static const std::string& ConditionCost();
    static const std::string& UseTimes();
    static const std::string& LevelUp();
};

class BTLSkillLvlUp
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Rate();
    static const std::string& MaxLv();
};

class BTLTargetAi
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& TargetOrderType();
    static const std::string& TargetOrderData();
};

class BTLTeam
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Index();
    static const std::string& UnlockConditionType();
    static const std::string& UnlockConditionData();
    static const std::string& TeamGroupID();
};

class BTLTeamGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
};

class BTLThreshold
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& DefenceThreshold();
};

class BanWord
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Word();
};

class BattleGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& UniqueId();
    static const std::string& StartTime();
    static const std::string& EndTime();
    static const std::string& CurBattleId();
    static const std::string& BigRound();
    static const std::string& TurnEntity();
    static const std::string& ContextCasterId();
    static const std::string& ContextSkillId();
    static const std::string& ContextTargetId();
    static const std::string& ContextSkillResult();
    static const std::string& ContextLatestBuff();
    static const std::string& Elemental();
    static const std::string& Psionics();
    static const std::string& Ether();
    static const std::string& Light();
    static const std::string& Dark();
    static const std::string& RequireSort();
    static const std::string& LastKillerId();
    static const std::string& CurReinforceCount();
    static const std::string& GamePlayId();
    static const std::string& DirectlyVictor();
    static const std::string& IgnoreBattleTrigger();
    static const std::string& BattleType();
    static const std::string& RecoverCristal();
    static const std::string& StarResult();
    static const std::string& ContinuousCount();
    static const std::string& AutoBuy();
    static const std::string& RandSpeedSequence();
    static const std::string& EndBattleCondition();
    static const std::string& BotArenaChallengeId();
    static const std::string& BotArenaReplayId();
    static const std::string& BotArenaChallengeResult();
    static const std::string& BotArenaAttackEntityId();
    static const std::string& BotArenaDefensiveEntityId();
    static const std::string& BotArenaDefensiveEntityInfo();
    static const std::string& ExploreDungeonMonsterId();
    static const std::string& ExploreDungeonMonsterIdx();
    //Record
    static const std::string& R_BattleList();
    enum BattleList
    {
        BattleList_BattleId = 0,
        BattleList_StartTime = 1,
        BattleList_EndTime = 2,
        BattleList_DestroyedEntityIds = 3,
    };

    static const std::string& R_TriggerList();
    enum TriggerList
    {
        TriggerList_TriggerId = 0,
    };

    static const std::string& R_Team();
    enum Team
    {
        Team_TeamId = 0,
        Team_TeamType = 1,
        Team_Cristal = 2,
        Team_CristalLimit = 3,
        Team_CristalExtra = 4,
        Team_CristalTotal = 5,
        Team_Name = 6,
        Team_DeathCount = 7,
    };

    static const std::string& R_TeamAutoMode();
    enum TeamAutoMode
    {
        TeamAutoMode_TeamId = 0,
        TeamAutoMode_Enable = 1,
        TeamAutoMode_WitchId1 = 2,
        TeamAutoMode_WitchMode1 = 3,
        TeamAutoMode_WitchId2 = 4,
        TeamAutoMode_WitchMode2 = 5,
        TeamAutoMode_WitchId3 = 6,
        TeamAutoMode_WitchMode3 = 7,
        TeamAutoMode_WitchId4 = 8,
        TeamAutoMode_WitchMode4 = 9,
        TeamAutoMode_PrioOppositeTarget = 10,
        TeamAutoMode_PrioTeammateTarget = 11,
    };

    static const std::string& R_NoneActionQueue();
    enum NoneActionQueue
    {
        NoneActionQueue_Entity = 0,
        NoneActionQueue_IsNew = 1,
        NoneActionQueue_IsCharging = 2,
    };

    static const std::string& R_ActionQueue();
    enum ActionQueue
    {
        ActionQueue_Entity = 0,
        ActionQueue_IsNew = 1,
        ActionQueue_IsCharging = 2,
    };

    static const std::string& R_CacheEvent();
    enum CacheEvent
    {
        CacheEvent_Event = 0,
        CacheEvent_Args = 1,
    };

    static const std::string& R_SourceSkills();
    enum SourceSkills
    {
        SourceSkills_SkillId = 0,
    };

    static const std::string& R_AckBTLMsg();
    enum AckBTLMsg
    {
        AckBTLMsg_Data = 0,
        AckBTLMsg_Type = 1,
    };

    static const std::string& R_BTLEffect();
    enum BTLEffect
    {
        BTLEffect_ConfigId = 0,
        BTLEffect_Type = 1,
        BTLEffect_CasterId = 2,
        BTLEffect_TargetId = 3,
        BTLEffect_EffectId = 4,
        BTLEffect_EventSourceId = 5,
        BTLEffect_Result = 6,
        BTLEffect_Entities = 7,
        BTLEffect_ConfigGuid = 8,
        BTLEffect_EffectIndex = 9,
    };

    static const std::string& R_EntityChangedData();
    enum EntityChangedData
    {
        EntityChangedData_EntityId = 0,
        EntityChangedData_Type = 1,
        EntityChangedData_Name = 2,
    };

};

class BattleNpc
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Name();
    static const std::string& RoleResId();
    static const std::string& AttrId();
    static const std::string& PlayType();
    static const std::string& AttrType();
    static const std::string& Rare();
    static const std::string& SubType();
    static const std::string& LevelType();
    static const std::string& LevelTypeData();
    static const std::string& AttrCorrect();
    static const std::string& AdvantagePeriodType();
    static const std::string& Skills();
    static const std::string& AiType();
    static const std::string& AiData();
};

class BeginningMission
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& UnlockDay();
    static const std::string& ObjectType();
    static const std::string& ObjectValue();
    static const std::string& Reward();
    static const std::string& Skip();
};

class BlackMarket
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ShopType();
    static const std::string& ResetData();
    static const std::string& RefreshType();
    static const std::string& RefreshData();
    static const std::string& TopbarData();
};

class BlackMarketGoods
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ShopType();
    static const std::string& SellType();
    static const std::string& SellChildContent();
    static const std::string& SellContent();
    static const std::string& BuyCost();
    static const std::string& MaxSellCount();
    static const std::string& OnceMaxBuyCount();
    static const std::string& Discount();
    static const std::string& Conditions();
};

class Bless
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Interval();
    static const std::string& BlessType();
    static const std::string& TimeType();
    static const std::string& Type();
    static const std::string& ParaNum();
    static const std::string& CombinePrama();
    static const std::string& CanNotStack();
};

class BotArenaGrade
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Grade();
    static const std::string& SubGrade();
    static const std::string& UpgradeExp();
    static const std::string& SpecificLimits();
    static const std::string& AttackStrategic();
    static const std::string& DefendStrategic();
    static const std::string& ShabowBadge();
    static const std::string& PvpPrompt();
    static const std::string& PvpReward();
    static const std::string& BTLBattleId();
};

class BotArenaInfo
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& TimeSpan();
    static const std::string& PhaseStartDay();
    static const std::string& BattleListLength();
    static const std::string& MatchOrderRotate();
    static const std::string& Matchingcount();
    static const std::string& ReduceCount();
    static const std::string& StageReset();
    static const std::string& SeasonReset();
    static const std::string& PvpHistoryListLen();
    static const std::string& RefreshCd();
    static const std::string& ShabowTokenRcoverLimit();
    static const std::string& ProtectGrade();
    static const std::string& ContinuousWin();
    static const std::string& RefreshCost();
    static const std::string& StrategicPointsRankingLimit();
    static const std::string& HonorPointsRankingLimit();
    static const std::string& RankingCd();
    static const std::string& SeasonTime();
    static const std::string& ChallengeCost();
    static const std::string& ShabowTokenBuyCost();
    static const std::string& ShabowTokenBuyLimit();
    static const std::string& SettleSessionTier();
    static const std::string& SettleSessionPromptTier();
    static const std::string& RankReward();
    static const std::string& ShopId();
};

class Bubble
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& BubbleUnlockType();
    static const std::string& BubbleUnlockValue();
};

class Cell
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Scene();
    static const std::string& Index();
    static const std::string& IsBlock();
};

class Channel
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ChannelUnlockType();
    static const std::string& ChannelUnlockValue();
};

class Chapter
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ChapterIndex();
    static const std::string& IsPrologue();
    static const std::string& NextChapter();
    static const std::string& Modules();
    static const std::string& UnlockCondition();
    static const std::string& Bonus();
};

class ChapterBranch
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Modules();
    static const std::string& ShowCondition();
    static const std::string& UnlockCondition();
    static const std::string& Bonus();
};

class ChapterSide
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Modules();
    static const std::string& UnlockCondition();
    static const std::string& Bonus();
};

class Condition
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& Data();
};

class ConstComm
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Float();
    static const std::string& Int();
    static const std::string& String();
};

class ConstServer
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Float();
    static const std::string& Int();
    static const std::string& String();
};

class DispatchAffair
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& AffairType();
    static const std::string& Quality();
    static const std::string& FavRewardData();
    static const std::string& UniversalDebrisRandomData();
    static const std::string& ExpRewardCoefficient();
    static const std::string& WorkingTime();
    static const std::string& RedList();
    static const std::string& BlackList();
    static const std::string& CanNotStack();
};

class DispatchArea
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Index();
    static const std::string& RewardData_1();
    static const std::string& RewardData_2();
    static const std::string& RewardData_3();
    static const std::string& RewardData_4();
    static const std::string& RewardData_5();
    static const std::string& RewardData_6();
    static const std::string& RewardData_7();
    static const std::string& RewardData_8();
    static const std::string& RewardData_9();
    static const std::string& StepGiftRewardChanceData();
    static const std::string& StepAffairRewardChanceData();
};

class DispatchBasicOutPut
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& TeamLevel();
    static const std::string& GoldRewardBasicValue();
    static const std::string& ExpRewardBasicValue();
};

class Enemy
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& PlayType();
    static const std::string& AttrType();
    static const std::string& Rare();
    static const std::string& LevelType();
    static const std::string& LevelTypeData();
    static const std::string& SubType();
    static const std::string& MonsterId();
    static const std::string& AttrCorrect();
};

class Examination
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& RewardData();
    static const std::string& ExamStory();
    static const std::string& QuestionData();
};

class Exp
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Player();
    static const std::string& Power();
    static const std::string& PowerReward();
    static const std::string& Witch_1();
    static const std::string& Witch_2();
    static const std::string& Witch_3();
    static const std::string& AttrReward_1_1();
    static const std::string& AttrReward_1_2();
    static const std::string& AttrReward_1_3();
    static const std::string& AttrReward_1_4();
    static const std::string& AttrReward_1_5();
    static const std::string& AttrReward_1_6();
    static const std::string& AttrReward_1_7();
    static const std::string& AttrReward_1_8();
    static const std::string& AttrReward_2_1();
    static const std::string& AttrReward_2_2();
    static const std::string& AttrReward_2_3();
    static const std::string& AttrReward_2_4();
    static const std::string& AttrReward_2_5();
    static const std::string& AttrReward_2_6();
    static const std::string& AttrReward_2_7();
    static const std::string& AttrReward_2_8();
    static const std::string& AttrReward_3_1();
    static const std::string& AttrReward_3_2();
    static const std::string& AttrReward_3_3();
    static const std::string& AttrReward_3_4();
    static const std::string& AttrReward_3_5();
    static const std::string& AttrReward_3_6();
    static const std::string& AttrReward_3_7();
    static const std::string& AttrReward_3_8();
    static const std::string& BasicFight_1_1();
    static const std::string& BasicFight_1_2();
    static const std::string& BasicFight_1_3();
    static const std::string& BasicFight_1_4();
    static const std::string& BasicFight_1_5();
    static const std::string& BasicFight_1_6();
    static const std::string& BasicFight_1_7();
    static const std::string& BasicFight_1_8();
    static const std::string& BasicFight_2_1();
    static const std::string& BasicFight_2_2();
    static const std::string& BasicFight_2_3();
    static const std::string& BasicFight_2_4();
    static const std::string& BasicFight_2_5();
    static const std::string& BasicFight_2_6();
    static const std::string& BasicFight_2_7();
    static const std::string& BasicFight_2_8();
    static const std::string& BasicFight_3_1();
    static const std::string& BasicFight_3_2();
    static const std::string& BasicFight_3_3();
    static const std::string& BasicFight_3_4();
    static const std::string& BasicFight_3_5();
    static const std::string& BasicFight_3_6();
    static const std::string& BasicFight_3_7();
    static const std::string& BasicFight_3_8();
    static const std::string& Collect();
    static const std::string& CollectAttrReward();
    static const std::string& CollectBasicFight();
    static const std::string& PneumaBook();
    static const std::string& PneumaBookAttrReward();
    static const std::string& PneumaBookBasicFight();
};

class Experience
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Condition();
};

class ExploreArea
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NodeMapID();
    static const std::string& AreaBonus();
    static const std::string& AreaStarBonus();
};

class ExploreChange
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& MapID();
    static const std::string& State();
    static const std::string& StateChange();
};

class ExploreDungeon
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Scene();
    static const std::string& Camera();
    static const std::string& PowerConsume();
    static const std::string& BossAppearRate();
    static const std::string& MonsterCombination();
    static const std::string& ServantBattle();
    static const std::string& BossBattle();
    static const std::string& Bonus();
    static const std::string& AutoBattle();
    static const std::string& DailyBonus();
    static const std::string& DailyBonusItem();
    static const std::string& ExtraBonusRandom();
    static const std::string& ExtraBonusEffect();
    static const std::string& EliteID();
};

class ExploreElite
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& EliteName();
    static const std::string& EliteImage();
    static const std::string& EliteBattle();
    static const std::string& LastTime();
    static const std::string& PowerConsume();
    static const std::string& ElitePoint();
    static const std::string& EliteMaxPoint();
    static const std::string& EliteRate();
    static const std::string& EventFirstDrop();
    static const std::string& EventMustDrop();
    static const std::string& EventMainDrop();
    static const std::string& FirstRefreshRate();
};

class ExploreGuide
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& FriendlyItem();
    static const std::string& FriendlyItemTopbar();
    static const std::string& FriendlyPoint();
    static const std::string& GuideShop();
    static const std::string& LevelCondtion();
};

class ExploreMap
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NodeMapNum();
    static const std::string& ExploreSceneID();
    static const std::string& UnlockCondition();
    static const std::string& ExploreMapIcon();
    static const std::string& MapStarBonus();
    static const std::string& MapSideBonus();
    static const std::string& AdventureImage();
};

class ExploreMission
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ObjectType();
    static const std::string& ObjectValue();
    static const std::string& Reward();
};

class ExploreNode
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NodeIndex();
    static const std::string& EventType();
    static const std::string& EventParam();
    static const std::string& NodeStartStory();
    static const std::string& NodeEndStory();
    static const std::string& Map();
    static const std::string& ExtraUnlockCondition();
    static const std::string& GamePlayUnlockCondition();
    static const std::string& Type();
    static const std::string& IsMainNode();
    static const std::string& IsImportantSideNode();
    static const std::string& EventFirstDrop();
    static const std::string& StarDrop();
    static const std::string& EventMustDrop();
    static const std::string& EventMainDrop();
    static const std::string& EventMinorDrop();
    static const std::string& EventMopExtraDrop();
    static const std::string& EventConsume();
    static const std::string& MopConsume();
};

class ExploreRaid
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& BattleID();
    static const std::string& SpecialDropID();
    static const std::string& DropID();
};

class ExploreTask
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& BattleID();
    static const std::string& DropID();
    static const std::string& MissionID();
};

class ExploreTreasureBox
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RewardID();
};

class Favorability
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& WitchID();
    static const std::string& ExpData();
    static const std::string& AttrReward();
    static const std::string& BasicFight();
};

class Files
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Experience();
    static const std::string& Stories();
    static const std::string& Voice();
};

class Group
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& TriggerId();
};

class Guide
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NextGuideID();
    static const std::string& StartCondition();
    static const std::string& FinishCondition();
    static const std::string& GuideClickType();
    static const std::string& OperationType();
};

class GuideCondition
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ConditionValue();
    static const std::string& ServerCheckType();
    static const std::string& ServerCheckValue();
};

class GuideGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Priority();
    static const std::string& GuideType();
    static const std::string& Condition();
    static const std::string& StartGuide();
    static const std::string& FinishGuide();
    static const std::string& FinishReward();
    static const std::string& ExceptionalHandlingGroupID();
};

class GuildFlag
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Recourse();
};

class GuildIcon
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Recourse();
};

class GuildLevel
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Exp();
    static const std::string& MemberQuantity();
};

class HeadPortrait
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& UnlockConditionData();
};

class HeartBeat
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& HeartBeatType();
    static const std::string& MaxTime();
    static const std::string& MaxTimeoutTimes();
};

class Homework
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Index();
    static const std::string& LessonId();
    static const std::string& InteractiveObject();
    static const std::string& TaskData();
};

class HomeworkTask
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Index();
    static const std::string& HomeWorkId();
    static const std::string& Condition();
    static const std::string& ConditionData();
    static const std::string& Type();
    static const std::string& BattleData();
    static const std::string& BattleRewardData();
    static const std::string& TaskData();
    static const std::string& TaskRewardData();
    static const std::string& BattleCostData();
};

class IObject
{
public:
    static const std::string& ThisName();
    //Property
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
};

class InteractiveObject
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& InteractiveType();
    static const std::string& InteractiveData();
};

class Item
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& AddAttrData();
    static const std::string& BtnData();
    static const std::string& Quality();
    static const std::string& CanNotStack();
};

class Knowledge
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Subject();
    static const std::string& CostData_1();
    static const std::string& CostData_2();
    static const std::string& CostData_3();
    static const std::string& MetData_1_1();
    static const std::string& MetData_1_2();
    static const std::string& MetData_1_3();
    static const std::string& MetData_1_4();
    static const std::string& MetData_1_5();
    static const std::string& MetData_2_1();
    static const std::string& MetData_2_2();
    static const std::string& MetData_2_3();
    static const std::string& MetData_2_4();
    static const std::string& MetData_2_5();
    static const std::string& MetData_3_1();
    static const std::string& MetData_3_2();
    static const std::string& MetData_3_3();
    static const std::string& MetData_3_4();
    static const std::string& MetData_3_5();
    static const std::string& StageCondition();
    static const std::string& LevelCondition();
    static const std::string& AttrReward_1_1();
    static const std::string& AttrReward_1_2();
    static const std::string& AttrReward_1_3();
    static const std::string& AttrReward_1_4();
    static const std::string& AttrReward_1_5();
    static const std::string& AttrReward_1_6();
    static const std::string& AttrReward_1_7();
    static const std::string& AttrReward_1_8();
    static const std::string& AttrReward_2_1();
    static const std::string& AttrReward_2_2();
    static const std::string& AttrReward_2_3();
    static const std::string& AttrReward_2_4();
    static const std::string& AttrReward_2_5();
    static const std::string& AttrReward_2_6();
    static const std::string& AttrReward_2_7();
    static const std::string& AttrReward_2_8();
    static const std::string& AttrReward_3_1();
    static const std::string& AttrReward_3_2();
    static const std::string& AttrReward_3_3();
    static const std::string& AttrReward_3_4();
    static const std::string& AttrReward_3_5();
    static const std::string& AttrReward_3_6();
    static const std::string& AttrReward_3_7();
    static const std::string& AttrReward_3_8();
    static const std::string& BasicFight_1_1();
    static const std::string& BasicFight_1_2();
    static const std::string& BasicFight_1_3();
    static const std::string& BasicFight_1_4();
    static const std::string& BasicFight_1_5();
    static const std::string& BasicFight_1_6();
    static const std::string& BasicFight_1_7();
    static const std::string& BasicFight_1_8();
    static const std::string& BasicFight_2_1();
    static const std::string& BasicFight_2_2();
    static const std::string& BasicFight_2_3();
    static const std::string& BasicFight_2_4();
    static const std::string& BasicFight_2_5();
    static const std::string& BasicFight_2_6();
    static const std::string& BasicFight_2_7();
    static const std::string& BasicFight_2_8();
    static const std::string& BasicFight_3_1();
    static const std::string& BasicFight_3_2();
    static const std::string& BasicFight_3_3();
    static const std::string& BasicFight_3_4();
    static const std::string& BasicFight_3_5();
    static const std::string& BasicFight_3_6();
    static const std::string& BasicFight_3_7();
    static const std::string& BasicFight_3_8();
};

class KnowledgeStage
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& CostData_1();
    static const std::string& CostData_2();
    static const std::string& CostData_3();
    static const std::string& MetData_1();
    static const std::string& MetData_2();
    static const std::string& MetData_3();
    static const std::string& LevelCondition();
    static const std::string& AttrReward_1_1();
    static const std::string& AttrReward_1_2();
    static const std::string& AttrReward_1_3();
    static const std::string& AttrReward_1_4();
    static const std::string& AttrReward_1_5();
    static const std::string& AttrReward_1_6();
    static const std::string& AttrReward_1_7();
    static const std::string& AttrReward_1_8();
    static const std::string& AttrReward_2_1();
    static const std::string& AttrReward_2_2();
    static const std::string& AttrReward_2_3();
    static const std::string& AttrReward_2_4();
    static const std::string& AttrReward_2_5();
    static const std::string& AttrReward_2_6();
    static const std::string& AttrReward_2_7();
    static const std::string& AttrReward_2_8();
    static const std::string& AttrReward_3_1();
    static const std::string& AttrReward_3_2();
    static const std::string& AttrReward_3_3();
    static const std::string& AttrReward_3_4();
    static const std::string& AttrReward_3_5();
    static const std::string& AttrReward_3_6();
    static const std::string& AttrReward_3_7();
    static const std::string& AttrReward_3_8();
    static const std::string& BasicFight_1_1();
    static const std::string& BasicFight_1_2();
    static const std::string& BasicFight_1_3();
    static const std::string& BasicFight_1_4();
    static const std::string& BasicFight_1_5();
    static const std::string& BasicFight_1_6();
    static const std::string& BasicFight_1_7();
    static const std::string& BasicFight_1_8();
    static const std::string& BasicFight_2_1();
    static const std::string& BasicFight_2_2();
    static const std::string& BasicFight_2_3();
    static const std::string& BasicFight_2_4();
    static const std::string& BasicFight_2_5();
    static const std::string& BasicFight_2_6();
    static const std::string& BasicFight_2_7();
    static const std::string& BasicFight_2_8();
    static const std::string& BasicFight_3_1();
    static const std::string& BasicFight_3_2();
    static const std::string& BasicFight_3_3();
    static const std::string& BasicFight_3_4();
    static const std::string& BasicFight_3_5();
    static const std::string& BasicFight_3_6();
    static const std::string& BasicFight_3_7();
    static const std::string& BasicFight_3_8();
};

class Lesson
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Index();
    static const std::string& SemesterId();
    static const std::string& SubjectId();
    static const std::string& StudyStoryId();
    static const std::string& StudyStoryReward();
    static const std::string& StudyAssignment();
    static const std::string& RewardData();
    static const std::string& LessonTestId();
};

class Lottery
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& LotterType();
    static const std::string& OpenTime();
    static const std::string& CloseTime();
    static const std::string& LotteryNum();
    static const std::string& FreeLotteryType();
    static const std::string& ColdDownTime();
    static const std::string& LotteryItem();
    static const std::string& LotteryCostType();
    static const std::string& LotteryCostValue();
    static const std::string& QualityWeight();
    static const std::string& FloorsNum();
    static const std::string& FloorsQuality();
    static const std::string& MainFloors();
    static const std::string& SpecialFloor();
    static const std::string& SpecialFloorWitch();
    static const std::string& LotteryLimit();
    static const std::string& LotteryTime();
};

class LotteryPool
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Lottery();
    static const std::string& WitchID();
    static const std::string& Weight();
};

class Meme
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& MemeGroup();
    static const std::string& MemeUnlockType();
    static const std::string& MemeUnlockValue();
};

class MemeGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& MemeGroupUnlockType();
    static const std::string& MemeGroupUnlockValue();
};

class MissionObject
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Holder();
};

class Module
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NextModule();
    static const std::string& SkipToModule();
    static const std::string& ModuleIndex();
    static const std::string& Chapter();
    static const std::string& Scene();
    static const std::string& ImageScene();
    static const std::string& Battle();
    static const std::string& BattleDrop();
};

class ModuleBranch
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NextModule();
    static const std::string& SkipToModule();
    static const std::string& Chapter();
    static const std::string& Scene();
    static const std::string& ImageScene();
    static const std::string& Battle();
    static const std::string& BattleDrop();
};

class ModuleCharacter
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NextModule();
    static const std::string& Chapter();
    static const std::string& Scene();
    static const std::string& ImageScene();
    static const std::string& Battle();
};

class ModuleExplore
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Scene();
    static const std::string& ImageScene();
};

class ModuleSide
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& NextModule();
    static const std::string& Chapter();
    static const std::string& Scene();
    static const std::string& ImageScene();
    static const std::string& Battle();
};

class Monster
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RoleResIdData();
    static const std::string& Race();
    static const std::string& AttrDataId();
    static const std::string& Skills();
    static const std::string& PassvieSkillsSet();
    static const std::string& AlternaAiType();
    static const std::string& AlternaAiData();
    static const std::string& PrimaryAiType();
    static const std::string& PrimaryAiData();
    static const std::string& Team();
    static const std::string& Rare();
    static const std::string& SubType();
    static const std::string& Pos();
    static const std::string& Level();
    static const std::string& EnemyId();
    static const std::string& Seq();
    static const std::string& DeadSeq();
    static const std::string& Disable();
    static const std::string& Hp();
    static const std::string& HpMax();
    static const std::string& Shield();
    static const std::string& ShieldMax();
    static const std::string& Energy();
    static const std::string& EnergyMax();
    static const std::string& HitRate();
    static const std::string& ResistRate();
    static const std::string& ResistProbQueue();
    static const std::string& SpeedThreshold();
    static const std::string& NextPrimaryAi();
    static const std::string& NextAlternateAi();
    static const std::string& AdvantagePeriod();
    static const std::string& ShowAdvantage();
    static const std::string& IsPriorityAction();
    static const std::string& SuppressionType();
    static const std::string& BuffState();
    static const std::string& ExtraAction();
    static const std::string& FinishAction();
    static const std::string& BattleFight();
    static const std::string& HurtFluctuation();
    static const std::string& RandSpeedSeq();
    static const std::string& DamageValue();
    static const std::string& ReceiveDamge();
    static const std::string& HealValue();
    static const std::string& IncrDamageRatio();
    static const std::string& UsedSkills();
    static const std::string& NextPrimaryAiIndex();
    static const std::string& NextAlternateAiIndex();
    //Record
    static const std::string& R_Skill();
    enum Skill
    {
        Skill_SkillId = 0,
        Skill_Level = 1,
        Skill_Cd = 2,
        Skill_Consume = 3,
        Skill_LastTargets = 4,
        Skill_IsSealed = 5,
        Skill_Effects = 6,
        Skill_UseTimes = 7,
        Skill_SelfRoundUsed = 8,
        Skill_StoreValue = 9,
    };

    static const std::string& R_BuffList();
    enum BuffList
    {
        BuffList_BuffGuid = 0,
        BuffList_BuffId = 1,
        BuffList_Level = 2,
        BuffList_Caster = 3,
        BuffList_LeftRound = 4,
        BuffList_TimeType = 5,
        BuffList_AvoidDispel = 6,
        BuffList_SealData = 7,
        BuffList_BuffValue = 8,
    };

    static const std::string& R_AppliedBuffEffects();
    enum AppliedBuffEffects
    {
        AppliedBuffEffects_Id = 0,
        AppliedBuffEffects_CustomData = 1,
    };

    static const std::string& R_AttrData();
    enum AttrData
    {
        AttrData_Hp = 0,
        AttrData_Defence = 1,
        AttrData_Speed = 2,
        AttrData_Attack = 3,
        AttrData_Crit = 4,
        AttrData_CritDmg = 5,
        AttrData_Hit = 6,
        AttrData_Resist = 7,
    };

    static const std::string& R_HitProbQueue();
    enum HitProbQueue
    {
        HitProbQueue_QueueId = 0,
        HitProbQueue_Data = 1,
    };

};

class NoSqlServer
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ServerID();
    static const std::string& IP();
    static const std::string& Port();
    static const std::string& Auth();
    static const std::string& Zone();
};

class NoteBook
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& ChildType();
    static const std::string& Condition();
    static const std::string& ConditionData();
};

class PVPRobot
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RobotName();
    static const std::string& RobotPicture();
    static const std::string& RobotLevel();
    static const std::string& RobotFight();
    static const std::string& RobotStrategicPoints();
    static const std::string& RobotTeam();
};

class PlantingSkills
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& PlantReward();
};

class Player
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Account();
    static const std::string& DigitalId();
    static const std::string& Channel();
    static const std::string& NickName();
    static const std::string& ZoneId();
    static const std::string& CreateTs();
    static const std::string& ClientId();
    static const std::string& GameId();
    static const std::string& GateId();
    static const std::string& LoginTs();
    static const std::string& LogoutTs();
    static const std::string& Exp();
    static const std::string& Level();
    static const std::string& LastLevelUpTs();
    static const std::string& CurWitchTeamId();
    static const std::string& CurTitleId();
    static const std::string& TeamId();
    static const std::string& Power();
    static const std::string& LastPowerRecoverTs();
    static const std::string& FrozenPowerRecoverTime();
    static const std::string& Gold();
    static const std::string& Diamond();
    static const std::string& TotalCash();
    static const std::string& Couples();
    static const std::string& ModuleId();
    static const std::string& ChapterStatus();
    static const std::string& PowerBuyTimes();
    static const std::string& LastPowerBuyTimesResetTime();
    static const std::string& CurHouseKeeperId();
    static const std::string& CurHouseKeeperSkinId();
    static const std::string& DailyActiveValue();
    static const std::string& WeeklyActiveValue();
    static const std::string& TotalDailyActiveValue();
    static const std::string& TotalWeeklyActiveValue();
    static const std::string& ActiveMissionFlags();
    static const std::string& LastNonBattleScene();
    static const std::string& TotalFC();
    static const std::string& RefreshRecommendedListTS();
    static const std::string& FindPlayerTS();
    static const std::string& CurGuideGroup();
    static const std::string& ChaoticBookLevel();
    static const std::string& ChaoticBookExp();
    static const std::string& MagicalBottle();
    static const std::string& UniversalDebris();
    static const std::string& MercenaryUnit();
    static const std::string& MercenaryRewardCount();
    static const std::string& MailSessionTs();
    static const std::string& FriendshipCoin();
    static const std::string& IsUnlockTalentSystem();
    static const std::string& TalentWitchId();
    static const std::string& TalentReplaceTS();
    static const std::string& FirstDCFlag();
    static const std::string& RedpointFlag();
    static const std::string& FreePowerFlag();
    static const std::string& UniversalArtifactDebris();
    static const std::string& AvatarUrl();
    static const std::string& AvatarFrameId();
    static const std::string& Age();
    static const std::string& Height();
    static const std::string& Weight();
    static const std::string& Gender();
    static const std::string& Constellation();
    static const std::string& PermLocation();
    static const std::string& Signature();
    static const std::string& Country();
    static const std::string& StudyStatus();
    static const std::string& SemesterId();
    static const std::string& SemesterModuleFinish();
    static const std::string& CollegeStatus();
    static const std::string& IsDefaultInClass();
    static const std::string& LessonId();
    static const std::string& InClassStatus();
    static const std::string& InClassUnlockTime();
    static const std::string& HomeWorkId();
    static const std::string& HomeworkStatus();
    static const std::string& HomeWorkTaskId();
    static const std::string& HomeworkTaskStatus();
    static const std::string& InteractiveObjectStatus();
    static const std::string& HomeworkTaskModueId();
    static const std::string& HomeworkTaskProgress();
    static const std::string& HomeworkTaskEndTime();
    static const std::string& FirstHomeworkUnlockTime();
    static const std::string& ExamStatus();
    static const std::string& ExtraExamEndTime();
    static const std::string& ExamCD();
    static const std::string& ExamPassTime();
    static const std::string& NeedExamAnswerCount();
    static const std::string& MopTicket();
    static const std::string& SigninPoker();
    static const std::string& SigninLastFinishedTs();
    static const std::string& SigninContinuousCount();
    static const std::string& AccTicket();
    static const std::string& AppointTotalTime();
    static const std::string& CurAppointAreaId();
    static const std::string& AppointGetRewardTS();
    static const std::string& AppointState();
    static const std::string& CurMessagerId();
    static const std::string& ExpWitch();
    static const std::string& Intimacy();
    static const std::string& Respectability();
    static const std::string& AutoDecomposeState();
    static const std::string& PneumaBagSize();
    static const std::string& PreStrategyPoint();
    static const std::string& StrategyPoint();
    static const std::string& HonorPoint();
    static const std::string& ShabowToken();
    static const std::string& ShabowBadge();
    static const std::string& PreBotarenaGrade();
    static const std::string& BotarenaGrade();
    static const std::string& BotarenaPreSeasonRank();
    static const std::string& LastUseFreeRefreshTs();
    static const std::string& IsRegisterCurrentSession();
    static const std::string& BotarenaDefensiveTeam_Witch1();
    static const std::string& BotarenaDefensiveTeam_Witch2();
    static const std::string& BotarenaDefensiveTeam_Witch3();
    static const std::string& BotarenaDefensiveTeam_Witch4();
    static const std::string& BotArenaContinuousWinNum();
    static const std::string& IsPromptStageRefresh();
    static const std::string& IsPromptSessionRefresh();
    static const std::string& LastFinishedSettleBotArenaStageTs();
    static const std::string& LastFinishedSettleBotArenaSessionTs();
    static const std::string& TowerId();
    static const std::string& SettledTowerId();
    static const std::string& TowerRes();
    static const std::string& CommunityId();
    static const std::string& CommunityPos();
    static const std::string& CommunityQuitTS();
    static const std::string& CommunityChiefOptCount();
    static const std::string& CommunityDismissCount();
    static const std::string& CommunitySignInFlag();
    static const std::string& CommunitySearchTS();
    static const std::string& CommunityQuickJoinTS();
    static const std::string& PlayerOsId();
    static const std::string& Platform();
    static const std::string& MediaId();
    static const std::string& Mac();
    static const std::string& Ip();
    static const std::string& DeviceModel();
    static const std::string& DeviceSys();
    static const std::string& DeviceRam();
    static const std::string& Idfa();
    static const std::string& DeviceId();
    static const std::string& Language();
    static const std::string& GameVer();
    static const std::string& ChatPasswd();
    static const std::string& ChatBubble();
    static const std::string& ReportChatCount();
    static const std::string& ForbiddenChatTs();
    static const std::string& LastChatTs();
    static const std::string& AnswerRound();
    static const std::string& AnswerConsumeTime();
    static const std::string& AnswerCurQuestionNumber();
    static const std::string& AnswerCorrectCount();
    static const std::string& AnswerRewardSchedule();
    static const std::string& AnswerQuestionStartTS();
    static const std::string& AnswerCurAnswerState();
    static const std::string& AnswerRoundState();
    //Record
    static const std::string& R_ChaoticBook();
    enum ChaoticBook
    {
        ChaoticBook_BookId = 0,
        ChaoticBook_FragmentRepairFlag = 1,
        ChaoticBook_IsUnlock = 2,
    };

    static const std::string& R_Witch();
    enum Witch
    {
        Witch_WitchId = 0,
        Witch_Level = 1,
        Witch_Exp = 2,
        Witch_CurRoleResId = 3,
        Witch_StarLevel = 4,
        Witch_EmotionLevel = 5,
        Witch_EmotionExp = 6,
        Witch_IsCollect = 7,
        Witch_CommentList = 8,
        Witch_FreeGiftCount = 9,
        Witch_UnlockGiftList = 10,
        Witch_FinishedAffairTypes = 11,
        Witch_KnowledgeLevel = 12,
        Witch_MedicineLevel = 13,
        Witch_RuneLevel = 14,
        Witch_DivinationLevel = 15,
        Witch_AlchemyLevel = 16,
        Witch_PneumaGuid = 17,
        Witch_FCTotal = 18,
        Witch_HpTotal = 19,
        Witch_DefenceTotal = 20,
        Witch_SpeedTotal = 21,
        Witch_AttackTotal = 22,
        Witch_CritTotal = 23,
        Witch_CritDmgTotal = 24,
        Witch_HitTotal = 25,
        Witch_ResistTotal = 26,
        Witch_ExperienceFlag1 = 27,
        Witch_ExperienceFlag2 = 28,
        Witch_StoryFlag1 = 29,
        Witch_StoryFlag2 = 30,
        Witch_VoiceFlag1 = 31,
        Witch_VoiceFlag2 = 32,
        Witch_PneumaInfo = 33,
        Witch_HpBasic = 34,
        Witch_DefenceBasic = 35,
        Witch_SpeedBasic = 36,
        Witch_AttackBasic = 37,
        Witch_TalentStatus = 38,
    };

    static const std::string& R_WitchSkills();
    enum WitchSkills
    {
        WitchSkills_WitchId = 0,
        WitchSkills_GeneralSkillId = 1,
        WitchSkills_AdvancedSkillId = 2,
        WitchSkills_UniqueSkillId = 3,
        WitchSkills_VersedSkillId = 4,
        WitchSkills_AwakeningSkillId = 5,
        WitchSkills_ExtraSkillId1 = 6,
        WitchSkills_ExtraSkillId2 = 7,
    };

    static const std::string& R_WitchTeams();
    enum WitchTeams
    {
        WitchTeams_TeamId = 0,
        WitchTeams_Name = 1,
        WitchTeams_Witch1 = 2,
        WitchTeams_Witch2 = 3,
        WitchTeams_Witch3 = 4,
        WitchTeams_Witch4 = 5,
        WitchTeams_IsLock = 6,
    };

    static const std::string& R_BattleFood();
    enum BattleFood
    {
        BattleFood_BattleType = 0,
        BattleFood_FoodId = 1,
        BattleFood_LeftTimes = 2,
        BattleFood_Auto = 3,
    };

    static const std::string& R_BattleTotem();
    enum BattleTotem
    {
        BattleTotem_Guid = 0,
        BattleTotem_Totem1 = 1,
        BattleTotem_Totem2 = 2,
        BattleTotem_Totem3 = 3,
        BattleTotem_Totem4 = 4,
    };

    static const std::string& R_BattleWitchTeam();
    enum BattleWitchTeam
    {
        BattleWitchTeam_BattleLabel = 0,
        BattleWitchTeam_TeamId = 1,
    };

    static const std::string& R_WitchSkins();
    enum WitchSkins
    {
        WitchSkins_RoleResId = 0,
        WitchSkins_WitchId = 1,
        WitchSkins_SkinGotTs = 2,
        WitchSkins_IsValid = 3,
    };

    static const std::string& R_FightingCapacity();
    enum FightingCapacity
    {
        FightingCapacity_WitchId = 0,
        FightingCapacity_CalcFlag = 1,
        FightingCapacity_LevelVal = 2,
        FightingCapacity_LevelPercent = 3,
        FightingCapacity_StarLevelVal = 4,
        FightingCapacity_StarLevelPercent = 5,
        FightingCapacity_EmotionVal = 6,
        FightingCapacity_EmotionPercent = 7,
        FightingCapacity_KnowledgeVal = 8,
        FightingCapacity_KnowledgePercent = 9,
        FightingCapacity_PneumaVal = 10,
        FightingCapacity_PneumaPercent = 11,
        FightingCapacity_ChaoticBookVal = 12,
        FightingCapacity_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchStory();
    enum WitchStory
    {
        WitchStory_Guid = 0,
        WitchStory_WitchId = 1,
        WitchStory_StoryId = 2,
        WitchStory_ModuleId = 3,
    };

    static const std::string& R_WitchAttr_Hp();
    enum WitchAttr_Hp
    {
        WitchAttr_Hp_WitchId = 0,
        WitchAttr_Hp_CalcFlag = 1,
        WitchAttr_Hp_LevelVal = 2,
        WitchAttr_Hp_LevelPercent = 3,
        WitchAttr_Hp_StarLevelVal = 4,
        WitchAttr_Hp_StarLevelPercent = 5,
        WitchAttr_Hp_EmotionVal = 6,
        WitchAttr_Hp_EmotionPercent = 7,
        WitchAttr_Hp_KnowledgeVal = 8,
        WitchAttr_Hp_KnowledgePercent = 9,
        WitchAttr_Hp_PneumaVal = 10,
        WitchAttr_Hp_PneumaPercent = 11,
        WitchAttr_Hp_ChaoticBookVal = 12,
        WitchAttr_Hp_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_Defence();
    enum WitchAttr_Defence
    {
        WitchAttr_Defence_WitchId = 0,
        WitchAttr_Defence_CalcFlag = 1,
        WitchAttr_Defence_LevelVal = 2,
        WitchAttr_Defence_LevelPercent = 3,
        WitchAttr_Defence_StarLevelVal = 4,
        WitchAttr_Defence_StarLevelPercent = 5,
        WitchAttr_Defence_EmotionVal = 6,
        WitchAttr_Defence_EmotionPercent = 7,
        WitchAttr_Defence_KnowledgeVal = 8,
        WitchAttr_Defence_KnowledgePercent = 9,
        WitchAttr_Defence_PneumaVal = 10,
        WitchAttr_Defence_PneumaPercent = 11,
        WitchAttr_Defence_ChaoticBookVal = 12,
        WitchAttr_Defence_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_Speed();
    enum WitchAttr_Speed
    {
        WitchAttr_Speed_WitchId = 0,
        WitchAttr_Speed_CalcFlag = 1,
        WitchAttr_Speed_LevelVal = 2,
        WitchAttr_Speed_LevelPercent = 3,
        WitchAttr_Speed_StarLevelVal = 4,
        WitchAttr_Speed_StarLevelPercent = 5,
        WitchAttr_Speed_EmotionVal = 6,
        WitchAttr_Speed_EmotionPercent = 7,
        WitchAttr_Speed_KnowledgeVal = 8,
        WitchAttr_Speed_KnowledgePercent = 9,
        WitchAttr_Speed_PneumaVal = 10,
        WitchAttr_Speed_PneumaPercent = 11,
        WitchAttr_Speed_ChaoticBookVal = 12,
        WitchAttr_Speed_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_Attack();
    enum WitchAttr_Attack
    {
        WitchAttr_Attack_WitchId = 0,
        WitchAttr_Attack_CalcFlag = 1,
        WitchAttr_Attack_LevelVal = 2,
        WitchAttr_Attack_LevelPercent = 3,
        WitchAttr_Attack_StarLevelVal = 4,
        WitchAttr_Attack_StarLevelPercent = 5,
        WitchAttr_Attack_EmotionVal = 6,
        WitchAttr_Attack_EmotionPercent = 7,
        WitchAttr_Attack_KnowledgeVal = 8,
        WitchAttr_Attack_KnowledgePercent = 9,
        WitchAttr_Attack_PneumaVal = 10,
        WitchAttr_Attack_PneumaPercent = 11,
        WitchAttr_Attack_ChaoticBookVal = 12,
        WitchAttr_Attack_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_Crit();
    enum WitchAttr_Crit
    {
        WitchAttr_Crit_WitchId = 0,
        WitchAttr_Crit_CalcFlag = 1,
        WitchAttr_Crit_LevelVal = 2,
        WitchAttr_Crit_LevelPercent = 3,
        WitchAttr_Crit_StarLevelVal = 4,
        WitchAttr_Crit_StarLevelPercent = 5,
        WitchAttr_Crit_EmotionVal = 6,
        WitchAttr_Crit_EmotionPercent = 7,
        WitchAttr_Crit_KnowledgeVal = 8,
        WitchAttr_Crit_KnowledgePercent = 9,
        WitchAttr_Crit_PneumaVal = 10,
        WitchAttr_Crit_PneumaPercent = 11,
        WitchAttr_Crit_ChaoticBookVal = 12,
        WitchAttr_Crit_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_CritDmg();
    enum WitchAttr_CritDmg
    {
        WitchAttr_CritDmg_WitchId = 0,
        WitchAttr_CritDmg_CalcFlag = 1,
        WitchAttr_CritDmg_LevelVal = 2,
        WitchAttr_CritDmg_LevelPercent = 3,
        WitchAttr_CritDmg_StarLevelVal = 4,
        WitchAttr_CritDmg_StarLevelPercent = 5,
        WitchAttr_CritDmg_EmotionVal = 6,
        WitchAttr_CritDmg_EmotionPercent = 7,
        WitchAttr_CritDmg_KnowledgeVal = 8,
        WitchAttr_CritDmg_KnowledgePercent = 9,
        WitchAttr_CritDmg_PneumaVal = 10,
        WitchAttr_CritDmg_PneumaPercent = 11,
        WitchAttr_CritDmg_ChaoticBookVal = 12,
        WitchAttr_CritDmg_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_Hit();
    enum WitchAttr_Hit
    {
        WitchAttr_Hit_WitchId = 0,
        WitchAttr_Hit_CalcFlag = 1,
        WitchAttr_Hit_LevelVal = 2,
        WitchAttr_Hit_LevelPercent = 3,
        WitchAttr_Hit_StarLevelVal = 4,
        WitchAttr_Hit_StarLevelPercent = 5,
        WitchAttr_Hit_EmotionVal = 6,
        WitchAttr_Hit_EmotionPercent = 7,
        WitchAttr_Hit_KnowledgeVal = 8,
        WitchAttr_Hit_KnowledgePercent = 9,
        WitchAttr_Hit_PneumaVal = 10,
        WitchAttr_Hit_PneumaPercent = 11,
        WitchAttr_Hit_ChaoticBookVal = 12,
        WitchAttr_Hit_ChaoticBookPercent = 13,
    };

    static const std::string& R_WitchAttr_Resist();
    enum WitchAttr_Resist
    {
        WitchAttr_Resist_WitchId = 0,
        WitchAttr_Resist_CalcFlag = 1,
        WitchAttr_Resist_LevelVal = 2,
        WitchAttr_Resist_LevelPercent = 3,
        WitchAttr_Resist_StarLevelVal = 4,
        WitchAttr_Resist_StarLevelPercent = 5,
        WitchAttr_Resist_EmotionVal = 6,
        WitchAttr_Resist_EmotionPercent = 7,
        WitchAttr_Resist_KnowledgeVal = 8,
        WitchAttr_Resist_KnowledgePercent = 9,
        WitchAttr_Resist_PneumaVal = 10,
        WitchAttr_Resist_PneumaPercent = 11,
        WitchAttr_Resist_ChaoticBookVal = 12,
        WitchAttr_Resist_ChaoticBookPercent = 13,
    };

    static const std::string& R_AvatarFrames();
    enum AvatarFrames
    {
        AvatarFrames_AvatarFrameId = 0,
        AvatarFrames_UnlockTs = 1,
    };

    static const std::string& R_Avatars();
    enum Avatars
    {
        Avatars_AvatarId = 0,
        Avatars_UnlockTs = 1,
    };

    static const std::string& R_Title();
    enum Title
    {
        Title_TitleId = 0,
        Title_State = 1,
        Title_ConditionStates = 2,
    };

    static const std::string& R_Bag();
    enum Bag
    {
        Bag_Guid = 0,
        Bag_ItemId = 1,
        Bag_Count = 2,
        Bag_LastTs = 3,
        Bag_DeadTs = 4,
    };

    static const std::string& R_AssetsList();
    enum AssetsList
    {
        AssetsList_AssetsId = 0,
        AssetsList_Count = 1,
        AssetsList_ProductId = 2,
        AssetsList_UserData = 3,
        AssetsList_Comment = 4,
        AssetsList_TransactionState = 5,
    };

    static const std::string& R_BlackmartShop();
    enum BlackmartShop
    {
        BlackmartShop_ShopId = 0,
        BlackmartShop_FreeRefreshCount = 1,
        BlackmartShop_TotalRefreshCount = 2,
        BlackmartShop_RefreshTS = 3,
    };

    static const std::string& R_BlackmartCommodity();
    enum BlackmartCommodity
    {
        BlackmartCommodity_CommodityId = 0,
        BlackmartCommodity_BuyCount = 1,
        BlackmartCommodity_DiscountRate = 2,
        BlackmartCommodity_IsUnlock = 3,
    };

    static const std::string& R_BlackmartCommodityLog();
    enum BlackmartCommodityLog
    {
        BlackmartCommodityLog_CommodityId = 0,
        BlackmartCommodityLog_TotalBuyCount = 1,
    };

    static const std::string& R_ShopReceipts();
    enum ShopReceipts
    {
        ShopReceipts_ProductId = 0,
        ShopReceipts_Count = 1,
        ShopReceipts_CreateTs = 2,
    };

    static const std::string& R_UnlockShop();
    enum UnlockShop
    {
        UnlockShop_ShopId = 0,
    };

    static const std::string& R_UnlockShopGoods();
    enum UnlockShopGoods
    {
        UnlockShopGoods_ShopGoodsId = 0,
    };

    static const std::string& R_TaskList();
    enum TaskList
    {
        TaskList_TaskId = 0,
        TaskList_TaskStatus = 1,
        TaskList_Progress = 2,
        TaskList_ActiveTs = 3,
        TaskList_ReadStatus = 4,
    };

    static const std::string& R_SceneData();
    enum SceneData
    {
        SceneData_SceneId = 0,
        SceneData_Position = 1,
        SceneData_Orientation = 2,
    };

    static const std::string& R_TriggerData();
    enum TriggerData
    {
        TriggerData_NpcId = 0,
        TriggerData_Position = 1,
        TriggerData_Orientation = 2,
        TriggerData_EventTimes = 3,
        TriggerData_EventGroup = 4,
        TriggerData_Title = 5,
        TriggerData_Visible = 6,
        TriggerData_CreateTs = 7,
    };

    static const std::string& R_FriendList();
    enum FriendList
    {
        FriendList_PlayerId = 0,
        FriendList_IsCollect = 1,
        FriendList_AddTS = 2,
    };

    static const std::string& R_AppliedFriendList();
    enum AppliedFriendList
    {
        AppliedFriendList_PlayerId = 0,
        AppliedFriendList_ApplyTS = 1,
    };

    static const std::string& R_Blacklist();
    enum Blacklist
    {
        Blacklist_PlayerId = 0,
    };

    static const std::string& R_SystemFunction();
    enum SystemFunction
    {
        SystemFunction_FunctionId = 0,
        SystemFunction_Flag = 1,
    };

    static const std::string& R_Course();
    enum Course
    {
        Course_LessonId = 0,
        Course_Status = 1,
    };

    static const std::string& R_Exam();
    enum Exam
    {
        Exam_QuestionId = 0,
        Exam_Options = 1,
        Exam_IsCorrect = 2,
        Exam_IsAnswered = 3,
    };

    static const std::string& R_Subject();
    enum Subject
    {
        Subject_SubjectId = 0,
    };

    static const std::string& R_Notebook();
    enum Notebook
    {
        Notebook_NotebookId = 0,
    };

    static const std::string& R_CollegeSkill();
    enum CollegeSkill
    {
        CollegeSkill_SkillId = 0,
        CollegeSkill_SubjectId = 1,
    };

    static const std::string& R_FinishedTriggerBattles();
    enum FinishedTriggerBattles
    {
        FinishedTriggerBattles_BattleId = 0,
    };

    static const std::string& R_StarRatingBattles();
    enum StarRatingBattles
    {
        StarRatingBattles_GamePlayId = 0,
        StarRatingBattles_StarCondtionPass = 1,
    };

    static const std::string& R_ExploreNode();
    enum ExploreNode
    {
        ExploreNode_Id = 0,
        ExploreNode_State = 1,
        ExploreNode_IsArrived = 2,
    };

    static const std::string& R_ExploreMap();
    enum ExploreMap
    {
        ExploreMap_Id = 0,
        ExploreMap_Position = 1,
        ExploreMap_StarProgress = 2,
        ExploreMap_ArrivedProgress = 3,
    };

    static const std::string& R_ExploreAreaBonus();
    enum ExploreAreaBonus
    {
        ExploreAreaBonus_Id = 0,
        ExploreAreaBonus_TimeStamp = 1,
    };

    static const std::string& R_ExploreMapBonus();
    enum ExploreMapBonus
    {
        ExploreMapBonus_Id = 0,
        ExploreMapBonus_TimeStamp = 1,
    };

    static const std::string& R_ExploreBasic();
    enum ExploreBasic
    {
        ExploreBasic_Id = 0,
        ExploreBasic_IsFirstTimePass = 1,
        ExploreBasic_IsReceivedThreeStarRewards = 2,
    };

    static const std::string& R_ExploreGuider();
    enum ExploreGuider
    {
        ExploreGuider_Id = 0,
        ExploreGuider_Level = 1,
        ExploreGuider_Exp = 2,
    };

    static const std::string& R_ExploreDungeon();
    enum ExploreDungeon
    {
        ExploreDungeon_Id = 0,
        ExploreDungeon_IsAutoBattle = 1,
        ExploreDungeon_DailyCompleteCount = 2,
        ExploreDungeon_IsFirstTimePass = 3,
        ExploreDungeon_ChallengingMonster = 4,
        ExploreDungeon_Flgs = 5,
    };

    static const std::string& R_ExploreDungeonMonsters();
    enum ExploreDungeonMonsters
    {
        ExploreDungeonMonsters_Id = 0,
        ExploreDungeonMonsters_ExploreDungeonId = 1,
        ExploreDungeonMonsters_BattleId = 2,
        ExploreDungeonMonsters_Index = 3,
        ExploreDungeonMonsters_IsComplete = 4,
        ExploreDungeonMonsters_ExtraBonus = 5,
        ExploreDungeonMonsters_ExtraBonusCount = 6,
        ExploreDungeonMonsters_Flgs = 7,
    };

    static const std::string& R_ExploreElite();
    enum ExploreElite
    {
        ExploreElite_Id = 0,
        ExploreElite_ExploreDungeonId = 1,
        ExploreElite_TotalPower = 2,
        ExploreElite_ActiveExploreNode = 3,
        ExploreElite_DeadLineTs = 4,
        ExploreElite_IsFirstTimePass = 5,
    };

    static const std::string& R_ExploreBuilding();
    enum ExploreBuilding
    {
        ExploreBuilding_Id = 0,
        ExploreBuilding_State = 1,
    };

    static const std::string& R_ExploreTask();
    enum ExploreTask
    {
        ExploreTask_Id = 0,
        ExploreTask_BattleId = 1,
    };

    static const std::string& R_ExploreRaid();
    enum ExploreRaid
    {
        ExploreRaid_Id = 0,
        ExploreRaid_SpecialDropHistory = 1,
    };

    static const std::string& R_ExploreTreasureBox();
    enum ExploreTreasureBox
    {
        ExploreTreasureBox_Id = 0,
        ExploreTreasureBox_IsReceived = 1,
    };

    static const std::string& R_Timers();
    enum Timers
    {
        Timers_TimerName = 0,
        Timers_TimerIndex = 1,
    };

    static const std::string& R_AppointArea();
    enum AppointArea
    {
        AppointArea_AreaId = 0,
    };

    static const std::string& R_Affairs();
    enum Affairs
    {
        Affairs_Guid = 0,
        Affairs_AffairId = 1,
        Affairs_WitchId = 2,
        Affairs_StartTS = 3,
        Affairs_EndTS = 4,
        Affairs_AffairState = 5,
        Affairs_UniversalDebrisCount = 6,
        Affairs_StartLevel = 7,
    };

    static const std::string& R_BlessActivated();
    enum BlessActivated
    {
        BlessActivated_Id = 0,
        BlessActivated_StartTs = 1,
        BlessActivated_Count = 2,
    };

    static const std::string& R_BlessEffect();
    enum BlessEffect
    {
        BlessEffect_Type = 0,
        BlessEffect_Parm1 = 1,
        BlessEffect_Parm2 = 2,
        BlessEffect_Parm3 = 3,
        BlessEffect_Parm4 = 4,
    };

    static const std::string& R_PseudoRandom();
    enum PseudoRandom
    {
        PseudoRandom_PseudoRandomId = 0,
        PseudoRandom_SeedList = 1,
        PseudoRandom_SeedListSize = 2,
    };

    static const std::string& R_ActiveMission();
    enum ActiveMission
    {
        ActiveMission_MissionId = 0,
        ActiveMission_MissionUnlockFlag = 1,
        ActiveMission_MissionProgress = 2,
        ActiveMission_MissionStatus = 3,
        ActiveMission_UpdateProgressTS = 4,
    };

    static const std::string& R_BeginningMission();
    enum BeginningMission
    {
        BeginningMission_MissionId = 0,
        BeginningMission_MissionProgress = 1,
        BeginningMission_MissionStatus = 2,
        BeginningMission_UpdateProgressTS = 3,
    };

    static const std::string& R_ExploreMission();
    enum ExploreMission
    {
        ExploreMission_MissionId = 0,
        ExploreMission_MissionProgress = 1,
        ExploreMission_MissionStatus = 2,
        ExploreMission_UpdateProgressTS = 3,
    };

    static const std::string& R_TalentMission();
    enum TalentMission
    {
        TalentMission_MissionId = 0,
        TalentMission_MissionProgress = 1,
        TalentMission_MissionStatus = 2,
        TalentMission_UpdateProgressTS = 3,
    };

    static const std::string& R_DrawCard();
    enum DrawCard
    {
        DrawCard_CardPoolId = 0,
        DrawCard_DrawCardCount = 1,
        DrawCard_TotalDrawCardCount = 2,
        DrawCard_FreeDrawCardFlag = 3,
        DrawCard_FreeDrawCardTimestamp = 4,
        DrawCard_CommonGuaranteeCount = 5,
        DrawCard_GuaranteeRemainCount = 6,
        DrawCard_UpGuaranteeRemainCount = 7,
        DrawCard_IsValid = 8,
    };

    static const std::string& R_PneumaIsland();
    enum PneumaIsland
    {
        PneumaIsland_BossId = 0,
        PneumaIsland_IsPassed = 1,
        PneumaIsland_RewardState = 2,
        PneumaIsland_PassedCount = 3,
    };

    static const std::string& R_PneumaIslandGroup();
    enum PneumaIslandGroup
    {
        PneumaIslandGroup_GroupId = 0,
        PneumaIslandGroup_ShowState = 1,
        PneumaIslandGroup_UnlockedStars = 2,
        PneumaIslandGroup_BossLevel = 3,
    };

    static const std::string& R_PneumaDecompose();
    enum PneumaDecompose
    {
        PneumaDecompose_PneumaType = 0,
        PneumaDecompose_Scheme = 1,
    };

    static const std::string& R_PneumaBag();
    enum PneumaBag
    {
        PneumaBag_PneumaGuid = 0,
        PneumaBag_PneumaId = 1,
        PneumaBag_PneumaStar = 2,
        PneumaBag_PneumaQuality = 3,
        PneumaBag_PneumaMagicHue = 4,
        PneumaBag_AcquireTimestamp = 5,
        PneumaBag_EquippedWitchId = 6,
        PneumaBag_Level = 7,
        PneumaBag_MainAttrId = 8,
        PneumaBag_MainAttrVal = 9,
        PneumaBag_SubAttrId1 = 10,
        PneumaBag_SubAttrVal1 = 11,
        PneumaBag_SubAttrInc1 = 12,
        PneumaBag_SubAttrId2 = 13,
        PneumaBag_SubAttrVal2 = 14,
        PneumaBag_SubAttrInc2 = 15,
        PneumaBag_SubAttrId3 = 16,
        PneumaBag_SubAttrVal3 = 17,
        PneumaBag_SubAttrInc3 = 18,
        PneumaBag_SubAttrId4 = 19,
        PneumaBag_SubAttrVal4 = 20,
        PneumaBag_SubAttrInc4 = 21,
        PneumaBag_SubAttrId5 = 22,
        PneumaBag_SubAttrVal5 = 23,
        PneumaBag_SubAttrInc5 = 24,
        PneumaBag_NormalItemCost = 25,
        PneumaBag_SpecialItemCost = 26,
    };

    static const std::string& R_PneumaCreation();
    enum PneumaCreation
    {
        PneumaCreation_PneumaId = 0,
        PneumaCreation_MaxQuality1 = 1,
        PneumaCreation_MaxQuality2 = 2,
        PneumaCreation_MaxQuality3 = 3,
        PneumaCreation_MaxQuality4 = 4,
        PneumaCreation_MaxQuality5 = 5,
        PneumaCreation_MaxQuality6 = 6,
    };

    static const std::string& R_MailBox();
    enum MailBox
    {
        MailBox_Id = 0,
        MailBox_PromptId = 1,
        MailBox_Title = 2,
        MailBox_Context = 3,
        MailBox_Sender = 4,
        MailBox_Parms = 5,
        MailBox_OrginalRewards = 6,
        MailBox_RemainRewards = 7,
        MailBox_CreateTs = 8,
        MailBox_Deadline = 9,
        MailBox_State = 10,
        MailBox_TimerIdx = 11,
    };

    static const std::string& R_ChatReportList();
    enum ChatReportList
    {
        ChatReportList_ReportType = 0,
        ChatReportList_ReportCount = 1,
        ChatReportList_HandleCount = 2,
    };

    static const std::string& R_ChatBubbles();
    enum ChatBubbles
    {
        ChatBubbles_BubbleId = 0,
    };

    static const std::string& R_ChatMemeGroups();
    enum ChatMemeGroups
    {
        ChatMemeGroups_MemeGroupId = 0,
    };

    static const std::string& R_ChatMemes();
    enum ChatMemes
    {
        ChatMemes_MemeId = 0,
    };

    static const std::string& R_GuideGroups();
    enum GuideGroups
    {
        GuideGroups_GuideGroupId = 0,
        GuideGroups_State = 1,
    };

    static const std::string& R_StoryBranch();
    enum StoryBranch
    {
        StoryBranch_ChapterID = 0,
        StoryBranch_ModuleID = 1,
        StoryBranch_ChapterStatus = 2,
        StoryBranch_UnlockConditionID = 3,
    };

    static const std::string& R_AnswerQuestions();
    enum AnswerQuestions
    {
        AnswerQuestions_QuestionId = 0,
    };

    static const std::string& R_ActivityList();
    enum ActivityList
    {
        ActivityList_Id = 0,
        ActivityList_Type = 1,
        ActivityList_State = 2,
        ActivityList_ShowTime = 3,
        ActivityList_StartTime = 4,
        ActivityList_EndTime = 5,
        ActivityList_CloseTime = 6,
    };

    static const std::string& R_ActivityData();
    enum ActivityData
    {
        ActivityData_Id = 0,
        ActivityData_Progress = 1,
        ActivityData_State = 2,
        ActivityData_UpdateProgressTS = 3,
    };

};

class Pneuma
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& BossType();
    static const std::string& PneumaType();
    static const std::string& Skill_1();
    static const std::string& SkillAttrData_1();
    static const std::string& Skill_2();
    static const std::string& SkillAttrData_2();
    static const std::string& Skill_3();
    static const std::string& SkillAttrData_3();
    static const std::string& Skill_4();
    static const std::string& SkillAttrData_4();
    static const std::string& Skill_5();
    static const std::string& SkillAttrData_5();
    static const std::string& Skill_6();
    static const std::string& SkillAttrData_6();
};

class PneumaAttr
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& SubAttrData();
    static const std::string& DataType();
    static const std::string& AttrId();
    static const std::string& AttrData();
    static const std::string& Weight();
    static const std::string& AttrGrowth();
    static const std::string& BasicFight();
    static const std::string& TypeWeight();
};

class PneumaBook
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& PneumaId();
    static const std::string& JigsawItem();
    static const std::string& JigsawExp();
    static const std::string& Condition();
    static const std::string& ConditionConversion();
    static const std::string& UpGrade();
};

class PneumaCreate
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& PneumaID();
    static const std::string& PneumaStar();
    static const std::string& PneumaQuality();
    static const std::string& PneumaMagicHue();
    static const std::string& MaterialData();
    static const std::string& AttrData();
};

class PneumaIslandBoss
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Level();
    static const std::string& UnlockCondition();
    static const std::string& BossGroupID();
    static const std::string& BossResource();
    static const std::string& BattleID();
    static const std::string& StarReward();
    static const std::string& Cost();
    static const std::string& PneumaType();
    static const std::string& FixedDrop();
    static const std::string& FirstDrop();
    static const std::string& MainDrop();
    static const std::string& MinorDrop();
};

class PneumaIslandGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& PneumaIslandBossID();
};

class PneumaStrong
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Star();
    static const std::string& Quality();
    static const std::string& MainAttrData();
    static const std::string& SideAttrData();
    static const std::string& InitSideAttrNum();
    static const std::string& IntensifyCostGold();
    static const std::string& IntensifyCostNormal();
    static const std::string& IntensifyCostSpecial();
    static const std::string& SmeltValueNormal();
    static const std::string& SmeltValueSpecial();
    static const std::string& CreateCostGold();
    static const std::string& CreateCostMet();
    static const std::string& IntensifyLimit();
};

class Poker
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Name();
    static const std::string& Desc();
    static const std::string& Picture();
    static const std::string& RewardData();
};

class PokerHands
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Name();
    static const std::string& Desc();
    static const std::string& Picture();
    static const std::string& Stage1Othe();
    static const std::string& Stage2Othe();
    static const std::string& Stage3Othe();
    static const std::string& Stage4Othe();
    static const std::string& CrystalBallRes();
    static const std::string& EffectType();
    static const std::string& EffectData();
};

class Prompt
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& TypeValue();
    static const std::string& BroadcastRange();
};

class Protagonist
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ConditionId();
};

class PseudoRandom
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RandomProbability();
};

class Question
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Option();
    static const std::string& Answer();
};

class QuestionAnswer
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Option();
    static const std::string& Answer();
    static const std::string& Condition();
    static const std::string& RightReward();
    static const std::string& WrongReward();
};

class QuestionStageReward
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RightNum();
    static const std::string& RewardData();
};

class QueueUpServer
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& AesKey();
    static const std::string& AesIv();
    static const std::string& TicketDeadLineTimeStamp();
    static const std::string& TicketExpiredTimesLimit();
    static const std::string& PrivilegePoolSize();
    static const std::string& SyncWorldFrequency();
    static const std::string& KeepOnlineStatus();
    static const std::string& KeepOnlineTS();
    static const std::string& QTBTokenGenerationRate();
    static const std::string& QTBBucketSize();
    static const std::string& STBTokenGenerationRate();
    static const std::string& STBBucketSize();
};

class QuintusFunciton
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Name();
    static const std::string& FunctionId();
    static const std::string& FunctionPoint();
    static const std::string& InteractType();
    static const std::string& InteractTypeData();
};

class Random
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Remarks();
    static const std::string& RandomType();
    static const std::string& DropData();
};

class RandomName
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& FirstName();
    static const std::string& Name();
};

class Recharge
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Remarks();
    static const std::string& BasicGoods();
    static const std::string& ExtraGoods();
};

class Resource
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Name();
    static const std::string& ResourceType();
    static const std::string& Quality();
    static const std::string& InitNum();
    static const std::string& MaxValue();
    static const std::string& OverflowHandling();
    static const std::string& Type();
    static const std::string& CanNotStack();
};

class RoleRes
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& QualityType();
    static const std::string& IsUnLocked();
    static const std::string& AttrData();
    static const std::string& BasicFight();
};

class Scene
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& PlayerNumType();
    static const std::string& LeftBottom();
    static const std::string& RightTop();
    static const std::string& CellWidth();
    static const std::string& PlayerNumData();
    static const std::string& TriggerIdData();
};

class SceneType
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& GroupType();
};

class Semester
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Index();
    static const std::string& LessonData();
    static const std::string& RewardData();
    static const std::string& StartStoryId();
    static const std::string& EndStoryId();
    static const std::string& NextSemester();
    static const std::string& FinalTestId();
};

class ServiceRoute
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& SourceType();
    static const std::string& TargetType();
};

class Shop
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ShopType();
    static const std::string& TabType();
    static const std::string& SubTabIds();
    static const std::string& ShopGoodsId();
    static const std::string& Conditions();
    static const std::string& ReLockConditions();
};

class ShopGoods
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& SellType();
    static const std::string& SellContent();
    static const std::string& BuyCost();
    static const std::string& MaxSellCount();
    static const std::string& OnceMaxBuyCount();
    static const std::string& RefreshTime();
    static const std::string& SellPeriod();
    static const std::string& Conditions();
};

class SignIn
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& RewardData();
    static const std::string& PokerData();
};

class SqlServer
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ServerID();
    static const std::string& IP();
    static const std::string& Port();
    static const std::string& User();
    static const std::string& Password();
    static const std::string& DbName();
    static const std::string& Zone();
};

class Star
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& WitchID();
    static const std::string& CostData();
    static const std::string& AttrReward();
    static const std::string& LevelUpReward();
    static const std::string& BasicFight();
};

class Stories
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Condition();
    static const std::string& ModuleSideData();
};

class Subject
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ConditionType();
    static const std::string& ConditionData();
    static const std::string& Scene();
};

class SystemFunction
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Name();
    static const std::string& ConditionId();
    static const std::string& FunctionType();
    static const std::string& ChildFunction();
    static const std::string& UnlockStory();
};

class Talent
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& UnlockCondition();
    static const std::string& TalentMission1();
    static const std::string& TalentMission2();
};

class TalentMission
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
    static const std::string& ObjectType();
    static const std::string& ObjectValue();
    static const std::string& BattleId();
    static const std::string& Reward();
};

class Tips
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Type();
};

class Tower
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Level();
    static const std::string& TowerGroupID();
    static const std::string& BattleID();
    static const std::string& Cost();
    static const std::string& FixedDrop();
    static const std::string& SweptDrop();
};

class TowerGroup
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& PneumaIslandBossID();
};

class TowerSwept
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& SweptDrop();
    static const std::string& ProbabilityDrop();
};

class UnicodeCharacterRanges
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Min();
    static const std::string& Max();
    static const std::string& CharacterLength();
};

class Voice
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Condition();
};

class Witch
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& Rare();
    static const std::string& Class();
    static const std::string& ClassAttrMod();
    static const std::string& AttrDataId();
    static const std::string& AdvantagePeriodType();
    static const std::string& RoleResIdData();
    static const std::string& AiType();
    static const std::string& AiData();
    static const std::string& Skills();
    static const std::string& TalentSkill();
    static const std::string& TalentSkillBand();
    static const std::string& FavoriteGiftList();
    static const std::string& GenericGiftList();
    static const std::string& BoringGiftList();
    static const std::string& DispatchEmoData();
    static const std::string& FragmentItem();
    static const std::string& FragmentValue();
    static const std::string& FilesData();
    static const std::string& Talent();
    static const std::string& Team();
    static const std::string& AssociatedPlayer();
    static const std::string& PossessionPlayer();
    static const std::string& Pos();
    static const std::string& Level();
    static const std::string& Seq();
    static const std::string& DeadSeq();
    static const std::string& Disable();
    static const std::string& RoleResId();
    static const std::string& Hp();
    static const std::string& HpMax();
    static const std::string& Shield();
    static const std::string& ShieldMax();
    static const std::string& HitRate();
    static const std::string& ResistRate();
    static const std::string& ResistProbQueue();
    static const std::string& Totem();
    static const std::string& NpcId();
    static const std::string& SpeedThreshold();
    static const std::string& AdvantagePeriod();
    static const std::string& ShowAdvantage();
    static const std::string& AutomaticRole();
    static const std::string& BattleFight();
    static const std::string& StarLevel();
    static const std::string& BuffState();
    static const std::string& ExtraAction();
    static const std::string& FinishAction();
    static const std::string& MercenaryUnitInfo();
    static const std::string& RandSpeedSeq();
    static const std::string& PneumaInfo();
    static const std::string& DamageValue();
    static const std::string& ReceiveDamge();
    static const std::string& HealValue();
    static const std::string& Assistor();
    static const std::string& UsedSkills();
    //Record
    static const std::string& R_Skill();
    enum Skill
    {
        Skill_SkillId = 0,
        Skill_Level = 1,
        Skill_Cd = 2,
        Skill_Consume = 3,
        Skill_LastTargets = 4,
        Skill_IsSealed = 5,
        Skill_Effects = 6,
        Skill_UseTimes = 7,
        Skill_SelfRoundUsed = 8,
        Skill_StoreValue = 9,
    };

    static const std::string& R_BuffList();
    enum BuffList
    {
        BuffList_BuffGuid = 0,
        BuffList_BuffId = 1,
        BuffList_Level = 2,
        BuffList_Caster = 3,
        BuffList_LeftRound = 4,
        BuffList_TimeType = 5,
        BuffList_AvoidDispel = 6,
        BuffList_SealData = 7,
        BuffList_BuffValue = 8,
    };

    static const std::string& R_AppliedBuffEffects();
    enum AppliedBuffEffects
    {
        AppliedBuffEffects_Id = 0,
        AppliedBuffEffects_CustomData = 1,
    };

    static const std::string& R_AttrData();
    enum AttrData
    {
        AttrData_Hp = 0,
        AttrData_Defence = 1,
        AttrData_Speed = 2,
        AttrData_Attack = 3,
        AttrData_Crit = 4,
        AttrData_CritDmg = 5,
        AttrData_Hit = 6,
        AttrData_Resist = 7,
    };

    static const std::string& R_HitProbQueue();
    enum HitProbQueue
    {
        HitProbQueue_QueueId = 0,
        HitProbQueue_Data = 1,
    };

};

class Zone
{
public:
    static const std::string& ThisName();
    static const std::string& ID();
    static const std::string& ClassName();
    static const std::string& SceneID();
    static const std::string& GroupID();
    static const std::string& ConfigID();
    static const std::string& Position();
    static const std::string& Orientation();
    //Property
    static const std::string& ZoneId();
    static const std::string& TimeZone();
    static const std::string& QueueUpServerId();
    static const std::string& ServerMaximumLoadLimit();
    static const std::string& OnlinePlayerBufferLimit();
    static const std::string& CreateCharacterLimit();
};

} // namespace KWFrame
#endif
