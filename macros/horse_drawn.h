#define HORSE_DRAWN_PURCHASE_SPRITESET(VEHICLENAME)                         \
spriteset (spriteset_purchase_##VEHICLENAME, PNGNAME(VEHICLENAME,_purchase) ) {   \
  template_purchase()                                           \
}

#define HORSE_DRAWN_BASE_GFX(VEHICLENAME) \
  PURCHASE_SPRITESET(VEHICLENAME) \
  HORSE_DRAWN_ANIM_SWITCH(VEHICLENAME)


#define HORSE_DRAWN_ANIM_SWITCH(VEHICLENAME) \
  switch(FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_animation, motion_counter % 4) { \
    0..1: return spriteset_horses_1;   \
    return spriteset_horses_2;       \
  }

#define HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, CARGONAME, CARGOTYPE)                             \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics##CARGONAME, position_in_consist ) { \
      0: switch_##VEHICLENAME##_animation;                                                                    \
      sprite##CARGOTYPE##_##TRAILERNAME##CARGONAME;                                                  \
  }

  #define HORSE_DRAWN_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY) \
    ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, capacity, 1, param_realistic_early_vehicle_capacity ? REALISTIC_CAPACITY - 1 : CAPACITY - 1)                         \
    ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, length, 4, LENGTH / 8)                             \
    switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_articulation, extra_callback_info1) { \
        0..1: return vehicle_##VEHICLENAME##;                                                   \
        return CB_RESULT_NO_MORE_ARTICULATED_PARTS;                                           \
    }

  #define HORSE_DRAWN_GFX(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY)                               \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _goods, group)                                   \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _coal, group)                                  \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _copper, group)                                \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _iore, group)                                  \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _tanker, group)                                  \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grain, group)                                 \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grey, group)                                  \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _stel, group)                                    \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _timber, group)                                \
    HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _wood, group)

#define HORSE_DRAWN(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY)         \
      HORSE_DRAWN_BASE_GFX(VEHICLENAME)                               \
      HORSE_DRAWN_GFX(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY)       \
      HORSE_DRAWN_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY)

#define HORSE_DRAWN_BUS(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY)         \
      HORSE_DRAWN_BASE_GFX(VEHICLENAME)                               \
      HORSE_DRAWN_GFX_SWITCH(VEHICLENAME, TRAILERNAME, , set)  \
      HORSE_DRAWN_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, CAPACITY)

#define HORSE_DRAWN_BUS_GRAPHICS_BLOCK(VEHICLENAME) \
  articulated_part: switch_##VEHICLENAME##_articulation;  \
  cargo_capacity: switch_##VEHICLENAME##_capacity;        \
  purchase_cargo_capacity: spriteset_purchase_##VEHICLENAME; \
  length: switch_##VEHICLENAME##_length;                  \
  purchase: spriteset_purchase_##VEHICLENAME;             \
  default: switch_##VEHICLENAME##_graphics;

#define HORSE_DRAWN_GRAPHICS_BLOCK(VEHICLENAME) \
  articulated_part: switch_##VEHICLENAME##_articulation;  \
  cargo_capacity: switch_##VEHICLENAME##_capacity;        \
  purchase_cargo_capacity: spriteset_purchase_##VEHICLENAME;       \
  length: switch_##VEHICLENAME##_length;                  \
  purchase: spriteset_purchase_##VEHICLENAME;             \
  COAL: switch_##VEHICLENAME##_graphics_coal;             \
  OIL_: switch_##VEHICLENAME##_graphics_tanker;           \
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
  SGBT: switch_##VEHICLENAME##_graphics_iore;             \
  default: switch_##VEHICLENAME##_graphics_goods;
