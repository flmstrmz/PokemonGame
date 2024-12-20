GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_FLASH_TOOL
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "WOAH, chill man chill...\p"
	.string "Look I have nothing left after\l"
	.string "that last guy please!\p"
	.string "The one who came by earlier…\n"
	.string "You didn't see them?\p"
	.string "Well look you seem alot nicer so,\n"
	.string "if you're going deeper youre gonna\l"
	.string "need flash!"
	.string "Well, for us HIKERS, it's a must if\n"
	.string "you're delving.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "DEVON CORP created that tool so\n"
	.string "we didn't need to keep HM Slaves.\l"
	.string "as dead weight in our teams anymore!\p"
	.string "It works the same way as a HM but\n"
	.string "without the need of a pokemon.\p"
	.string "this one lights up even the\n"
	.string "inky darkness of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

