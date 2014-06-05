#if !(defined(GUARD_PYPA_AST_AST_HH_INCLUDED) && defined(GUARD_PYPA_AST_TYPES_HH_INCLUDED))
#   error "This must be only included by pypa/ast/ast.hh"
#endif
#ifndef GUARD_PYPA_AST_MACROS_HH_INCLUDED
#define GUARD_PYPA_AST_MACROS_HH_INCLUDED


#define DEF_AST_TYPE_BY_ID(ID, TYPE) \
    template<> struct AstTypeByID<AstType::ID> { typedef TYPE Type; }

#define DEF_AST_TYPE_BY_ID1(TYPE) DEF_AST_TYPE_BY_ID(TYPE, Ast##TYPE)




#define PYPA_AST_TYPE_DECL_ALIAS(NAME, ALIASPTR, ALIASLIST) \
    typedef std::shared_ptr<struct NAME> ALIASPTR; \
    typedef std::vector<ALIASPTR> ALIASLIST; \
    struct NAME

#define PYPA_AST_TYPE_DECL(NAME) \
    PYPA_AST_TYPE_DECL_ALIAS(NAME, NAME##Ptr, NAME##List)

#define PYPA_AST_TYPE_DECL_DERIVED_TPL(NAME, TPL) \
    PYPA_AST_TYPE_DECL(Ast##NAME) : TPL<AstType::NAME>

#define PYPA_AST_TYPE_DECL_DERIVED(NAME) \
    PYPA_AST_TYPE_DECL_DERIVED_TPL(NAME, AstT)

#define PYPA_AST_TYPE_DECL_DERIVED_ALIAS(NAME, ALIASPTR, ALIASLIST) \
    PYPA_AST_TYPE_DECL_ALIAS(Ast##NAME, ALIASPTR, ALIASLIST) : AstT<AstType::NAME>





#define PYPA_AST_TYPE_DECL_SLICE_KIND(NAME) \
    PYPA_AST_TYPE_DECL_DERIVED_TPL(NAME, AstSliceT)





#define PYPA_AST_STMT(AST_TYPE) \
    typedef std::shared_ptr<struct Ast##AST_TYPE> Ast##AST_TYPE##Ptr; \
    DEF_AST_TYPE_BY_ID(AST_TYPE, struct Ast##AST_TYPE); \
    struct Ast##AST_TYPE : AstStmtT<AstType::AST_TYPE>

#define PYPA_AST_EXPR(AST_TYPE) \
    typedef std::shared_ptr<struct Ast##AST_TYPE> Ast##AST_TYPE##Ptr; \
    DEF_AST_TYPE_BY_ID(AST_TYPE, struct Ast##AST_TYPE); \
    struct Ast##AST_TYPE : AstExprT<AstType::AST_TYPE>

#endif //GUARD_PYPA_AST_MACROS_HH_INCLUDED
