cat header/*.pnml templates/*.pnml trailers/*.pnml horse_drawn/*.pnml vehicles/buses/*.pnml vehicles/small/*.pnml vehicles/goods/*.pnml vehicles/cargo_trams/*.pnml vehicles/trams/*.pnml > timberwolf_uk.prenml
cpp timberwolf_uk.prenml > timberwolf_uk.nml
..\nml\nmlc timberwolf_uk.nml
