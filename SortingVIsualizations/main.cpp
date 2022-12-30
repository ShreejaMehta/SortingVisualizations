
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include <SFML/Graphics.hpp>
#include<unistd.h>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

sf::RenderWindow window(sf::VideoMode(960, 600), "Insertion Sort");
int n=80;
float recHs[80];
unsigned int microsecond = 1000000;
bool sorted=false;

void dispSort(int index){
    window.clear();
    for(int i=0; i<n; i++){
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i*12, 600-recHs[i]);
        block.setFillColor(sorted || i==index? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }
    
    window.display();
}

void insertionSort()
{
    usleep(microsecond*5);
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = recHs[i];
        j = i - 1;

        while (j >= 0 && recHs[j] > key)
        {
            recHs[j + 1] = recHs[j];
            j = j - 1;
            dispSort(j);
        }
        recHs[j + 1] = key;
    }

    sorted = true;

    dispSort(i);

}

int main(int, char const**)
{
    for(int i=0; i<n; i++){
            recHs[i]=(rand()%500);
        }

    // Start the game loop
    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        if(!sorted){
                    dispSort(0);
                    insertionSort();
                }

//        window.clear();
//        window.display();
    }

    return ;
}


