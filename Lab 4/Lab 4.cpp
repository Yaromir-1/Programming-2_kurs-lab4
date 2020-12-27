﻿#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Dealer.h"
#include "Player.h"
#include "IFormattable.h"
#include "Adapted.h"
#include <Windows.h>
#include <ctime>
int main()
{
    /*1. Написать простой консольный вариант карточной игры BlackJack для игры один - наодин с дилером, в соответствии с вариантом.В приложении А приведены вариации и
        особенности правил игры для каждого варианта.В ходе работы необходимо сделать
        как минимум следующее :
         создать и связать отношением агрегации / композиции и / или наследования классы
        КАРТА, КОЛОДА, ДИЛЕР, ИГРОК, ИГРА.В целом, Вы можете предлагать здесь
        свои варианты объектно - ориентированного проектирования;
         в начале игры генерировать случайным образом 4 колоды с 36 или 52 картами, в
        зависимости от варианта;
         имитировать действия дилера, в соответствии с вариантом игры;
         запрограммировать обработку всех потенциально возможных вариантов исхода :
        блек - джек, перебор, ровно, выигрыш по очкам, проигрыш по очкам;
         бросать и отлавливать исключение при «переборе»(«перебор» рассматривать как
        исключительную ситуацию);
         перегрузить операцию потокового вывода объекта класса карты на экран с
        помощью дружественной функции.Выводить карту в виде 2♠, Q♦ и т.д. (символы
        карточных мастей имеют ASCII - коды 3, 4, 5, 6 и UNICODE - коды "\u2665",
        "\u2666", "\u2663", "\u2660", соответственно).
        2. Реализуйте паттерн GOF «Адаптер» в обоих видах(адаптер класса и адаптер объекта)
        на следующем примере.Напишите интерфейс IFormattable с методом std::string
        format() для форматирования объекта, реализующего данный интерфейс, а также
        функцию void prettyPrint(const IFormattable & object), которая выводит на
        экран объект - параметр в отформатированном виде.Сделайте так, чтобы в эту
        функцию можно было передавать ссылку на Вашу колоду карт, разработанную в
        задании 1. Алгоритм форматирования придумайте произвольный сами.*/

    setlocale(LC_ALL, "Russian");
    Game* game = new Game();
    game->play();
    while (game->nextGame()) {
        game->play();
    }
    Deck* deck = new Deck();
    IFormattable* ifo = new Adapted(deck);
    ifo->prettyPrint(*ifo);
}
    