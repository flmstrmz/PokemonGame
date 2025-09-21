.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Winstrates_OnFrame
	.byte 0

Winstrates_OnFrame:
	map_script_2 VAR_WINSTRATE_STAIRS, 4, Route111_WinstrateFamilysHouse_EventScript_ShowStairs
	.2byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Sign_Window::
	goto_if_ne VAR_WINSTRATE_STAIRS, 0, Route111_WinstrateFamilysHouse_EventScript_ResetLock
	msgbox Route111_WinstrateFamilysHouse_Text_Click, MSGBOX_AUTOCLOSE
	addvar VAR_WINSTRATE_STAIRS, 1
	end

Route111_WinstrateFamilysHouse_Sign_Drawers::
	goto_if_eq VAR_WINSTRATE_STAIRS, 0, Route111_WinstrateFamilysHouse_EventScript_Nothing
	goto_if_ne VAR_WINSTRATE_STAIRS, 3, Route111_WinstrateFamilysHouse_EventScript_ResetLock
	msgbox Route111_WinstrateFamilysHouse_Text_Click, MSGBOX_AUTOCLOSE
	addvar VAR_WINSTRATE_STAIRS, 1
	end

Route111_WinstrateFamilysHouse_Sign_Sink::
	msgbox Route111_WinstrateFamilysHouse_Text_Sink, MSGBOX_AUTOCLOSE
	end

Route111_WinstrateFamilysHouse_Sign_Fridge::
	msgbox Route111_WinstrateFamilysHouse_Text_Fridge, MSGBOX_AUTOCLOSE
	end

Route111_WinstrateFamilysHouse_Sign_Counter::
	goto_if_eq VAR_WINSTRATE_STAIRS, 0, Route111_WinstrateFamilysHouse_EventScript_Nothing
	goto_if_ne VAR_WINSTRATE_STAIRS, 1, Route111_WinstrateFamilysHouse_EventScript_ResetLock
	msgbox Route111_WinstrateFamilysHouse_Text_Mechanism, MSGBOX_AUTOCLOSE
	addvar VAR_WINSTRATE_STAIRS, 1
	end

Route111_WinstrateFamilysHouse_Sign_PlantRight::
	msgbox Route111_WinstrateFamilysHouse_Text_PlantRight, MSGBOX_AUTOCLOSE
	end

Route111_WinstrateFamilysHouse_Sign_PlantLeft::
	goto_if_eq VAR_WINSTRATE_STAIRS, 0, Route111_WinstrateFamilysHouse_EventScript_Nothing
	goto_if_ne VAR_WINSTRATE_STAIRS, 2, Route111_WinstrateFamilysHouse_EventScript_ResetLock
	msgbox Route111_WinstrateFamilysHouse_Text_Rumble, MSGBOX_AUTOCLOSE
	addvar VAR_WINSTRATE_STAIRS, 1
	end

Route111_WinstrateFamilysHouse_Sign_DisplayCase::
	msgbox Route111_WinstrateFamilysHouse_Text_DisplayCase, MSGBOX_AUTOCLOSE
	end

Route111_WinstrateFamilysHouse_EventScript_ResetLock::
	setvar VAR_WINSTRATE_STAIRS, 0
	msgbox Route111_WinstrateFamilysHouse_Text_Locked, MSGBOX_AUTOCLOSE
	end

Route111_WinstrateFamilysHouse_EventScript_Addlock::
	addvar VAR_WINSTRATE_STAIRS, 1
	end

Route111_WinstrateFamilysHouse_EventScript_Nothing::
	msgbox Route111_WinstrateFamilysHouse_Text_Nothing, MSGBOX_AUTOCLOSE
	end

Route111_WinstrateFamilysHouse_EventScript_ShowStairs::
	setmetatile 0, 4, METATILE_GenericBuilding_TrickHouse_Stairs_Down, FALSE
	special DrawWholeMapView
	playse SE_TRUCK_DOOR
	msgbox Route111_WinstrateFamilysHouse_Text_Hatch, MSGBOX_AUTOCLOSE
	setvar VAR_WINSTRATE_STAIRS, 0
	end

Route111_WinstrateFamilysHouse_Text_Sink:
	.string "Its just a sink...$"

Route111_WinstrateFamilysHouse_Text_PlantRight:
	.string "Its just a Plant...$"

Route111_WinstrateFamilysHouse_Text_DisplayCase:
	.string "It's littered with dragon statues...$"

Route111_WinstrateFamilysHouse_Text_Fridge:
	.string "The fridge has a child lock on it...$"

Route111_WinstrateFamilysHouse_Text_Click:
	.string "You hear a faint click...$"

Route111_WinstrateFamilysHouse_Text_Mechanism:
	.string "You hear a mechanism rotate below...$"

Route111_WinstrateFamilysHouse_Text_Rumble:
	.string "You feel the floor shift beneath...$"

Route111_WinstrateFamilysHouse_Text_Locked:
	.string "You hear the lock reset!$" 

Route111_WinstrateFamilysHouse_Text_Nothing:
	.string "Nothing happens!$"

Route111_WinstrateFamilysHouse_Text_Hatch:
	.string "You hear a hatch crash open!$"

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "You're the first TRAINER I've seen who\n"
	.string "deploys POKéMON so masterfully.\p"
	.string "But, I should tell you--my son is\n"
	.string "stronger than you.\p"
	.string "He even took the POKéMON LEAGUE\n"
	.string "challenge, I'll have you know.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "We use this MACHO BRACE to more\n"
	.string "effectively strengthen our POKéMON\l"
	.string "in training.\p"
	.string "Since you've beaten all of us here,\n"
	.string "I don't know if you need it, but we\l"
	.string "would like you to have our MACHO BRACE.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "When it comes to POKéMON battles,\n"
	.string "we tend to be pretty passionate.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mommy is stronger than Daddy.\p"
	.string "I'm stronger than Mommy.\p"
	.string "And Grandma's stronger than me!\p"
	.string "But my big brother is even stronger\n"
	.string "than Grandma.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "There's no question that you're strong.\p"
	.string "But if you were to battle my grandson,\n"
	.string "you'd end up crying in frustration.\p"
	.string "He's much stronger than any TRAINER\n"
	.string "our family knows.\p"
	.string "He must be challenging the POKéMON\n"
	.string "LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "My grandson must be challenging the\n"
	.string "POKéMON LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"

