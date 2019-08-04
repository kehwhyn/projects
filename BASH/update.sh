#!/bin/bash

echo "Starting ful system update..."
sudo apt update -qq
sudo apt dist-upgrade -yy
sudo apt-get autoremove -yy
echo "--------------------"
echo "- Update Complete! -"
echo "--------------------"
