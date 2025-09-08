BattleTower_Entrance_MapScripts::
	.byte 0

BattleTower_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox BattleTower_Entrance_Text_WelcomeToBattleTower, MSGBOX_YESNO
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
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
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ETHER
	.2byte ITEM_NONE
	release
	end

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
	.string "the use of REVIVES which are strictly\l"
	.string "forbidden!\p"
	.string "Your goal is to fight your way to the\n"
	.string "top of the tower, where you can speak\l"
	.string "to the leader to complete the challenge.$"

BattleTower_Entrance_Text_AscentionStart:
	.string "Well then, you may begin your challenge\n"
	.string "stepping through the stairs just ahead.\p"
	.string "Good Luck! Though im sure you won't need\n"
	.string "it, haha.$"

BattleTower_Entrance_Text_BattleTower:
	.string "Welcome to the Battle Tower\p"
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
