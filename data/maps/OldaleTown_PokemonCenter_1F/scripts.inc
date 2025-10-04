OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_MoveRelearner::
	lockall
	faceplayer
	waitmovement 0
	goto OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	end

OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove::
	msgbox OldaleTown_PokemonCenter_1F_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OldaleTown_PokemonCenter_1F_EventScript_SeeYouLater
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMon::
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_PokemonCenter_1F_EventScript_SeeYouLater
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMove
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMove::
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	goto OldaleTown_PokemonCenter_1F_EventScript_SeeYouLater
	end

OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon::
	msgbox OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg::
	msgbox OldaleTown_PokemonCenter_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_SeeYouLater::
	msgbox OldaleTown_PokemonCenter_1F_Text_SeeYouLater, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

OldaleTown_PokemonCenter_1F_Text_WantMeToTeachMove:
	.string "I'm the MOVE TUTOR.\n"
	.string "Want me to teach a move?$"

OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon:
	.string "This POKéMON can't learn any moves.$"

OldaleTown_PokemonCenter_1F_Text_SeeYouLater:
	.string "See you later!$"

OldaleTown_PokemonCenter_1F_Text_CantTeachEgg:
	.string "I can't teach moves to an EGG.$"