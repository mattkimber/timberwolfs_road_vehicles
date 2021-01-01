#!/bin/bash
mkdir -p intermediate

echo "Compositing (1st round)"
../cargopositor/cargopositor.exe -o intermediate/output_fp -v voxels/composite -t compositor/first_pass/*

echo "Compositing (2nd round)"
../cargopositor/cargopositor.exe -o intermediate/voxels/ -v voxels/composite -t compositor/second_pass/*

echo "Copying static objects"
cp -u voxels/static/* intermediate/voxels

echo "Rendering outputs"
echo ""
ls intermediate/voxels/*.vox | xargs ../gorender/renderobject.exe -8 -r -s 2,1 -u -p
ls voxels/horse/*.vox | xargs ../gorender/renderobject.exe -m files/manifest_horses.json -8 -r -s 2,1 -u -p

echo ""
echo "Rendering purchase sprites"
../purchaser/purchaser.exe table.csv

echo "Producing NML"
../roadie/roadie.exe set.json

echo "Compiling GRF"
../nml/nmlc.exe -c timberwolf_uk.nml

echo "Building TAR"
mkdir -p timberwolf_uk
mv *.grf timberwolf_uk
cp grf_readme/* timberwolf_uk
tar -c timberwolf_uk > timberwolf_uk.tar
