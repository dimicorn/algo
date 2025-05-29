#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> file;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty())
        file.push_back(line);

    std::string command;
    std::list<std::string> buffer;
    auto cursor = file.begin();
    auto shift = file.begin();
    bool shiftPressed = false;
    int shiftOffset = 0;
    while (std::cin >> command) {
        if (command == "Up") {
            if (cursor == file.begin())
                continue;
            --cursor;
            if (!shiftPressed)
                shift = cursor;
            else
                --shiftOffset;
        } else if (command == "Down") {
            if (cursor == file.end())
                continue;
            ++cursor;
            if (!shiftPressed)
                shift = cursor;
            else
                ++shiftOffset;
        } else if (command == "Ctrl+X") {
            if (shift == cursor && cursor == file.end())
                continue;

            buffer.clear();
            if (shift == cursor) {
                auto toSplice = cursor;
                cursor = std::next(cursor);
                buffer.splice(buffer.begin(), file, toSplice);
            } else if (shiftOffset < 0) {
                buffer.splice(buffer.begin(), file, cursor, shift);
                cursor = shift;
            } else {
                buffer.splice(buffer.begin(), file, shift, cursor);
            }

            shiftPressed = false;
            shift = cursor;
            shiftOffset = 0;
        } else if (command == "Ctrl+V") {
            if (buffer.empty())
                continue;
            if (shiftOffset < 0) 
                cursor = file.erase(cursor, shift);
            else if (shiftOffset > 0)
                cursor = file.erase(shift, cursor);

            file.insert(cursor, buffer.begin(), buffer.end());

            shiftPressed = false;
            shift = cursor;
            shiftOffset = 0;
        } else if (command == "Shift") {
            shiftPressed = true;
        }
    }

    for (const auto& line : file)
        std::cout << line << '\n';

    return 0;
}
