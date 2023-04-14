#ifndef KW_CLASS_DEFINE_HPP
#define KW_CLASS_DEFINE_HPP

#include <string>
namespace KWFrame
{
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
    static const std::string& MissionType();
    static const std::string& MissionSubType();
    static const std::string& UnlockType();
    static const std::string& UnlockValue();
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
    static const std::string& HpGrowth();
    static const std::string& Defence();
    static const std::string& DefenceGrowth();
    static const std::string& Speed();
    static const std::string& SpeedGrowth();
    static const std::string& AttackMin();
    static const std::string& AttackMinGrowth();
    static const std::string& AttackMax();
    static const std::string& AttackMaxGrowth();
    static const std::string& Crit();
    static const std::string& CritGrowth();
    static const std::string& CritDmg();
    static const std::string& CritDmgGrowth();
    static const std::string& Hit();
    static const std::string& HitGrowth();
    static const std::string& Resist();
    static const std::string& ResistGrowth();
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
    static const std::string& Type();
    static const std::string& Scene();
    static const std::string& Feature();
    static const std::string& MemberNum();
    static const std::string& JoinCondition();
    static const std::string& NpcData();
    static const std::string& Operable();
    static const std::string& EnemyData();
    static const std::string& Fight();
    static const std::string& WinCondition();
    static const std::string& LoseCondition();
    static const std::string& StarCondition();
    static const std::string& MaxRound();
    static const std::string& ClashReward();
    static const std::string& BattleSetData();
    static const std::string& BattleTrigger();
    static const std::string& TriggerDisposable();
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
    static const std::string& Level();
    static const std::string& Gain();
    static const std::string& Type();
    static const std::string& Effects();
    static const std::string& Event();
    static const std::string& EffectType();
    static const std::string& Rate();
    static const std::string& LazyEffects();
    static const std::string& Time();
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
    static const std::string& LevelUp();
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
    static const std::string& Effects();
    static const std::string& Rate();
    static const std::string& DirectorId();
    static const std::string& UnlockConditions();
    static const std::string& UnlockMartial();
    static const std::string& UnlockCost();
    static const std::string& NextSkill();
    static const std::string& CurLv();
    static const std::string& MaxLv();
    static const std::string& Cd();
    static const std::string& Cost();
    static const std::string& UseTimes();
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
    static const std::string& CritThreshold();
    static const std::string& HitThreshold();
    static const std::string& ResistThreshold();
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
    static const std::string& BotArenaChallengeId();
    static const std::string& BotArenaReplayId();
    static const std::string& BotArenaChallengeResult();
    static const std::string& BotArenaAttackEntityId();
    static const std::string& BotArenaDefensiveEntityId();
    static const std::string& BotArenaDefensiveEntityInfo();
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
        Team_Cristal = 1,
        Team_MagicHue = 2,
        Team_Energy = 3,
        Team_Name = 4,
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
    static const std::string& RewardData();
    static const std::string& ValidTime();
    static const std::string& WorkingTime();
    static const std::string& AreaTypeData();
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
    static const std::string& RegionType();
    static const std::string& UnlockCondition();
    static const std::string& DispatchSceneID();
};

class DispatchFunction
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
    static const std::string& UnlockLevelData();
};

class DispatchLevel
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
    static const std::string& LevelUpData();
    static const std::string& ExpReward();
    static const std::string& ExpRewardTime();
    static const std::string& GoldReward();
    static const std::string& GoldRewardTime();
    static const std::string& ContributionReward();
    static const std::string& ContributionRewardTime();
    static const std::string& GiftReward();
    static const std::string& GiftRewardTime();
    static const std::string& AffairReward();
    static const std::string& AffairRewardTime();
    static const std::string& FunctionUnlock();
    static const std::string& PrestigeUpgrade();
    static const std::string& ExpOverflowLevel();
    static const std::string& TimeLimit();
    static const std::string& QuickCollect();
    static const std::string& WitchRewardData();
};

class DispatchPosition
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
    static const std::string& AreaData();
    static const std::string& AreaTypeData();
};

class DispatchRegion
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
    static const std::string& AreaData();
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
    static const std::string& AttrType();
    static const std::string& Rare();
    static const std::string& SubType();
    static const std::string& MonsterId();
    static const std::string& LevelType();
    static const std::string& LevelTypeData();
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
    static const std::string& Witch();
    static const std::string& Power();
    static const std::string& AttrReward();
    static const std::string& BasicFight();
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
    static const std::string& Map();
    static const std::string& ExtraUnlockCondition();
    static const std::string& Type();
    static const std::string& IsMainNode();
    static const std::string& IsImportantSideNode();
    static const std::string& EventFirstDrop();
    static const std::string& EventMustDrop();
    static const std::string& EventMainDrop();
    static const std::string& EventMinorDrop();
    static const std::string& EventMopExtraDrop();
    static const std::string& EventConsume();
    static const std::string& MopConsume();
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
    static const std::string& LevelUpReward();
    static const std::string& BasicFight();
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
    static const std::string& StartCondition();
    static const std::string& FinishCondition();
    static const std::string& OperationType();
    static const std::string& NextGuideID();
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
    static const std::string& ServerCheckType();
    static const std::string& ConditionValue();
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
};

class GuideTrigger
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
    static const std::string& CostData();
    static const std::string& MetData();
    static const std::string& StageCondition();
    static const std::string& LevelCondition();
    static const std::string& AttrReward();
    static const std::string& BasicFight();
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
    static const std::string& CostData();
    static const std::string& MetData();
    static const std::string& LevelCondition();
    static const std::string& AttrReward();
    static const std::string& BasicFight();
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
    static const std::string& LotteryNum();
    static const std::string& FreeLotteryType();
    static const std::string& ColdDownTime();
    static const std::string& LotteryItem();
    static const std::string& LotteryCostType();
    static const std::string& LotteryCostValue();
    static const std::string& FloorsValue();
    static const std::string& MainFloors();
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
    static const std::string& ModuleIndex();
    static const std::string& Chapter();
    static const std::string& Scene();
    static const std::string& ImageScene();
    static const std::string& Battle();
    static const std::string& BattleDrop();
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
        AttrData_AttackMin = 3,
        AttrData_AttackMax = 4,
        AttrData_Crit = 5,
        AttrData_CritDmg = 6,
        AttrData_Hit = 7,
        AttrData_Resist = 8,
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
    static const std::string& DailyFreeRefreshCountBM();
    static const std::string& DailyTotalRefreshCountBM();
    static const std::string& RefreshRecommendedListTS();
    static const std::string& FindPlayerTS();
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
    static const std::string& SigninPokerRewards();
    static const std::string& LastFinishedSigninTs();
    static const std::string& ContinuousSigninNum();
    static const std::string& ContributionLevel();
    static const std::string& Contribution();
    static const std::string& CurAppointArea();
    static const std::string& AppointStartTs();
    static const std::string& AppointAccumulativeTime();
    static const std::string& AppointState();
    static const std::string& WitchFragmentCount();
    static const std::string& WitchFragmentReward();
    static const std::string& NextSwitchAreaTs();
    static const std::string& CurMessagerId();
    static const std::string& ExpWitch();
    static const std::string& Intimacy();
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
    static const std::string& ChatPasswd();
    static const std::string& ChatBubble();
    static const std::string& ReportChatCount();
    static const std::string& ForbiddenChatTs();
    //Record
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
        BattleWitchTeam_GamePlayName = 0,
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
        FightingCapacity_TotalFC = 1,
        FightingCapacity_LevelFC = 2,
        FightingCapacity_EmotionFC = 3,
        FightingCapacity_SkinFC = 4,
        FightingCapacity_StarLevelFC = 5,
        FightingCapacity_KnowledgeFC = 6,
        FightingCapacity_PneumaFC = 7,
    };

    static const std::string& R_WitchAttr_Hp();
    enum WitchAttr_Hp
    {
        WitchAttr_Hp_WitchId = 0,
        WitchAttr_Hp_Total = 1,
        WitchAttr_Hp_Base = 2,
        WitchAttr_Hp_BaseGrowth = 3,
        WitchAttr_Hp_EmotionLevel = 4,
        WitchAttr_Hp_StarLevel = 5,
        WitchAttr_Hp_Knowledge = 6,
        WitchAttr_Hp_PneumaVal = 7,
        WitchAttr_Hp_PneumaPercent = 8,
        WitchAttr_Hp_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_Defence();
    enum WitchAttr_Defence
    {
        WitchAttr_Defence_WitchId = 0,
        WitchAttr_Defence_Total = 1,
        WitchAttr_Defence_Base = 2,
        WitchAttr_Defence_BaseGrowth = 3,
        WitchAttr_Defence_EmotionLevel = 4,
        WitchAttr_Defence_StarLevel = 5,
        WitchAttr_Defence_Knowledge = 6,
        WitchAttr_Defence_PneumaVal = 7,
        WitchAttr_Defence_PneumaPercent = 8,
        WitchAttr_Defence_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_Speed();
    enum WitchAttr_Speed
    {
        WitchAttr_Speed_WitchId = 0,
        WitchAttr_Speed_Total = 1,
        WitchAttr_Speed_Base = 2,
        WitchAttr_Speed_BaseGrowth = 3,
        WitchAttr_Speed_EmotionLevel = 4,
        WitchAttr_Speed_StarLevel = 5,
        WitchAttr_Speed_Knowledge = 6,
        WitchAttr_Speed_PneumaVal = 7,
        WitchAttr_Speed_PneumaPercent = 8,
        WitchAttr_Speed_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_AttackMin();
    enum WitchAttr_AttackMin
    {
        WitchAttr_AttackMin_WitchId = 0,
        WitchAttr_AttackMin_Total = 1,
        WitchAttr_AttackMin_Base = 2,
        WitchAttr_AttackMin_BaseGrowth = 3,
        WitchAttr_AttackMin_EmotionLevel = 4,
        WitchAttr_AttackMin_StarLevel = 5,
        WitchAttr_AttackMin_Knowledge = 6,
        WitchAttr_AttackMin_PneumaVal = 7,
        WitchAttr_AttackMin_PneumaPercent = 8,
        WitchAttr_AttackMin_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_AttackMax();
    enum WitchAttr_AttackMax
    {
        WitchAttr_AttackMax_WitchId = 0,
        WitchAttr_AttackMax_Total = 1,
        WitchAttr_AttackMax_Base = 2,
        WitchAttr_AttackMax_BaseGrowth = 3,
        WitchAttr_AttackMax_EmotionLevel = 4,
        WitchAttr_AttackMax_StarLevel = 5,
        WitchAttr_AttackMax_Knowledge = 6,
        WitchAttr_AttackMax_PneumaVal = 7,
        WitchAttr_AttackMax_PneumaPercent = 8,
        WitchAttr_AttackMax_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_Crit();
    enum WitchAttr_Crit
    {
        WitchAttr_Crit_WitchId = 0,
        WitchAttr_Crit_Total = 1,
        WitchAttr_Crit_Base = 2,
        WitchAttr_Crit_BaseGrowth = 3,
        WitchAttr_Crit_EmotionLevel = 4,
        WitchAttr_Crit_StarLevel = 5,
        WitchAttr_Crit_Knowledge = 6,
        WitchAttr_Crit_PneumaVal = 7,
        WitchAttr_Crit_PneumaPercent = 8,
        WitchAttr_Crit_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_CritDmg();
    enum WitchAttr_CritDmg
    {
        WitchAttr_CritDmg_WitchId = 0,
        WitchAttr_CritDmg_Total = 1,
        WitchAttr_CritDmg_Base = 2,
        WitchAttr_CritDmg_BaseGrowth = 3,
        WitchAttr_CritDmg_EmotionLevel = 4,
        WitchAttr_CritDmg_StarLevel = 5,
        WitchAttr_CritDmg_Knowledge = 6,
        WitchAttr_CritDmg_PneumaVal = 7,
        WitchAttr_CritDmg_PneumaPercent = 8,
        WitchAttr_CritDmg_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_Hit();
    enum WitchAttr_Hit
    {
        WitchAttr_Hit_WitchId = 0,
        WitchAttr_Hit_Total = 1,
        WitchAttr_Hit_Base = 2,
        WitchAttr_Hit_BaseGrowth = 3,
        WitchAttr_Hit_EmotionLevel = 4,
        WitchAttr_Hit_StarLevel = 5,
        WitchAttr_Hit_Knowledge = 6,
        WitchAttr_Hit_PneumaVal = 7,
        WitchAttr_Hit_PneumaPercent = 8,
        WitchAttr_Hit_PneumaTotal = 9,
    };

    static const std::string& R_WitchAttr_Resist();
    enum WitchAttr_Resist
    {
        WitchAttr_Resist_WitchId = 0,
        WitchAttr_Resist_Total = 1,
        WitchAttr_Resist_Base = 2,
        WitchAttr_Resist_BaseGrowth = 3,
        WitchAttr_Resist_EmotionLevel = 4,
        WitchAttr_Resist_StarLevel = 5,
        WitchAttr_Resist_Knowledge = 6,
        WitchAttr_Resist_PneumaVal = 7,
        WitchAttr_Resist_PneumaPercent = 8,
        WitchAttr_Resist_PneumaTotal = 9,
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

    static const std::string& R_Blackmart();
    enum Blackmart
    {
        Blackmart_CommodityId = 0,
        Blackmart_BuyCount = 1,
        Blackmart_DiscountRate = 2,
        Blackmart_IsUnlock = 3,
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
        ExploreNode_EventId = 2,
    };

    static const std::string& R_ExploreMap();
    enum ExploreMap
    {
        ExploreMap_Id = 0,
        ExploreMap_Position = 1,
        ExploreMap_StarCount = 2,
    };

    static const std::string& R_ExploreAreaBonus();
    enum ExploreAreaBonus
    {
        ExploreAreaBonus_Id = 0,
        ExploreAreaBonus_TimeStamp = 1,
    };

    static const std::string& R_ExploreMapStarBonus();
    enum ExploreMapStarBonus
    {
        ExploreMapStarBonus_Id = 0,
        ExploreMapStarBonus_TimeStamp = 1,
    };

    static const std::string& R_ExploreMapBranchlineBonus();
    enum ExploreMapBranchlineBonus
    {
        ExploreMapBranchlineBonus_Id = 0,
        ExploreMapBranchlineBonus_TimeStamp = 1,
    };

    static const std::string& R_ExploreGuider();
    enum ExploreGuider
    {
        ExploreGuider_Id = 0,
        ExploreGuider_Level = 1,
        ExploreGuider_Exp = 2,
    };

    static const std::string& R_Timers();
    enum Timers
    {
        Timers_TimerName = 0,
        Timers_TimerIndex = 1,
    };

    static const std::string& R_DispatchFunction();
    enum DispatchFunction
    {
        DispatchFunction_FunctionId = 0,
    };

    static const std::string& R_AppointArea();
    enum AppointArea
    {
        AppointArea_AreaId = 0,
    };

    static const std::string& R_AppointReward();
    enum AppointReward
    {
        AppointReward_RewardId = 0,
        AppointReward_Count = 1,
    };

    static const std::string& R_AppointRewardTime();
    enum AppointRewardTime
    {
        AppointRewardTime_RewardColName = 0,
        AppointRewardTime_LastRewardTs = 1,
        AppointRewardTime_UnrewardedTime = 2,
    };

    static const std::string& R_Affairs();
    enum Affairs
    {
        Affairs_Guid = 0,
        Affairs_AffairId = 1,
        Affairs_DeleteTs = 2,
    };

    static const std::string& R_AffairPosition();
    enum AffairPosition
    {
        AffairPosition_PositionId = 0,
        AffairPosition_AffairId = 1,
        AffairPosition_WitchId = 2,
        AffairPosition_DeadlineTs = 3,
    };

    static const std::string& R_Bless();
    enum Bless
    {
        Bless_Id = 0,
        Bless_StartTs = 1,
        Bless_Count = 2,
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
        ActiveMission_MissionType = 1,
        ActiveMission_MissionUnlockFlag = 2,
        ActiveMission_MissionProgress = 3,
        ActiveMission_MissionStatus = 4,
    };

    static const std::string& R_DrawCard();
    enum DrawCard
    {
        DrawCard_CardPoolId = 0,
        DrawCard_DrawCardCount = 1,
        DrawCard_FreeDrawCardFlag = 2,
        DrawCard_FreeDrawCardTimestamp = 3,
        DrawCard_GuaranteeRemainCount = 4,
    };

    static const std::string& R_PneumaIsland();
    enum PneumaIsland
    {
        PneumaIsland_BossId = 0,
        PneumaIsland_IsPassed = 1,
        PneumaIsland_RewardState = 2,
    };

    static const std::string& R_PneumaIslandGroup();
    enum PneumaIslandGroup
    {
        PneumaIslandGroup_GroupId = 0,
        PneumaIslandGroup_ShowState = 1,
        PneumaIslandGroup_UnlockedStars = 2,
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
        PneumaBag_FightVal = 8,
        PneumaBag_MainAttrId = 9,
        PneumaBag_MainAttrVal = 10,
        PneumaBag_SubAttrId1 = 11,
        PneumaBag_SubAttrVal1 = 12,
        PneumaBag_SubAttrInc1 = 13,
        PneumaBag_SubAttrId2 = 14,
        PneumaBag_SubAttrVal2 = 15,
        PneumaBag_SubAttrInc2 = 16,
        PneumaBag_SubAttrId3 = 17,
        PneumaBag_SubAttrVal3 = 18,
        PneumaBag_SubAttrInc3 = 19,
        PneumaBag_SubAttrId4 = 20,
        PneumaBag_SubAttrVal4 = 21,
        PneumaBag_SubAttrInc4 = 22,
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
        MailBox_Rewards = 6,
        MailBox_CreateTs = 7,
        MailBox_Deadline = 8,
        MailBox_State = 9,
        MailBox_TimerIdx = 10,
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
    static const std::string& Skill();
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
    static const std::string& AttrType();
    static const std::string& AttrId();
    static const std::string& AttrData();
    static const std::string& Weight();
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
    static const std::string& SmeltOutPut();
    static const std::string& BasicFight();
    static const std::string& IntensifyFight();
    static const std::string& SideAttrFight();
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
    static const std::string& ConditionId();
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
    static const std::string& Quality();
    static const std::string& InitNum();
    static const std::string& MaxValue();
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
    static const std::string& SellContent();
    static const std::string& BuyCost();
    static const std::string& MaxSellCount();
    static const std::string& OnceMaxBuyCount();
    static const std::string& RefreshTime();
    static const std::string& SellPeriod();
    static const std::string& Conditions();
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
    static const std::string& AttrDataId();
    static const std::string& AdvantagePeriodType();
    static const std::string& RoleResIdData();
    static const std::string& AiType();
    static const std::string& AiData();
    static const std::string& Skills();
    static const std::string& FavoriteGiftList();
    static const std::string& GenericGiftList();
    static const std::string& BoringGiftList();
    static const std::string& DispatchEmoData();
    static const std::string& FragmentItem();
    static const std::string& FragmentValue();
    static const std::string& Team();
    static const std::string& AssociatedPlayer();
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
        AttrData_AttackMin = 3,
        AttrData_AttackMax = 4,
        AttrData_Crit = 5,
        AttrData_CritDmg = 6,
        AttrData_Hit = 7,
        AttrData_Resist = 8,
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
