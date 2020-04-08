cat header/*.pnml templates/*.pnml trailers/*.pnml horse_drawn/*.pnml vehicles/buses/*.pnml vehicles/small/*.pnml vehicles/goods/*.pnml vehicles/cargo_trams/*.pnml vehicles/trams/*.pnml > timberwolf_uk.prenml
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\bin\Hostx64\x64\cl" /E timberwolf_uk.prenml > timberwolf_uk.nml
..\nml\nmlc timberwolf_uk.nml