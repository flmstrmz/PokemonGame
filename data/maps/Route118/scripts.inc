.set LOCALID_STEVEN, 10

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ROUTE118_STATE, 1, Route118_SetSteven
	end

Route118_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_SetSteven::
	setobjectxyperm LOCALID_STEVEN, 43, 10
	return

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_WALLY_SHIP, 2, Route118_EventScript_EarlyOpal0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_ROUTE118_STATE, 1
	releaseall
	end

Route118_EventScript_EarlyOpal0::
	setvar VAR_ROUTE118_STATE, 2
	setvar VAR_ROUTE111_MEGA, 5
	msgbox Route118_Text_EarlyOpal MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	clearflag FLAG_ROUTE111_HIDE_STEVEN
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_StevenTrigger1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_WALLY_SHIP, 2, Route118_EventScript_EarlyOpal1
	applymovement LOCALID_STEVEN, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_ROUTE118_STATE, 1
	releaseall
	end

Route118_EventScript_EarlyOpal1::
	msgbox Route118_Text_EarlyOpal MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	clearflag FLAG_ROUTE111_HIDE_STEVEN
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	setvar VAR_ROUTE118_STATE, 2
	setvar VAR_ROUTE111_MEGA, 5
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_StevenTrigger2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_WALLY_SHIP, 2, Route118_EventScript_EarlyOpal2
	applymovement LOCALID_STEVEN, Route118_Movement_StevenWalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_ROUTE118_STATE, 1
	releaseall
	end

Route118_EventScript_EarlyOpal2::
	msgbox Route118_Text_EarlyOpal MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	clearflag FLAG_ROUTE111_HIDE_STEVEN
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	setvar VAR_ROUTE118_STATE, 2
	setvar VAR_ROUTE111_MEGA, 5
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_StevenCheck0::
	lockall
	applymovement LOCALID_STEVEN, Common_Movement_FaceDown
	waitmovement 0
	goto_if_eq VAR_WALLY_SHIP, 2,  Route118_EventScript_HaveOpal0
	msgbox Route118_Text_StevenCheck, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end


Route118_EventScript_StevenCheck1::
	lockall
	applymovement LOCALID_STEVEN, Route118_Movement_StevenAprroach0
	waitmovement 0
	goto_if_eq VAR_WALLY_SHIP, 2,  Route118_EventScript_HaveOpal1
	msgbox Route118_Text_StevenCheck, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

Route118_EventScript_StevenCheck2::
	lockall
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproach1
	waitmovement 0
	goto_if_eq VAR_WALLY_SHIP, 2,  Route118_EventScript_HaveOpal2
	msgbox Route118_Text_StevenCheck, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenWalkLeft
	waitmovement 0
	releaseall
	end

Route118_EventScript_HaveOpal0::
	msgbox Route118_Text_HaveOpal, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	clearflag FLAG_ROUTE111_HIDE_STEVEN
	setvar VAR_ROUTE118_STATE, 2
	setvar VAR_ROUTE111_MEGA, 5
	waitmovement 0
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_HaveOpal1::
	msgbox Route118_Text_HaveOpal, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	clearflag FLAG_ROUTE111_HIDE_STEVEN
	setvar VAR_ROUTE118_STATE, 2
	setvar VAR_ROUTE111_MEGA, 5
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_HaveOpal2::
	msgbox Route118_Text_HaveOpal, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0
	clearflag FLAG_ROUTE111_HIDETOWERMAN
	clearflag FLAG_ROUTE111_HIDE_STEVEN
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	setvar VAR_ROUTE118_STATE, 2
	setvar VAR_ROUTE111_MEGA, 5
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_Movement_PlayerWatchStevenExit:
	delay_16
	walk_in_place_faster_right
	step_end

Route118_Movement_StevenApproachLedge0:
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2:
	walk_right
	step_end

Route118_Movement_StevenJumpLedge:
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenWalkLeft:
	walk_left
	walk_left
	step_end

Route118_Movement_StevenAprroach0:
	walk_right
	walk_in_place_down
	step_end

Route118_Movement_StevenApproach1:
	walk_right
	walk_right
	walk_in_place_down
	step_end

Route118_Movement_StevenExit0:
	walk_right
	walk_down
	walk_down
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

Route118_Movement_StevenExit1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route118_Movement_StevenExit2:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_EarlyOpal:
	.string "Huh? whats that glow in your\n"
	.string "pocket!?\p"
	.string "... ... ... ... ...\p"
	.string "Wait, you already have the\n"
	.string "Opal we need!?\p"
	.string "You my friend are efficient!\p"
	.string "Well we now have all we need so,\n"
	.string "please join me by Krillers battle\l"
	.string "tower when you can.\p"
	.string "I'll be waiting!$"


Route118_Text_HaveOpal:
	.string "Hey {PLAYER}, did you manage\n"
	.string "to get it?\p"
	.string "Oh! I can tell just by that glow,\n"
	.string "I trust no issues?\p"
	.string "... ... ...\p"
	.string "Ah a fair run in with WALLY? Glad\n"
	.string "to hear hes running strong!\p"
	.string "Well we now have all we need so,\n"
	.string "please join me by Krillers battle\l"
	.string "tower when you can.\p"
	.string "I'll be waiting!$"

Route118_Text_StevenCheck:
	.string "Have you checked the ABANDONED SHIP\n"
	.string "yet?\p"
	.string "It should be Between DEWFORD Town\n"
	.string "and SLATEPORT.$"

Route118_Text_StevenQuestions:
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
	.string "How has the adventure been?\p"
	.string "... ... ... ...\p"
	.string "Considering you're here means\n"
	.string "you bested your father?\p"
	.string "Meaning you've grown considerably\p"
	.string "I'm glad I ran into you here,\n"
	.string "I think we've made a breakthrough\l"
	.string "on Mega Evolution!\p"
	.string "I've asked one of the Devon\n"
	.string "researchers for assistance but\l"
	.string "they're taking quite a while...\p"
	.string "Could I ask you check on them for me?\p"
	.string "He should be on the ABANDONED SHIP,\n"
	.string "Between DEWFORD Town and SLATEPORT.$"

Route118_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree?$"

Route118_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

Route118_Text_TryYourLuckFishing:
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route118_Text_DontYouLikeToFish:
	.string "Don't you like to fish?$"

Route118_Text_TryCatchingMonWithGoodRod:
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"

Route118_Text_CanCrossRiversWithSurf:
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route118_Text_RouteSignMauville:
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MAUVILLE CITY$"

Route118_Text_RouteSign119:
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

