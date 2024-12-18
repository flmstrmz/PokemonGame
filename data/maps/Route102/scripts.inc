Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated, Route102_Script_WinCount
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated, Route102_Script_WinCount
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated, Route102_Script_WinCount
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Script_WinCount::
	addvar VAR_ROUTE102_WIN_COUNT, 1
	goto_if_eq VAR_ROUTE102_WIN_COUNT, 3, Route102_ACE_Ready
	end

Route102_ACE_Ready::
	setflag FLAG_ROUTE102_ACEFIGHT
 	msgbox Route102_Text_TianaPostBattle MSGBOX_DEFAULT
	closemessage
	end

Route102_Script_ACE::
	goto_if_set FLAG_ROUTE102_ACEFIGHT, Route102_ACE_Fight
	goto_if_unset FLAG_ROUTE102_ACEFIGHT, Route102_ACE_Talk
	end

Route102_ACE_Fight::
	trainerbattle_single TRAINER_102_ACE, Route102_Text_ACE2, Route102_Text_ACE3, Route102_ACE_Won
	msgbox Route102_Text_ACE4, MSGBOX_NPC
	end

Route102_ACE_Won::
	msgbox Route102_TEXT_ACE5, MSGBOX_NPC
	closemessage
	giveitem ITEM_MODEST_MINT
	closemessage
	giveitem ITEM_ADAMANT_MINT
	closemessage
	end

Route102_ACE_Talk::
	msgbox Route102_Text_ACE1, MSGBOX_NPC
	end


Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "What are you talking to little\n"
	.string "kids for?\p"
	.string "You trying to Diddy me?$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "Did you know there are super rare\n"
	.string "POKéMON in each route?\p"
	.string "I hear some arent even from this region!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_Text_ACE1:
	.string "Huh?\p"
	.string "You wanna fight me?\p"
	.string "Go beat everyone else first Boomer$"

Route102_Text_ACE2:
	.string "Another Lamb to the slaughter!$"

Route102_Text_ACE3:
	.string "Oh wow congrats you beat a 12 year\n"
	.string "old..$"

Route102_Text_ACE4:
	.string "Wow you're so cool..$"

Route102_TEXT_ACE5:
	.string "You must feel so good, here take\n"
	.string "my house!\p"
	.string "You earned it beating someone half\n"
	.string "your size..$"
