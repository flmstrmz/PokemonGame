.set LOCALID_NURSE, 1

AbandonedShip_Deck_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
	.byte 0

AbandonedShip_Deck_OnTransition:
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	end


AbandonedShip_Deck_EventScript_Nurse::
	applymovement LOCALID_NURSE, Common_Movement_FacePlayer
	msgbox AbandonedShip_Deck_Text_Nurse MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	setrespawn HEAL_LOCATION_ABANDONED_SHIP
	end

AbandonedShip_Deck_Text_Nurse:
	.string "Hey there!\n"
	.string "I'm tending to trainers in need\p"
	.string "I can heal your pokémon if you'd like?$"
