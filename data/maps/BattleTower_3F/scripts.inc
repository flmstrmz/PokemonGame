.set LOCALID_DOLTSZ, 1

BattleTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_3F_OnFrame
	.byte 0

BattleTower_3F_OnFrame:
	map_script_2 VAR_BT_FLOOR3, 0, BattleTower_3F_EventScript_SetFloor
	.2byte 0

BattleTower_3F_EventScript_SetFloor::
	setvar VAR_BT_FLOOR3, 1
	msgbox BattleTower_3F_Text_Final, MSGBOX_AUTOCLOSE
	end

BattleTower_3F_EventScript_Trial3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox BattleTower_3F_Text_WelcomeFinal, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_BTOWER_3F, BattleTower_3F_Text_Outcome
	playfanfare MUS_OBTAIN_SYMBOL
	waitfanfare 
	msgbox BattleTower_3F_Text_Congrats, MSGBOX_AUTOCLOSE
	setvar VAR_BT_FLOOR3, 2
	releaseall
	end
	
BattleTower_3F_EventScript_Calculated::
	lock
	applymovement LOCALID_DOLTSZ, Common_Movement_FacePlayer
	msgbox BattleTower_3F_Text_Calculated, MSGBOX_AUTOCLOSE
	releaseall
	end

BattleTower_3F_EventScript_Doltsz::
	lock
	goto_if_eq VAR_BT_FLOOR3, 2, BattleTower_3F_EventScript_Calculated
	applymovement LOCALID_DOLTSZ, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleTower_3F_Text_Trial3, MSGBOX_AUTOCLOSE
	applymovement LOCALID_DOLTSZ, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

BattleTower_3F_EventScript_FightMe::
	lock
	msgbox BattleTower_3F_Text_CantGo MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

BattleTower_3F_Text_Congrats:
	.string "Announcer: {PLAYER} has completed\n"
	.string "all floors and thus successfully\l"
	.string "overcome their trial!\p"
	.string "Please ascend to the roof where\n"
	.string "GREAT DANE awaits!$"

BattleTower_3F_Text_CantGo:
	.string "Doltsz: Your third floor and you\n"
	.string "attempt to bypass me?\p"
	.string "Come, bring no shame to my floor\n"
	.string "and show me how you bested\l"
	.string "those before me.$"

BattleTower_3F_Text_Trial3:
	.string "You stand before your final\n"
	.string "challenge.\p"
	.string "But how will your strategy fare?$"

BattleTower_3F_Text_Outcome:
	.string "This outcome couldn't be helped\n"
	.string "you were just better.\p"
	.string "Well played my friend.$"

BattleTower_3F_Text_Calculated:
	.string "You were a step ahead of me and\n"
	.string "my peers, and now you may ascend\l"
	.string "beyond.$"

BattleTower_3F_Text_Final:
	.string "Announcer: Welcome to the third and\n"
	.string "final floor!\p"
	.string "Please proceed to the challengers\n"
	.string "circle for the last time! Good\l"
	.string "luck, {PLAYER}!$"

BattleTower_3F_Text_WelcomeFinal:
	.string "The final trial commences.\p"
	.string "But will you come out victorious?\p"
	.string "Why don't we find out hmm?$"
