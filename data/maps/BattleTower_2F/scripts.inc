.set LOCALID_DRAVEN, 1

BattleTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_2F_OnFrame
	.byte 0

BattleTower_2F_OnFrame:
	map_script_2 VAR_BT_FLOOR2, 0, BattleTower_2F_EventScript_SetFloor
	.2byte 0

BattleTower_2F_EventScript_SetFloor::
	setvar VAR_BT_FLOOR2, 1
	msgbox BattleTower_2F_Text_ToProceed, MSGBOX_AUTOCLOSE
	end

BattleTower_2F_EventScript_Trial2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox BattleTower_2F_Text_HereICome, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_BTOWER_2F, BattleTower_2F_Text_Excellent
	playse SE_DING_DONG
	waitse 
	msgbox BattleTower_2F_Text_Congrats, MSGBOX_AUTOCLOSE
	setvar VAR_BT_FLOOR2, 2
	releaseall
	end

BattleTower_2F_EventScript_Worthy::
	lock
	applymovement LOCALID_DRAVEN, Common_Movement_FacePlayer
	msgbox BattleTower_2F_Text_Worthy, MSGBOX_AUTOCLOSE
	releaseall
	end

BattleTower_2F_EventScript_Draven::
	lock
	goto_if_eq VAR_BT_FLOOR2, 2, BattleTower_2F_EventScript_Worthy
	applymovement LOCALID_DRAVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleTower_2F_Text_Trial2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_DRAVEN, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

BattleTower_2F_EventScript_FightMe::
	lock
	msgbox BattleTower_2F_Text_CantGo MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

BattleTower_2F_Text_ToProceed:
	.string "Announcer: Congrats on getting to\n"
	.string "the second floor!\p"
	.string "Whenever you're ready please step\n"
	.string "onto the challengers circle again$"

BattleTower_2F_Text_Trial2:
	.string "So you beat Serena?\p"
	.string "She is the newest among us,\n"
	.string "so it is to be expected.\p"
	.string "I shan't be so simple.$"

BattleTower_2F_Text_Congrats:
	.string "Announcer: {PLAYER} has won!\p"
	.string "Please proceed to the next floor\n"
	.string "to face the third and final\l"
	.string "challenge!$"

BattleTower_2F_Text_CantGo:
	.string "Draven: You know how this works.\p"
	.string "Face your fears, overcome them\n"
	.string "with overwhelming force!$"

BattleTower_2F_Text_HereICome:
	.string "Draven: Good, you are ready.\p"
	.string "Prepare yourself, Here I come!$"

BattleTower_2F_Text_Excellent:
	.string "Excellent form, perfect Execution\n"
	.string "you have bested me.$"

BattleTower_2F_Text_Worthy:
	.string "Your Strength is impressive.\p"
	.string "Maybe you shall make it to the top!$"

