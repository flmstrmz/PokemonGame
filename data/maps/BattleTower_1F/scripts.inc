.set LOCALID_SERENA, 1

BattleTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_1F_OnFrame
	.byte 0

BattleTower_1F_OnFrame:
	map_script_2 VAR_BT_FLOOR1, 0, BattleTower_1F_EventScript_SetFloor
	.2byte 0

BattleTower_1F_EventScript_SetFloor::
	lockall
	setvar VAR_BT_FLOOR1, 1
	msgbox BattleTower_1F_Text_ToProceed, MSGBOX_AUTOCLOSE
	end

BattleTower_1F_EventScript_Trial1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox BattleTower_1F_Text_Ready, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_BTOWER_1F, BattleTower_1F_Text_BeatMega1
	playse SE_DING_DONG
	waitse 
	msgbox BattleTower_1F_Text_Congrats, MSGBOX_AUTOCLOSE
	setvar VAR_BT_FLOOR1, 2
	releaseall
	end

BattleTower_1F_EventScript_Wow::
	lock
	applymovement LOCALID_SERENA, Common_Movement_FacePlayer
	msgbox BattleTower_1F_Text_Wow, MSGBOX_AUTOCLOSE
	releaseall
	end

BattleTower_1F_EventScript_Serena::
	lock
	goto_if_eq VAR_BT_FLOOR1, 2, BattleTower_1F_EventScript_Wow
	applymovement LOCALID_SERENA, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleTower_1F_Text_Trial1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SERENA, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

BattleTower_1F_EventScript_FightMe::
	lock
	msgbox BattleTower_1F_Text_CantGo MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

BattleTower_1F_Text_Congrats:
	.string "Announcer: {PLAYER} has won!\p"
	.string "Please proceed to the next floor\n"
	.string "to face your next challenge!$"

BattleTower_1F_Text_BeatMega1:
	.string "Hmpm, I guess I still have much\n"
	.string "to learn still$"

BattleTower_1F_Text_Trial1:
	.string "Ahem...\p"
	.string "The circle OPPOSITE me...\p"
	.string "Not the one I'm standing on...$"

BattleTower_1F_Text_CantGo:
	.string "Serena: Hey! Uhm you have to BEAT\n"
	.string "me first...\p"
	.string "You cant just skip the whole\n"
	.string "Challenge yknow...$"

BattleTower_1F_Text_Ready:
	.string "Serena: Perfect, I hope youre ready!\p"
	.string "Your first trial begins now!$"

BattleTower_1F_Text_Wow:
	.string "Wow you're stronger than you\n"
	.string "look!\p"
	.string "Well you can continue through\n"
	.string "the stairs to the second floor.$"

BattleTower_1F_Text_ToProceed:
	.string "Announcer: Welcome to the first\n"
	.string "floor.\p"
	.string "Please step onto the Challengers\n"
	.string "circle to begin!$"

