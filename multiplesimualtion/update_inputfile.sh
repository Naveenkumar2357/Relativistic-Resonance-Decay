#!/bin/bash
# Usage: ./update_inputfile.sh <simulation_name>

echo "Running update_inputfile.sh"
echo "simulation_name=$1"

simulation_name=$1

# Extract parameters using regular expressions
lambda_mass=$(echo $simulation_name | sed -n 's/.*Lambda_\([0-9.]*\)_.*$/\1/p')
eta_min=$(echo $simulation_name | sed -n 's/.*etamin_\([0-9.]*\)_etamax_.*$/\1/p')
eta_max=$(echo $simulation_name | sed -n 's/.*etamax_\([0-9.]*\)_ptmin_.*$/\1/p')
pt_min=$(echo $simulation_name | sed -n 's/.*ptmin_\([0-9.]*\)_ptmax_.*$/\1/p')
pt_max=$(echo $simulation_name | sed -n 's/.*ptmax_\([0-9.]*\)$/\1/p')

# Debugging output to check if the parameters are correctly extracted
echo "lambda_mass: $lambda_mass"
echo "eta_min: $eta_min"
echo "eta_max: $eta_max"
echo "pt_min: $pt_min"
echo "pt_max: $pt_max"

# Pass these values to another script or use them directly to update inputfile.cpp
./update_inputfile.sh $lambda_mass $eta_min $eta_max $pt_min $pt_max

echo "Finished updating inputfile.cpp"

