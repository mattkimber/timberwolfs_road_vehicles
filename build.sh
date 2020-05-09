#!/bin/bash
mkdir -p intermediate

./cargopositor.exe -o intermediate/output_fp -v voxels/composite -t compositor/first_pass/*
./cargopositor.exe -o intermediate/voxels/ -v voxels/composite -t compositor/second_pass/*

cp voxels/static/* intermediate/voxels

for i in `ls intermediate/voxels`; do 
	echo $i
	./renderobject.exe -i intermediate/voxels/$i -o $i -s 4,2,1 -u
done

./roadie.exe set.json && ../nml/nmlc.exe timberwolf_uk.nml