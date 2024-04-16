#!/bin/bash 
ssh-keygen -t rsa -b 4096 -C "$1"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
cat id_rsa.pub