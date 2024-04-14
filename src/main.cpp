#include "Chinese/write.h"
#include "English/speak.h"

#include <wx/string.h>

#include <iostream>

namespace demo {
void Dance() { std::cout << "Dancing.... [Src]" << std::endl; }
} // namespace demo

int main() {
    demo::Dance();

    chinese::Write();

    english::Speak();

    wxString str = "Hello, World!";

    std::cout << "String: " << str << std::endl;

    size_t length = str.length();
    std::cout << "Length: " << length << std::endl;

    bool isEmpty = str.empty();
    std::cout << "Is Empty: " << (isEmpty ? "true" : "false") << std::endl;

    wxString greeting = "Welcome";
    wxString message = greeting + ", " + str;
    std::cout << "Message: " << message << std::endl;

    wxString searchStr = "World";
    size_t pos = str.find(searchStr);
    if (pos != wxString::npos) {
        std::cout << "Found at position: " << pos << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    wxString replacedStr = str;
    replacedStr.Replace("World", "Universe");
    std::cout << "Replaced String: " << replacedStr << std::endl;

    return 0;
}