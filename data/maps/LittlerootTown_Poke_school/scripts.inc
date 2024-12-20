.set LOCALID_TY, 1
.set LOCALID_SAMIR, 2
.set LOCALID_LADY, 3
.set LOCALID_SUGI, 4
.set LOCALID_AABHASH, 5
.set LOCALID_MIRO, 6

LittlerootTown_Poke_school_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootSchool_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootSchool_OnFrame
	.byte 0


LittlerootSchool_OnTransition:
	end

LittlerootSchool_OnFrame:
	map_script_2 VAR_LITTLEROOT_SCHOOL_STATE, 2, LittlerootSchool_Script_OldLadyTroubled
	map_script_2 VAR_LR_SCHOOL_WINS, 5, LittlerootSchool_Script_Complete
	.2byte 0



LittlerootSchool_Script_OldLadyTroubled::
	setvar VAR_LITTLEROOT_SCHOOL_STATE, 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	call LittlerootSchool_Script_BeatAllTrainers
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	end

LittlerootSchool_Script_BeatAllTrainers::
	msgbox LittlerootSchool_Text_BeatAllTrainers, MSGBOX_DEFAULT
	closemessage
	return

LittlerootSchool_Script_OldLady::
	call_if_eq VAR_LITTLEROOT_SCHOOL_STATE, 4, LittlerootSchool_Script_Thanks
	call_if_eq VAR_LITTLEROOT_SCHOOL_STATE, 3, LittlerootSchool_Script_GoFight
	end

LittlerootSchool_Script_Thanks::
	applymovement LOCALID_LADY, Common_Movement_FacePlayer
	setvar VAR_LITTLEROOT_SCHOOL_STATE, 5
	msgbox LittlerootSchool_Text_Thanks, MSGBOX_NPC
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	closemessage
	msgbox LittlerootSchool_Text_Rod, MSGBOX_DEFAULT
	closemessage
	end

LittlerootSchool_Script_Complete::
	setvar VAR_LITTLEROOT_SCHOOL_STATE, 4
	addvar VAR_LR_SCHOOL_WINS, 1
	setflag FLAG_SCHOOL_COMPLETE
	end

LittlerootSchool_Script_GoFight::
	msgbox LittlerootSchool_Text_Heal, MSGBOX_NPC
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox LittlerootSchool_Text_GoFight, MSGBOX_NPC
	end

LittlerootSchool_Script_Ty::
	trainerbattle_single TRAINER_TY, LittlerootSchool_Text_Ty_Opening_Chat, LittlerootSchool_Text_Ty_Losing_Chat, LittlerootSchool_Script_BeatTy
	end

LittlerootSchool_Script_BeatTy::
	addvar VAR_LR_SCHOOL_WINS, 1
	msgbox LittlerootSchool_Text_TyLeave, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_DEFEATED_TYSCHOOL
	removeobject LOCALID_TY
	fadescreen FADE_FROM_BLACK
	end

LittlerootSchool_Script_Samir::
	trainerbattle_single TRAINER_SAMIR, LittlerootSchool_Text_Samir_Opening_Chat, LittlerootSchool_Text_Samir_Losing_Chat, LittlerootSchool_Script_BeatSamir
	end

LittlerootSchool_Script_BeatSamir::
	addvar VAR_LR_SCHOOL_WINS, 1
	msgbox LittlerootSchool_Text_Samir_Leave, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_DEFEATED_SAMIRSCHOOL
	removeobject LOCALID_SAMIR
	fadescreen FADE_FROM_BLACK
	end

LittlerootSchool_Script_Sugi::
	trainerbattle_single TRAINER_SUGI, LittlerootSchool_Text_Sugi_Opening_Chat, LittlerootSchool_Text_Sugi_Losing_Chat, LittlerootSchool_Script_BeatSugi
	end

LittlerootSchool_Script_BeatSugi::
	addvar VAR_LR_SCHOOL_WINS, 1
	msgbox LittlerootSchool_Text_Sugi_Leave, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_DEFEATED_SUGISCHOOL
	removeobject LOCALID_SUGI
	fadescreen FADE_FROM_BLACK
	end

LittlerootSchool_Script_Aabhash::
	trainerbattle_single TRAINER_AABHASH, LittlerootSchool_Text_Aabhash_Opening_Chat, LittlerootSchool_Text_Aabhash_Losing_Chat, LittlerootSchool_BeatAabhash
	end

LittlerootSchool_BeatAabhash::
	addvar VAR_LR_SCHOOL_WINS, 1
	msgbox LittlerootSchool_Text_Aabhash_Leave, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_DEFEATED_AABHASHSCHOOL
	removeobject LOCALID_AABHASH
	fadescreen FADE_FROM_BLACK
	end

LittlerootSchool_Script_DontLeave::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_LADY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LittlerootSchool_Text_DontLeave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	end

LittlerootSchool_Script_Miro::
	trainerbattle_single TRAINER_MIRO, LittlerootSchool_Text_Miro_Opening_Chat, LittlerootSchool_Text_Miro_Losing_Chat, LittlerootSchool_Script_BeatMiro
	end

LittlerootSchool_Script_BeatMiro::
	addvar VAR_LR_SCHOOL_WINS, 1
	msgbox LittlerootSchool_Text_MiroLeave, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_DEFEATED_MIROSCHOOL
	removeobject LOCALID_MIRO
	fadescreen FADE_FROM_BLACK
	end


LittlerootSchool_Text_Thanks:
	.string "Oh thank you so much!\n"
	.string "Hopefully I never see them again..\p"
	.string "Sorry for screaming at you,\n"
	.string "Please take this for the trouble.$" 

LittlerootSchool_Text_Rod:
	.string "Back in my youth I used that\n"
	.string "to catch a rare few myself!\p"
	.string "if you don't want to fall behind\p"
	.string "the other students, I suggest you get\l"
	.string "Fishin'!$"

LittlerootSchool_Text_Heal:
	.string "What?\p"
	.string "Oh you need a heal?$"

LittlerootSchool_Text_GoFight:
	.string "Well don't just stand there\n"
	.string "GET THEM OUT!$"

LittlerootSchool_Text_BeatAllTrainers:
	.string "Oh thank god someone normal!\n"
	.string "Can you get these freaks out please?\p"
	.string "They beat all the regular kids and\n"
	.string "wont leave...$"

LittlerootSchool_Text_DontLeave:
	.string "Oh no you don't!\n"
	.string "You are NOT leaving me with them.\p"
	.string "GET THEM OUT!$"

LittlerootSchool_Text_Ty_Opening_Chat:
	.string "lil bro im literally an orange\n"
	.string "rank healer...\p"
	.string "What makes you think you have\n"
	.string "Any chance?$"

LittlerootSchool_Text_Ty_Losing_Chat:
	.string "Yeah nice op team\n"
	.string "Did you search up a guide or what?$"

LittlerootSchool_Text_TyLeave:
	.string "Bro you're not good, you just got\n"
	.string "lucky.$"

LittlerootSchool_Text_Samir_Opening_Chat:
	.string "U ain’t locked in like me\n"
	.string "lil bro...\p"
	.string "I been goonmaxing all day\n"
	.string "to Astolfo.$"

LittlerootSchool_Text_Samir_Losing_Chat:
	.string "Bro this game is DOG.$"

LittlerootSchool_Text_Samir_Leave:
	.string "got bettter things to do than lose in a\n"
	.string " pokemon fight.. Gonna go play some wow.$"

LittlerootSchool_Text_Sugi_Opening_Chat:
	.string "Ayo whos this PUSSIO YUTE?!$"

LittlerootSchool_Text_Sugi_Losing_Chat:
	.string "I didnt have enough Space to\n"
	.string "download more Pokèmon..\p"
	.string "Nah acc this is designers fault\n"
	.string "L Designer bro.$"

LittlerootSchool_Text_Sugi_Leave:
	.string "On my life bro, watch next time..$"

LittlerootSchool_Text_Aabhash_Opening_Chat:
	.string "Bro Im kinda hot as a goth girl huh?$"

LittlerootSchool_Text_Aabhash_Losing_Chat:
	.string "Bro I wasn't even playing, I've got\n"
	.string "like 4 shows on my other monitor.$"

LittlerootSchool_Text_Aabhash_Leave:
	.string "I mean, I didn't even want to be here\p"
	.string "Whatever I guess...$"

LittlerootSchool_Text_Miro_Opening_Chat:
	.string "What bruv?\p"
	.string "You wanna tussle??$"

LittlerootSchool_Text_Miro_Losing_Chat:
	.string "Bumboclaaat...$"

LittlerootSchool_Text_MiroLeave:
	.string "I got cooked, Icl...$"

