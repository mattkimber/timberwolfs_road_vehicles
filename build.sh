#!/bin/bash
mkdir -p intermediate

echo "Compositing (1st round)"
../cargopositor/cargopositor.exe -o intermediate/output_fp -v voxels/composite -t compositor/first_pass/*

echo "Compositing (2nd round)"
../cargopositor/cargopositor.exe -o intermediate/voxels/ -v voxels/composite -t compositor/second_pass/*

echo "Copying static objects"
cp voxels/static/* intermediate/voxels

echo "Rendering outputs"
echo ""
ls intermediate/voxels/*.vox | xargs ../gorender/renderobject.exe -r -s 4,2,1 -u -p

echo "Producing SD set"
../roadie/roadie.exe set.json && ../nml/nmlc.exe -c timberwolf_uk.nml

echo "Producing HD set"
../roadie/roadie.exe set_hd.json && ../nml/nmlc.exe -c timberwolf_uk_hd.nml