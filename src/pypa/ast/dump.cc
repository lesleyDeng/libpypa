#include <pypa/ast/visitor.hh>

namespace pypa {

struct dump_visitor {
    template<typename T> // Fallback visitor
    void operator()(T const & t) {
        printf("No defined visitor for AstType #%d\n", int(t.TYPE));
    }

    void operator() (AstModule const & p) {
        printf("Module:\n\n");
        for(auto stmt : p.body) {
            visit(stmt);
        }
    }

    void operator() (AstArguments const & a) {
       visit(a.arguments);
       if(!a.args.empty()) { printf("*%s, ", a.args.c_str()); }
       if(!a.kwargs.empty()) { printf("**%s, ", a.kwargs.c_str()); }
    }

    void operator() (AstFunctionDef const & p) {
        printf("FunctionDef: %s\n", p.name.c_str());
        printf("Decorators:  "); visit(p.decorators);
        printf("\nArguments: "); visit(p.args);
        printf("\nBody:");
        visit(p.body);
    }

    void visit(AstContext p) {
        printf("[Context: ");
        switch(p) {
        case AstContext::AugLoad:   printf("AugLoad"); break;
        case AstContext::AugStore:  printf("AugStore"); break;
        case AstContext::Load:      printf("Load"); break;
        case AstContext::Store:     printf("Store"); break;
        case AstContext::Param:     printf("Param"); break;
        case AstContext::Del:       printf("Del"); break;
        }
        printf("] ");
    }

    void operator() (AstWithItem const & p) {
        printf("WithItem:\n\tContext:");
        visit(p.context);
        printf("\n\tOptional:");
        visit(p.optional);
        printf("\n");
    }

    void operator() (AstWith const & p) {
        printf("With:\n\tItems: ");
        visit(p.items);
        printf("\tBody:\n");
        visit(p.body);
        printf("\n");
    }

    void operator() (AstPrint const & p) {
        printf("\t- Print ");
        if(p.destination) { printf(" >> "); visit(p.destination); printf(","); }
        visit(p.values);
        printf("\n");
    }

    void operator() (AstNumber const & n) {
        if(n.num_type == AstNumber::Float) printf("Number: %g", n.floating);
        else printf("Number: %lli", n.integer);
    }

    void operator() (AstPass const &) {
        printf("\t- Pass\n");
    }

    void operator() (AstName const & p) {
        printf("Name: %s ", p.id.c_str());
        visit(p.context);
        printf(", ");
    }

    template< typename T >
    void visit(std::vector<T> const & v) {
        if(v.empty()) printf("[]");
        else for(auto e : v) {
            visit(e);
        }
    }

    void visit(Ast const & p) {
        pypa::visit(*this, p);
    }

    void visit(AstPtr p) {
        if(p) {
            pypa::visit(*this, *p);
        } else {
            printf("<NULL>");
        }
    }
};

void dump(AstPtr p) {
    visit(dump_visitor(), *p);
}

}
