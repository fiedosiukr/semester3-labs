#include "../include/game.h"

#include "../include/constants.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <iostream>


int main() {
    
    if (!al_init()) {
      std::cout << "Failed to initialize allegro!\n";
    }

    if (!al_init_primitives_addon()) {
      std::cout << "Failed to initialize primitives addon!\n";
    }
    
    if (!al_install_mouse()) {
      std::cout << "Failed to install mouse!\n";
    }

    if (!al_init_font_addon()) {
      std::cout << "Failed to initialize font addon!\n";
    }

    if (!al_init_ttf_addon()) {
      std::cout << "Failed to intialize ttf addon!\n";
    }

    Game game;
    game.start();
    return 0;
}