#ifndef CARDS_H
#define CARDS_H

#include <vector>
#include <algorithm>
#include <random>

/**
 * 发牌堆类
 * 负责管理54张牌的洗牌和发牌
 */
class Cards {
public:
    Cards();
    void RandCards();      // 洗牌
    int GetCard();         // 发一张牌
    int GetRemain() const { return remain; }

private:
    int cards[54];         // 牌数组: 0-51表示普通牌, 52小王, 53大王
    int remain;            // 剩余牌数
};

#endif // CARDS_H
