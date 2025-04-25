#!/bin/bash

# Print project title
echo "Implementation of Relativistic Decay of Lambda Baryon to Proton and Pion"

# Prompt for the number of simulations
read -p "Enter the number of simulations (N) in integer: " N

# Validate that N is a positive integer
if ! [[ "$N" =~ ^[0-9]+$ ]] || [ "$N" -le 0 ]; then
    echo "Error: Please enter a valid positive integer for N."
    exit 1
fi

# Create or overwrite the text file where executable names will be stored
echo "" > simulation_executables.txt

# Loop through each simulation to gather parameters
for ((i = 1; i <= N; i++))
do
    echo "Simulation $i:"

    # Collect the parameters for each simulation
    read -p "  Enter Lambda mass in double: " lamda_mass
    read -p "  Enter eta min in double: " eta_min
    read -p "  Enter eta max in double: " eta_max
    read -p "  Enter pt min in double: " pt_min
    read -p "  Enter pt max in double: " pt_max

    # Validate input for double (floating-point numbers)
    if ! [[ "$lamda_mass" =~ ^-?[0-9]+([.][0-9]+)?$ ]] || ! [[ "$eta_min" =~ ^-?[0-9]+([.][0-9]+)?$ ]] || ! [[ "$eta_max" =~ ^-?[0-9]+([.][0-9]+)?$ ]] || ! [[ "$pt_min" =~ ^-?[0-9]+([.][0-9]+)?$ ]] || ! [[ "$pt_max" =~ ^-?[0-9]+([.][0-9]+)?$ ]]; then
        echo "Error: Please enter valid double values for the parameters."
        exit 1
    fi

    # Create the executable name string
    exec_name="Lambda_${lamda_mass}_N-O-E_${i}_etamin_${eta_min}_etamax_${eta_max}_ptmin_${pt_min}_ptmax_${pt_max}"

    # Write the executable name to the text file
    echo "$exec_name" >> simulation_executables.txt
done

echo "Executable names have been written to simulation_executables.txt"

