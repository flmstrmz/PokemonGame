.set LOCALID_TY, 4

OldaleTown_Mart_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_Mart_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldaleTownMart_OnFrame
	.byte 0

OldaleTown_Mart_OnTransition:
	setflag FLAG_TY_MART
	end

OldaleTownMart_OnFrame:
	map_script_2 VAR_OLDALE_TYMART, 0, OldaleTown_Mart_Script_Ty
	.2byte 0


OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Script_Ty::
	lockall
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_TY
	setvar VAR_OLDALE_TYMART, 1
	clearflag FLAG_TY_MART
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	playse SE_SLIDING_DOOR
	waitse
	applymovement LOCALID_TY, OldaleTown_TyWalk
	waitmovement 0
	msgbox OldaleTown_Mart_Text_Ty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TY, OldaleTown_TyLeave
	waitmovement 0
	playse SE_SLIDING_DOOR
	waitse
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_VAR_2
	removeobject LOCALID_TY
	releaseall
	end

OldaleTown_TyWalk::
	walk_in_place_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

OldaleTown_TyLeave::
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end



OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "The clerk says that guy got the last\n"
	.string "POKé BALLS...\p"
	.string "How am I supposed to catch my Vulpix now..$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "POKé BALLS back in stock!\n"
	.string "I hope I see another Vulpix soon.$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "If a POKéMON gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your POKéMON from fainting,\n"
	.string "play better lmao.$"


	OldaleTown_Mart_Text_Ty:
	.string "AYO BOSSMAN, hook me up\p"
	.string "Yeah I'll take those last Pokéballs.\p"
	.string "My guyyy!\p"
	.string "Yhyh Safeeee.$"

