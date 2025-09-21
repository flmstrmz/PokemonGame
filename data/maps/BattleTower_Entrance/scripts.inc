.set LOCALID_NURSE, 2
.set LOCALID_DOOR_MAN, 7
.set LOCALID_KRILL, 8

BattleTower_Entrance_MapScripts::
	.byte 0

BattleTower_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox BattleTower_Entrance_Text_BattleTower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleTower_Entrance_EventScript_AscentionTrial
	msgbox BattleTower_Entrance_Text_NotReady, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

BattleTower_Entrance_EventScript_AscentionTrial::
	msgbox BattleTower_Entrance_Text_ExplainRules, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, BattleTower_Entrance_EventScript_AscentionTrialRules
	msgbox BattleTower_Entrance_Text_AscentionStart, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLETOWER, 2
	special ReducePlayerPartyLevelTo50
	setflag FLAG_INBATTLETOWER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

BattleTower_Entrance_EventScript_Elevator::
	lockall
	msgbox BattleTower_Entrance_Text_NotElevator MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

BattleTower_Entrance_EventScript_ExtraWork::
	lockall
	clearflag FLAG_HIDE_KRILLINBT
	applymovement LOCALID_DOOR_MAN, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox BattleTower_Entrance_Text_DoorManYW MSGBOX_AUTOCLOSE
	addobject LOCALID_KRILL
	applymovement LOCALID_KRILL, BattleTower_Entrance_Movement_KrillApproach
	waitmovement 0
	applymovement LOCALID_DOOR_MAN, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox BattleTower_Entrance_Text_KrillShowYou, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Entrance_Movement_BackUp
	applymovement LOCALID_KRILL, BattleTower_Entrance_Movement_KrillPC
	waitmovement 0
	delay 32
	playse SE_PC_LOGIN
	delay 32
	applymovement LOCALID_KRILL, BattleTower_Entrance_Movement_KrillTalk
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox BattleTower_Entrance_Text_KrillRegistered, MSGBOX_AUTOCLOSE
	giveitem ITEM_PIDGEOTITE
	giveitem ITEM_SLOWBRONITE
	giveitem ITEM_BEEDRILLITE
	msgbox BattleTower_Entrance_Text_KrillTakeHis, MSGBOX_AUTOCLOSE
	applymovement LOCALID_KRILL, BattleTower_Entrance_Movement_KrillLeave
	waitmovement 0 
	removeobject LOCALID_KRILL
	setflag FLAG_HIDE_KRILLINBT
	setvar VAR_BATTLETOWER, 5
	end



BattleTower_Entrance_EventScript_Ascended::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox BattleTower_Entrance_Text_Congrats, MSGBOX_AUTOCLOSE
	special RestorePlayerPartyFromBackup
	setvar VAR_BATTLETOWER, 4
	clearflag FLAG_INBATTLETOWER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

BattleTower_Entrance_Movement_KrillTalk:
	walk_down
	face_right
	step_end

BattleTower_Entrance_Movement_KrillPC:
	walk_down
	walk_left
	face_up
	step_end

BattleTower_Entrance_Movement_BackUp:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

BattleTower_Entrance_Movement_KrillLeave:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleTower_Entrance_Movement_KrillApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleTower_Entrance_EventScript_DoorMan::
	lockall
	applymovement LOCALID_DOOR_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleTower_Entrance_Text_DMWait MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleTower_Entrance_EventScript_DoorManFight
	msgbox BattleTower_Entrance_Text_DMTakeIt, MSGBOX_AUTOCLOSE
	giveitem ITEM_STEELIXITE
	setflag FLAG_STEELIXITE
	releaseall
	end

BattleTower_Entrance_EventScript_DoorManFight::
	lockall
	msgbox BattleTower_Entrance_Text_DMSpirit MSGBOX_AUTOCLOSE
	special ReducePlayerPartyLevelTo50
	trainerbattle_no_intro TRAINER_DOOR_MAN_SERIOUS, BattleTower_Entrance_Text_DMCant
	msgbox BattleTower_Entrance_Text_DMTakeIt, MSGBOX_AUTOCLOSE
	applymovement LOCALID_DOOR_MAN, Common_Movement_FaceLeft
	special RestorePlayerPartyFromBackup
	giveitem ITEM_STEELIXITE
	setflag FLAG_STEELIXITE
	releaseall
	end

BattleTower_Entrance_EventScript_DoorManGoAway::
	lockall
	goto_if_unset FLAG_MEGA_TRAINER, BattleTower_Entrance_EventScript_DoorManNotHere
	goto_if_unset FLAG_STEELIXITE, BattleTower_Entrance_EventScript_DoorMan
	applymovement LOCALID_DOOR_MAN, Common_Movement_FacePlayer
	msgbox BattleTower_Entrance_Text_DMWow, MSGBOX_AUTOCLOSE
	releaseall
	end

BattleTower_Entrance_EventScript_DoorManNotHere::
	lockall
	applymovement LOCALID_DOOR_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleTower_Entrance_Text_DMNotHere, MSGBOX_AUTOCLOSE
	end

BattleTower_Entrance_Text_DMNotHere:
	.string "Oh no... Krillers not here...\n"
	.string "Guess you have to leave now!$"

BattleTower_Entrance_Text_DMSpirit:
	.string "HAHAHAHAHAHA!\p"
	.string "I will NEVER lose to you again!$"

BattleTower_Entrance_Text_DMWait:
	.string "Woah, hahaha cmon buddy hold up a sec!\p"
	.string "You're at least gonna give me a chance\n"
	.string "to face you properly right?\p"
	.string "No way you'd take a stone on a\n"
	.string "handicap right??$"

BattleTower_Entrance_Text_DMWow:
	.string "... ... ...$"

BattleTower_Entrance_Text_DMCant:
	.string "I can't believe I lost AGAIN...$"

BattleTower_Entrance_Text_DMTakeIt:
	.string "Man just take it and go...$"

BattleTower_Entrance_Text_KrillTakeHis:
	.string "And dont forget to take that frauds\n"
	.string "MEGA Stone too...\p"
	.string "I shall take my leave.$"

BattleTower_Entrance_Text_KrillRegistered:
	.string "Now you are officially registered\n"
	.string "as a MEGA Trainer.\p"
	.string "Many who have ascended before you\n"
	.string "roam the land, and now you have rights\l"
	.string "to face them.\p"
	.string "Beware as they do not face the same\n"
	.string "restrictions of my Tower.\p"
	.string "And unlike that dumbass behind you,\n"
	.string "they will hit you with all they have.\p"
	.string "If you can beat them however, they\n"
	.string "must hand over their MEGA Stone.\p"
	.string "You may use the Screen behind me\n"
	.string "to locate them.\p"
	.string "And before I forget here are your\n"
	.string "First 3 MEGA Stones.$"


BattleTower_Entrance_Text_KrillShowYou:
	.string "Kriller: Let me show you something\n"
	.string "before you go.$"

BattleTower_Entrance_Text_DoorManYW:
	.string "Aww hell naw, they let a bum like you\n"
	.string "beat them???\p"
	.string "They really lowered the bar...\p"
	.string "If I was really trying you would've\n"
	.string "never stepped foot in here.$"

BattleTower_Entrance_Text_Congrats:
	.string "Wow you really performed out there!\p"
	.string "Its always a pleasure to see as strong\n"
	.string "as yourself attempt the trials.\p"
	.string "Well congratulations again on completing\n"
	.string "the Battle Tower!$"

BattleTower_Entrance_EventScript_QuitChallenge::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox BattleTower_Entrance_Text_QuitChallenge MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleTower_Entrance_EventScript_Disappointing
	msgbox BattleTower_Entrance_Text_OtherWay, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	end

BattleTower_Entrance_EventScript_Disappointing::
	msgbox BattleTower_Entrance_Text_Disappointing, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLETOWER, 1
	setvar VAR_BT_FLOOR1, 0
	setvar VAR_BT_FLOOR2, 0
	setvar VAR_BT_FLOOR3, 0
	special RestorePlayerPartyFromBackup
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	end

BattleTower_Entrance_EventScript_AscentionTrialRules::
	msgbox BattleTower_Entrance_Text_RulesExplanation, MSGBOX_AUTOCLOSE
	return

BattleTower_Entrance_EventScript_Man::
	msgbox BattleTower_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

BattleTower_Entrance_EventScript_Girl::
	msgbox BattleTower_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

BattleTower_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	setrespawn HEAL_LOCATION_BATTLE_TOWER
	release
	end

BattleTower_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleTower_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleTower_Entrance_Pokemart_Basic:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ETHER
	.2byte ITEM_NONE
	release
	end

BattleTower_Entrance_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleTower_Entrance_Pokemoves_mart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleTower_Entrance_Pokemoves_mart:
	.2byte ITEM_TM_LUNGE
	.2byte ITEM_TM_SIGNAL_BEAM
	.2byte ITEM_TM_DARK_PULSE
	.2byte ITEM_TM_DRAGON_TAIL
	.2byte ITEM_TM_SECRET_SWORD
	.2byte ITEM_TM_KARATE_CHOP
	.2byte ITEM_TM_WILD_CHARGE
	.2byte ITEM_TM_VOLT_SWITCH
	.2byte ITEM_TM_DRAGON_BREATH
	.2byte ITEM_TM_LIQUIDATION
	.2byte ITEM_TM_SCALD
	.2byte ITEM_TM_ANCIENT_POWER
	.2byte ITEM_TM_STONE_EDGE
	.2byte ITEM_TM_PSYCHIC_FANGS
	.2byte ITEM_TM_SLUDGE_WAVE
	.2byte ITEM_TM_HEAT_WAVE
	.2byte ITEM_NONE
	release
	end

BattleTower_Entrance_Text_Disappointing:
	.string "Oh... thats disappointing\p"
	.string "I would've expected more from one\n"
	.string "on our VIP list...\p"
	.string "Well, can you make way for other\n"
	.string "real challengers then?...$"

BattleTower_Entrance_Text_OtherWay:
	.string "Then the entrance is the other way,\n"
	.string "silly!$"

BattleTower_Entrance_Text_QuitChallenge:
	.string "Uhmm, are you trying to quit?$"

BattleTower_Entrance_Text_NotReady:
	.string "Ah, ok in that case please allow way\n"
	.string "for the other trainers.$"

BattleTower_Entrance_Text_ExplainRules:
	.string "Now for this trial there are special\n"
	.string "rules that must be followed!\p"
	.string "Would you like me to explain them?$"

BattleTower_Entrance_Text_RulesExplanation:
	.string "As you start the trial, initially your\n"
	.string "POKéMON will be set to a strict level\l"
	.string "of 50.\p"
	.string "You will be fully allowed the use of\n"
	.string "all held items and usable items.\p"
	.string "The only exception to that rule is\n"
	.string "the use of REVIVES which are limited\l"
	.string "to 5 uses!\p"
	.string "Your goal is to fight your way to the\n"
	.string "top of the tower, where you can speak\l"
	.string "to the leader to complete the challenge.$"

BattleTower_Entrance_Text_AscentionStart:
	.string "Well then, you may begin your challenge\n"
	.string "stepping through the stairs just ahead.\p"
	.string "Good Luck! Though im sure you won't need\n"
	.string "it, haha.$"

BattleTower_Entrance_Text_BattleTower:
	.string "Announcer: Welcome to the Battle Tower\p"
	.string "This is a place in which only the\n"
	.string "strong will prevail.\p"
	.string "Your name is?\p"
	.string "Ah! {PLAYER}...\p"
	.string "Oh wow I can see you are on our\n"
	.string "VIP list! That makes for a second\l"
	.string "this week.\p"
	.string "Well I'm assuming you wish to take\n"
	.string "on the Ascention Trial?$"

BattleTower_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Maaaaan!\p"
	.string "I managed to get to the second floor\n"
	.string "but I ran out of POTIONS...\p"
	.string "But a true champ never quits!\n"
	.string "I'll win on my 9th attempt...$"

BattleTower_Entrance_Text_CantWaitToTestTheWaters:
	.string "I heard tough TRAINERS come to this\n"
	.string "TRAINER HILL from all over.\p"
	.string "I can't wait to test the waters!\p"
	.string "I'll knock aside anyone that stands\n"
	.string "in my way!$"

BattleTower_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Oh, are you here for the MEGA\n"
	.string "challenge too?\p"
	.string "It's hard enough to get in here,\n"
	.string "let alone beat the challenge!\p"
	.string "If you haven't already, I'd advise\n"
	.string "going to SLATEPORT market for EV\l"
	.string "training and VENDARUF for mints!$"

BattleTower_Entrance_Text_NotElevator:
	.string "Announcer: That would be an elevator,\n"
	.string "not stairs...$"

BattleTower_Entrance_Text_Really:
	.string "Announcer: You came all the way\n"
	.string "back down for this?\p"
	.string "please return to the challenge\n"
	.string "or just quit if its easier...$"
