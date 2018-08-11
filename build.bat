cat header/*.pnml templates/*.pnml trailers/*.pnml horse_drawn/*.pnml vehicles/buses/*.pnml vehicles/small/*.pnml vehicles/goods/*.pnml vehicles/cargo_trams/*.pnml vehicles/trams/*.pnml > timberwolf_uk.prenml
"c:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\cl" /E timberwolf_uk.prenml > timberwolf_uk.nml
..\nml\nmlc timberwolf_uk.nml