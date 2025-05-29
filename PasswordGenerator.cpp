#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
int randomInRange(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(std::min(a, b), std::max(a, b));
    return dist(gen);
}

int main() {
    std::string letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    std::string numbers = "1234567890";
    std::string specialCharacters = "~!@#$%^&*()_+-=[]{}|;:<>?/";

    std::cout << "Password length: ";
    int length;
    std::cin >> length;

    std::string passWord;

    int lettersCount = randomInRange(1, length - 2);
    int numberCount = randomInRange(1, length - lettersCount - 1);
    int specialCharactersCount = length - lettersCount - numberCount;

    for (int i = 0; i < lettersCount; i++) {
        passWord += letters[randomInRange(0, letters.size() - 1)];
    }
    for (int i = 0; i < numberCount; i++) {
        passWord += numbers[randomInRange(0, numbers.size() - 1)];
    }
    for (int i = 0; i < specialCharactersCount; i++) {
        passWord += specialCharacters[randomInRange(0, specialCharacters.size() - 1)];
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(passWord.begin(), passWord.end(), g);

    std::cout << passWord << std::endl;
    system("pause");
    return 0;
}