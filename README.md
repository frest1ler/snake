# 🐍 Snake Game

Этот проект представляет собой классическую игру "Змейка", реализованную на C++ с использованием библиотеки SFML. Проект разделён на две основные части:

1. **Игровой движок** - отвечает за логику игры, управление змейкой и обработку столкновений
2. **Графическая система** - обеспечивает отрисовку игровых объектов с помощью SFML

## Структура проекта

Проект организован в следующих директориях:

- **include/** - заголовочные файлы:
  - `Direction.h` - перечисление направлений движения
  - `Food.h` - класс для работы с едой
  - `Game.h` - основной класс игры
  - `Snake.h` - класс змейки
- **src/** - исходные файлы реализации:
  - `main.cpp` - точка входа
  - `Game.cpp` - игровая логика
  - `Snake.cpp` - механика змейки
  - `Food.cpp` - генерация еды

## Основные компоненты

### Игровой движок
- Управление змейкой (4 направления)
- Система роста змейки при поедании еды
- Обнаружение столкновений (со стенами и собой)
- Генерация еды в случайных позициях

### Графическая система
- Отрисовка игрового поля (сетка 20x20 пикселей)
- Визуализация змейки и еды
- Окно игры с фиксированным FPS

## Установка и запуск

### Требования
- Компилятор C++17 (g++/clang/MSVC)
- CMake ≥ 3.10
- SFML 2.6+

### Сборка и запуск
mkdir build && cd build
cmake ..
make
./SnakeGame# snake

### Управление
Клавиша	Действие
Стрелка ↑	Движение вверх
Стрелка ↓	Движение вниз
Стрелка ←	Движение влево
Стрелка →	Движение вправо
Закрытие окна	Выход из игры

###Игровой процесс
Змейка автоматически движется в выбранном направлении
Съедая еду (красные квадраты), змейка увеличивается в размере
Игра заканчивается при столкновении со стенами или собой
Чем длиннее змейка, тем сложнее управление

###Особенности реализации
Чистый объектно-ориентированный код
Фиксированный шаг игрового цикла (10 FPS)
Проверка допустимости смены направления
Эффективная система проверки столкновений
