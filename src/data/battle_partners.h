//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 18
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .lvl = 42,
#line 16
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 25
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 29
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .lvl = 43,
#line 26
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 30
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 35
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 39
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 38
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .lvl = 44,
#line 36
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 40
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 45
    [PARTNER_TY] =
    {
#line 46
        .trainerName = _("TY"),
#line 47
        .trainerClass = TRAINER_CLASS_TY,
#line 48
        .trainerPic = TRAINER_BACK_PIC_TEST,
        .encounterMusic_gender = 
#line 50
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 52
            .species = SPECIES_GOGOAT,
#line 52
            .gender = TRAINER_MON_FEMALE,
#line 52
            .heldItem = ITEM_TERRAIN_EXTENDER,
#line 55
            .ev = TRAINER_PARTY_EVS(165, 12, 0, 0, 0, 165),
#line 57
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 53
            .ability = ABILITY_GRASS_PELT,
#line 54
            .lvl = 35,
#line 56
            .nature = NATURE_CAREFUL,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 57
                MOVE_GRASSY_TERRAIN,
                MOVE_LEECH_SEED,
                MOVE_AERIAL_ACE,
                MOVE_SEED_BOMB,
            },
            },
            {
#line 62
            .species = SPECIES_DOUBLADE,
#line 62
            .gender = TRAINER_MON_MALE,
#line 62
            .heldItem = ITEM_EXPERT_BELT,
#line 66
            .ev = TRAINER_PARTY_EVS(165, 165, 0, 0, 0, 0),
#line 68
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 63
            .ability = ABILITY_NO_GUARD,
#line 64
            .lvl = 35,
#line 67
            .nature = NATURE_ADAMANT,
#line 65
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 68
                MOVE_SHADOW_SNEAK,
                MOVE_NIGHT_SLASH,
                MOVE_RETALIATE,
                MOVE_SWORDS_DANCE,
            },
            },
            {
#line 73
            .species = SPECIES_MAREANIE,
#line 73
            .gender = TRAINER_MON_FEMALE,
#line 73
            .heldItem = ITEM_LEFTOVERS,
#line 77
            .ev = TRAINER_PARTY_EVS(165, 0, 0, 0, 0, 165),
#line 79
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 74
            .ability = ABILITY_REGENERATOR,
#line 75
            .lvl = 35,
#line 78
            .nature = NATURE_SASSY,
#line 76
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 79
                MOVE_TOXIC_SPIKES,
                MOVE_RECOVER,
                MOVE_VENOSHOCK,
                MOVE_LIQUIDATION,
            },
            },
        },
    },
#line 84
    [PARTNER_MIRO] =
    {
#line 85
        .trainerName = _("MIRO"),
#line 86
        .trainerClass = TRAINER_CLASS_MIRO,
#line 87
        .trainerPic = TRAINER_BACK_PIC_TEST,
        .encounterMusic_gender = 
#line 89
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 91
            .species = SPECIES_LUXRAY,
#line 91
            .gender = TRAINER_MON_MALE,
#line 91
            .heldItem = ITEM_FLAME_ORB,
#line 94
            .ev = TRAINER_PARTY_EVS(0, 65, 0, 165, 100, 0),
#line 97
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 92
            .ability = ABILITY_GUTS,
#line 93
            .lvl = 35,
#line 95
            .nature = NATURE_MILD,
#line 96
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 97
                MOVE_VOLT_SWITCH,
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_SHOCK_WAVE,
            },
            },
            {
#line 102
            .species = SPECIES_PORYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 102
            .heldItem = ITEM_WISE_GLASSES,
#line 105
            .ev = TRAINER_PARTY_EVS(165, 0, 0, 4, 165, 0),
#line 107
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 103
            .ability = ABILITY_DOWNLOAD,
#line 104
            .lvl = 35,
#line 106
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 107
                MOVE_PSYBEAM,
                MOVE_THUNDER_WAVE,
                MOVE_SWIFT,
                MOVE_ELECTROWEB,
            },
            },
            {
#line 112
            .species = SPECIES_SCRAGGY,
#line 112
            .gender = TRAINER_MON_MALE,
#line 112
            .heldItem = ITEM_FIGHTING_GEM,
#line 116
            .ev = TRAINER_PARTY_EVS(165, 165, 0, 0, 0, 0),
#line 118
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 113
            .ability = ABILITY_MOXIE,
#line 114
            .lvl = 35,
#line 117
            .nature = NATURE_BRAVE,
#line 115
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 118
                MOVE_BRICK_BREAK,
                MOVE_BEAT_UP,
                MOVE_DRAIN_PUNCH,
                MOVE_FAKE_OUT,
            },
            },
        },
    },
#line 123
    [PARTNER_SUGI] =
    {
#line 124
        .trainerName = _("SUGI"),
#line 125
        .trainerClass = TRAINER_CLASS_SUGI,
#line 126
        .trainerPic = TRAINER_BACK_PIC_TEST,
        .encounterMusic_gender = 
#line 128
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 130
            .species = SPECIES_BRONZONG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 130
            .heldItem = ITEM_ROCKY_HELMET,
#line 133
            .ev = TRAINER_PARTY_EVS(165, 0, 0, 0, 0, 165),
#line 135
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 0, 31, 31),
#line 131
            .ability = ABILITY_LEVITATE,
#line 132
            .lvl = 35,
#line 134
            .nature = NATURE_SASSY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 136
                MOVE_BLOCK,
                MOVE_GYRO_BALL,
                MOVE_EXTRASENSORY,
                MOVE_HYPNOSIS,
            },
            },
            {
#line 141
            .species = SPECIES_SWANNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 141
            .heldItem = ITEM_SHARP_BEAK,
#line 144
            .ev = TRAINER_PARTY_EVS(165, 65, 0, 0, 100, 0),
#line 146
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 142
            .ability = ABILITY_KEEN_EYE,
#line 143
            .lvl = 35,
#line 145
            .nature = NATURE_SERIOUS,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 146
                MOVE_AQUA_JET,
                MOVE_AIR_SLASH,
                MOVE_BUBBLE_BEAM,
                MOVE_BRINE,
            },
            },
            {
#line 151
            .species = SPECIES_MONFERNO,
#line 151
            .gender = TRAINER_MON_MALE,
#line 151
            .heldItem = ITEM_LIFE_ORB,
#line 155
            .ev = TRAINER_PARTY_EVS(12, 165, 0, 165, 0, 0),
#line 157
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 152
            .ability = ABILITY_IRON_FIST,
#line 153
            .lvl = 35,
#line 156
            .nature = NATURE_JOLLY,
#line 154
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 157
                MOVE_MACH_PUNCH,
                MOVE_FLAME_WHEEL,
                MOVE_CLOSE_COMBAT,
                MOVE_U_TURN,
            },
            },
        },
    },
