/**
 * @file Menus.h
 * @brief Declarations of all console menu display functions.
 *
 * Each function clears the screen and prints a formatted menu for
 * the corresponding data-structure module.
 */

#ifndef _MENUS_H
#define _MENUS_H

/** @brief Displays the main application menu. */
void mainMenu();

/** @brief Displays the singly-linked-list operations menu. */
void linkedListMenu();

/** @brief Displays the queue operations menu. */
void queueMenu();

/** @brief Displays the stack operations menu. */
void stackMenu();

/** @brief Displays the hash-table operations menu. */
void hashTableMenu();

/** @brief Displays the binary search tree operations menu. */
void treeMenu();

/** @brief Displays the AVL tree operations menu. */
void avlTreeMenu();

/** @brief Displays the red-black tree operations menu. */
void redBlackTreeMenu();

/** @brief Displays the graph operations menu. */
void graphMenu();

#endif
