
# Game of Life

## Description
Le Jeu de la Vie (Game of Life) est un automate cellulaire inventé par John Horton Conway en 1970.
Ce projet implémente le Jeu de la Vie en C++ avec une fenêtre de visualisation utilisant la bibliothèque SDL2.

## Prérequis
Avant de pouvoir compiler et exécuter ce projet, assurez-vous que les éléments suivants sont installés sur votre système :
- CMake (version 3.10 ou supérieure)
- SDL2

### Installation de SDL2

#### Sous Linux (Debian/Ubuntu)
```bash
sudo apt-get install libsdl2-dev
```

#### Sous macOS avec Homebrew
```bash
brew install sdl2
```

#### Sous Windows
Téléchargez SDL2 depuis le [site officiel de SDL](https://www.libsdl.org/download-2.0.php) et suivez les instructions pour installer les bibliothèques et les headers.

## Configuration du projet CLion

1. Clonez ce dépôt ou copiez les fichiers dans votre environnement de développement :
```bash
git clone <URL_DU_DEPOT>
cd <NOM_DU_PROJET>
```

2. Ouvrez le projet dans CLion.

3. Assurez-vous que votre fichier `CMakeLists.txt` est correctement configuré. Voici un exemple de `CMakeLists.txt` :

```cmake
cmake_minimum_required(VERSION 3.28)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

# Add SDL2 library
set(SDL2_DIR "path/to/your/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

add_executable(GameOfLife main.cpp)
target_link_libraries(GameOfLife ${SDL2_LIBRARIES})
```

Remplacez `"path/to/your/SDL2"` par le chemin où SDL2 est installé sur votre système. Sur Linux et macOS, ce chemin est généralement `/usr/local`.

4. Rechargez le projet dans CLion :
   - Allez dans `File` > `Reload CMake Project`.

5. Assurez-vous que la configuration du projet est correctement détectée par CLion.

## Compilation et exécution

1. Utilisez les options de construction et d'exécution dans CLion pour compiler le projet :
   - Cliquez sur l'icône de construction (`Build`) dans la barre d'outils.
   - Ensuite, cliquez sur l'icône d'exécution (`Run`).

2. Le programme devrait s'exécuter et ouvrir une fenêtre où vous pouvez observer le Jeu de la Vie en action.

