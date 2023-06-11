#!/bin/bash

# Vérifiez si un argument (nom de fichier) a été passé
if [ $# -eq 0 ]; then
  echo "Usage: $0 <fichier>"
  exit 1
fi

# Récupérez le nom de fichier sans l'extension
filename="${1%.*}"

cd test
pwd
echo "testing $1"

# Exécutez le programme de test en redirigeant l'entrée, la sortie standard et la sortie d'erreur vers les fichiers correspondants
cat "$1" | ../bin/subnet > "$filename.result" 2> "$filename.erreur"
