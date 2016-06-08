cat header/*.pnml templates/*.pnml trailers/*.pnml vehicles/*.pnml > timberwolf_uk.prenml
cpp timberwolf_uk.prenml > timberwolf_uk.nml
..\nml\nmlc timberwolf_uk.nml
