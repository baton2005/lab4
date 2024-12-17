#include <UnitTest++/UnitTest++.h>
#include "modAlphaChiper.h" // Подключаем заголовочный файл вашего шифра

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"");
    CHECK(encrypted == L""); // Ожидаем пустую строку
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    modAlphaCipher cipher(L"БКД");
    std::wstring decrypted = cipher.decrypt(L"");
    CHECK(decrypted == L""); // Ожидаем пустую строку
}

// Тест на шифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"бгеж"), std::invalid_argument); // Ожидаем исключение
}

// Тест на дешифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInKey) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.decrypt(L"бгеж"), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование минимального ключа
TEST(TestMinimalKey) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ"); // валидный текст
    CHECK(encrypted != L""); // Ожидаем, что результат не пустой
}

// Тест на шифрование длинного ключа
TEST(TestLongKey) {
    modAlphaCipher cipher(L"БКДБКДБКДБКДБКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ"); // валидный текст
    CHECK(encrypted != L""); // Ожидаем, что результат не пустой
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ");
    CHECK(encrypted == L"ВНИЗ"); // ожидаемый результат
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness) {
    modAlphaCipher cipher(L"БКД");
    std::wstring decrypted = cipher.decrypt(L"ВНИЗ");
    CHECK(decrypted == L"БГЕЖ"); // ожидаемый результат
}

// Тест на шифрование с ключом, содержащим пробел
TEST(TestKeyWithSpaces) {
    modAlphaCipher cipher(L"Б КД");
    std::wstring encrypted = cipher.encrypt(L"ТЕСТ");
    CHECK(encrypted != L""); // Ожидаем, что результат не пустой
}

// Тест на дешифрование с ключом, содержащим пробел
TEST(TestKeyWithSpacesDecryption) {
    modAlphaCipher cipher(L"Б КД");
    std::wstring encrypted = cipher.encrypt(L"ТЕСТ");
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK(decrypted == L"ТЕСТ"); // Ожидаемый результат
}

// Тест на шифрование текста, содержащего цифры
TEST(TestNumbersInText) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.encrypt(L"1234"), std::invalid_argument); // Ожидаем исключение
}

// Тест на дешифрование текста, содержащего цифры
TEST(TestNumbersInTextDecryption) {
    modAlphaCipher cipher(L"БКД");
    CHECK_THROW(cipher.decrypt(L"1234"), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование текста с пробелами
TEST(TestSpacesInText) {
    modAlphaCipher cipher(L"БКД");
    std::wstring encrypted = cipher.encrypt(L"ТЕ СТ");
    CHECK(encrypted != L""); // Ожидаем, что результат не пустой
}




// Тест на шифрование с ключом, содержащим только один символ
TEST(TestSingleCharacterKey) {
    modAlphaCipher cipher(L"Б");
    std::wstring encrypted = cipher.encrypt(L"ТЕСТ");
    CHECK(encrypted != L""); // Ожидаем, что результат не пустой
}

// Тест на шифрование текста с ключом, который содержит одинаковые символы
TEST(TestIdenticalCharactersInKey) {
    modAlphaCipher cipher(L"БББ");
    std::wstring encrypted = cipher.encrypt(L"ТЕСТ");
    CHECK(encrypted != L""); // Ожидаем, что результат не пустой
}



// Основная функция для запуска тестов
int main() {
    return UnitTest::RunAllTests();
}

