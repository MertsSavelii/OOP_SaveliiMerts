#ifndef TBINARYTREE_H
#define TBINARYTREE_H


#include <iostream>
#include "octagon.h"
#include "tree_elem.h"


// В каждой вершине двоичного дерева хранится фигура и счетчик, отражающий ее количество.
class TBinaryTree {
public:
TBinaryTree();

// Полное копирование дерева 
TBinaryTree(const TBinaryTree& other);

// Добавление фигуры в дерево согласно правилу:
// При добавлении фигуры в новую вершину, в вершине создается счетчик со значением 1.
// Если фигура совпадает с фигурой из вершины, счетчик в вершине увеличивается на 1.
// Иначе сравнивается с вершиной из левого поддерева, если площадь фигуры < площади в вершине
// или с вершиной правого поддерева, если >=.
void Push(Octagon octagon);

// Удаление фигуры из дерева:
// Счетчик вершины уменьшается на единицу.
// Если счетчик становится равен 0, вершина удаляется с заменой на корректный узел поддерева.
void Pop(Octagon octagon);

// Полная очистка дерева
void Clear();

// Проверка наличия в дереве вершин
bool Empty();

// Подсчет количества фигур с площадью,
// находящейся в промежутке: [min_area, max_area)
double Count(double min_area, double max_area);

// Вывод дерева в формате вложенных списков, где каждый вложенный список является:
// "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - строка вида результат_счетчика*площадь_фигуры
// Пример: 1*1.5: [3*1.0, 2*2.0: [2*1.5, 1*6.4]]
friend std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree);

virtual ~TBinaryTree();

private:
TreeElem *t_root;
void DeleteTree(TreeElem *root);

};

#endif