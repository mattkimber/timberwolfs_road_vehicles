#define TRAM_ENGINE(VEHICLENAME, LENGTH)        \
  SPRITESET_TRAM(VEHICLENAME,,LENGTH)            \
  PURCHASE_SPRITESET(VEHICLENAME)           \
  ALTERNATIVESPRITE_TRAM(VEHICLENAME, , LENGTH)  \
  ALTERNATIVESPRITE_4X_TRAM(VEHICLENAME, , LENGTH)


#define CARGO_TRAM_SWITCH(VEHICLENAME, TRAILERNAME, SWITCHTYPE, VALUE1, VALUE2)              \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_##SWITCHTYPE, position_in_consist ) {  \
      0: return VALUE1;                                                                      \
      return VALUE2;                                                                         \
  }

#define CARGO_TRAM_CAPACITY_SWITCH(VEHICLENAME, TRAILERNAME, SWITCHTYPE, VALUE1, VALUE2, VALUE3) \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_##SWITCHTYPE, position_in_consist ) {  \
      0: return VALUE1;                                                                      \
      1: return VALUE2;                                                                      \
      return VALUE3;                                                                         \
  }


#define CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, CARGONAME, CARGOTYPE)                      \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics##CARGONAME, position_in_consist ) { \
      0: spriteset_##VEHICLENAME;                                                                  \
      sprite##CARGOTYPE##_##TRAILERNAME##CARGONAME;                                                \
  }

#define HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, CARGONAME, CARGOTYPE)                \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics##CARGONAME, position_in_consist ) { \
      0: switch_##VEHICLENAME##_animation;                                                         \
      sprite##CARGOTYPE##_##TRAILERNAME##CARGONAME;                                                \
  }

#define CARGO_TRAM_GOODS_GFX_SWITCH(VEHICLENAME, TRAILERNAME)                                 \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics_goods, position_in_consist) {  \
      0: spriteset_##VEHICLENAME;                                                           \
      switch_tram_goods_trailer;                                                   \
  }

#define HORSE_CARGO_TRAM_GOODS_GFX_SWITCH(VEHICLENAME, TRAILERNAME)                                 \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics_goods, position_in_consist) {  \
      0: switch_##VEHICLENAME##_animation;                                                     \
      switch_tram_goods_trailer;                                                   \
  }


  #define CARGO_TRAM_SWITCHES(VEHICLENAME, TRAILERNAME, WAGONS, LENGTH, CAPACITY, VISUAL_EFFECT)                  \
    CARGO_TRAM_CAPACITY_SWITCH(VEHICLENAME, TRAILERNAME, capacity, 1, CAPACITY - 1, CAPACITY)      \
    CARGO_TRAM_SWITCH(VEHICLENAME, TRAILERNAME, visual_effect, VISUAL_EFFECT, VISUAL_EFFECT_DISABLE) \
    CARGO_TRAM_SWITCH(VEHICLENAME, TRAILERNAME, length, LENGTH / 8, 4)                             \
    switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_articulation, extra_callback_info1) { \
        0..##WAGONS##: return vehicle_##VEHICLENAME;                                          \
        return CB_RESULT_NO_MORE_ARTICULATED_PARTS;                                           \
        }


  #define CARGO_TRAM_GFX(VEHICLENAME, TRAILERNAME, LENGTH)          \
    CARGO_TRAM_GOODS_GFX_SWITCH(VEHICLENAME, TRAILERNAME)           \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _coal, group)   \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _copper, group) \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _iore, group)   \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _tanker, set)   \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grain, group)  \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grey, group)   \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _lvst, set)     \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _stel, group)   \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _timber, group) \
    CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _wood, group)


  #define HORSE_CARGO_TRAM_GFX(VEHICLENAME, TRAILERNAME, LENGTH)          \
    HORSE_CARGO_TRAM_GOODS_GFX_SWITCH(VEHICLENAME, TRAILERNAME)           \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _coal, group)   \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _copper, group) \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _iore, group)   \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _tanker, set)   \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grain, group)  \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grey, group)   \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _lvst, set)     \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _stel, group)   \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _timber, group) \
    HORSE_CARGO_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _wood, group)

#define CARGO_TRAM(VEHICLENAME, TRAILERNAME, WAGONS, LENGTH, CAPACITY, VISUAL_EFFECT)    \
      TRAM_ENGINE(VEHICLENAME, LENGTH)                                    \
      CARGO_TRAM_GFX(VEHICLENAME, TRAILERNAME, length)                    \
      CARGO_TRAM_SWITCHES(VEHICLENAME, TRAILERNAME, WAGONS, LENGTH, CAPACITY, VISUAL_EFFECT)

#define HORSE_CARGO_TRAM(VEHICLENAME, TRAILERNAME, WAGONS, LENGTH, CAPACITY)  \
      PURCHASE_SPRITESET(VEHICLENAME)                                         \
      HORSE_DRAWN_CARGO_TRAM_ANIM_SWITCH(VEHICLENAME)                               \
      HORSE_CARGO_TRAM_GFX(VEHICLENAME, TRAILERNAME, LENGTH)                  \
      CARGO_TRAM_SWITCHES(VEHICLENAME, TRAILERNAME, WAGONS, LENGTH, CAPACITY, VISUAL_EFFECT_DISABLE)

#define CARGO_TRAM_GRAPHICS_BLOCK(VEHICLENAME)            \
  articulated_part: switch_##VEHICLENAME##_articulation;  \
  cargo_capacity: switch_##VEHICLENAME##_capacity;        \
  purchase_cargo_capacity: spriteset_purchase_##VEHICLENAME; \
  length: switch_##VEHICLENAME##_length;                  \
  purchase: spriteset_purchase_##VEHICLENAME;             \
  visual_effect: switch_##VEHICLENAME##_visual_effect;    \
  COAL: switch_##VEHICLENAME##_graphics_coal;             \
  OIL_: switch_##VEHICLENAME##_graphics_tanker;           \
  LVST: switch_##VEHICLENAME##_graphics_lvst;             \
  GRAI: switch_##VEHICLENAME##_graphics_grain;            \
  WOOD: switch_##VEHICLENAME##_graphics_wood;             \
  STEL: switch_##VEHICLENAME##_graphics_stel;             \
  METL: switch_##VEHICLENAME##_graphics_stel;             \
  IORE: switch_##VEHICLENAME##_graphics_iore;             \
  WHEA: switch_##VEHICLENAME##_graphics_grain;            \
  RUBR: switch_##VEHICLENAME##_graphics_tanker;           \
  MAIZ: switch_##VEHICLENAME##_graphics_grain;            \
  CORE: switch_##VEHICLENAME##_graphics_iore;             \
  WATR: switch_##VEHICLENAME##_graphics_tanker;           \
  SAND: switch_##VEHICLENAME##_graphics_grain;            \
  AORE: switch_##VEHICLENAME##_graphics_iore;             \
  CLAY: switch_##VEHICLENAME##_graphics_iore;             \
  GRVL: switch_##VEHICLENAME##_graphics_grey;             \
  SCMT: switch_##VEHICLENAME##_graphics_grey;             \
  LIME: switch_##VEHICLENAME##_graphics_grey;             \
  WDPR: switch_##VEHICLENAME##_graphics_timber;           \
  COPR: switch_##VEHICLENAME##_graphics_copper;           \
  RFPR: switch_##VEHICLENAME##_graphics_tanker;           \
  MILK: switch_##VEHICLENAME##_graphics_tanker;           \
  PETR: switch_##VEHICLENAME##_graphics_tanker;           \
  SGBT: switch_##VEHICLENAME##_graphics_iore;             \
  default: switch_##VEHICLENAME##_graphics_goods;
