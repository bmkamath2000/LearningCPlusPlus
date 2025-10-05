#include <SFML/Graphics.hpp>
#include <string>
#include <optional>
#include <sstream>
#include<iostream>
// using namespace std;
// A simple TextBox class to handle all text input functionality
class TextBox {
public:
    TextBox(const sf::Font& font, int size, sf::Color color):
        textbox(), background(), cursor() {
        // Set up the text box
        textbox.setFont(font);
        textbox.setString("Hello");
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        textbox.setPosition(sf::Vector2f(100.f, 100.f));

        // Set up the background rectangle
        background.setSize({200.f, 30.f});
        background.setPosition(sf::Vector2f(100.f, 100.f));
        background.setFillColor(sf::Color(50, 50, 50));
        
        // Set up the blinking cursor
        cursor.setSize({2.f, static_cast<float>(size)});
        cursor.setFillColor(sf::Color::White);
        cursor.setPosition(sf::Vector2f(textbox.getPosition().x, textbox.getPosition().y));
    }
    
    // Process typed characters
    void typedOn(char32_t unicode) {
        if (isSelected) {
            if (unicode < 128) {
                if (unicode == 8) { // Handle backspace
                    if (!text.str().empty()) {
                        deleteLastChar();
                    }
                } else if (unicode == 13) { // Handle enter (optional)
                    // Do something when enter is pressed
                } else if (text.str().length() < 20) { // Limit input length
                    inputLogic(unicode);
                }
            }
        }
    }

    // Set focus on the text box
    void setSelected(bool sel) {
        isSelected = sel;
    }

    // Draw the textbox and cursor to the window
    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(textbox);
        if (isSelected) {
            updateCursor();
            if (showCursor) {
                window.draw(cursor);
            }
        }
    }

private:
    sf::Text textbox;
    sf::RectangleShape background;
    sf::RectangleShape cursor;
    std::ostringstream text;
    bool isSelected = false;
    sf::Clock cursorClock;
    bool showCursor = true;

    void inputLogic(char32_t unicode) {
        text << static_cast<char>(unicode);
        textbox.setString(text.str());
        // Move the cursor to the end of the text
        cursor.setPosition(textbox.findCharacterPos(text.str().length()));
        cursorClock.restart();
    }
    
    void deleteLastChar() {
        std::string currentText = text.str();
        currentText.pop_back();
        text.str(""); // Clear and reset
        text << currentText;
        textbox.setString(text.str());
        // Move the cursor back
        cursor.setPosition(textbox.findCharacterPos(text.str().length()));
        cursorClock.restart();
    }
    
    void updateCursor() {
        if (cursorClock.getElapsedTime().asMilliseconds() > 500) {
            showCursor = !showCursor;
            cursorClock.restart();
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0 Text Box");
    sf::Font font;//("ARIAL.TTF");
    std::cout << "Current path is " ;
    std::cout<< std::filesystem::current_path() << std::endl;
    const std::filesystem::path& filename = "ARIAL.TTF";
    if (!font.openFromFile(filename)) {
    std::cerr << "Failed to load font\n";
    return 1;
    }

    TextBox input(font, 20, sf::Color::White);
    input.setSelected(true); // Automatically select on launch

    while (window.isOpen()) {
        std::optional event = window.pollEvent();
        if (event) {
        // An event was retrieved, now process it
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto textEntered = event->getIf<sf::Event::TextEntered>()) {
                input.typedOn(textEntered->unicode);
            }
            //event = window.pollEvent();
        }

        window.clear(sf::Color::Black);
        input.draw(window);
        window.display();
    }

    return 0;
}
