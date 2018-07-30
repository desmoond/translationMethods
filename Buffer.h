#ifndef BUFFER_H
#define BUFFER_H


#include <fstream>
#include <memory>
#include <string>


#define LIMITER '\0'
#define NO_BUFFER -1
#define FIRST_BUFFER 1
#define SECOND_BUFFER 2


class Buffer
{
public:
  Buffer(const std::string fileName, size_t buffersSize = 4096);
  Buffer(const Buffer &) = delete;
  Buffer(Buffer && obj);
  ~Buffer();

  
  char get() noexcept; // Получить символ и перейти на следующий
  char peek() const noexcept; // Посмотреть символ
  char peek(int offset); // Посмотреть на n-символов вперед/назад
  void markLexemeStart() noexcept; // Установить текущий просматриваемый символ в буфере началом лексемы
  std::string getLexeme() const;  // Получить подстроку из буфера, которая начинается с lexemeBegin и заканчивается currentSymbol


  void open(const std::string fileName); // Открыть другой файл для чтения.

  size_t available() noexcept; // Сколько ещё символов доступно для чтения
  size_t size() const noexcept; // Получить размеры буферов
  void resize(size_t newSize); // Изменить размеры буферов


  Buffer & operator=(Buffer && r_op) noexcept; 
  Buffer & operator=(const Buffer &) = delete;


  static const char limiter; // Ограничитель

private:
  struct {
    int index;
    int bufferNo;
  } m_lexemeBegin, m_currentSymbol;

  size_t m_buffersSize;

  std::unique_ptr<char> m_firstBuffer;
  std::unique_ptr<char> m_secondBuffer;

  std::unique_ptr<std::ifstream> m_file;
};



#endif