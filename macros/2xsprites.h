#define PNGNAME2X(VEHICLENAME, CARGONAME) STR(2x/VEHICLENAME##CARGONAME.vox.png)
#define PNGNAME2X_32BPP(VEHICLENAME, CARGONAME) STR(2x_32bpp/VEHICLENAME##CARGONAME.vox.png)
#define PNGNAME2X_32BPP_MASK(VEHICLENAME, CARGONAME) STR(2x_32bpp/VEHICLENAME##CARGONAME.vox.mask.png)
#define PNGNAME_32BPP(VEHICLENAME, CARGONAME) STR(32bpp/VEHICLENAME##CARGONAME.vox.png)
#define PNGNAME_32BPP_MASK(VEHICLENAME, CARGONAME) STR(32bpp/VEHICLENAME##CARGONAME.vox.mask.png)

#define ALTERNATIVESPRITE(VEHICLENAME, CARGO, LENGTH) \
alternative_sprites(spriteset_##VEHICLENAME##CARGO, ZOOM_LEVEL_IN_2X, BIT_DEPTH_8BPP, PNGNAME2X(VEHICLENAME,CARGO)) { template_rv_2x() } \
alternative_sprites(spriteset_##VEHICLENAME##CARGO, ZOOM_LEVEL_IN_2X, BIT_DEPTH_32BPP, PNGNAME2X_32BPP(VEHICLENAME,CARGO), PNGNAME2X_32BPP_MASK(VEHICLENAME,CARGO)) { template_rv_2x() } \
alternative_sprites(spriteset_##VEHICLENAME##CARGO, ZOOM_LEVEL_NORMAL, BIT_DEPTH_32BPP, PNGNAME_32BPP(VEHICLENAME,CARGO), PNGNAME_32BPP_MASK(VEHICLENAME,CARGO)) { template_rv_1x() }

#define ALTERNATIVESPRITE_TRAM(VEHICLENAME, CARGO, LENGTH) \
alternative_sprites(spriteset_##VEHICLENAME##CARGO, ZOOM_LEVEL_IN_2X, BIT_DEPTH_8BPP, PNGNAME2X(VEHICLENAME,CARGO)) { template_tram_2x() } \
alternative_sprites(spriteset_##VEHICLENAME##CARGO, ZOOM_LEVEL_IN_2X, BIT_DEPTH_32BPP, PNGNAME2X_32BPP(VEHICLENAME,CARGO), PNGNAME2X_32BPP_MASK(VEHICLENAME,CARGO)) { template_tram_2x() } \
alternative_sprites(spriteset_##VEHICLENAME##CARGO, ZOOM_LEVEL_NORMAL, BIT_DEPTH_32BPP, PNGNAME_32BPP(VEHICLENAME,CARGO), PNGNAME_32BPP_MASK(VEHICLENAME,CARGO)) { template_tram_1x() }


#define SPRITES2X(VEHICLENAME, LENGTH)                  \
ALTERNATIVESPRITE(VEHICLENAME, , LENGTH)                \
ALTERNATIVESPRITE(VEHICLENAME, _coal, LENGTH)           \
ALTERNATIVESPRITE(VEHICLENAME, _copper, LENGTH)         \
ALTERNATIVESPRITE(VEHICLENAME, _goods, LENGTH)          \
ALTERNATIVESPRITE(VEHICLENAME, _grain, LENGTH)          \
ALTERNATIVESPRITE(VEHICLENAME, _grey, LENGTH)           \
ALTERNATIVESPRITE(VEHICLENAME, _iore, LENGTH)           \
ALTERNATIVESPRITE(VEHICLENAME, _lvst, LENGTH)           \
ALTERNATIVESPRITE(VEHICLENAME, _stel, LENGTH)           \
ALTERNATIVESPRITE(VEHICLENAME, _tanker, LENGTH)         \
ALTERNATIVESPRITE(VEHICLENAME, _timber, LENGTH)         \
ALTERNATIVESPRITE(VEHICLENAME, _wood, LENGTH)

#define SPRITES2X_GOODS_MAIL(VEHICLENAME, LENGTH)       \
ALTERNATIVESPRITE(VEHICLENAME, , LENGTH)                \
ALTERNATIVESPRITE(VEHICLENAME, _goods, LENGTH)          \
ALTERNATIVESPRITE(VEHICLENAME, _mail, LENGTH)

#define SPRITES2X_BUS(VEHICLENAME, LENGTH)              \
ALTERNATIVESPRITE(VEHICLENAME, , LENGTH)

#define SPRITES2X_TRAM(VEHICLENAME, LENGTH)              \
ALTERNATIVESPRITE_TRAM(VEHICLENAME, , LENGTH)


#define SPRITES2X_WITH_FLATBED(VEHICLENAME, LENGTH)     \
ALTERNATIVESPRITE(VEHICLENAME, _flatbed, LENGTH)
