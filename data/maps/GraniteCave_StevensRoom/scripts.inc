.set LOCALID_STEVEN, 1
.set LOCALID_SAMIR, 2

GraniteCave_StevensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GraniteCaveOnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SetSamir
	.byte 0

SetSamir:
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SAMIR
	end

GraniteCaveOnFrame:
	map_script_2 VAR_SAMIR_STEPHEN, 0, GraniteCave_Samir_Stephen
	.2byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_GRANITE_SAMIR
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	release
	end

GraniteCave_Samir_Stephen::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, GraniteCave_CamDown
	addvar VAR_SAMIR_STEPHEN, 1
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox GraniteCave_StevenShocked, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_SAMIR, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox GraniteCave_SamirIDTYR, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox GraniteCave_StevenStop, MSGBOX_DEFAULT
	closemessage
	delay 48
	applymovement LOCALID_SAMIR, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_SAMIR, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox GraniteCave_SamirUltimatum, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, GraniteCave_CamUp
	applymovement LOCALID_SAMIR, GraniteCave_SamirWalkUp
	waitmovement 0
	special RemoveCameraObject
	playse SE_PIN
	applymovement LOCALID_SAMIR, Common_Movement_ExclamationMark
	waitmovement 0
	delay 8
	msgbox GraniteCave_SamirOpen MSGBOX_AUTOCLOSE
	setflag FLAG_HIDE_SAMIR_GRANITE
	setflag FLAG_3VS3
	trainerbattle_no_intro TRAINER_SAMIR_3, GraniteCave_SamirLost
	switch VAR_RESULT
	case 1, GraniteCave_Samir_Leaves
	goto GraniteCave_Samir_Leaves2
	end

GraniteCave_Samir_Leaves::
	lockall
	setflag FLAG_BEAT_SAMIR_GRANITE
	msgbox GraniteCave_SamirShow, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_PlayerMove
	applymovement LOCALID_SAMIR, GraniteCave_SamirLeave
	waitmovement 0
	removeobject LOCALID_SAMIR
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_VAR_2
	releaseall
	end

GraniteCave_Samir_Leaves2::
	lockall
	setflag FLAG_BEAT_SAMIR_GRANITE
	msgbox GraniteCave_SamirMove, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_PlayerMove
	applymovement LOCALID_SAMIR, GraniteCave_SamirLeave
	waitmovement 0
	removeobject LOCALID_SAMIR
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_VAR_2
	releaseall
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_SamirWalkUp::
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

GraniteCave_SamirLeave::
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

GraniteCave_PlayerMove::
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

GraniteCave_CamDown::
	walk_down
	walk_down
	walk_down
	step_end

GraniteCave_CamUp::
	walk_up
	walk_up
	walk_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "...\p"
	.string "Apologies you were pulled into that.\p"
	.string "I was taken aback, murmurs of a madman.\p" 
	.string "I noticed they recognized you?\n"
	.string "Clearly not on friendly terms however.\p"
	.string "Anyhow, what is your buisiness here?\p"
	.string "... ... ...\p"
	.string "You're looking for Stephen? Well\n"
	.string "you have found him!\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains one my favorite moves,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "Watching you fight just now...\n"
	.string "Impressive I must say!\p"
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could\n"
	.string "challenge the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Well it has been an eventful\n"
	.string "day.\p"
	.string "Now, I'm afraid I've got to hurry along.\p"
	.string "DEVON has me on an important task to\n"
	.string "find some colourful 'rocks'!$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

GraniteCave_StevenShocked:
	.string "You seek to WHAT!?\p"
	.string "While I admire your optimism,\n"
	.string "you're not...$"

GraniteCave_SamirIDTYR:
	.string "Bro...\p"
	.string "Like...\p"
	.string "I don't think you realise,\n"
	.string "how easy it is...$"

GraniteCave_StevenStop:
	.string "I'd suggest you stop before\n"
	.string "you get yourself hurt kid.$"

GraniteCave_SamirUltimatum:
	.string "If you don't tell me right nyow\p"
	.string "...\p"
	.string "You're not the only one who\n"
	.string "knows y'know...$"

GraniteCave_SamirOpen:
	.string "Nyaa! Move out of my way, right meow,\n"
	.string "or else!!$"

GraniteCave_SamirLost:
	.string "THIS GAME IS SO DOGSHIT$"

GraniteCave_SamirShow:
	.string "...Just you wait$"

GraniteCave_SamirMove:
	.string "bro you fucking suck...$"


