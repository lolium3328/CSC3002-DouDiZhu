#include "cards.h"
#include <ctime>

Cards::Cards() : remain(54) {
    // 初始化54张牌: 0-51表示普通牌, 52小王, 53大王
    for (int i = 0; i < 54; ++i) {
        cards[i] = i;
    }
}

void Cards::RandCards() {
    // 洗牌 - 使用Fisher-Yates算法
    static std::random_device rd;
    static std::mt19937 gen(rd());

    for (int i = 53; i > 0; --i) {
        std::uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        std::swap(cards[i], cards[j]);
    }

    remain = 54;
}

int Cards::GetCard() {
    if (remain > 0) {
        --remain;
        return cards[remain];
    }
    return -1;  // 没有牌了
}
