#define PURCHASE_SPRITESET(VEHICLENAME)                         \
spriteset (spriteset_purchase_##VEHICLENAME, PNGNAME(VEHICLENAME,_purchase) ) {   \
  template_purchase()                                           \
}

#define TRACTOR(VEHICLENAME, LENGTH)        \
  SPRITESET(VEHICLENAME,,LENGTH)            \
  PURCHASE_SPRITESET(VEHICLENAME)           \
  ALTERNATIVESPRITE(VEHICLENAME, , LENGTH)  \
  SPRITEGROUP(VEHICLENAME,,)                \

#define ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, SWITCHTYPE, VALUE1, VALUE2)                           \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_##SWITCHTYPE, position_in_consist ) {          \
      0: return VALUE1;                                                                              \
      return VALUE2;                                                                                 \
  }

#define ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, CARGONAME, CARGOTYPE)                             \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics##CARGONAME, position_in_consist ) { \
      0: spritegroup_##VEHICLENAME;                                                                    \
      sprite##CARGOTYPE##_##TRAILERNAME##CARGONAME;                                                  \
  }

  #define ARTIC_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY)                          \
    ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, capacity, 1, param_realistic_modern_vehicle_capacity ? REALISTIC_CAPACITY - 1 : CAPACITY - 1)                         \
    ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, length, LENGTH / 8, 8)                             \
    switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_articulation, extra_callback_info1) { \
        0..1: return vehicle_##VEHICLENAME;                                                   \
        return CB_RESULT_NO_MORE_ARTICULATED_PARTS;                                           \
    }

  #define ARTIC_GFX(VEHICLENAME, TRAILERNAME, LENGTH)                               \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _goods, set)                                   \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _coal, group)                                  \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _copper, group)                                \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _iore, group)                                  \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _tanker, set)                                  \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grain, group)                                 \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _grey, group)                                  \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _lvst, set)                                    \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _stel, group)                                    \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _timber, group)                                \
    ARTIC_GFX_SWITCH(VEHICLENAME, TRAILERNAME, _wood, group)

#define ARTIC(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY) \
      TRACTOR(VEHICLENAME, LENGTH)                                \
      ARTIC_GFX(VEHICLENAME, TRAILERNAME, LENGTH)       \
      ARTIC_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY)  \

#define ARTIC_GRAPHICS_BLOCK(VEHICLENAME)                 \
  articulated_part: switch_##VEHICLENAME##_articulation;  \
  cargo_capacity: switch_##VEHICLENAME##_capacity;        \
  purchase_cargo_capacity: spriteset_##VEHICLENAME;       \
  length: switch_##VEHICLENAME##_length;                  \
  purchase: spriteset_purchase_##VEHICLENAME;             \
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
  SGBT: switch_##VEHICLENAME##_graphics_iore;             \
  default: switch_##VEHICLENAME##_graphics_goods;
