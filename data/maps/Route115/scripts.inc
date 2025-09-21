.set LOCALID_HELENE, 19
.set LOCALID_ALIX, 20

Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_EventScript_AceFight
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	goto_if_eq VAR_ROUTE115_ACE, 8, Route115_EventScript_AlixDefeated
	msgbox Route115_Text_AceAlixWontFight, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	goto_if_eq VAR_ROUTE115_ACE, 8, Route115_EventScript_HeleneDefeated
	msgbox Route115_Text_AceHeleneWontFight, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_HeleneDefeated::
	msgbox Route115_Text_AceHeleneDefeated, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_AlixDefeated::
	msgbox Route115_Text_AceAlixDefeated, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Ace::
	playse SE_PIN
	applymovement LOCALID_ALIX, Common_Movement_ExclamationMark
	waitmovement 0
	delay 32
	applymovement LOCALID_ALIX Route115_Movement_AceAlix
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Route115_Text_AceAlixFight, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement LOCALID_HELENE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HELENE, Route115_Movement_AceHelene
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route115_Text_AceHeleneFight, MSGBOX_AUTOCLOSE
	trainerbattle_two_trainers TRAINER_ALIX, Route115_Text_AceAlixLost, TRAINER_HELENE, Route115_Text_AceHeleneLost
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox Route115_Text_AceHeleneAfter, MSGBOX_AUTOCLOSE
	giveitem ITEM_LEFTOVERS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	msgbox Route115_Text_AceAlixAfter, MSGBOX_AUTOCLOSE
	giveitem ITEM_MUSCLE_BAND
	end 


Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat, Route115_EventScript_AceFight
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_AceFight::
	addvar VAR_ROUTE115_ACE, 1
	end

Route115_Movement_AceAlix:
	walk_right
	walk_right
	step_end

Route115_Movement_AceHelene:
	walk_left
	walk_left
	step_end

Route115_Text_AceHeleneDefeated:
	.string "You're insanely strong!$"

Route115_Text_AceAlixDefeated:
	.string "Whatever...$"

Route115_Text_AceHeleneWontFight:
	.string "Sorry we dont fight Rookies\p"
	.string "Maybe try the other trainers?$"

Route115_Text_AceAlixWontFight:
	.string "Eww, you're not worth our time\n"
	.string "Go fight the others first...$" 

Route115_Text_AceHeleneFight:
	.string "We. Are. UNDEFEATABLE!$"

Route115_Text_AceAlixFight:
	.string "You dare challenge your superiors!?$"

Route115_Text_AceAlixLost:
	.string "I guess you was the superior\n"
	.string "afterall...$"

Route115_Text_AceHeleneLost:
	.string "We. Are. Defeatable...$"

Route115_Text_AceHeleneAfter:
	.string "Wow, to beat us you must be\n"
	.string "insanely strong!$"
	.string "I hope you make better use of\n"
	.string "this than I did.$"

Route115_Text_AceAlixAfter:
	.string "Whatever...\p"
	.string "I didnt want this anyways.$"


Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Caves have been much more eventful\n"
	.string "as of recent, have you noticed?\p"
	.string "Theres so much more variety in caves\n"
	.string "now, it excites me to see what jumps out!$"

Route115_Text_RouteSignRustboro:
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

