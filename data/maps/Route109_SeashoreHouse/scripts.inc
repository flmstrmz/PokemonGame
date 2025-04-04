.set LOCALID_SUGI, 2
.set LOCALID_TY, 3
.set LOCALID_MIRO, 4

Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route109_SeaShoreHouseOnFrame
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeaShoreHouseOnFrame:
	map_script_2 VAR_SEASHORE_BATTLE, 0, Route109_Script_SeaShoreHouseDoubleBattle
	.2byte 0

Route109_Script_SeaShoreHouseDoubleBattle::
	addvar VAR_SEASHORE_BATTLE, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route109_Script_CamWalk
	msgbox Route109_Text_MoreTrainersToBeat, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_TY, Common_Movement_FaceDown
	msgbox Route109_Text_TyFortunate, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox Route109_Text_MiroAgrees, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox Route109_Text_SugiTeam, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Script_CamWalk
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Route109_Script_WalkFinish
	waitmovement 0
	applymovement LOCALID_TY, Common_Movement_FaceLeft
	msgbox Route109_Text_TyTeam, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_MiroBroStop, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox Route109_Text_SugiAyo, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_TyDiffGame, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_MiroWhyMention, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_TyShut, MSGBOX_DEFAULT
	closemessage
	goto TestBPartner
	end

Route109_SeashoreHouse_EventScript_OwnerUnused::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

PartnerText:
	.string "You now have the option to select\n"
	.string "who you fight with\p"
	.string "Choose Wisely as to the winner go\n"
	.string "the spoils\p"
	.string "Who is your Partner?$"

TestBPartner::
	msgbox PartnerText, MSGBOX_DEFAULT
	waitmessage
	multichoicegrid 3, 1, MULTI_BATTLE_PARTNER, 1, FALSE
	switch VAR_RESULT
	case 0, TestBattleSugiPartner
	case 1, TestBattleTyPartner
	case 2, TestBattleMiroPartner
	case MULTI_B_PRESSED, TestBPartner
	end

TestBattleSugiPartner::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, TestBPartner
	multi_2_vs_2 TRAINER_MIRO3, Route109_Text_MiroLost, TRAINER_TY3, Route109_Text_TyLost, PARTNER_SUGI
	switch VAR_RESULT
	case 1, Route109_Script_WonWithSugi
	goto Route109_Script_LostToTyMiro
	end

TestBattleTyPartner::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, TestBPartner
	multi_2_vs_2 TRAINER_SUGI3, Route109_Text_SugiLost, TRAINER_MIRO3, Route109_Text_MiroLost, PARTNER_TY
	switch VAR_RESULT
	case 1, Route109_Script_WonWithTy
	goto Route109_Script_LostToMiroSugi
	end

TestBattleMiroPartner::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, TestBPartner
	multi_2_vs_2 TRAINER_SUGI3, Route109_Text_SugiLost, TRAINER_TY3, Route109_Text_TyLost, PARTNER_MIRO
	switch VAR_RESULT
	case 1, Route109_Script_WonWithMiro
	goto Route109_Script_LostToSugiTy
	end

Route109_Script_WonWithSugi::
	lockall
	addvar VAR_SEASHORE_BATTLE, 1
	msgbox Route109_Text_OwnerReward, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_SugiWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SUGI, Route109_SugiReward
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route109_Text_SugiGetReward, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox Route109_Text_SugiBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SUGI, Route109_SugiLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SUGI
	setflag FLAG_HIDESUGI_SEAHOUSE
	setflag FLAG_HIDETY_SEAHOUSE
	setflag FLAG_HIDEMIRO_SEAHOUSE
	setflag FLAG_SUGIWON
	addvar VAR_ROUTE109_CLEARED, 1
	releaseall
	end

Route109_Script_WonWithTy::
	lockall
	addvar VAR_SEASHORE_BATTLE, 1
	msgbox Route109_Text_OwnerReward, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_TyWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, Route109_TyReward
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route109_Text_TyGetReward, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox Route109_Text_TyBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, Route109_TyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_TY
	setflag FLAG_HIDESUGI_SEAHOUSE
	setflag FLAG_HIDETY_SEAHOUSE
	setflag FLAG_HIDEMIRO_SEAHOUSE
	setflag FLAG_TYWON
	addvar VAR_ROUTE109_CLEARED, 1
	releaseall
	end

Route109_Script_WonWithMiro::
	lockall
	addvar VAR_SEASHORE_BATTLE, 1
	msgbox Route109_Text_OwnerReward, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_MiroGetReward, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRO, Route109_MiroReward
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route109_Text_MiroReceives, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox Route109_Text_MiroBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRO, Route109_MiroLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MIRO
	setflag FLAG_HIDESUGI_SEAHOUSE
	setflag FLAG_HIDETY_SEAHOUSE
	setflag FLAG_HIDEMIRO_SEAHOUSE
	setflag FLAG_MIROWON
	addvar VAR_ROUTE109_CLEARED, 1
	releaseall
	end

Route109_Script_LostToTyMiro::
	lockall
	msgbox Route109_Text_OwnerReward, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_TyWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, Route109_TyReward
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route109_Text_TyGetReward, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox Route109_Text_TyBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, Route109_TyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_TY
	setflag FLAG_HIDETY_SEAHOUSE
	msgbox Route109_Text_MiroGetReward, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRO, Route109_MiroReward
	waitmovement 0
	msgbox Route109_Text_MiroReceives, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	msgbox Route109_Text_MiroBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRO, Route109_MiroLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MIRO
	setflag FLAG_HIDEMIRO_SEAHOUSE
	setflag FLAG_HIDESUGI_SEAHOUSE
	setflag FLAG_SEAHOUSEREWARD
	setflag FLAG_MIROWON
	setflag FLAG_TYWON
	addvar VAR_ROUTE109_CLEARED, 2
	releaseall
	end

Route109_Script_LostToMiroSugi::
	lockall
	msgbox Route109_Text_OwnerReward, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_SugiWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SUGI, Route109_SugiReward
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route109_Text_SugiGetReward, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox Route109_Text_SugiBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SUGI, Route109_SugiLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SUGI
	setflag FLAG_HIDESUGI_SEAHOUSE
	msgbox Route109_Text_MiroGetReward, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRO, Route109_MiroReward
	waitmovement 0
	msgbox Route109_Text_MiroReceives, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	msgbox Route109_Text_MiroBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRO, Route109_MiroLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MIRO
	setflag FLAG_HIDEMIRO_SEAHOUSE
	setflag FLAG_HIDETY_SEAHOUSE
	setflag FLAG_SEAHOUSEREWARD
	setflag FLAG_MIROWON
	setflag FLAG_SUGIWON
	addvar VAR_ROUTE109_CLEARED, 2
	releaseall
	end

Route109_Script_LostToSugiTy::
	lockall
	msgbox Route109_Text_OwnerReward, MSGBOX_DEFAULT
	closemessage
	msgbox Route109_Text_TyWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, Route109_TyReward
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route109_Text_TyGetReward, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox Route109_Text_TyBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, Route109_TyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_TY
	setflag FLAG_HIDETY_SEAHOUSE
	msgbox Route109_Text_SugiWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SUGI, Route109_SugiReward
	waitmovement 0
	msgbox Route109_Text_SugiGetReward, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	msgbox Route109_Text_SugiBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SUGI, Route109_SugiLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SUGI
	setflag FLAG_HIDESUGI_SEAHOUSE
	setflag FLAG_HIDEMIRO_SEAHOUSE
	setflag FLAG_SEAHOUSEREWARD
	setflag FLAG_TYWON
	setflag FLAG_SUGIWON
	addvar VAR_ROUTE109_CLEARED, 2
	releaseall
	end

Route109_Script_Ty::
	msgbox Route109_Text_TyLost MSGBOX_DEFAULT
	closemessage
	end

Route109_Script_Miro::
	msgbox Route109_Text_MiroLost MSGBOX_DEFAULT
	closemessage
	end

Route109_Script_Sugi::
	msgbox Route109_Text_SugiLost MSGBOX_DEFAULT
	closemessage
	end

Route109_PickReward::
	msgbox Route109_Text_WhatWouldYouLike MSGBOX_DEFAULT
	closemessage
	multichoicegrid 8, 1, MULTI_BATTLE_REWARD, 1, FALSE
	switch VAR_RESULT
	case 0, Route109_WStone
	case 1, Route109_FStone
	case 2, Route109_TStone
	case 3, Route109_LStone
	case 4, Route109_SStone
	case 5, Route109_DskStone
	case 6, Route109_DwnStone
	case 7, Route109_IStone
	case MULTI_B_PRESSED, Route109_PickReward
	end

Route109_WStone::
	giveitem ITEM_WATER_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_FStone::
	giveitem ITEM_FIRE_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_TStone::
	giveitem ITEM_THUNDER_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_LStone::
	giveitem ITEM_LEAF_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_SStone::
	giveitem ITEM_SHINY_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_DskStone::
	giveitem ITEM_DUSK_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_DwnStone::
	giveitem ITEM_DAWN_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_IStone::
	giveitem ITEM_ICE_STONE
	setflag FLAG_SEAHOUSEREWARD
	end

Route109_SeashoreHouse_EventScript_Owner::
	goto_if_unset FLAG_SEAHOUSEREWARD, Route109_PickReward
	goto_if_eq VAR_SEASHORE_BATTLE, 1, Route109_SeashoreHouse_EventScript_OwnerLost
	goto_if_eq VAR_SEASHORE_BATTLE, 2, Route109_SeashoreHouse_EventScript_OwnerGrats
	end

Route109_SeashoreHouse_EventScript_OwnerLost::
	msgbox Route109_Text_NextTime, MSGBOX_DEFAULT
	closemessage
	end

Route109_SeashoreHouse_EventScript_OwnerGrats::
	msgbox Route109_Text_Congrats, MSGBOX_DEFAULT
	closemessage
	end

Route109_Text_OwnerReward:
	.string "Annnd we have our winners!\p"
	.string "Please collect your rewards\n"
	.string "when youre ready.$"

Route109_Text_WhatWouldYouLike:
	.string "Well, Please choose your reward!$"

Route109_Text_Congrats:
	.string "Congratulations again on the win!$"

Route109_Text_NextTime:
	.string "Maybe next time buddy...$"

Route109_Text_TyWon:
	.string "Ty: I could've predicted that outcome...\p"
	.string "Welp I'll be taking that reward boss,\n"
	.string "what you got for me?$"

Route109_Text_TyGetReward:
	.string "Ty received a Dusk Stone!$"

Route109_Text_TyBye:
	.string "Ayt I'm off to the next gym, pce!$"

Route109_Text_TyLost:
	.string "Always my team isn't it...$"

Route109_Text_SugiWon:
	.string "Sugi: Another day, another W.$"

Route109_Text_SugiGetReward:
	.string "Sugi received a Shiny Stone!$"

Route109_Text_SugiBye:
	.string "Hmmm...\p"
	.string "W Dev.$"

Route109_Text_SugiLost:
	.string "Brudda... You man are SWEATS$"

Route109_Text_MiroWon:
	.string "Never try tussle the tussler.$"

Route109_Text_MiroGetReward:
	.string "Miro: And with that gentlemen, I'll take\n"
	.string "what is rightfully mine.$"

Route109_Text_MiroLost:
	.string "Unlucky game, Go next...$"

Route109_Text_MiroReceives:
	.string "Miro received an Upgrade!$"

Route109_Text_MiroBye:
	.string "With a Majestic leave.$"

Route109_Text_WinnerOfBattle:
	.string "Well Clearly we have decided winners then!\n"
	.string "If you would come to me to choose your\l"
	.string "desired reward.$" 

Route109_TyReward::
	walk_left
	walk_left
	face_up
	step_end

Route109_TyLeave::
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route109_SugiReward::
	walk_up
	step_end

Route109_SugiLeave::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route109_MiroReward::
	walk_right
	face_up
	step_end

Route109_MiroLeave::
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_Script_CamWalk::
	walk_up
	walk_up
	walk_up
	step_end

Route109_Script_WalkFinish::
	walk_up
	walk_up
	step_end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "I'm the owner of the SEASHORE HOUSE.\n"
	.string "But you can call me MR. SEA!\p"
	.string "What I love above all is to see hot\n"
	.string "POKéMON battles.\p"
	.string "Let me see that your heart burns hot!\p"
	.string "If you can defeat all the TRAINERS\n"
	.string "here, I'll reward your efforts.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Show me some hot matches!\p"
	.string "I run this SEASHORE HOUSE just for\n"
	.string "that reason alone!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "You're scorching hot!\n"
	.string "Those battles blazed!\l"
	.string "I'm more than just satisfied!\p"
	.string "As thanks for showing me your hot\n"
	.string "streak, I want you to take these.\p"
	.string "It's half a dozen bottles of SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Want to buy some SODA POP?\n"
	.string "POKéMON love it!\p"
	.string "Just ¥300 a bottle!\n"
	.string "Buy some!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Here you go!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "You don't have the money.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "That's too bad.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "If you're looking for a battle in the\n"
	.string "SEASHORE HOUSE, you'll find no\l"
	.string "hotter TRAINER than me, matey!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "That was a hot battle!\n"
	.string "I can accept that loss, matey!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
	.string "hot battles and ice-cold SODA POP!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Boring battles aren't worth the effort.\p"
	.string "Fiery hot battles are what toughen up\n"
	.string "TRAINERS and POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "That's hot!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Whew, I'm all thirsty.\n"
	.string "Maybe I'll have a SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "I'm going to show you how great\n"
	.string "my POKéMON are, but don't cry!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…I lost, but I won't cry…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "If one of my POKéMON knew the move\n"
	.string "for carrying me across water on its\l"
	.string "back, I could get rid of this inner tube.$"

Route109_Text_MoreTrainersToBeat:
	.string "Owner:...Unfortunately one more stepped\n"
	.string "through the door.$"

Route109_Text_TyFortunate:
	.string "Ty: Well look who decided to join the\n"
	.string "party!\p"
	.string "I think this about evens it out\n"
	.string "actually.$" 

Route109_Text_MiroAgrees:
	.string "Miro: Oh, Yeahhhh now we can call\n"
	.string "the best Dynamic Duo instead\p"
	.string "Winners take all innit.$"

Route109_Text_SugiTeam:
	.string "Sugi: Ayo teamwork and dat yhyh.$"

Route109_Text_TyTeam:
	.string "Ty: Well who gets to team with mr\n"
	.string "rank 109 EUW then? Heh.$"

Route109_Text_MiroBroStop:
	.string "Miro: Bro shut the fuck up wasn't you\n"
	.string "like hardstuck plat for 6 years?$"

Route109_Text_SugiAyo:
	.string "Sugi: Ayo, thats kinda embarrassing\n"
	.string "still....$"

Route109_Text_TyDiffGame:
	.string "Ty: BRO this is a different game dont\n"
	.string "worry bout it innit.$"

Route109_Text_MiroWhyMention:
	.string "Miro: Well if its a different game why\n"
	.string "mentio...$"

Route109_Text_TyShut:
	.string "Ty: OK MY BAD I GET IT HOLY... Lets\n"
	.string "just get this started.\p"
	.string "Lets let {PLAYER} decide the teams.$"

