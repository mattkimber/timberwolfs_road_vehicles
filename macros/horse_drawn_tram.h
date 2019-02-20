#define HORSE_DRAWN_TRAM_BASE_GFX(VEHICLENAME) \
  PURCHASE_SPRITESET(VEHICLENAME) \
  HORSE_DRAWN_TRAM_ANIM_SWITCH(VEHICLENAME)


#define HORSE_DRAWN_TRAM_ANIM_SWITCH(VEHICLENAME) \
  switch(FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_animation, motion_counter % 4) { \
    0..1: return spriteset_tram_horses_1;   \
    return spriteset_tram_horses_2;       \
  }

#define HORSE_DRAWN_CARGO_TRAM_ANIM_SWITCH(VEHICLENAME) \
  switch(FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_animation, motion_counter % 4) { \
    0..1: return spriteset_cargo_tram_horses_1;   \
    return spriteset_cargo_tram_horses_2;       \
  }  

#define HORSE_DRAWN_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, CARGONAME, CARGOTYPE)                             \
  switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_graphics##CARGONAME, position_in_consist ) { \
      0: switch_##VEHICLENAME##_animation;                                                                    \
      sprite##CARGOTYPE##_##TRAILERNAME##CARGONAME;                                                  \
  }

  #define HORSE_DRAWN_TRAM_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, REALISTIC_CAPACITY) \
    ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, capacity, 1, param_realistic_early_vehicle_capacity ? REALISTIC_CAPACITY - 1 : CAPACITY - 1)                         \
    ARTIC_SWITCH(VEHICLENAME, TRAILERNAME, length, 4, LENGTH / 8)                             \
    switch (FEAT_ROADVEHS, SELF, switch_##VEHICLENAME##_articulation, extra_callback_info1) { \
        0..1: return vehicle_##VEHICLENAME##;                                                   \
        return CB_RESULT_NO_MORE_ARTICULATED_PARTS;                                           \
    }

#define HORSE_DRAWN_TRAM(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY)         \
      HORSE_DRAWN_TRAM_BASE_GFX(VEHICLENAME)                               \
      HORSE_DRAWN_TRAM_GFX_SWITCH(VEHICLENAME, TRAILERNAME, , group)  \
      HORSE_DRAWN_TRAM_SWITCHES(VEHICLENAME, TRAILERNAME, LENGTH, CAPACITY, CAPACITY)

#define HORSE_DRAWN_TRAM_GRAPHICS_BLOCK(VEHICLENAME) \
  articulated_part: switch_##VEHICLENAME##_articulation;  \
  cargo_capacity: switch_##VEHICLENAME##_capacity;        \
  purchase_cargo_capacity: spriteset_purchase_##VEHICLENAME; \
  length: switch_##VEHICLENAME##_length;                  \
  purchase: spriteset_purchase_##VEHICLENAME;             \
  default: switch_##VEHICLENAME##_graphics;
