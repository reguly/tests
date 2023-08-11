#!/bin/bash
mkdir -p apps/Rotor37_8M
cd apps/Rotor37_8M
wget https://users.itk.ppke.hu/~regiszo/rotor8m.tgz
tar xfv rotor8m.tgz
rm rotor8m.tgz
cd ../../
cd apps/volna/sp
wget https://users.itk.ppke.hu/~regiszo/volna_30m2.h5
mv volna_30m2.h5 Problem.h5
