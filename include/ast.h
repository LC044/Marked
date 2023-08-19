#pragma once

#include <cstdio>
#include <vector>
#include <string>

enum ast_operator_type {
    AST_NULL,
    AST_TITLE,
    AST_CODE_LINE,
    AST_CODE_BLOCK,
    AST_PARAGRAPH,
    AST_STRONG,
};

enum digitnum_kind {
    DIGIT_KIND_INT,  // 整型字面量
    DIGIT_KIND_REAL, // 实数字面量
    DIGIT_KIND_ID,   // 变量名称
    CMP_KIND,
    KEYWORD_ID,     // 关键词
    DEFAULT,
};

// 叶子节点的属性值
typedef struct ast_node_attr {

    enum digitnum_kind kind;

    int lineno;  // 行号信息，只有DIGIT_KIND_ID有效

    std::string content; // 节点的文本内容

} ast_node_attr;

struct ast_node {
    struct ast_node *parent;    // 父节点
    std::vector<struct ast_node *> sons; // 孩子节点
    enum ast_operator_type type; // 节点类型
    struct ast_node_attr attr;   // node的其它属性
    // 线性IR指令块，可包含多条IR指令
    // InterCode blockInsts;
    // 线性IR指令或者运行产生的Value
    // Value *val;
};

/// @brief 创建最多三个孩子的节点
struct ast_node *new_ast_node(
    enum ast_operator_type type,
    struct ast_node *first_son = nullptr,
    struct ast_node *second_son = nullptr,
    struct ast_node *third_son = nullptr,
    struct ast_node *forth_son = nullptr
);

/// @brief 创建抽象语法树的叶子节点
struct ast_node *new_ast_leaf_node(struct ast_node_attr &val);

/// @brief AST资源清理
void free_ast();
void free_ast_node(struct ast_node *node);
/// @brief抽象语法树的根节点指针
extern struct ast_node *ast_root;

