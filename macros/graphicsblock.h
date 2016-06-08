#define CUSTOMGRAPHICSBLOCK(VEHICLENAME, CAPACITY, TANKER_TYPE, LVST_TYPE, GOODS_TYPE) \
  cargo_capacity: return CAPACITY;                \
  COAL: spritegroup_##VEHICLENAME##_coal;         \
  OIL_: sprite##TANKER_TYPE##_##VEHICLENAME##_tanker;         \
  LVST: sprite##LVST_TYPE##_##VEHICLENAME##_lvst;           \
  GRAI: spritegroup_##VEHICLENAME##_grain;        \
  WOOD: spritegroup_##VEHICLENAME##_wood;         \
  STEL: spritegroup_##VEHICLENAME##_stel;         \
  IORE: spritegroup_##VEHICLENAME##_iore;         \
  WHEA: spritegroup_##VEHICLENAME##_grain;        \
  RUBR: sprite##TANKER_TYPE##_##VEHICLENAME##_tanker;         \
  MAIZ: spritegroup_##VEHICLENAME##_grain;        \
  CORE: spritegroup_##VEHICLENAME##_iore;         \
  WATR: sprite##TANKER_TYPE##_##VEHICLENAME##_tanker;         \
  default: sprite##GOODS_TYPE##_##VEHICLENAME##_goods;       \


#define GRAPHICSBLOCK(VEHICLENAME, CAPACITY) CUSTOMGRAPHICSBLOCK(VEHICLENAME, CAPACITY, set, set, set)
