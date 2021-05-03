#!/bin/bash

activities=( swimming "water skiing" canoeing "white-water rafting" surfing )

for act in "${activities[@]}"; do 
  echo "Activity: $act"; 
done
