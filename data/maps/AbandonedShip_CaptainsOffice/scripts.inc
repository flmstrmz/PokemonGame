.set LOCALID_WALLY, 3

AbandonedShip_CaptainsOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShipOfficeOnFrame
	.byte 0

ShipOfficeOnFrame:
	map_script_2 VAR_WALLY_SHIP, 0, AbandonedShip_CaptainsOffice_WallyFight
	.2byte 0

AbandonedShip_CaptainsOffice_WallyFight::
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	delay 24
	applymovement LOCALID_WALLY, AbandonedShip_CaptainsOffice_WallyApproach
	waitmovement 0
	msgbox AbandonedShip_CaptainsOffice_Text_WallyHi, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_WALLY_SHIP, AbandonedShip_CaptainsOffice_Text_WallyDefeated
	msgbox AbandonedShip_CaptainsOffice_Text_WallyTraining, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_WALLY_SHIP
	setflag FLAG_BEAT_WALLY_SHIP
	setvar VAR_WALLY_SHIP, 1
	applymovement LOCALID_WALLY, AbandonedShip_CaptainsOffice_WallyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_WALLY
	end

AbandonedShip_CaptainsOffice_Text_WallyHi:
	.string "Oh, hi {PLAYER}!\p"
	.string "Its been quite a while hasn't it!\p"
	.string "What am I here for? Just running an\n"
	.string "errand for my new friend - research\l"
	.string "for some colourful rocks and such!\p"
	.string "They said not to be too long so I\n"
	.string "will have to run sadly\p"
	.string "but not before I show you I have\n"
	.string "surpassed you!$"

AbandonedShip_CaptainsOffice_Text_WallyDefeated:
	.string "I'm still not enough...$"

AbandonedShip_CaptainsOffice_Text_WallyTraining:
	.string "Thank you for the battle {PLAYER},\n"
	.string "I still have room to improve.\p"
	.string "The next time we meet I promise,\n"
	.string "will end in your loss.$"

AbandonedShip_CaptainsOffice_WallyApproach:
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

AbandonedShip_CaptainsOffice_WallyLeave:
	walk_right
	walk_down
	step_end

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	goto_if_eq VAR_WALLY_SHIP, 1, AbandonedShip_CaptainsOffice_EventScript_GiveOpal
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_GiveOpal::
	msgbox AbandonedShip_CaptainsOffice_Text_NeedThis, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_OPAL
	msgbox AbandonedShip_CaptainsOffice_Text_KeyToMegev, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WALLY_SHIP, 2
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_KeyToMegev:
	.string "This precious stone is the key\n"
	.string "to finishing up the bracelet!\p"
	.string "CAPT. STERN informed me he had found\n"
	.string "a deposit and stored it in his office.\p"
	.string "Please deliver this to STEVEN for me.\p"
	.string "I'm busy investigating this ship for\n"
	.string "CAPT. STERN.\p"
	.string "He also asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "I'm busy investigating this ship for\n"
	.string "CAPT. STERN.\p"
	.string "He asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"


AbandonedShip_CaptainsOffice_Text_NeedThis:
	.string "Ah, you must be {PLAYER}?\p"
	.string "Steven gave me a call earlier, seems\n"
	.string "Like you'll be needing this.$"


AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh! That's a SCANNER!\p"
	.string "Listen, can I get you to deliver that\n"
	.string "to CAPT. STERN?\p"
	.string "I want to investigate this ship a\n"
	.string "little more.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "This ship is called S.S. CACTUS.\n"
	.string "It seems to be from an earlier era.$"

