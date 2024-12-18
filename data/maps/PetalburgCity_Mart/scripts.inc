PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE
	release
	end

PetalburgCity_Mart_EventScript_ExpandedItems::
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE
	release
	end

PetalburgCity_Mart_EventScript_Woman::
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Script_AabhashMinMax::
	msgbox PetalburgCity_Mart_Text_AabhashMinMax, MSGBOX_NPC
	goto_if_unset FLAG_AABHASH_PETALMART, PetalburgCity_Mart_Script_AabhashHide
	end

PetalburgCity_Mart_Script_AabhashHide::
	setflag FLAG_AABHASH_PETALMART
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger:
	.string "There are some strong trainers,\n"
	.string "running about nowadays.\p"
	.string "I heard some are abusing held items,\n"
	.string "stat boosts, and natures!$"

PetalburgCity_Mart_Text_RepelIsUseful:
	.string "Man I really want some\n"
	.string "Mints and Vitamins for my team!\p"
	.string "But the store clerk says you need at\n"
	.string "least 2 badges to be 'worthy'$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
	.string "Have you seen the prices of\n"
	.string "these stores?\p"
	.string "I heard it was bad, but this is\n"
	.string "outrageous!\p"
	.string "Inflation is crazy here...$"


PetalburgCity_Mart_Text_AabhashMinMax:
	.string "Mmmm...\p"
	.string "I can minmax the fuck outta this game\n"
	.string "huh?\p"
	.string "Time to spreadsheet I guess.$"
