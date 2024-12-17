#include <UnitTest++/UnitTest++.h>
#include "modAlphakey.h"

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText) {
    modAlphakey cipher(123); 
    CHECK_THROW(cipher.encrypt(""), std::invalid_argument);
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    modAlphakey cipher(123); 
    CHECK_THROW(cipher.decrypt(""), std::invalid_argument); 
}

// Тест на шифрование текста с невалидным символом (например, буквы не в алфавите)
TEST(TestForeignCharacterInText) {
    modAlphakey cipher(123); // Пример ключа
    CHECK_THROW(cipher.encrypt("Hello"), std::invalid_argument); 
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness) {
    modAlphakey cipher(3); 
    std::string encrypted = cipher.encrypt("HELLO"); 
    CHECK(encrypted == "HLEOL"); 
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness) {
    modAlphakey cipher(3); 
    std::string decrypted = cipher.decrypt("HLEOL"); 
    CHECK(decrypted == "HELLO"); 
}

// Тест на шифрование текста с невалидным ключом
TEST(TestInvalidKey) {
    CHECK_THROW(modAlphakey cipher(-1), std::invalid_argument); 
}



// Новый тест: шифрование с пустым ключом
TEST(TestEmptyKey) {
    CHECK_THROW(modAlphakey cipher(0), std::invalid_argument); 
}

// Новый тест: шифрование строки с одной буквой (проверка на минимальную длину текста)
TEST(TestSingleCharacterText) {
    modAlphakey cipher(1); // Key is 1, which is valid for a single character
    std::string encrypted = cipher.encrypt("A");
    CHECK(encrypted == "A"); // Expected result: one character should remain unchanged
}

// Новый тест: дешифрование строки с одной буквой
TEST(TestSingleCharacterTextDecryption) {
    modAlphakey cipher(1); // Key is 1, which is valid for a single character
    std::string decrypted = cipher.decrypt("A");
    CHECK(decrypted == "A"); // Expected result: one character should remain unchanged
}

// Новый тест: шифрование строки длиной больше 1 символа с правильным ключом
TEST(TestMultipleCharacterText) {
    modAlphakey cipher(3); // Valid key for longer text
    std::string encrypted = cipher.encrypt("HELLO");
    CHECK(encrypted == "HLEOL"); // Expected result based on the encryption logic
}

// Новый тест: дешифрование строки длиной больше 1 символа с правильным ключом
TEST(TestMultipleCharacterTextDecryption) {
    modAlphakey cipher(3); // Valid key for longer text
    std::string decrypted = cipher.decrypt("HLEOL");
    CHECK(decrypted == "HELLO"); // Expected result based on the decryption logic
}

// Новый тест: шифрование очень длинной строки
TEST(TestLongStringEncryption) {
    modAlphakey cipher(5);
    std::string long_text = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    std::string encrypted = cipher.encrypt(long_text);
    CHECK(encrypted != long_text); // Encryption should change the text
}





int main() {
    return UnitTest::RunAllTests();
}

