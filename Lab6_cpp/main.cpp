#include <iostream>
#include "text.h"

using namespace std;

void displayText(const TextContainer& text) {
    cout << "Current text content:" << endl;
    for (size_t i = 0; i < text.size(); ++i) {
        cout << "[" << i << "]: " << text.getRow(i).getData() << endl;
    }
    cout << endl;
}

int main() {
    TextContainer text;
    
    text.addRow(Row("   Hello   world!   "));
    text.addRow(Row("This    is    a    test"));
    text.addRow(Row("   Multiple      spaces     everywhere   "));
    text.addRow(Row("NoSpacesHere"));
    text.addRow(Row("    "));
    
    cout << "Original text:" << endl;
    displayText(text);
    
    cout << "Length of shortest row: " << text.getShortestRowLength() << endl;
    cout << "Consonant percentage: " << text.getConsonantPercentage() << "%" << endl << endl;
    
    cout << "Processing spaces..." << endl;
    text.processSpaces();
    displayText(text);
    
    cout << "Removing row 1..." << endl;
    text.removeRow(1);
    displayText(text);
    
    cout << "Clearing text..." << endl;
    text.clearText();
    displayText(text);
    
    cout << "Adding new rows..." << endl;
    text.addRow(Row("New content"));
    text.addRow(Row("With less spaces"));
    displayText(text);
    
    cout << "New consonant percentage: " << text.getConsonantPercentage() << "%" << endl;
    
    return 0;
}