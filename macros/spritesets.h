#define PNGNAME(VEHICLENAME, CARGONAME) STR(png/VEHICLENAME##CARGONAME.vox.png)
#define STR(s) #s

#define SPRITESET(VEHICLENAME, CARGONAME, LENGTH) \
spriteset (spriteset_##VEHICLENAME##CARGONAME, PNGNAME(VEHICLENAME,CARGONAME) ) { \
  template_length_##LENGTH()                                                      \
}

#define SPRITEGROUP(VEHICLENAME, EMPTYSTATE, CARGONAME)                                 \
spritegroup spritegroup_##VEHICLENAME##CARGONAME {                                      \
	loading: [ spriteset_##VEHICLENAME##EMPTYSTATE, spriteset_##VEHICLENAME##CARGONAME ]; \
	loaded:  [ spriteset_##VEHICLENAME##EMPTYSTATE, spriteset_##VEHICLENAME##CARGONAME ]; \
}

#define VEHICLESPRITES_BUS(VEHICLENAME, LENGTH)  \
SPRITESET(VEHICLENAME,,LENGTH)                   \


#define VEHICLESPRITES(VEHICLENAME, LENGTH)      \
SPRITESET(VEHICLENAME,,LENGTH)                   \
SPRITESET(VEHICLENAME,_copper,LENGTH)            \
SPRITESET(VEHICLENAME,_goods,LENGTH)             \
SPRITESET(VEHICLENAME,_coal,LENGTH)              \
SPRITESET(VEHICLENAME,_grain,LENGTH)             \
SPRITESET(VEHICLENAME,_grey,LENGTH)              \
SPRITESET(VEHICLENAME,_iore,LENGTH)              \
SPRITESET(VEHICLENAME,_lvst,LENGTH)              \
SPRITESET(VEHICLENAME,_stel,LENGTH)              \
SPRITESET(VEHICLENAME,_tanker,LENGTH)            \
SPRITESET(VEHICLENAME,_timber,LENGTH)            \
SPRITESET(VEHICLENAME,_wood,LENGTH)

#define VEHICLESPRITES_NO_LIVESTOCK(VEHICLENAME, LENGTH)      \
SPRITESET(VEHICLENAME,,LENGTH)                   \
SPRITESET(VEHICLENAME,_copper,LENGTH)            \
SPRITESET(VEHICLENAME,_goods,LENGTH)             \
SPRITESET(VEHICLENAME,_coal,LENGTH)              \
SPRITESET(VEHICLENAME,_grain,LENGTH)             \
SPRITESET(VEHICLENAME,_grey,LENGTH)              \
SPRITESET(VEHICLENAME,_iore,LENGTH)              \
SPRITESET(VEHICLENAME,_stel,LENGTH)              \
SPRITESET(VEHICLENAME,_tanker,LENGTH)            \
SPRITESET(VEHICLENAME,_timber,LENGTH)            \
SPRITESET(VEHICLENAME,_wood,LENGTH)

#define VEHICLESPRITES_WITH_FLATBED(VEHICLENAME, LENGTH) \
VEHICLESPRITES(VEHICLENAME, LENGTH)                      \
SPRITESET(VEHICLENAME,_flatbed,LENGTH)

#define BASE_SPRITEGROUPS(VEHICLENAME, FLATBEDTYPE)  \
SPRITEGROUP(VEHICLENAME,, _coal)                \
SPRITEGROUP(VEHICLENAME,, _grain)               \
SPRITEGROUP(VEHICLENAME,, _grey)                \
SPRITEGROUP(VEHICLENAME,, _iore)                \
SPRITEGROUP(VEHICLENAME, FLATBEDTYPE, _copper)  \
SPRITEGROUP(VEHICLENAME, FLATBEDTYPE, _stel)    \
SPRITEGROUP(VEHICLENAME, FLATBEDTYPE, _timber)  \
SPRITEGROUP(VEHICLENAME, FLATBEDTYPE, _wood)

#define SPRITEGROUPS_WITH_FLATBED(VEHICLENAME)  BASE_SPRITEGROUPS(VEHICLENAME, _flatbed)
#define SPRITEGROUPS(VEHICLENAME)  BASE_SPRITEGROUPS(VEHICLENAME,)

#define SPRITEGROUPS_PIECE_GOODS(VEHICLENAME) SPRITEGROUP(VEHICLENAME,, _goods)
#define SPRITEGROUPS_PIECE_GOODS_FLATBED(VEHICLENAME) SPRITEGROUP(VEHICLENAME, _flatbed, _goods)

#define SPRITEGROUPS_LIVESTOCK(VEHICLENAME) SPRITEGROUP(VEHICLENAME,, _lvst)
#define SPRITEGROUPS_LIVESTOCK_FLATBED(VEHICLENAME) SPRITEGROUP(VEHICLENAME, _flatbed, _lvst)

#define SPRITEGROUPS_TANKER(VEHICLENAME) SPRITEGROUP(VEHICLENAME,, _tanker)
#define SPRITEGROUPS_TANKER_FLATBED(VEHICLENAME) SPRITEGROUP(VEHICLENAME, _flatbed, _tanker)

#define TRAILERSPRITES(VEHICLENAME, LENGTH)      \
SPRITESET(VEHICLENAME,,LENGTH)                   \
SPRITESET(VEHICLENAME,_copper,LENGTH)            \
SPRITESET(VEHICLENAME,_goods,LENGTH)             \
SPRITESET(VEHICLENAME,_coal,LENGTH)              \
SPRITESET(VEHICLENAME,_grain,LENGTH)             \
SPRITESET(VEHICLENAME,_grey,LENGTH)              \
SPRITESET(VEHICLENAME,_iore,LENGTH)              \
SPRITESET(VEHICLENAME,_lvst,LENGTH)              \
SPRITESET(VEHICLENAME,_stel,LENGTH)              \
SPRITESET(VEHICLENAME,_tanker,LENGTH)            \
SPRITESET(VEHICLENAME,_timber,LENGTH)            \
SPRITESET(VEHICLENAME,_flatbed,LENGTH)           \
SPRITESET(VEHICLENAME,_wood,LENGTH)

#define TRAILERGROUPS(VEHICLENAME)               \
SPRITEGROUPS_WITH_FLATBED(VEHICLENAME)
