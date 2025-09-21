.set LOCALID_VICTOR, 1
.set LOCALID_VICTORIA, 2
.set LOCALID_VIVI, 3
.set LOCALID_VICKY, 4
.set LOCALID_ROCK_SMASH_MAN, 35
.set LOCALID_REPORTER, 39
.set LOCALID_CAMERAMAN, 40
.set LOCALID_STEVEN, 37
.set LOCALID_KRILL, 36
.set LOCALID_SAMIR, 38
.set LOCALID_TOWERMAN, 41

@ Note: LOCALID_ROUTE111_PLAYER_FALLING is a local id for this map used elsewhere. It's defined in event_objects.h

Route111_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
	end

Route111_EventScript_CloseDesertRuins::
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
	return

@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
Route111_EventScript_ShowTemporaryMirageTower::
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
	return

Route111_OnTransition:
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special SetMirageTowerVisibility
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
	call_if_eq VAR_ROUTE111_MEGA, 2, Route111_EventScript_SetSteven
	call_if_eq VAR_ROUTE111_MEGA, 4, Route111_EventScript_BlockTower
	call_if_eq VAR_ROUTE111_MEGA, 5, Route111_EventScript_SetSteven
	call_if_eq VAR_ROUTE111_MEGA, 6, Route111_EventScript_SetSteven
	call Route111_EventScript_CheckSetSandstorm
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
	end

Route111_EventScript_BlockTower::
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	return

Route111_EventScript_SetFallingPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
	return

Route111_EventScript_SetFallingPlayerGfxMale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Route111_EventScript_SetFallingPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

Route111_EventScript_CheckSetSandstorm::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
Route111_EventScript_SetSandstorm::
	setweather WEATHER_SANDSTORM
Route111_EventScript_EndCheckSetSandstorm::
	return

Route111_EventScript_SetWinstratesNotDefeated::
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_SetLayoutNoMirageTower::
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
	return

Route111_EventScript_SetMirageTowerGone::
	setvar VAR_MIRAGE_TOWER_STATE, 3
	return

Route111_OnWarp:
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
	.2byte 0

Route111_EventScript_HidePlayerForMirageTower::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	end

Route111_OnFrame:
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
	map_script_2 VAR_ROUTE111_MEGA, 3, Route111_EventScript_LostKrill
	map_script_2 VAR_ROUTE111_MEGA, 7, Route111_EventScript_DoorManLost
	.2byte 0

Route111_EventScript_MirageTowerDisappear::
	lockall
	special StartMirageTowerShake
	waitstate
	delay 24
	playse SE_FALL
	addobject LOCALID_ROUTE111_PLAYER_FALLING
	special StartPlayerDescendMirageTower
	waitstate
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 16
	special StartMirageTowerDisintegration
	waitstate
	special StartMirageTowerFossilFallAndSink
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 2
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_RootFossilDisappeared::
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

@ Unused
Route111_Movement_PlayerFall::
	lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_Girl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
	giveitem ITEM_RAZZ_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ReceivedBerry::
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
	release
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerUp::
	lockall
	setvar VAR_0x8004, 0
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerDown::
	lockall
	setvar VAR_0x8004, 1
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerLeft::
	lockall
	setvar VAR_0x8004, 2
	goto Route111_EventScript_ViciousSandstormTrigger
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerRight::
	lockall
	setvar VAR_0x8004, 3
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTrigger::
	checkitem ITEM_GO_GOGGLES
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, 1
	releaseall
	end

Route111_EventScript_PreventRouteAccess::
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
	releaseall
	end

Route111_EventScript_PushUpFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
	waitmovement 0
	return

Route111_EventScript_PushDownFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
	waitmovement 0
	return

Route111_EventScript_PushLeftFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
	waitmovement 0
	return

Route111_EventScript_PushRightFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
	waitmovement 0
	return

Route111_Movement_PushUpFromRoute:
	walk_up
	step_end

Route111_Movement_PushDownFromRoute:
	walk_down
	step_end

Route111_Movement_PushLeftFromRoute:
	walk_left
	step_end

Route111_Movement_PushRightFromRoute:
	walk_right
	step_end

Route111_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	fadenewbgm MUS_ROUTE110
	doweather
	setvar VAR_TEMP_3, 0
	end

Route111_EventScript_SandstormTrigger::
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_DESERT
	doweather
	end

Route111_EventScript_Victor::
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_BattleWinstrates::
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICTOR
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VICTORIA
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICTORIA
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VIVI
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VIVI
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VICKY
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICKY
	call Route111_EventScript_CloseWinstrateDoor
	release
	end

Route111_EventScript_OpenWinstrateDoor::
	opendoor 13, 113
	waitdooranim
	return

Route111_EventScript_CloseWinstrateDoor::
	closedoor 13, 113
	waitdooranim
	return

Route111_Movement_WinstrateEnterHouse:
	walk_in_place_faster_up
	walk_up
	step_end

Route111_Movement_WinstrateExitHouse:
	walk_down
	step_end

Route111_Movement_WaitForNextWinstrate:
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_RouteSignMauville::
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route111_EventScript_WinstrateHouseSign::
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign112::
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign113::
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
	end

Route111_EventScript_OldLadysRestStopSign::
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
	end

Route111_EventScript_TrainerTipsSpAtkSpDef::
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
	end

Route111_EventScript_Man1::
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
	end

Route111_EventScript_Man2::
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
	end

Route111_EventScript_Hiker::
	lock
	faceplayer
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerGone::
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerDisintegrated::
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerVisible::
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RockSmashTipFatMan::
	lockall
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route111_EventScript_Drew::
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Beau::
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Becky::
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Dusty::
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_Travis::
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Daisuke::
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_Brooke::
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_Bryan::
	goto_if_ne VAR_ROUTE111_ACE, 8, Route111_EventScript_BryanNotReady
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_BryanNotReady::
	msgbox Route111_Text_BryanNotReady, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Branden::
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat, Route111_EventScript_AceFight
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_TrainerHillSign::
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
	end

Route111_EventScript_AceFight::
	addvar VAR_ROUTE111_ACE, 1
	end

Route111_EventScript_KrillarFight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_STEVEN, Common_Movement_FaceUp
	waitmovement 0
	special BackupPlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, Route111_EventScript_NotReady
	special ReducePlayerPartyToSelectedMons
	setflag FLAG_3VS3
	msgbox Route111_Text_KrillRunt MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_KRILL_1, Route111_Text_KrillImpressive
	switch VAR_RESULT
	case 1, Route111_EventScript_BeatKrill
	end

Route111_EventScript_Steven::
	lockall
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	delay 16
	applymovement LOCALID_STEVEN, Route111_StevenApproach1
	waitmovement 0
	msgbox Route111_Text_StevenHi, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, Route111_StevenFollowMe
	applymovement OBJ_EVENT_ID_PLAYER, Route111_FollowSteven
	waitmovement 0
	goto Route111_EventScript_StevenIntro
	end

Route111_EventScript_SpecialReport::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	msgbox Route111_Text_SpecialReport MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	end

Route111_EventScript_Reporter::
	msgbox Route111_Text_BreakingNews MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Recorder::
	msgbox Route111_Text_LiveIn MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Steven2::
	lockall
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	delay 16
	applymovement LOCALID_STEVEN, Route111_StevenApproach2
	waitmovement 0
	msgbox Route111_Text_StevenHi, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, Route111_StevenFollowMe2
	applymovement OBJ_EVENT_ID_PLAYER, Route111_FollowSteven2
	waitmovement 0
	goto Route111_EventScript_StevenIntro
	end

Route111_EventScript_Steven3::
	lockall
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	delay 16
	applymovement LOCALID_STEVEN, Route111_StevenApproach3
	waitmovement 0
	msgbox Route111_Text_StevenHi, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, Route111_StevenFollowMe3
	applymovement OBJ_EVENT_ID_PLAYER, Route111_FollowSteven3
	waitmovement 0
	goto Route111_EventScript_StevenIntro
	end

Route111_EventScript_StevenIntro::
	addvar VAR_ROUTE111_MEGA, 1
	applymovement LOCALID_SAMIR, Route111_SamirLook
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FaceUp
	msgbox Route111_Text_SamirHiss MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAMIR, Route111_SamirLeave
	waitmovement 0
	removeobject LOCALID_SAMIR
	setflag FLAG_ROUTE111_HIDE_SAMIR
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_StevenWhat, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, Route111_StevenToKrill
	applymovement OBJ_EVENT_ID_PLAYER, Route111_FollowStevenToKrill
	waitmovement 0
	msgbox Route111_Text_StevenISee, MSGBOX_AUTOCLOSE
	msgbox Route111_Text_KrillHi, MSGBOX_AUTOCLOSE
	msgbox Route111_Text_StevenIWant, MSGBOX_AUTOCLOSE
	applymovement LOCALID_KRILL, Common_Movement_FaceLeft
	msgbox Route111_Text_KrillSeems, MSGBOX_AUTOCLOSE
	msgbox Route111_Text_StevenNoAnswer, MSGBOX_AUTOCLOSE
	applymovement LOCALID_KRILL, Common_Movement_FaceDown
	msgbox Route111_Text_KrillDepends, MSGBOX_AUTOCLOSE
	msgbox Route111_Text_StevenMyFriend, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route111_EventScript_KrillarFight
	case NO, Route111_EventScript_NotReady
	case MULTI_B_PRESSED, Route111_EventScript_NotReady
	end

Route111_EventScript_TowerMan::
	applymovement LOCALID_TOWERMAN, Common_Movement_FacePlayer
	goto_if_eq VAR_ROUTE111_MEGA, 6, Route111_EventScript_DoorManCheckFight
	msgbox Route111_Text_TowerMan  MSGBOX_AUTOCLOSE
	applymovement LOCALID_TOWERMAN, Common_Movement_FaceDown
	end

Route111_EventScript_LostKrill::
	addvar VAR_ROUTE111_MEGA, 1
	setflag FLAG_HIDE_ROUTE_111_REPORTERS
	setflag FLAG_ROUTE111_HIDE_KRILL
	removeobject LOCALID_CAMERAMAN
	removeobject LOCALID_REPORTER
	msgbox Route111_Text_KrillComeBack MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox Route111_Text_StevenHelpMe, MSGBOX_AUTOCLOSE
	playfanfare MUS_HEAL
	waitfanfare
	special RestorePlayerPartyFromBackup
	msgbox Route111_Text_StevenBadFeeling MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route111_FollowStevenLeave
	waitmovement 0
	removeobject LOCALID_STEVEN
	setflag FLAG_ROUTE111_HIDE_STEVEN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_KRILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_KrillInteresting MSGBOX_AUTOCLOSE
	end

Route111_EventScript_BeatKrill::
	addvar VAR_ROUTE111_MEGA, 2
	setflag FLAG_HIDE_ROUTE_111_REPORTERS
	setflag FLAG_ROUTE111_HIDE_KRILL
	removeobject LOCALID_REPORTER
	removeobject LOCALID_CAMERAMAN
	msgbox Route111_Text_KrillInterested MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox Route111_Text_StevenHelpMe, MSGBOX_AUTOCLOSE
	playfanfare MUS_HEAL
	waitfanfare
	special RestorePlayerPartyFromBackup
	msgbox Route111_Text_StevenBadFeeling MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route111_FollowStevenLeave
	waitmovement 0
	removeobject LOCALID_STEVEN
	setflag FLAG_ROUTE111_HIDE_STEVEN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_KRILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_KrillInteresting MSGBOX_AUTOCLOSE
	end

Route111_EventScript_NotReady::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer 
	msgbox Route111_Text_StevenBeHere, MSGBOX_AUTOCLOSE
	setobjectxyperm LOCALID_STEVEN, 31, 115
	return

Route111_EventScript_SetSteven::
	setobjectxyperm LOCALID_STEVEN, 31, 115
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

Route111_EventScript_SetMegaQuest::
	setobjectxyperm LOCALID_STEVEN, 31, 115
	return

Route111_EventScript_StevenScript::
	goto_if_eq VAR_ROUTE111_MEGA, 5, Route111_EventScript_DoorMan
	goto_if_eq VAR_ROUTE111_MEGA, 6, Route111_EventScript_TalkToHim
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	msgbox Route111_Text_StevenReady MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route111_EventScript_KrillarFight
	case NO, Route111_EventScript_NotReady
	case MULTI_B_PRESSED, Route111_EventScript_NotReady
	end

Route111_EventScript_DoorMan::
	setvar VAR_ROUTE111_MEGA, 6
	applymovement LOCALID_TOWERMAN, Common_Movement_FaceDown
	msgbox Route111_Text_BeatMeFirst, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Route111_Text_StevenBadges, MSGBOX_DEFAULT
	closemessage
	msgbox Route111_Text_DoorManHellNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWERMAN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 24
	applymovement LOCALID_TOWERMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route111_Text_DoorManLook MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route111_EventScript_DoorManFight
	case NO, Route111_EventScript_DoorManNR
	case MULTI_B_PRESSED, Route111_EventScript_DoorManNR
	end

Route111_EventScript_DoorManFight::
	msgbox Route111_Text_DoorManHeatedUp, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DOOR_MAN, Route111_Text_BeatDoorMan
	setvar VAR_ROUTE111_MEGA, 7
	setvar VAR_BATTLETOWER, 1
	end

Route111_EventScript_DoorManLost::
	setvar VAR_ROUTE111_MEGA, 8
	msgbox Route111_Text_DoorManLost, MSGBOX_DEFAULT
	applymovement LOCALID_TOWERMAN, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_ROUTE111_HIDETOWERMAN
	removeobject LOCALID_TOWERMAN
	delay 32
	delay 32
	delay 32
	applymovement LOCALID_STEVEN, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox Route111_Text_StevenFinally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route111_FollowStevenLeave
	waitmovement 0
	setflag FLAG_ROUTE111_HIDE_STEVEN
	removeobject LOCALID_STEVEN
	end

Route111_Text_StevenFinally:
	.string "Steven: That was truely a masterful\n"
	.string "display!\p"
	.string "Now you can finally finish this up.\p"
	.string "I have an errand to run so I'll find\n"
	.string "you later, hopefully with a MEGA\l"
	.string "Bracelet to boot!\p"
	.string "Catch you later, {PLAYER}.$"

Route111_Text_DoorManLost:
	.string "DoorMan: Crap...\p"
	.string "Fine, you wanna get burned so bad\n"
	.string "be my guest!\p"
	.string "... ... ...\p"
	.string "Follow me...$" 

Route111_EventScript_DoorManNR::
	msgbox Route111_Text_DoorManNR, MSGBOX_AUTOCLOSE
	setobjectxyperm LOCALID_STEVEN, 31, 115
	end

Route111_EventScript_DoorManCheckFight::
	msgbox Route111_Text_DoorManReadyYet, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route111_EventScript_DoorManFight
	case NO, Route111_EventScript_DoorManNR
	case MULTI_B_PRESSED, Route111_EventScript_DoorManNR
	end

Route111_EventScript_TalkToHim::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_StevenTalkToHim, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_FaceUp
	waitmovement 0
	end

Route111_Text_StevenTalkToHim:
	.string "I know hes making this difficult but,\n"
	.string "talk to him when you're ready.$"

Route111_Text_DoorManReadyYet:
	.string "You stepping up to the challenge now?$"

Route111_Text_DoorManNR:
	.string "Then why you here for fool?\p"
	.string "Go play with the other small timers,\n"
	.string "this is the big leagues!$"
	
Route111_Text_BeatMeFirst:
	.string "DoorMan: Sorry, boss says no weaklings\p"
	.string "STEVEN, you're cleared but your friend...\n"
	.string "I cant just let you in bud$" 

Route111_Text_StevenBadges:
	.string "Steven: Surely the collection of five\n"
	.string "badges makes the cut?$"

Route111_Text_DoorManHellNo:
	.string "DoorMan: Badges? Ha, you're joking right?\p"
	.string "You think those mean anything before the\n"
	.string "Battle Tower??$"

Route111_Text_DoorManLook:
	.string "Look I'll tell you what hotshot, you beat\n"
	.string "me in a MEGA battle and I'll let you in.\p"
	.string "Rules is simple see- as challenger you hit\n"
	.string "me with all you got.\p"
	.string "As Mega Successor I'm allowed 5 POKéMON\n"
	.string "with no held items...\p"
	.string "Matter of fact, I'll go down to 4 so\n"
	.string "I can enjoy the fight, hows that?$"

Route111_Text_DoorManHeatedUp:
	.string "Hahahaha, thats some spirit!\p"
	.string "Time to heat things up!$"

Route111_Text_BeatDoorMan:
	.string "Woah, woah, woah, alright chill\n"
	.string "you put out my flame...$"

Route111_EventScript_Krill::
	applymovement LOCALID_KRILL, Common_Movement_FacePlayer
	goto_if_eq VAR_ROUTE111_MEGA, 2, Route111_EventScript_KrillPreBattle
	goto_if_eq VAR_ROUTE111_MEGA, 4, Route111_EventScript_KrillPostBattle
	end

Route111_EventScript_KrillPreBattle::
	msgbox Route111_Text_KrillNotInteresting MSGBOX_AUTOCLOSE
	applymovement LOCALID_KRILL, Common_Movement_FaceOriginalDirection
	end

Route111_EventScript_KrillPostBattle::
	msgbox Route111_Text_KrillInteresting MSGBOX_AUTOCLOSE
	applymovement LOCALID_KRILL, Common_Movement_FaceOriginalDirection
	end

Route111_FollowStevenLeave:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route111_FollowStevenToKrill:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Route111_StevenToKrill:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Route111_SamirLook:
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

Route111_SamirLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route111_FollowSteven:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
Route111_FollowSteven2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route111_FollowSteven3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route111_StevenFollowMe:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route111_StevenFollowMe2:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route111_StevenFollowMe3:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route111_StevenApproach1:
	walk_down
	walk_down
	walk_down
	step_end

Route111_StevenApproach2:
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

Route111_StevenApproach3:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

Route111_Text_TowerMan:
	.string "Hey! - You sure as hell aint allowed\n"
	.string "in here.\p"
	.string "Beat it kid!$"

Route111_Text_KrillInterested:
	.string "Krillar: You may be worth your\n"
	.string "Salt...\p"
	.string "So I'll tell you as I did your\n"
	.string "friend.\p"
	.string "Come back stronger and face me again.\p"
	.string "Beat me properly and you shall have\n"
	.string "the knowledge you seek!$"

Route111_Text_StevenReady:
	.string "Steven: I take it you are ready?$"

Route111_Text_KrillNotInteresting:
	.string "bros shaking in his boots...$"

Route111_Text_KrillInteresting:
	.string "I expect we'll meet again.\p"
	.string "So don't expect me to hold back\n"
	.string "next time.\p"
	.string "Now go, I await my next opponent.$"

Route111_Text_StevenBadFeeling:
	.string "Either way, I need to keep an eye\n"
	.string "on that cat kid.\p"
	.string "Something gives me a bad feeling\n"
	.string "about him...$"

Route111_Text_StevenHelpMe:
	.string "Steven: Well {PLAYER} let me.\n"
	.string "cut you a deal\p"
	.string "Help me with this task and I will\n"
	.string "personally ensure you receive a\l"
	.string "MEGA bracelet.\p"
	.string "I hope this is of interest for you\n"
	.string "as it seems to be for others.\p"
	.string "Let me get your pokemon for you.$"

Route111_Text_KrillComeBack:
	.string "Krillar: Disappointing.\p"
	.string "I expected far better from one you\n"
	.string "call 'Rising Star' Steven...\p"
	.string "Yet, in the jaws of defeat I see\n"
	.string "determination.\p"
	.string "You're behind that goofball that\n"
	.string "was here a second ago - but not\l"
	.string "too far. So I'll tell you as I did him\p"
	.string "Come back stronger and face me again.\p"
	.string "Beat me properly and you shall have\n"
	.string "the knowledge you seek!$"

Route111_Text_KrillImpressive:
	.string "Hmm.\n"
	.string "pretty decent.$"

Route111_Text_StevenBeHere:
	.string "You're not ready?\p"
	.string "Well - Get prepped, we'll be\n"
	.string "right here.$"

Route111_Text_KrillRunt:
	.string "Krillar: HA!\p" 
	.string "I'll show you a glimpse into\n"
	.string "real power.$"

Route111_Text_StevenMyFriend:
	.string "Steven: Not today unfortunately.\p"
	.string "However I'd like you to consider\n"
	.string "my friend {PLAYER}'s strength.\p"
	.string "A rising star if I say so myself!\p"
	.string "As they've just started a proving\n"
	.string "3V1 should suffice - Right\l"
	.string "{PLAYER}?$"

Route111_Text_KrillDepends:
	.string "Krillar: I answer only those who can\n"
	.string "prove their strength.\p"
	.string "so unless you're here to do battle...$"

Route111_Text_StevenNoAnswer:
	.string "Steven: I assume you had no answer\n"
	.string "for him...$"

Route111_Text_KrillSeems:
	.string "Krillar: Seems they're not the only\n"
	.string "ones...\p"
	.string "I assume you know why he was here.$"

Route111_Text_StevenIWant:
	.string "Steven: DEVONCORP have almost figured\n"
	.string "it out.\p"
	.string "They're asking your help again.$"

Route111_Text_KrillHi:
	.string "Krillar: Bro is a FREAK\n"
	.string "but no joke of a trainer.\p"
	.string "Looks can be deceiving huh.\p"
	.string "What you here for Steven?$"

Route111_Text_StevenISee:
	.string "Steven: I see you're also\n"
	.string "aquainted with our furred friend.$"

Route111_Text_SamirHiss:
	.string "Hiss...$"

Route111_Text_StevenWhat:
	.string "...\p"
	.string "Did he just hiss at me??\p"
	.string "Sometimes you wonder whats going\n"
	.string "through peoples heads...\p"
	.string "Anyways...$"

Route111_Text_StevenHi:
	.string "{PLAYER}! Fancy seeing you here.\p"
	.string "I can assume your journey is going\n"
	.string "well?\p"
	.string "3 Badges... Hmm, you still have a ways\n"
	.string "to go yet.\p"
	.string "But I wonder...\p"
	.string "Come there is someone I want you to meet.$"

Route111_Text_SpecialReport:
	.string "Ugh...\p"
	.string "Can you not see we're reporting a\n"
	.string "special case?\p"
	.string "Go run along and play somewhere else,\n"
	.string "adults are adulting!$"

Route111_Text_LiveIn:
	.string "aaaaand we're live in\p"
	.string "5, 4, 3...$"

Route111_Text_BreakingNews:
	.string "Reporting live outside Krillars battle\n"
	.string "tower...$"

Route111_Text_BattleOurFamily:
	.string "Hello! I take it you're a traveler.\p"
	.string "How's this? What do you say to taking\n"
	.string "on our family of four in a series of\l"
	.string "POKéMON battles?$"

Route111_Text_IsThatSo:
	.string "Is that so?\n"
	.string "Drop in, if you change your mind!$"

Route111_Text_VictorIntro:
	.string "That's the spirit! I like you!$"

Route111_Text_VictorDefeat:
	.string "Aiyah!\n"
	.string "You're a lot tougher than I expected!$"

Route111_Text_VictorPostBattle:
	.string "Hey, all!\n"
	.string "I've found a pretty strong TRAINER!$"

Route111_Text_VictoriaIntro:
	.string "Oh, my goodness! Aren't you young?\p"
	.string "You must be quite the TRAINER to beat\n"
	.string "my husband, though.\p"
	.string "It's my turn to battle now!$"

Route111_Text_VictoriaDefeat:
	.string "Oh, gosh!\n"
	.string "I can't get over how strong you are!$"

Route111_Text_VictoriaPostBattle:
	.string "There's a strong TRAINER here!\n"
	.string "This one's really strong!$"

Route111_Text_ViviIntro:
	.string "You're stronger than Mommy? Wow!\p"
	.string "But I'm strong, too!\n"
	.string "Really! Honestly!$"

Route111_Text_ViviDefeat:
	.string "Huh? Did I just lose?$"

Route111_Text_ViviPostBattle:
	.string "This stinks…\p"
	.string "…Snivel… Grandma!$"

Route111_Text_VickyIntro:
	.string "How dare you make my granddaughter\n"
	.string "cry!\p"
	.string "For that, I'm going to smack you!\n"
	.string "Prepare to lose!$"

Route111_Text_VickyDefeat:
	.string "Kwah! You are strong…\n"
	.string "My granddaughter was right…$"

Route111_Text_VickyPostBattle:
	.string "We WINSTRATES been doing this for\n"
	.string "years. Quite a while since we lost!\p"
	.string "By all means come in, we welcome\n"
	.string "one so strong in our humble abode!$"

Route111_Text_ToughToKeepWinningUpTheRanks:
	.string "If you don't raise your POKéMON some\n"
	.string "more, it could be tough to keep winning\l"
	.string "up through the ranks.\p"
	.string "I've heard rumour of monster trainers\n"
	.string "far stronger than any GYM LEADER\p"
	.string "Unlike those self proclaimed 'Ace\n"
	.string "Trainers'$"

Route111_Text_WinstrateFamilyDestroyedMe:
	.string "I know that Winstrate family,\n"
	.string "is hiding something...\p"
	.string "They said they'd answer my\n"
	.string "questions if I beat them...\p"
	.string "But four matches in a row is\n"
	.string "Rough... They destroyed me.$"

Route111_Text_RouteSignMauville:
	.string "ROUTE 111\n"
	.string "{DOWN_ARROW} MAUVILLE CITY$"

Route111_Text_WinstrateHouseSign:
	.string "“Our family's hearts beat to the”\n"
	.string "“roar of Dragons vitality!”\p"
	.string "“The WINSTRATE ESTATE”" 

Route111_Text_RouteSign112:
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 112$"

Route111_Text_RouteSign113:
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 113$"

Route111_Text_OldLadysRestStopSign:
	.string "OLD LADY'S REST STOP\n"
	.string "“Come in and rest your tired bones.”$"

Route111_Text_TrainerTipsSpAtkSpDef:
	.string "TRAINER TIPS\p"
	.string "One of the indicators of a POKéMON's\n"
	.string "powerfulness is SP. ATK. It stands for\l"
	.string "“SPECIAL ATTACK.”\p"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
	.string "DEFENSE.”$"

Route111_Text_ShouldBeMirageTowerAroundHere:
	.string "There should be a tower made of sand\n"
	.string "around here somewhere.\p"
	.string "But for some reason, it can be seen\n"
	.string "sometimes, and sometimes not.\p"
	.string "That's why I call it the MIRAGE TOWER.$"

Route111_Text_MirageTowerClearlyVisible:
	.string "I see it!\n"
	.string "The tower of sand!\p"
	.string "The sand tower they called a mirage\n"
	.string "is clearly visible!\p"
	.string "But it looks so fragile…\n"
	.string "It could crumble away anytime…\p"
	.string "I want to go inside it, but I can't\n"
	.string "get my courage up for it…$"

Route111_Text_ThatWasShockingSandRainedDown:
	.string "Whoa…\n"
	.string "That was shocking.\p"
	.string "Sand rained down in chunks all of\n"
	.string "a sudden.\p"
	.string "What was it like inside?\n"
	.string "Were there sandy ghosts and such?$"

Route111_Text_MirageTowerHasntBeenSeenSince:
	.string "Since I spoke to you, the tower of sand\n"
	.string "hasn't been seen.\p"
	.string "Perhaps it really was\n"
	.string "the MIRAGE TOWER…$"

Route111_Text_ClawFossilDisappeared:
	.string "The CLAW FOSSIL disappeared into\n"
	.string "the sand…$"

Route111_Text_RootFossilDisappeared:
	.string "The ROOT FOSSIL disappeared into\n"
	.string "the sand…$"

Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
	.string "Oh, no!\p"
	.string "My uncle in MAUVILLE told me to grab\n"
	.string "the ROCK SMASH TOOL with me if I was\l"
	.string "going toROUTE 111!\p"
	.string "My uncle? He lives across from\n"
	.string "the bike shop in MAUVILLE.\p"
	.string "Though he is a little... loud...$"

Route111_Text_TrainerHillSign:
	.string "{RIGHT_ARROW} Krillers BATTLE TOWER\p"
	.string "“Show your true skill and resolve,\n"
	.string "Only the strong will ascend!”$"

Route111_Text_BryanNotReady:
	.string "Heyoo, I'm the ace round 'ese parts\p"
	.string "You beat the rest before you try\n"
	.string "the best?$"

