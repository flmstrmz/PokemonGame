.set LOCALID_SUGI, 1

Winstrates_Tunnel_MapScripts::
	.byte 0

WinstrateTunnel_EventScript_Sugi::
	applymovement LOCALID_SUGI, Common_Movement_FacePlayer
	waitmovement 0
	msgbox WinstrateTunnel_Text_Sugi, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_SUGI_DRAKEGROTTO, WinstrateTunnel_Text_SugiLost
	msgbox WinstrateTunnel_Text_SugiFine, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDESUGI_WSTUNNEL
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	removeobject LOCALID_SUGI
	fadescreen FADE_FROM_BLACK
	end


WinstrateTunnel_Text_Sugi:
.string "Nah bruv...\p"
.string "How the hell did you get in here?\p"
.string "Bro this here is MY ENDS, you\n"
.string "can't be in here like that...\p"
.string "... ... ... ... ...\p"
.string "Brodie if you ain't gonna leave,\n"
.string "I'll remove you myself.$"

WinstrateTunnel_Text_SugiLost:
.string "In my own home... This is violation$"

WinstrateTunnel_Text_SugiFine:
.string "Fam, you know what yeah...\p"
.string "You're lucky I ain't got work today\n"
.string "I ain't got time to be stressing\p"
.string "You better not be here time I\n"
.string "get back...$"
