.set LOCALID_KRILL, 1

BattleTower_Roof_MapScripts::
	.byte 0

BattleTower_Roof_EventScript_Krillar::
	goto_if_eq VAR_BATTLETOWER, 2, BattleTower_Roof_EventScript_KrillarRing
	applymovement LOCALID_KRILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleTower_Roof_Text_JoinBelow, MSGBOX_AUTOCLOSE
	end

BattleTower_Roof_EventScript_KrillarRing::
	msgbox BattleTower_Roof_Text_AboutTime MSGBOX_AUTOCLOSE
	applymovement LOCALID_KRILL, Common_Movement_FacePlayer
	msgbox BattleTower_Roof_Text_EvolutionExplained MSGBOX_AUTOCLOSE
	msgbox BattleTower_Roof_Text_HandToMe MSGBOX_AUTOCLOSE
	msgbox BattleTower_Roof_Text_HandoverOpal MSGBOX_AUTOCLOSE
	removeitem ITEM_OPAL
	msgbox BattleTower_Roof_Text_MegaBracelet MSGBOX_AUTOCLOSE
	giveitem ITEM_MEGA_RING
	msgbox BattleTower_Roof_Text_JoinBelow MSGBOX_AUTOCLOSE
	setvar VAR_BATTLETOWER, 3
	end

BattleTower_Roof_Text_AboutTime:
	.string "And so the challenger becomes\n"
	.string "the successor.\p"
	.string "You've bested my weakest students.\p"
	.string "Though my students you have bested\n"
	.string "nonetheless.$"

BattleTower_Roof_Text_EvolutionExplained:
	.string "You stand before me to attain the\n"
	.string "secrets for MEGA EVOLUTION.\p"
	.string "...\p"
	.string "Truth being you need only display\n"
	.string "your strength in battle to your\l"
	.string "Pokemon.\p"
	.string "That same strength you displayed\n"
	.string "in combat with my students.\p"
	.string "If you were to channel that same\n"
	.string "energy into a MEGA Bracer, you\l"
	.string "could achieve true Evolution.\p"
	.string "I take it STEVEN gave you the\n"
	.string "required OPAL?$"

BattleTower_Roof_Text_HandToMe:
	.string "Hand it to me let me see.$"

BattleTower_Roof_Text_HandoverOpal:
	.string "{PLAYER} gave Kriller the OPAL$"

BattleTower_Roof_Text_MegaBracelet:
	.string "Having fought so hard, I can\n"
	.string "see this will work perfectly\p"
	.string "With this energy stored, allow\n"
	.string "me to merge stone with Bracer\p"
	.string "... ... ... ...\p"
	.string "And with that, I relinquish your\n"
	.string "reward.$"

BattleTower_Roof_Text_JoinBelow:
	.string "You may take your leave through\n"
	.string "the elevator if you wish.\p"
	.string "I shall join you shortly.$"

