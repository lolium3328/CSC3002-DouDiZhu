#include "cardgroup.h"
#include <algorithm>

CardGroup::CardGroup() : type(Unknown), value(0), count(0) {}

CardGroup::CardGroup(Type t, int v) : type(t), value(v), count(0) {}

CardGroup& CardGroup::operator=(const CardGroup& cg) {
    if (this != &cg) {
        group = cg.group;
        cards = cg.cards;
        type = cg.type;
        value = cg.value;
        count = cg.count;
    }
    return *this;
}

void CardGroup::AddNumber(int num) {
    if (num < 0 || num > 53) return;

    cards.insert(num);
    int val = Translate(num);
    group[val]++;
    count++;
}

void CardGroup::DeleteNumber(int num) {
    if (cards.find(num) == cards.end()) return;

    cards.erase(num);
    int val = Translate(num);
    group[val]--;
    if (group[val] == 0) {
        group.erase(val);
    }
    count--;
}

void CardGroup::Clear() {
    group.clear();
    cards.clear();
    type = Unknown;
    value = 0;
    count = 0;
}

// 将牌号(0-53)转换为权值(3-17)
// 0-12: 方块3-2, 13-25: 梅花3-2, 26-38: 红桃3-2, 39-51: 黑桃3-2
// 52: 小王, 53: 大王
int CardGroup::Translate(int num) {
    if (num < 0) return 0;
    if (num == 52) return 16;  // 小王
    if (num == 53) return 17;  // 大王

    int val = num % 13;
    // 0-12 对应 3-K,A,2
    if (val >= 0 && val <= 8) {
        return val + 3;  // 3-J (3-11)
    } else if (val == 9) {
        return 12;  // Q
    } else if (val == 10) {
        return 13;  // K
    } else if (val == 11) {
        return 14;  // A
    } else {  // val == 12
        return 15;  // 2
    }
}

