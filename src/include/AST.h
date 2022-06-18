#ifndef AST_H
#define AST_H 

typedef struct AST_STRUCT {
    enum {
        AST_COMPOUND,
        AST_FUNCTION_DEFINITON,
        AST_DEFFINITION_TYPE,
        AST_VARIABLE,
        AST_STATEMENT,
        AST_NOOP
    } type;
} AST_T;

AST_T* init_ast(int type);

#endif