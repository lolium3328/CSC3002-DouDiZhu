#ifndef CARDGROUP_H
#define CARDGROUP_H


#include <map>
#include <set>
#include <vector>

/**
 * 牌型枚举
 */
#pragma once

#include <map>
#include <set>
#include <vector>

/**
 * 牌型枚举
 */
enum Type {
    Unknown,              // 未知
    Single,               // 单张
    Double,               // 对子
    Three,                // 三条
    SingleSeq,            // 单顺(顺子)
    DoubleSeq,            // 双顺(连对)
    ThreeSeq,             // 三顺(飞机不带翅膀)
    ThreePlusOne,         // 三带一(三带一张)
    ThreePlusTwo,         // 三带二(三带一对)
    AirplaneSingles,      // 飞机带单(三顺+同数目单牌)
    AirplanePairs,        // 飞机带双(三顺+同数目对子)
    FourPlusTwoSingle,    // 四带二(四带两张单牌)
    FourPlusTwoPair,      // 四带二(四带两个对子)
    Bomb,                 // 炸弹
    KingBomb              // 王炸
};

/**
 * 牌型结构类
 * 表示一组牌及其类型
 */
class CardGroup {
    friend class Player;
    friend class Game;

public:
    CardGroup();
    CardGroup(Type t, int v);
    CardGroup& operator=(const CardGroup& cg);

    void AddNumber(int num);       // 添加一张牌(0-53)
    void DeleteNumber(int num);    // 删除一张牌
    void Clear();                  // 清空

    // 将牌号(0-53)转换为权值(3-17)
    // 3-K(3-13), A(14), 2(15), 小王(16), 大王(17)
    static int Translate(int num);

    Type GetType() const { return type; }
    int GetValue() const { return value; }
    int GetCount() const { return count; }
    const std::set<int>& GetCards() const { return cards; }
    const std::map<int, int>& GetGroup() const { return group; }

private:
    std::map<int, int> group;  // 权值->数量的映射
    std::set<int> cards;       // 牌号集合(0-53)
    Type type;                 // 牌型
    int value;                 // 主要权值
    int count;                 // 牌的数量
};

#endif
