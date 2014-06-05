#ifndef GUARD_PYPA_AST_AST_HH_INCLUDED
#define GUARD_PYPA_AST_AST_HH_INCLUDED

#include <pypa/ast/base.hh>


namespace pypa {

PYPA_AST_TYPE_DECL_DERIVED(Arguments) {
    AstExprList arguments;
    AstExprList defaults;
    String kwargs;
    String args;
};
DEF_AST_TYPE_BY_ID1(Arguments);

PYPA_AST_TYPE_DECL_DERIVED(Keyword) {
    String name;
    AstExpr value;
};
DEF_AST_TYPE_BY_ID1(Keyword);

PYPA_AST_TYPE_DECL_DERIVED(Alias) {
    String name;
    String as_name;
};
DEF_AST_TYPE_BY_ID1(Alias);

PYPA_AST_STMT(Assert) {
    AstExpr expression;
    AstExpr test;
};

PYPA_AST_STMT(Assign) {
    AstExprList targets;
    AstExpr     value;
};

PYPA_AST_STMT(AugAssign) {
    AstExpr         value;
    AstExpr         target;
    AstBinOpType    op;
};

PYPA_AST_STMT(Attribute) {
    AstExpr     value;
    AstContext  context;
    String      attribute;
};

PYPA_AST_EXPR(BinOp) {
    AstBinOpType    op;
    AstExpr         left;
    AstExpr         right;
};

PYPA_AST_EXPR(BoolOp) {
    AstBoolOpType op;
    AstExprList   values;
};

PYPA_AST_STMT(Break) {};

PYPA_AST_STMT(Call) {
    AstExpr         function;
    AstExpr         args;
    AstExpr         kwargs;
    AstExprList     arguments;
    AstKeywordList  keywords;
};

PYPA_AST_STMT(ClassDef) {
    AstExprList bases;
    AstExprList decorators;
    AstStmtList body;
    String      name;
};

PYPA_AST_STMT(Continue) {};

PYPA_AST_STMT(Compare) {
    std::vector<AstCompareOpType> ops;
    AstExprList                 comperators;
    AstExpr                     left;
};

PYPA_AST_TYPE_DECL_DERIVED_ALIAS(Comprehension, AstComprPtr, AstComprList) {
    AstExpr target;
    AstExpr iter;
    AstExprList ifs;
};
DEF_AST_TYPE_BY_ID1(Comprehension);

PYPA_AST_EXPR(Decorator) {
    AstCall call;
};

PYPA_AST_EXPR(Decorators) {
    std::vector<AstDecoratorPtr> decorators;
};

PYPA_AST_EXPR(Decorated) {
    AstDecorators decorators;
    AstStmt       cls_or_fun_def;
};

PYPA_AST_STMT(Delete) {
    AstExprList targets;
};

PYPA_AST_EXPR(Dict) {
    AstExprList keys;
    AstExprList values;
};

PYPA_AST_EXPR(DictComp) {
    AstExpr         key;
    AstExpr         value;
    AstComprList    generators;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(Ellipsis) {};
DEF_AST_TYPE_BY_ID1(Ellipsis);

PYPA_AST_STMT(Exec) {
    AstExpr body;
    AstExpr globals;
    AstExpr locals;
};

PYPA_AST_STMT(Except) {
    AstStmtList body;
    AstExpr type;
    AstExpr name;
};
typedef std::vector<AstExceptPtr> AstExceptList;


PYPA_AST_STMT(ExpressionStatement) {
    AstExpr expr;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(ExtSlice) {
    AstExprList dims;
};
DEF_AST_TYPE_BY_ID1(ExtSlice);

PYPA_AST_STMT(For) {
    AstStmtList body;
    AstStmtList orelse;
    AstExpr     target;
    AstExpr     iter;
};

PYPA_AST_STMT(FunctionDef) {
   String       name;
   AstArguments args;
   AstStmtList  body;
   AstExprList  decorators;
};

PYPA_AST_STMT(Global) {
    StringList names;
};

PYPA_AST_STMT(If) {
    AstStmtList body;
    AstStmtList orelse;
    AstExpr     test;
};

PYPA_AST_EXPR(IfExpr) {
    AstExpr body;
    AstExpr orelse;
    AstExpr test;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(Index) {
    AstExpr value;
};
DEF_AST_TYPE_BY_ID1(Index);

PYPA_AST_STMT(Import) {
    AstAliasList names;
};

PYPA_AST_STMT(ImportFrom) {
    String          module;
    AstAliasList    names;
    int             level;
};

PYPA_AST_EXPR(Lambda) {
    AstArguments    arguments;
    AstExpr         body;
};

PYPA_AST_EXPR(List) {
    AstExprList elements;
    AstContext  context;
};

PYPA_AST_EXPR(ListComp) {
    AstComprList generators;
    AstExpr      element;
};

PYPA_AST_EXPR(Name) {
    AstContext  context;
    String      id;
};

PYPA_AST_EXPR(Number) {
    enum Type {
        Integer,
        Float
    } num_type;
    union {
        double  floating;
        int64_t integer;
    };
};

PYPA_AST_TYPE_DECL_DERIVED(Module) {
    AstStmtList body;
};
DEF_AST_TYPE_BY_ID1(Module);

PYPA_AST_STMT(Pass) {
};

PYPA_AST_STMT(Print) {
    AstExpr         destination;
    bool            newline;
    AstExprList     values;
};


PYPA_AST_EXPR(Repr) {
    AstExpr value;
};

PYPA_AST_STMT(Raise) {
    AstExpr type;
    AstExpr instance;
    AstExpr traceback;
};

PYPA_AST_STMT(Return) {
    AstExpr value;
};

PYPA_AST_EXPR(Set) {
    AstExprList elements;
};

PYPA_AST_EXPR(SetComp) {
    AstExpr      element;
    AstComprList generators;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(Slice) {
    AstExpr lower;
    AstExpr upper;
    AstExpr step;
};
DEF_AST_TYPE_BY_ID1(Slice);

PYPA_AST_EXPR(Str) {
    String value;
    AstContext context;
};

PYPA_AST_EXPR(Subscript) {
    AstExpr         value;
    AstSliceKindPtr slice;
    AstContext      context;
};

PYPA_AST_STMT(TryExcept) {
    AstStmtList     body;
    AstStmtList     orelse;
    AstExceptList   handlers;
};

PYPA_AST_STMT(TryFinally) {
    AstStmtList body;
    AstStmtList final_body;
};

PYPA_AST_EXPR(Tuple) {
    AstExprList elements;
    AstContext  context;
};

PYPA_AST_EXPR(UnaryOp) {
    AstExpr         operand;
    AstUnaryOpType  op;
};

PYPA_AST_STMT(While) {
    AstExpr     test;
    AstStmtList body;
    AstStmtList orelse;
};

PYPA_AST_TYPE_DECL_DERIVED(WithItem) {
    AstExpr context;
    AstExpr optional;
};
DEF_AST_TYPE_BY_ID1(WithItem);

PYPA_AST_STMT(With) {
    AstWithItemList items;
    AstStmtList body;
};


PYPA_AST_STMT(Yield) {
    AstExprList args;
};

}
#endif // GUARD_PYPA_AST_AST_HH_INCLUDED
